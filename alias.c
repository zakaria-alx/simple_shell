#include "head.h"

/**
 * _alias - handle aliases
 *
 * @argc: arguments counter
 * @args: arguments list
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 *
 * Return: 1
 */
int _alias(int argc, char **args, char *name,
		   aliases *alias, int *idx, char **split, char *line)
{
	char **als;
	int i, j;
	(void)name;
	(void)split;
	(void)line;
	if (argc == 1)
	{
		for (i = 0; *idx && i < *idx; i++)
		{
			write_std(1, alias[i].name), write_std(1, "='");
			write_std(1, alias[i].value), write_std(1, "'\n");
		}
	}
	for (i = 1; i < argc; i++)
	{
		als = _strtok(args[i], "="), j = _getalias(alias, als[0], *idx);
		if (!_strstr(args[i], "="))
		{
			if (j != -1)
			{
				write_std(1, alias[j].name), write_std(1, "='");
				write_std(1, alias[j].value), write_std(1, "'\n");
			}
			else
				stderr(name, args, args[i], 10);
		}
		else if (j != -1)
		{
			alias[j].value = malloc(_strlen(als[1]) + 1 + _strlen("''"));
			_strcpy(alias[j].value, als[1]);
		}
		else
		{
			alias[*idx].name = malloc(_strlen(als[0]) + 1);
			alias[*idx].value = malloc(_strlen(als[1]) + 1 + _strlen("''"));
			_strcpy(alias[*idx].name, als[0]);
			_strcpy(alias[*idx].value, als[1]), (*idx)++;
		}
	}
	return (1);
}

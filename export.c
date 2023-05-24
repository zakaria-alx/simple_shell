#include "head.h"

/**
 * export - check code
 *
 * @argc: arguments count
 * @args: arguments length
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 *
 * Return: 1
 */
int export(int argc, char **args, char *name,
		   aliases *alias, int *idx, char **split, char *line)
{
	int i = 0;
	char *temp;

	(void)alias;
	(void)idx;
	(void)split;
	(void)line;
	if (argc != 3)
	{
		stderr(name, args, NULL, 4);
		return (0);
	}
	else
	{
		temp = _getenv(args[1]);
		if (temp)
			_strcpy(temp, args[2]);
		else
		{
			while (environ[i])
				i++;
			environ[i] = malloc(_strlen(args[1]) + _strlen(args[2]) + 3);
			_strconcat(environ[i], args[1]);
			_strconcat(environ[i], "=");
			_strconcat(environ[i], args[2]);
			environ[++i] = NULL;
		}
		return (1);
	}
}

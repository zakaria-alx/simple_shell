#include "head.h"

/**
 * unset - check code
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
int unset(int argc, char **args, char *name,
		  aliases *alias, int *idx, char **split, char *line)
{
	int i;

	(void)alias;
	(void)idx;
	(void)split;
	(void)line;
	if (argc != 2)
	{
		stderr(name, args, NULL, 5);
		return (0);
	}
	else if (_getenv(args[1]) == NULL)
	{
		stderr(name, args, NULL, 6);
		return (0);
	}
	else
	{
		for (i = 0; environ[i]; i++)
		{
			if (_strncmp(environ[i], args[1], _strlen(args[1])) == 0)
			{
				environ[i] = NULL;
				break;
			}
		}
		return (1);
	}
}

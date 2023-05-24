#include "head.h"

/**
 * env - prints env
 *
 * @argc: argc
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 *
 * Return: 1
 */
int env(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i;

	(void)argc;
	(void)args;
	(void)name;
	(void)split;
	(void)alias;
	(void)idx;
	(void)line;
	for (i = 0; environ[i]; i++)
	{
		write_std(1, environ[i]);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

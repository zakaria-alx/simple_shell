#include "head.h"

/**
 * exit_function - check code
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
int exit_function(int argc, char **args, char *name,
				  aliases *alias, int *idx, char **split, char *line)
{
	int i = 0;

	(void)alias;
	(void)idx;
	for (; argc > 1 && args[1][i]; i++)
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			stderr(name, args, NULL, 2);
			return (0);
		}
	}
	if (argc > 1)
		i = _atoi(args[1]);
	_free(split);
	free(line);
	_free(args);
	exit(i);
	return (1);
}

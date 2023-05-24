#include "head.h"

/**
 * handle_cd - check code
 * @argc: arguments count
 * @args: arguments length
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int handle_cd(int argc, char **args, char *name,
			  aliases *alias, int *idx, char **split, char *line)
{
	char *path, *temp;

	(void)alias;
	(void)idx;
	(void)line;
	(void)split;
	path = argc == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (chdir(path) < 0)
	{
		stderr(name, args, path, 3);
		return (0);
	}
	temp = _getenv("PWD");
	_strcpy(temp, path);
	if (argc == 1)
	{
		write_std(1, path);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

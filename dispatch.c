#include "head.h"

/**
 * args_count - check code
 *
 * @args: arguments list
 *
 * Return: argc
 */
int args_count(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);
	return (1 + args_count(args + 1));
}

/**
 * cmd_dispatch - check code
 *
 * @cmd: command name
 * @args: arguments list
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 *
 * Return: 1
 */
int cmd_dispatch(const char *cmd, char **args,
				 char *name, aliases *alias, int *idx, char **split, char *line)
{
	int j = 0;

	cmd_handler executers[] = {/* Same logic as printf*/
							   {"exit", exit_function},
							   {"cd", handle_cd},
							   {"setenv", export},
							   {"unsetenv", unset},
							   {"env", env},
							   {"alias", _alias},
							   {NULL, NULL}};

	while (executers[j].exec_func != NULL && _strcmp(cmd, executers[j].cmd) != 0)
	{
		j++;
	}
	if (executers[j].exec_func != NULL)
	{
		return (executers[j].exec_func(args_count(args), args,
									   name, alias, idx, split, line));
	}
	return (-1);
}

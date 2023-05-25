#include "head.h"

/**
 * get_builtin - builtin that pais the command in the arg
 * @command: command
 * Return: function pointer of the builtin command
 */
int (*get_builtin(char *command))(shell_data *)
{
	shell_builtin_list builtin[] = {/* Same as printf */
									{"env", _env},
									{"exit", exit_shell},
									{"setenv", _setenv},
									{"unsetenv", _unsetenv},
									{"cd", shell_cd},
									{"help", get_help},
									{NULL, NULL}};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, command) == 0)
			break;
	}

	return (builtin[i].f);
}

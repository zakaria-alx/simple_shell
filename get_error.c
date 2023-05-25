#include "head.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @shdata: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(shell_data *shdata, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(shdata);
		break;
	case 126:
		error = error_path_126(shdata);
		break;
	case 127:
		error = error_not_found(shdata);
		break;
	case 2:
		if (_strcmp("exit", shdata->args[0]) == 0)
			error = error_exit_shell(shdata);
		else if (_strcmp("cd", shdata->args[0]) == 0)
			error = error_get_cd(shdata);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	shdata->status = eval;
	return (eval);
}

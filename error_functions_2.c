#include "head.h"

/**
 * error_env - error message for env in get_env.
 * @shdata: data relevant (counter, arguments)
 * Return: error message.
 */
char *error_env(shell_data *shdata)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = _itoa(shdata->counter);
	msg = ": Unable to perform add or remove from/to environment\n";
	length = _strlen(shdata->vector[0]) + _strlen(ver_str);
	length += _strlen(shdata->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, shdata->vector[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, shdata->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * error_path_126 - error message for path and failure denied permission.
 * @shdata: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *error_path_126(shell_data *shdata)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = _itoa(shdata->counter);
	length = _strlen(shdata->vector[0]) + _strlen(ver_str);
	length += _strlen(shdata->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, shdata->vector[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, shdata->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

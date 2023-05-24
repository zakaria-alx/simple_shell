#include "head.h"

/**
 * is_valid - is valid command
 *
 * @command: command
 * @name: name
 * @arr: arr
 *
 * Return: string
 */
char *is_valid(char *command, char *name, char **arr)
{
	int i;
	struct stat buf;
	char *path, **path_arr = NULL, *env;

	env = _getenv("PATH");
	if (!env)
	{
		if (!access(command, X_OK) && stat(command, &buf) == 0)
			return (command);
		return (NULL);
	}
	else if (*env == '\0')
	{
		stderr(name, arr, NULL, 1);
		exit(EXIT_FAILURE);
	}
	else
		path_arr = _strtok(env, ":");
	for (i = 0; path_arr[i]; i++)
	{
		if (!_strstr(command, "/"))
		{
			path = malloc(_strlen(path_arr[i]) + _strlen(command) + 3);
			_strcpy(path, path_arr[i]);
			_strconcat(path, "/");
			_strconcat(path, command);
		}
		else
			path = malloc(_strlen(command) + 2), _strcpy(path, command);
		if (!access(path, X_OK) && stat(path, &buf) == 0)
		{
			_free(path_arr);
			return (path);
		}
		free(path);
	}
	_free(path_arr);
	free(path);
	return (NULL);
}

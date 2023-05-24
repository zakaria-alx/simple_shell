#include "head.h"

/**
 * _fork - check code
 *
 * @name: command name
 * @arr: arguments
 *
 * Return: success
 */
int _fork(char *name, char **arr)
{
	pid_t pid;
	int status, success = 1;
	char *path = NULL;

	path = is_valid(arr[0], name, arr);
	if (path != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			success = exec_command(arr, name, path);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
		free(path);
	}
	else
	{
		stderr(name, arr, NULL, 1);
		success = 0;
	}
	return (success);
}

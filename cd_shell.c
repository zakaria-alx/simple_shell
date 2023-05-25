#include "head.h"

/**
 * handle_dot - changes to the parent directory
 *
 * @shdata: data relevant (environ)
 *
 * Return: no return
 */
void handle_dot(shell_data *shdata)
{
	char pwd[PATH_MAX];
	char *dir, *cppwd, *strtok_cppwd;

	getcwd(pwd, sizeof(pwd));
	cppwd = _strdup(pwd);
	set_env("OLDPWD", cppwd, shdata);
	dir = shdata->args[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("PWD", cppwd, shdata);
		free(cppwd);
		return;
	}
	if (_strcmp("/", cppwd) == 0)
	{
		free(cppwd);
		return;
	}
	strtok_cppwd = cppwd;
	_strrev(strtok_cppwd);
	strtok_cppwd = _strtok(strtok_cppwd, "/");
	if (strtok_cppwd != NULL)
	{
		strtok_cppwd = _strtok(NULL, "\0");

		if (strtok_cppwd != NULL)
			_strrev(strtok_cppwd);
	}
	if (strtok_cppwd != NULL)
	{
		chdir(strtok_cppwd);
		set_env("PWD", strtok_cppwd, shdata);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", shdata);
	}
	shdata->status = 0;
	free(cppwd);
}

/**
 * handle_to_path - changes to a directory given
 * by the user
 *
 * @shdata: data relevant (directories)
 * Return: no return
 */
void handle_to_path(shell_data *shdata)
{
	char pwd[PATH_MAX];
	char *dir, *cppwd, *cpdir;

	getcwd(pwd, sizeof(pwd));

	dir = shdata->args[1];
	if (chdir(dir) == -1)
	{
		get_error(shdata, 2);
		return;
	}

	cppwd = _strdup(pwd);
	set_env("OLDPWD", cppwd, shdata);

	cpdir = _strdup(dir);
	set_env("PWD", cpdir, shdata);

	free(cppwd);
	free(cpdir);

	shdata->status = 0;

	chdir(dir);
}

/**
 * handle_cd_back - changes to the previous directory
 *
 * @shdata: data relevant (environ)
 * Return: no return
 */
void handle_cd_back(shell_data *shdata)
{
	char pwd[PATH_MAX];
	char *ppwd, *poldpwd, *cppwd, *cpoldpwd;

	getcwd(pwd, sizeof(pwd));
	cppwd = _strdup(pwd);

	poldpwd = _getenv("OLDPWD", shdata->_environ);

	if (poldpwd == NULL)
		cpoldpwd = cppwd;
	else
		cpoldpwd = _strdup(poldpwd);

	set_env("OLDPWD", cppwd, shdata);

	if (chdir(cpoldpwd) == -1)
		set_env("PWD", cppwd, shdata);
	else
		set_env("PWD", cpoldpwd, shdata);

	ppwd = _getenv("PWD", shdata->_environ);

	write(STDOUT_FILENO, ppwd, _strlen(ppwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cppwd);
	if (poldpwd)
		free(cpoldpwd);

	shdata->status = 0;

	chdir(ppwd);
}

/**
 * handle_cd_home - changes to home directory
 *
 * @shdata: data relevant (environ)
 * Return: no return
 */
void handle_cd_home(shell_data *shdata)
{
	char *ppwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	ppwd = _strdup(pwd);

	home = _getenv("HOME", shdata->_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", ppwd, shdata);
		free(ppwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(shdata, 2);
		free(ppwd);
		return;
	}

	set_env("OLDPWD", ppwd, shdata);
	set_env("PWD", home, shdata);
	free(ppwd);
	shdata->status = 0;
}

/**
 * shell_cd - changes current directory
 *
 * @shdata: data relevant
 * Return: 1 on success
 */
int shell_cd(shell_data *shdata)
{
	char *dir;
	int isHome, isTilda, isddash;

	dir = shdata->args[1];

	if (dir != NULL)
	{
		isHome = _strcmp("$HOME", dir);
		isTilda = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !isHome || !isTilda || !isddash)
	{
		handle_cd_home(shdata);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		handle_cd_back(shdata);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		handle_dot(shdata);
		return (1);
	}

	handle_to_path(shdata);

	return (1);
}

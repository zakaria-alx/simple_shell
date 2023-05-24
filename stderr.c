#include "head.h"

/**
 * _stderr - prints error msgs to stderr
 *
 * @args: args
 * @path: path
 * @n: error index
 *
 */
void _stderr(char **args, char *path, int n)
{
	char SEMICOLON = ';';

	if (n == 5)
		write_std(2, "usage: unsetenv VARIABLE VALUE");
	else if (n == 6)
	{
		write_std(2, "environment variable ");
		write_std(2, args[1]);
		write_std(2, " not found");
	}
	else if (n == 7)
		write_std(2, "Syntax error: \"&\" unexpected");
	else if (n == 8)
		write_std(2, "Syntax error: \"|\" unexpected");
	else if (n == 9)
	{
		write_std(2, "Syntax error: \"");
		write(STDERR_FILENO, &SEMICOLON, 1);
		write(STDERR_FILENO, &SEMICOLON, 1);
		write_std(2, "\" unexpected");
	}
	else if (n == 10)
	{
		write_std(2, "alias: ");
		write_std(2, path);
		write_std(2, " not found");
	}
}

/**
 * stderr - prints error msgs to stderr
 *
 * @name: name
 * @args: args
 * @path: path
 * @n: error index
 *
 * Return: value
 */
int stderr(char *name, char **args, char *path, int n)
{
	static unsigned int i;

	if (!n)
	{
		i++;
		return (0);
	}
	if (n == 11)
	{
		write_std(2, name);
		write_std(2, ": 0: Can't open ");
		write_std(2, args[1]);
		write(STDERR_FILENO, "\n", 1);
		return (EXIT_FAILURE);
	}
	write_std(2, name);
	write_std(2, ": ");
	cast_string(2, i);
	write_std(2, ": ");
	if (n == 1)
	{
		write_std(2, args[0]);
		write_std(2, ": not found");
	}
	else if (n == 2)
	{
		write_std(2, "exit: Illegal number: ");
		write_std(2, args[1]);
	}
	else if (n == 3)
	{
		write_std(2, "cd: can't cd to ");
		write_std(2, path);
	}
	else if (n == 4)
		write_std(2, "usage: setenv VARIABLE VALUE");
	else
		_stderr(args, path, n);
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}

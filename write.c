#include "head.h"

/**
 * cast_string - cast an integer to decimal
 * @n: input number
 * @i: integer
 * Return: string length
 */
int cast_string(int i, unsigned int n)
{
	char d;

	if (n >= 10)
	{
		return (cast_string(i, n / 10) + cast_string(i, n % 10));
	}
	d = '0' + n;
	if (i == 1)
	{
		return (write(STDOUT_FILENO, &d, 1));
	}
	return (write(STDERR_FILENO, &d, 1));
}

/**
 * write_std - Redirect output to stdout/stderr
 *
 * @i: exit status
 * @content: content to be redirected
 *
 * Return: string length
 */
int write_std(int i, char *content)
{
	if (i == 1)
		return (write(STDOUT_FILENO, content, _strlen(content)));
	return (write(STDERR_FILENO, content, _strlen(content)));
}

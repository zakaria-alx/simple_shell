#include "head.h"

/**
 * _atoi - Convert a string to an integer.
 *
 * @__nptr: string
 *
 * Return: integer
 */
int _atoi(char *__nptr)
{
	int i = 0;
	int m = 1;
	unsigned int n = 0;

	while (__nptr[i] != '\0')
	{
		if (__nptr[i] == '-')
			m = -m;

		if (__nptr[i] >= '0' && __nptr[i] <= '9')
		{
			n = (n * 10) + (__nptr[i] - '0');

			if (!(__nptr[i + 1] >= '0' && __nptr[i + 1] <= '9'))
				break;
		}

		i++;
	}

	n *= m;
	return (n);
}

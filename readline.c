#include "head.h"

/**
 * readline - reads the input string.
 *
 * @eof: return value of getline function
 * Return: input string
 */
char *readline(int *eof)
{
	char *input = NULL;
	size_t buff_size = 0;

	*eof = getline(&input, &buff_size, stdin);

	return (input);
}

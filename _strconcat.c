#include "head.h"

/**
 * _strconcat - Concatenates two strings
 *
 * @destination: destination
 * @source: source
 *
 *Return: destination string
 */

char *_strconcat(char *destination, char *source)
{
	int i, j;

	for (i = 0; destination[i] != '\0'; i++)
		;
	destination[i] = ' ';
	for (j = 0; source[j] != '\0'; i++, j++)
		destination[i] = source[j];
	destination[i] = '\0';
	return (destination);
}

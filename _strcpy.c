#include "head.h"

/**
 * _strcpy - Copies the string pointed to by source to destination
 *
 * @destination: This is the pointer to the destination array
 * where the content is to be copied.
 * @source: This is the string to be copied.
 *
 * Return: string
 */

char *_strcpy(char *destination, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return (destination);
}

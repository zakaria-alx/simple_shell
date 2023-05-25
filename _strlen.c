#include "head.h"

/**
 * _strlen - computes the length of a string.
 *
 * @str1: Type char pointer
 *
 * Return: length of string.
 */
int _strlen(const char *str1)
{
	int len;

	for (len = 0; str1[len] != 0; len++)
		;
	return (len);
}

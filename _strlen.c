#include "head.h"

/**
 * _strlen - Computes length of the string
 *
 * @s: string
 *
 * Return: length if string is truthy
 */

size_t _strlen(char *s)
{
	if (!s || *s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}

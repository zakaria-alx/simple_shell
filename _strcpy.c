#include "head.h"

/**
 * _strcpy - copies the string pointed to by src.
 *
 * @dest: destination string
 * @src: source string
 *
 * Return: destination string
 */
char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

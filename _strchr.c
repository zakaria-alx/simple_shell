#include "head.h"

/**
 * _strchr - searches for the first occurrence of the character c
 * in the string pointed to by the argument str
 *
 * @str: This is the C string to be scanned
 * @c: This is the character to be searched in str
 *
 * Return: a pointer to the first occurrence of
 * the character c in the string str,
 * or NULL if the character is not found.
 */
char *_strchr(char *str, char c)
{
	unsigned int i = 0;

	for (; *(str + i) != '\0'; i++)
		if (*(str + i) == c)
			return (str + i);

	if (*(str + i) == c)
		return (str + i);
	return ('\0');
}

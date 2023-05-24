#include "head.h"

/**
 * _strcmp - compares the string pointed to,
 * by str1 to the string pointed to by str2
 *
 * @str1: This is the first string to be compared
 * @str2: This is the second string to be compared
 *
 *Return: integer
 */
int _strcmp(const char *str1, char *str2)
{
	for (; *str1 == *str2; str1++, str2++)
	{
		if (*str1 == '\0')
			return (0);
	}
	return (*str1 - *str2);
}

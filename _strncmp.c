#include "head.h"

/**
 * _strncmp - compares at most the first n bytes of str1 and str2.
 *
 * @str1:  This is the first string to be compared
 * @str2:  This is the second string to be compared
 * @n: The maximum number of characters to be compared
 *
 * Return: integer
 */
int _strncmp(const char *str1, char *str2, int n)
{
	for (; n && *str1 == *str2; n--, str1++, str2++)
		;
	if (n)
	{
		return (*str1 - *str2);
	}
	return (0);
}

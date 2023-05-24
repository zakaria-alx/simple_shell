#include "head.h"

/**
 * _strpbrk - finds the first character in the string str1
 * that matches any character specified in str2
 *
 * @str1: This is the C string to be scanned.
 * @str2: This is the C string containing the characters to match
 *
 * Return: number or 0
 */
char *_strpbrk(char *str1, char *str2)
{
	int i, j;

	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	for (i = 0; str1[i] != '\0'; i++)
	{
		for (j = 0; str2[j] != '\0'; j++)
		{
			if (str1[i] == str2[j])
				break;
		}
		if (str2[j] != '\0')
			break;
	}
	if (str1[i] != '\0')
	{
		return (&str1[i]);
	}
	return (0);
}

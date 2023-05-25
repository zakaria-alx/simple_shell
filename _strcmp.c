#include "head.h"

/**
 * _strcmp - compares two strings.
 *
 * @str1: a string
 * @str2: a string
 *
 * Return: Always 0.
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i]; i++)
		;

	if (str1[i] > str2[i])
		return (1);
	if (str1[i] < str2[i])
		return (-1);
	return (0);
}

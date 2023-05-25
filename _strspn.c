#include "head.h"

/**
 * _strspn - gets the length of a prefix substring.
 *
 * @str1:  This is the main C string to be scanned.
 * @str2: This is the string containing the
 * list of characters to match in str1.
 *
 * Return: the number of characters in the initial segment of str1
 * which consist only of characters from str2.
 */
int _strspn(char *str1, char *str2)
{
	int i, j, bool;

	for (i = 0; *(str1 + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(str2 + j) != '\0'; j++)
		{
			if (*(str1 + i) == *(str2 + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}

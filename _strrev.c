#include "head.h"

/**
 * _strrev - reverses a string.
 *
 * @str1: input string.
 *
 * Return: no return.
 */
void _strrev(char *str1)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (str1[count] == '\0')
			break;
		count++;
	}
	str = str1;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}

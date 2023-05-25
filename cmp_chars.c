#include "head.h"
#include <stdbool.h>

/**
 * cmp_chars - compare characters of strings
 *
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i = 0, j = 0;

	for (; str[i] != '\0'; i++)
	{
		bool foundMatch = false;

		for (; delim[j] != '\0'; j++)
		{
			if (str[i] == delim[j])
			{
				foundMatch = true;
				break;
			}
		}
		if (!foundMatch)
			return (0);
	}
	return (1);
}

#include "head.h"

/**
 * _strstr - finds the first occurrence of the
 * substring needle in the string haystack
 *
 * @haystack: This is the main C string to be scanned
 * @needle: This is the small string to be searched
 * with-in haystack string
 *
 * Return: location pointer or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*haystack == '\0' && *needle == '\0')
	{
		return (NULL);
	}
	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (needle[j] != haystack[i + j])
			{
				break;
			}
		}
		if (needle[j] == '\0')
		{
			return (&haystack[i]);
		}
	}
	return (NULL);
}

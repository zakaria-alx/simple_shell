#include "head.h"

/**
 * _swap_text - check code
 *
 * @str: input string
 * @_sub_string: old substring
 * @sub_string: input substring
 *
 * Return: command decomposition
 */
void _swap_text(char *str, char *_sub_string, char *sub_string)
{
	char *ptr = NULL;
	size_t _len = _strlen(_sub_string),
		   len = _strlen(sub_string);
	size_t k = len, l = _len;

	ptr = _strstr(str, _sub_string);
	if (!ptr)
		return;
	do {
		ptr[k++] = ptr[l++];
	} while (ptr[l]);
	ptr[k] = '\0';
	_memcpy(ptr, sub_string, len);
	_swap_text(ptr + len, _sub_string, sub_string);
}

/**
 * _strrev - copies and reverses a string
 * @i: str length
 * @s: string
 * Return: i
 */

int _strrev(char *s, int i)
{
	char temp;
	int j;

	i--;
	for (j = 0; j <= i / 2; j++)
	{
		temp = s[j];
		s[j] = s[i - j];
		s[i - j] = temp;
	}
	return (j);
}

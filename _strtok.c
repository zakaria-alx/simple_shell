#include "head.h"

/**
 * exists_within - ...
 *
 * @c: character
 * @str: string
 *
 * Return: boolean
 *
 */
int exists_within(char c, char *str)
{
	if (*str == '\0')
	{
		return (c == *str);
	}
	return (c == *str ? 1 : exists_within(c, str + 1));
}

/**
 * _strtok - breaks string str into a series of tokens using
 * the delimiter delim
 *
 * @str: The contents of this string are modified and broken
 * into smaller strings (tokens).
 * @delim: This is the C string containing the delimiters.
 * These may vary from one call to another
 *
 * Return: tokens set
 *
 */
char **_strtok(char *str, char *delim)
{
	char **tokens;
	size_t j = 0, i, len = _strlen(str) + 1;
	int exists = 1, k = 0;

	tokens = (char **)_calloc(len * sizeof(char *), sizeof(char));
	*tokens = (char *)_calloc(len, sizeof(char));
	if (!*tokens)
		free(tokens);
	for (i = 0; str[i]; i++)
	{
		if (exists_within(str[i], delim))
		{
			if (!exists)
			{
				tokens[k++][j] = '\0';
				tokens[k] = (char *)_calloc(len, sizeof(char));
				if (!tokens[k])
					_free(tokens);
			}
			exists = 1;
			j = 0;
		}
		else
		{
			tokens[k][j++] = str[i];
			exists = 0;
		}
	}
	if (!exists)
		tokens[k][j] = '\0';
	else
	{
		free(tokens[k]);
		tokens[k] = NULL;
	}

	return (tokens);
}

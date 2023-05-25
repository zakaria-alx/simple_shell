#include "head.h"
#include <stdbool.h>

/**
 * _strtok - breaks string str into a series of
 * tokens using the delimiter delim
 *
 * @str: The contents of this string are modified and broken
 * into smaller strings (tokens)
 * @delim: This is the C string containing the delimiters.
 *
 * Return:  pointer to the first token found in the string.
 * A null pointer is returned if there are no tokens left to retrieve
 */
char *_strtok(char str[], const char *delim)
{
	static char *token, *string_;
	char *_string;
	unsigned int i, _bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		token = str;
		i = _strlen(str);
		string_ = &str[i];
	}
	_string = token;
	if (_string == string_)
		return (NULL);

	for (_bool = 0; *token; token++)
	{
		if (token != _string)
			if (*token && *(token - 1) == '\0')
				break;

		for (i = 0; delim[i]; i++)
		{
			if (*token == delim[i])
			{
				*token = '\0';
				if (token == _string)
					_string++;
				break;
			}
		}
		if (_bool == 0 && *token)
			_bool = 1;
	}
	if (_bool == 0)
		return (NULL);
	return (_string);
}

#include "head.h"

/**
 * _getenv - check code
 * @var: variable name
 * Return: string
 */
char *_getenv(char *var)
{
	int i;
	char *temp;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(var, environ[i], _strlen(var)))
		{
			temp = _strstr(environ[i], "=");
			temp++;
			return (temp);
		}
	}
	return (NULL);
}

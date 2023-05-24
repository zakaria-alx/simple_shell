#include "head.h"

/**
 * _getalias - checks for aliases
 *
 * @alias: aliases
 * @name: variable name
 * @idx: index
 *
 * Return: string
 */
int _getalias(aliases *alias, char *name, int idx)
{
	int i;

	for (i = 0; i < idx; i++)
	{
		if (!_strcmp(name, alias[i].name))
			return (i);
	}
	return (-1);
}

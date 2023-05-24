#include "head.h"

/**
 * del - deletes the first character of a string
 * @s: string
 */
void del(char **s)
{
	int i;

	for (i = 0; (*s)[i]; i++)
		(*s)[i] = (*s)[i + 1];
}

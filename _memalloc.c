#include "head.h"
/**
 * _free - deallocates the memory previously allocated
 * by a call to calloc, malloc, or realloc
 *
 * @dptr: dptr
 */
void _free(char **dptr)
{
	int i = 0;

	if (dptr == NULL)
	{
		return;
	}
	for (i = 0; dptr[i]; i++)
	{
		free(dptr[i]);
	}
	free(dptr);
}

/**
 * _calloc - allocates the requested memory and returns a pointer to it.
 *
 * @nitems: This is the number of elements to be allocated
 * @size: This is the size of elements
 *
 * Return: pointer or NULL
 */

void *_calloc(unsigned int nitems, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nitems == 0 || size == 0)
		return (NULL);
	p = malloc(size * nitems);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < size * nitems; i++)
		p[i] = 0;
	return (p);
}

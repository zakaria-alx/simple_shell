#include "head.h"

/**
 * _memcpy - Copies n characters from memory area
 * source to memory area destination.
 *
 * @destination: destination memory area
 * @source: source memory area
 * @n: bytes of the memory
 *
 * Return: destination
 */
char *_memcpy(char *destination, char *source, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		destination[i] = source[i];
	}
	return (destination);
}

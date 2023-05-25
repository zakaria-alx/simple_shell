#include "head.h"

/**
 * _memcpy - copies information between void pointers.
 *
 * @destination: destination pointer.
 * @source: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *destination, const void *source, unsigned int size)
{
	char *char_source = (char *)source;
	char *char_destination = (char *)destination;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_destination[i] = char_source[i];
}

/**
 * _realloc - reallocates a memory block.
 *
 * @source: pointer to the memory previously allocated.
 * @_size: size, in bytes, of the allocated space of ptr.
 * @size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if size == _size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *source, unsigned int _size, unsigned int size)
{
	void *destination;

	if (source == NULL)
		return (malloc(size));

	if (size == 0)
	{
		free(source);
		return (NULL);
	}

	if (size == _size)
		return (source);

	destination = malloc(size);
	if (destination == NULL)
		return (NULL);

	if (size < _size)
		_memcpy(destination, source, size);
	else
		_memcpy(destination, source, _size);

	free(source);
	return (destination);
}

/**
 * _reallocdptr - reallocates a memory block of a double pointer.
 * @source: double pointer to the memory previously allocated.
 * @_size: size, in bytes, of the allocated space of ptr.
 * @size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if size == _size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdptr(char **source, unsigned int _size, unsigned int size)
{
	char **destination;
	unsigned int i;

	if (source == NULL)
		return (malloc(sizeof(char *) * size));

	if (size == _size)
		return (source);

	destination = malloc(sizeof(char *) * size);
	if (destination == NULL)
		return (NULL);

	for (i = 0; i < _size; i++)
		destination[i] = source[i];

	free(source);

	return (destination);
}

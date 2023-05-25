#include "head.h"

/**
 * _itoa - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *_itoa(int n)
{
	unsigned int n1;
	int length = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + length) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	length--;
	do /* TODO Fix this */
	{
		*(buffer + length) = (n1 % 10) + '0';
		n1 = n1 / 10;
		length--;
	} while (n1 > 0);
	return (buffer);
}

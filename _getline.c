#include "head.h"

/**
 * _getline - check code
 * @line: string to read
 * Return: string length
 */
int _getline(char **line)
{
	int i;

	*line = _calloc(10240, sizeof(char));
	i = read(STDIN_FILENO, *line, 10240);
	(*line)[i] = '\0';
	return (i);
}

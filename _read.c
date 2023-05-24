#include "head.h"

/**
 * _read - Reads content from a file and stores it in a buffer.
 *
 * @line: Pointer to a pointer that will store the read content.
 * @args: Array of strings containing the command and its arguments.
 *
 * Return: The number of characters read from the file.
 *
 */
int _read(char **line, char **args)
{
	ssize_t i;
	int ret;

	ret = open(args[1], O_RDONLY);
	if (ret == -1)
	{
		stderr(args[0], args, NULL, 11);
		exit(EXIT_FAILURE);
	}
	*line = _calloc(10240, sizeof(char));
	i = read(ret, *line, 10240);
	close(ret);
	while (**line == ' ' || **line == '\t')
		(*line)++, i--;
	(*line)[i] = '\0';
	return (i);
}

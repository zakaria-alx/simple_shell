#include "head.h"

/**
 * main - Entry point for the shell program.
 *
 * @argc: The number of command-line arguments.
 * @args: Array of strings containing the command-line arguments.
 *
 * Return: Always returns 0.
 *
 */
int main(int argc, char **args)
{
	aliases alias;
	int idx = 0, output = 0;
	char *input = NULL, *name = args[0];

	(void)argc;
	alias.name = NULL;
	alias.value = NULL;
	while (1)
	{
		if (isatty(0) && argc == 1)
			write(STDOUT_FILENO, "$ ", 2);
		if (argc == 1 && _getline(&input) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(output);
		}
		else if (argc != 1 && _read(&input, args) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(output);
		}
		if (*input != '\0' && _strcmp(input, "\n"))
		{
			stderr(name, NULL, NULL, 0);
			output = splitline(input, name, &alias, &idx);
		}
		free(input);
		if (argc != 1)
			return (0);
	}
}

#include "head.h"

/**
 * without_comment - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *without_comment(char *in)
{
	int i, target_pos;

	target_pos = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				target_pos = i;
		}
	}

	if (target_pos != 0)
	{
		in = _realloc(in, i, target_pos + 1);
		in[target_pos] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @shdata: data relevant (vector, input, args)
 *
 * Return: no return.
 */
void shell_loop(shell_data *shdata)
{
	int loop, end_of_file;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "($) ", 4);
		input = readline(&end_of_file);
		if (end_of_file != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(shdata, input) == 1)
			{
				shdata->status = 2;
				free(input);
				continue;
			}
			input = replace_var(input, shdata);
			loop = split_commands(shdata, input);
			shdata->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

#include "head.h"

/**
 * swap_char - swaps | and & for non-printed chars
 *
 * @input: input string
 * @type: type of swap
 * Return: swapped string
 */
char *swap_char(char *input, int type)
{
	int i;

	if (type == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * add_nodes - add separators and command lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @input: input string
 * Return: no return
 */
void add_nodes(seperator_list **head_s, command_list **head_l, char *input)
{
	int i;
	char *line;

	input = swap_char(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			add_sep_node_end(head_s, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			add_sep_node_end(head_s, input[i]);
			i++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = swap_char(line, 1);
		add_cmd_node_end(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);
}

/**
 * get_next_command - go to the next command line stored
 *
 * @list_s: separator list
 * @list_l: command line list
 * @shdata: data structure
 *
 * Return: no return
 */
void get_next_command(seperator_list **list_s,
					  command_list **list_l, shell_data *shdata)
{
	int loop_sep;
	seperator_list *ls_s;
	command_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (shdata->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @shdata: data structure
 * @input: input string
 *
 * Return: 0 to exit, 1 to continue
 */
int split_commands(shell_data *shdata, char *input)
{

	seperator_list *head_s, *list_s;
	command_list *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		shdata->input = list_l->line;
		shdata->args = split_line(shdata->input);
		loop = exec_line(shdata);
		free(shdata->args);

		if (loop == 0)
			break;

		get_next_command(&list_s, &list_l, shdata);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_cmd_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - tokenizes the input string
 *
 * @input: input string.
 *
 * Return: string splitted.
 */
char **split_line(char *input)
{
	size_t btsize, i;
	char **tokens, *token;

	btsize = TKN_BUFFSIZE;
	tokens = malloc(sizeof(char *) * (btsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": memory allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TKN_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == btsize)
		{
			btsize += TKN_BUFFSIZE;
			tokens = _reallocdptr(tokens, i, sizeof(char *) * btsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": memory allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TKN_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}

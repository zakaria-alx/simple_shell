#include "head.h"

/**
 * check_env - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void check_env(variable_list **h, char *in, shell_data *data)
{
	int row, chr, j, valLength;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				valLength = _strlen(_envr[row] + chr + 1);
				add_var_node(h, j, _envr[row] + chr + 1, valLength);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_var_node(h, j, NULL, 0);
}

/**
 * check_vars - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int check_vars(variable_list **h, char *in, char *st, shell_data *data)
{
	int i, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_var_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				add_var_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				add_var_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_var_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_var_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_var_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_var_node(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
	}

	return (i);
}

/**
 * replaced_input - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replaced_input(variable_list **head,
					 char *input, char *new_input, int nlen)
{
	variable_list *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (indx->len_var);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * replace_var - calls functions to replace string into vars
 *
 * @input: input string
 * @shdata: data structure
 * Return: replaced string
 */
char *replace_var(char *input, shell_data *shdata)
{
	variable_list *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = _itoa(shdata->status);
	head = NULL;

	olen = check_vars(&head, input, status, shdata);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_var_list(&head);

	return (new_input);
}

#include "head.h"

/**
 * repeated_char - counts the repetitions of a char
 *
 * @str: input string
 * @i: index
 * Return: repetitions
 */
int repeated_char(char *str, int i)
{
	if (*(str - 1) == *str)
		return (repeated_char(str - 1, i + 1));

	return (i);
}

/**
 * error_sep_op - finds syntax errors
 *
 * @str: input string
 * @i: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int error_sep_op(char *str, int i, char last)
{
	int count;

	count = 0;
	if (*str == '\0')
		return (0);

	if (*str == ' ' || *str == '\t')
		return (error_sep_op(str + 1, i + 1, last));

	if (*str == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*str == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = repeated_char(str, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*str == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = repeated_char(str, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (error_sep_op(str + 1, i + 1, *str));
}

/**
 * first_char - finds index of the first char
 *
 * @str: input string
 * @i: index
 * Return: 1 if there is an error. 0 in other case.
 */
int first_char(char *str, int *i)
{

	for (*i = 0; str[*i]; *i += 1)
	{
		if (str[*i] == ' ' || str[*i] == '\t')
			continue;

		if (str[*i] == ';' || str[*i] == '|' || str[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax error is found
 *
 * @shdata: data structure
 * @str: input string
 * @i: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void print_syntax_error(shell_data *shdata, char *str, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (str[i] == ';')
	{
		if (bool == 0)
			msg = (str[i + 1] == ';' ? ";;" : ";");
		else
			msg = (str[i - 1] == ';' ? ";;" : ";");
	}

	if (str[i] == '|')
		msg = (str[i + 1] == '|' ? "||" : "|");

	if (str[i] == '&')
		msg = (str[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = _itoa(shdata->counter);
	length = _strlen(shdata->vector[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, shdata->vector[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_syntax_error - intermediate function to
 * find and print a syntax error
 *
 * @shdata: data structure
 * @str: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntax_error(shell_data *shdata, char *str)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = first_char(str, &begin);
	if (f_char == -1)
	{
		print_syntax_error(shdata, str, begin, 0);
		return (1);
	}

	i = error_sep_op(str + begin, 0, *(str + begin));
	if (i != 0)
	{
		print_syntax_error(shdata, str, begin + i, 1);
		return (1);
	}

	return (0);
}

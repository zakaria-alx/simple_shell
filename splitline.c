#include "head.h"

/**
 * check_alias - check code
 * @arr: arguments
 * @alias: alias array
 * @idx: integer
 * Return: none
 */
void check_alias(char ***arr, aliases *alias, int idx)
{
	int i, n;

	for (i = 0; (*arr)[i]; i++)
	{
		n = _getalias(alias, (*arr)[i], idx);
		if (n != -1)
		{
			(*arr)[i] = NULL;
			(*arr)[i] = malloc(_strlen(alias[n].value) + 1);
			_strcpy((*arr)[i], alias[n].value);
		}
	}
}

/**
 * write_double_dollar - check code
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int write_double_dollar(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "&\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free(arr);
			_free(line_split);
			return (stderr(name, NULL, NULL, 7));
		}
		_free(arr);
	}
	for (i = 0; line_split[i]; i++)
	{
		break_condition = 0;
		arr = _strtok(line_split[i], " \t");
		if (_strcmp(arr[0], "alias"))
			check_alias(&arr, alias, *idx);
		argc = args_count(arr);
		selector = cmd_dispatch(arr[0], arr, name, alias, idx, line_split, line);
		if (argc > 0 && selector < 0)
			break_condition = 1 - _fork(name, arr);
		else if (argc > 0)
			break_condition = 1 - selector;
		if (break_condition)
		{
			_free(arr);
			break;
		}
		_free(arr);
	}
	_free(line_split);
	return (break_condition ? 0 : EXIT_FAILURE);
}

/**
 * write_double_pipe - check code
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int write_double_pipe(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "|\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free(arr);
			_free(line_split);
			return (stderr(name, NULL, NULL, 8));
		}
		_free(arr);
	}
	i = 0;
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (_strcmp(arr[0], "alias"))
			check_alias(&arr, alias, *idx);
		break_condition = 0;
		argc = args_count(arr);
		selector = cmd_dispatch(arr[0], arr, name, alias, idx, line_split, line);
		if (argc > 0 && selector < 0)
			break_condition = _fork(name, arr);
		else if (argc > 0)
			break_condition = selector;
		if (break_condition)
		{
			_free(arr);
			break;
		}
		_free(arr);
	}
	_free(line_split);
	return (break_condition ? 0 : EXIT_FAILURE);
}

/**
 * write_semicolon - check code
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int write_semicolon(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int argc, i = 0, frk = 0;

	line_split = _strtok(line, ";\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free(arr);
			_free(line_split);
			return (stderr(name, NULL, NULL, 9));
		}
		_free(arr);
	}
	_free(line_split);
	line_split = _strtok(line, "@;\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t'");
		if (_strstr(line, "alias"))
			check_alias(&arr, alias, *idx);
		argc = args_count(arr);
		if (argc > 0 && cmd_dispatch(arr[0], arr,
									 name, alias, idx, line_split, line) < 0)
			_fork(name, arr);
		else if (!_strstr(line, "@") && argc == 0)
		{
			_free(line_split);
			_free(arr);
			return (stderr(name, NULL, NULL, 9));
		}
		_free(arr);
	}
	_free(line_split);
	return (frk ? EXIT_FAILURE : 0);
}

/**
 * splitline - read command line
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int splitline(char *line, char *name, aliases *alias, int *idx)
{
	size_t _len, len;
	char *temp;

	while (*line == ' ' || *line == '\t')
		del(&line);
	_len = _strlen(line);
	if (_len == 1)
		return (0);
	temp = _strstr(line, "#");
	if (temp)
		*temp = '\0';
	_swap_text(line, "&&", "&");
	len = _strlen(line);
	if (len < _len)
	{
		_swap_text(line, "&&", "&");
		if (_strlen(line) < len)
			return (stderr(name, NULL, NULL, 7));
		return (write_double_dollar(line, name, alias, idx));
	}
	_swap_text(line, "||", "|");
	len = _strlen(line);
	if (len < _len)
	{
		_swap_text(line, "||", "|");
		if (_strlen(line) < len)
			return (stderr(name, NULL, NULL, 8));
		return (write_double_pipe(line, name, alias, idx));
	}
	if (_strstr(line, ";;"))
		return (stderr(name, NULL, NULL, 9));
	_swap_text(line, "\n", "@");
	return (write_semicolon(line, name, alias, idx));
}

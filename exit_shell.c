#include "head.h"

/**
 * exit_shell - exits the shell
 *
 * @shdata: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(shell_data *shdata)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (shdata->args[1] != NULL)
	{
		ustatus = _atoi(shdata->args[1]);
		is_digit = _isdigit(shdata->args[1]);
		str_len = _strlen(shdata->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(shdata, 2);
			shdata->status = 2;
			return (1);
		}
		shdata->status = (ustatus % 256);
	}
	return (0);
}

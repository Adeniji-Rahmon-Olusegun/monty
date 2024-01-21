#include "monty.h"

/**
 * check_arg_len_req - checks if the argument length is
 * correct
 *
 * @argcount: number of argument passed to command line
 *
 * Return: None
 */

void check_arg_len_req(int argcount)
{
	if (argcount != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

#include "monty.h"

/**
 * read_arg_from_file - gets the argument command in the
 * file
 *
 * @file: file to be read
 *
 * Return: None
 */

void read_arg_from_file(char *file)
{
	int file_descriptor;

	file_descriptor = open(file, O_RDONLY);

	if (file_descriptor == -1)
	{
		getting_arg_fail(file);
	}

	global_variables->buffer = fdopen(file_descriptor, "r");

	if (global_variables->buffer == NULL)
	{
		close(file_descriptor);
		getting_arg_fail(file);
	}
}

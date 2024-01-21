#include "monty.h"

/**
 * close_file_buffer - closes the file buffer holing the
 * opcode in the file
 *
 * Return: None
 */

void close_file_buffer(void)
{
	if (global_variables->buffer == NULL)
	{
		return;
	}

	fclose(global_variables->buffer);
	global_variables->buffer = NULL;
}

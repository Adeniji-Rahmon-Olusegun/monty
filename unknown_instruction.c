#include "monty.h"

/**
 * unknown_instruction - prints an error message to
 * stderr for invalid instruction
 *
 * Return: None
 */

void unknown_instruction(void)
{
	dprintf(2, "L%d: unknown instruction %s\n", global_variables->line_num,
			global_variables->vect_tokenized_opscode[0]);

	close_file_buffer();
	free_vect_tokens();
	free_global_var();
	exit(EXIT_FAILURE);
}

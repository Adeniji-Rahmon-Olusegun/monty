#include "monty.h"

/**
 * free_top_stack - frees the top of the stack
 *
 * Return: None
 */

void free_top_stack(void)
{
	if (global_variables->top_stack)
		free_monty_stack(global_variables->top_stack);

	global_variables->top_stack = NULL;
}

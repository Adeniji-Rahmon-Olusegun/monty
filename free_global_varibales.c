#include "monty.h"

/**
 * free_global_var - frees the declared global
 * variables struct
 *
 * Return: None
 */

void free_global_var(void)
{
	if (global_variables == NULL)
	{
		return;
	}

	if (global_variables->stk_commands)
	{
		free(global_variables->stk_commands);
		global_variables->stk_commands = NULL;
	}

	free_top_stack();

	if (global_variables->lineptr)
	{
		free(global_variables->lineptr);
		global_variables->lineptr = NULL;
	}

	free(global_variables);
}

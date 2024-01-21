#include "monty.h"

/**
 * initialise_variables - initialises global variables
 *
 * Return: None
 */

void initialise_variables(void)
{
	global_variables = NULL;
	global_variables = (globalvar_t *)malloc(sizeof(globalvar_t));

	if (global_variables == NULL)
	{
		free(global_variables);
		mem_alloc_fail();
	}

	global_variables->stk_commands = malloc(sizeof(instruction_t));
	if (global_variables->stk_commands == NULL)
		mem_alloc_fail();

	global_variables->lineptr = NULL;
	global_variables->buffer = NULL;
	global_variables->top_stack = NULL;
	global_variables->line_num = 0;
	global_variables->stack = 1;
	global_variables->current_stk_len = 0;
	global_variables->num_tokens_opscode = 0;
	global_variables->vect_tokenized_opscode = NULL;
}

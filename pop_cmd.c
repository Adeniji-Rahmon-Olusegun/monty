#include "monty.h"

/**
 * pop_cmd - removes the top of the stack
 *
 * @stack: pointer to new node
 * @line_number: opcode line number
 *
 * Return: None
 */

void pop_cmd(stack_t **stack, unsigned int line_number)
{
	stack_t *stk_temp_var;

	(void) stack;

	if (global_variables->top_stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	stk_temp_var = global_variables->top_stack;
	global_variables->top_stack = global_variables->top_stack->next;
	free(stk_temp_var);
}

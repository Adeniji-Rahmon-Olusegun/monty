#include "monty.h"

/**
 * mod_cmd - obtains the modulus of the top two elements of the stack
 *
 * @stack: pointer to the new_node
 * @line_number: opcode line number
 *
 * Return: None
 */

void mod_cmd(stack_t **stack, unsigned int line_number)
{
	int mod_top_two;

	(void) stack;

	if (global_variables->current_stk_len < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	if (global_variables->top_stack->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	mod_top_two = (global_variables->top_stack->next->n) %
		(global_variables->top_stack->n);

	global_variables->top_stack->next->n = mod_top_two;

	pop_cmd(stack, line_number);

	global_variables->current_stk_len -= 1;
}

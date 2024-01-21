#include "monty.h"

/**
 * add_cmd - adds the top two elements of the stack
 *
 * @stack: pointer to the new_node
 * @line_number: opcode line number
 *
 * Return: None
 */

void add_cmd(stack_t **stack, unsigned int line_number)
{
	int sum_top_two;

	(void) stack;

	if (global_variables->current_stk_len < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	sum_top_two = 0;

	sum_top_two = global_variables->top_stack->n +
		global_variables->top_stack->next->n;

	global_variables->top_stack->next->n = sum_top_two;

	pop_cmd(stack, line_number);

	global_variables->current_stk_len--;
}

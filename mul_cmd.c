#include "monty.h"

/**
 * mul_cmd - multiplies the top two elements of the stack
 *
 * @stack: pointer to the new_node
 * @line_number: opcode line number
 *
 * Return: None
 */

void mul_cmd(stack_t **stack, unsigned int line_number)
{
	int mul_top_two;

	(void) stack;

	if (global_variables->current_stk_len < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	mul_top_two = global_variables->top_stack->n *
		global_variables->top_stack->next->n;

	global_variables->top_stack->next->n = mul_top_two;

	pop_cmd(stack, line_number);

	global_variables->current_stk_len--;
}

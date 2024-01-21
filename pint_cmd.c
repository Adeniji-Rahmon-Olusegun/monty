#include "monty.h"

/**
 * pint_cmd - prints the value of the
 * top of stack
 *
 * @stack: pointer to new node
 * @line_number: line number of opcode
 *
 * Return: None
 */

void pint_cmd(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (global_variables->top_stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", global_variables->top_stack->n);
}

#include "monty.h"

/**
 * pall_cmd - perfoms the pall operation on the
 * stack. prints all the elements of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number where error occured
 *
 * Return: None
 */

void pall_cmd(stack_t **stack, unsigned int line_number)
{
	stack_t *stk_tem_var;

	if (global_variables->top_stack == NULL)
	{
		return;
	}

	(void) line_number;
	(void) stack;

	stk_tem_var = global_variables->top_stack;

	while (stk_tem_var != NULL)
	{
		printf("%d\n", stk_tem_var->n);
		stk_tem_var = stk_tem_var->next;
	}
}

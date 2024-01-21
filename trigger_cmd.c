#include "monty.h"

/**
 * trigger_opcode_ops - activates the right function
 * to be performed on the stack
 *
 * Return: None
 */

void trigger_opcode_ops(void)
{
	stack_t *stack;

	stack = NULL;

	global_variables->stk_commands->f(&stack, global_variables->line_num);
}

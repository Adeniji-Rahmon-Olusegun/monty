#include "monty.h"

/**
 * free_monty_stack - frees all nodes in a stack
 *
 * @top_stack - top of the stack
 *
 * Return: None
 */

void free_monty_stack(stack_t *top_stack)
{
	if (top_stack == NULL)
	{
		return;
	}

	if (top_stack->next != NULL)
	{
		free_monty_stack(top_stack->next);
	}

	free(top_stack);
}

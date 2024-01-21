#include "monty.h"

/**
 * swap_cmd - swaps the first two elements of the
 * stack
 *
 * @stack: pointer to new node
 * @line_number: line_number od opcode
 *
 * Return: None
 */

void swap_cmd(stack_t **stack, unsigned int line_number)
{
	stack_t *front_node, *rear_node, *temp_var;

	(void) stack;

	if (global_variables->current_stk_len < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n",
				line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	rear_node = global_variables->top_stack;

	if (global_variables->current_stk_len == 2)
	{
		front_node = rear_node->next;
		rear_node->next = rear_node->prev;
		rear_node->prev = front_node;
		rear_node = front_node;
		front_node->prev = NULL;
		front_node->next = global_variables->top_stack;
		global_variables->top_stack = rear_node;
	}
	else
	{
		front_node = rear_node->next;
		temp_var = rear_node->next->next;
		rear_node->next = temp_var;
		temp_var->prev = global_variables->top_stack;
		rear_node->prev = front_node;
		rear_node = front_node;
		front_node->prev = NULL;
		front_node->next = global_variables->top_stack;
		global_variables->top_stack = rear_node;
	}
}

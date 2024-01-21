#include "monty.h"

/**
 * push_cmd - push operation on the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number where error occured
 *
 * Return: None
 */

void push_cmd(stack_t **stack, unsigned int line_number)
{
	if (global_variables->num_tokens_opscode <= 1 || !(check_if_number
				(global_variables->vect_tokenized_opscode[1])))
	{
		free_global_var();
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));

	if (*stack == NULL)
		mem_alloc_fail();

	(*stack)->n = (int) atoi(global_variables->vect_tokenized_opscode[1]);
	(*stack)->prev = NULL;
	(*stack)->next = NULL;

	if (global_variables->top_stack == NULL)
		global_variables->top_stack = *stack;
	else if (global_variables->stack)
	{
		(*stack)->next = global_variables->top_stack;
		global_variables->top_stack->prev = *stack;
		global_variables->top_stack = *stack;
	}
	else
	{
		stack_t *stk_temp_var = global_variables->top_stack;

		while (stk_temp_var->next)
			stk_temp_var = stk_temp_var->next;
		stk_temp_var->next = *stack;
		(*stack)->prev = stk_temp_var;
	}
	global_variables->current_stk_len++;
}

#include "monty.h"

/**
 * opscode_command_func - triggers or activate the
 * appropriate function to act on the stack.
 *
 * Return: None
 */

void opscode_command_func(void)
{
	int idx;

	instruction_t ops_cd[] = {
		{"push", &push_cmd},
		{"pall", &pall_cmd},
		{"pint", &pint_cmd},
		{"pop", &pop_cmd},
		{"swap", &swap_cmd},
		{"add", &add_cmd},
		{NULL, NULL}
	};

	if (global_variables->num_tokens_opscode == 0)
	{
		return;
	}

	for (idx = 0; ops_cd[idx].opcode != NULL; idx++)
	{
		if (strcmp(ops_cd[idx].opcode, global_variables->vect_tokenized_opscode[0])
				== 0)
		{
			global_variables->stk_commands->opcode = ops_cd[idx].opcode;
			global_variables->stk_commands->f = ops_cd[idx].f;
			return;
		}
	}

	unknown_instruction();
}


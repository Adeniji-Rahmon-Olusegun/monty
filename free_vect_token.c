#include "monty.h"

/**
 * free_vect_tokens - free the arrays of tokens
 *
 * Return: None
 */

void free_vect_tokens(void)
{
	int idx = 0;

	if (global_variables->vect_tokenized_opscode[idx] == NULL)
	{
		return;
	}

	while (global_variables->vect_tokenized_opscode[idx] != NULL)
	{
		free(global_variables->vect_tokenized_opscode[idx]);
		idx++;
	}

	free(global_variables->vect_tokenized_opscode);
	global_variables->vect_tokenized_opscode = NULL;
}

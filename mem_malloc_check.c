#include "monty.h"

/**
 * mem_alloc_fail - checks if memory allocation failed
 *
 * dyn_ptr - pointer to dynamically allocated memory
 *
 * Return: None.
 */

void mem_alloc_fail(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_global_var();
	exit(EXIT_FAILURE);
}



/**
 * getting_arg_fail - checks if the argument to 
 * be parsed failed
 *
 * file - file containing the opcodes command
 *
 * Return: None.
 */

void getting_arg_fail(char *file)
{
	dprintf(2, "Error: Can't open file %s\n", file);
	free_global_var();
	exit(EXIT_FAILURE);
}

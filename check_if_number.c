#include "monty.h"

/**
 * check_if_number - checks if a character is a number
 *
 * @tok: string to check
 *
 * Return: 1 if true and 0 otherwise
 */

int check_if_number(char *tok)
{
	int idx;

	idx = 0;

	while (tok[idx])
	{
		if (idx == 0 && tok[idx] == '-' && tok[1 + idx])
		{
			idx++;
			continue;
		}
		else if (tok[idx] < '0' || tok[idx] > '9')
		{
			return (0);
		}
		idx++;
	}

	return (1);
}

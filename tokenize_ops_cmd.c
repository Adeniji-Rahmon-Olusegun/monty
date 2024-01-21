#include "monty.h"

/**
 * tokenize_opscode_cmd - tokenizes opscode for
 * stack action
 *
 * @buff_str: string to be tokenized
 * @delimeter: criteria for dividing the strings
 *
 * Return: None
 */

void tokenize_opscode_cmd(char *buff_str, char *delimeter)
{
	int idx, num_tokens;
	char *tokens1, *tokens2;
	char **string_vec;
	char *first_dup, *second_dup;

	idx = 0;
	num_tokens = 0;

	first_dup = strdup(buff_str);
	second_dup = strdup(buff_str);

	tokens1 = strtok(first_dup, delimeter);

	while (tokens1 != NULL)
	{
		tokens1 = strtok(NULL, delimeter);
		num_tokens++;
	}

	string_vec = malloc(sizeof(char *) * num_tokens + 1);

	tokens2 = strtok(second_dup, delimeter);

	while (tokens2 != NULL)
	{
		string_vec[idx] = malloc(sizeof(char) * (strlen(tokens2) + 1));
		strcpy(string_vec[idx], tokens2);
		tokens2 = strtok(NULL, delimeter);
		idx++;
	}
	string_vec[idx] = NULL;
	global_variables->num_tokens_opscode = num_tokens;
	global_variables->vect_tokenized_opscode = string_vec;
	
	free(first_dup);
	free(second_dup);
}

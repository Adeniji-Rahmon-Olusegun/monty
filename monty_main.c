#include "monty.h"

globalvar_t *global_variables = NULL;

/**
 * main - executes the monty bytecode interpreter
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if sucess
 */

int main(int argc, char *argv[])
{
	size_t line_num = 0;

	check_arg_len_req(argc);

	initialise_variables();
	read_arg_from_file(argv[1]);

	while (getline(&global_variables->lineptr, &line_num,
				global_variables->buffer) != -1)
	{
		global_variables->line_num++;
		tokenize_opscode_cmd(global_variables->lineptr, "  \n\t");
		opscode_command_func();
		trigger_opcode_ops();
		free_vect_tokens();
	}
	close_file_buffer();
	free_global_var();

	return (0);
}

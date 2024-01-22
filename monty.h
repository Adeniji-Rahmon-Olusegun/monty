#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/** struct global_var_func - global variable and functions
 *
 * @lineptr: line pointer
 * @buffer: buffer for argument
 * @line_num: line number for opcode
 * @stack: 1 if stack Data structure
 * @num_tokens_opscode: number of tokens
 * @urrent_stk_len: stack length
 * @top_stack: top of the stack
 * @vect_tokenized_opscode: array containing the tokens
 * @stk_commands: opcode commands
 *
 * Description: global varibles for general usage by
 * functions
 */

typedef struct global_var_func
{
	char *lineptr;
	FILE *buffer;
	unsigned int line_num;
	int stack;
	int num_tokens_opscode;
	int current_stk_len;
	stack_t *top_stack;
	char **vect_tokenized_opscode;
	instruction_t *stk_commands; 
} globalvar_t;

extern globalvar_t *global_variables;

void check_arg_len_req(int argcount);
void mem_alloc_fail(void);
void getting_arg_fail(char *file);
void read_arg_from_file(char *file);
void initialise_variables(void);
void opscode_command_func(void);
void trigger_opcode_ops(void);
int check_if_number(char *tok);
void unknown_instruction(void);
void free_vect_tokens(void);
void close_file_buffer(void);
void free_top_stack(void);
void free_global_var(void);
void free_monty_stack(stack_t *top_stack);
void tokenize_opscode_cmd(char *buff_str, char *delimeter);
void push_cmd(stack_t **stack, unsigned int line_number);
void pall_cmd(stack_t **stack, unsigned int line_number);
void pint_cmd(stack_t **stack, unsigned int line_number);
void pop_cmd(stack_t **stack, unsigned int line_number);
void swap_cmd(stack_t **stack, unsigned int line_number);
void add_cmd(stack_t **stack, unsigned int line_number);
void sub_cmd(stack_t **stack, unsigned int line_number);
void div_cmd(stack_t **stack, unsigned int line_number);
void mul_cmd(stack_t **stack, unsigned int line_number);
void mod_cmd(stack_t **stack, unsigned int line_number);
void nop_cmd(stack_t **stack, unsigned int line_number);
#endif

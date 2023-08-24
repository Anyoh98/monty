#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct MontyContext - This is the global context for our Monty interpreter
 * @argument: string/int arg associated with opcode such as pop, push, etc
 * @file: pointer to the monty file being processed
 * @line: The current line that is being read from the monty file.
 *
 * Description: hold the gloabal data use dby the monty interpreter.
 * it stores the current argument, the monty file being processed and the
 * current line being read from the monty file.
 */

typedef struct MontyContext
{
	char *argument;/*arg associated with opcode*/
	FILE *file;/*pointer monty file*/
	char *line; /*current line being read from the monty file*/
} MontyContext;

extern MontyContext montycontext;


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

/*OTHER FUNCTIONS PROTOTYPES*/
void free_linked_list(stack_t *head);
void execute_opcode(char *opcode, stack_t **stack, unsigned int count);
void read_line(stack_t **stack);
stack_t *add_newnode(stack_t **stack, const int n);
bool isNumber(char *str);
void handle_error(stack_t **stack, char *message);

/*OPCODES PROTOTYPES*/
void pall_op(stack_t **stack, unsigned int line_number);
void push_op(stack_t **head, unsigned int line_number);
void pop_op(stack_t **head, unsigned int line_number);
void pint_op(stack_t **head, unsigned int line_number);
void swap_op(stack_t **head, unsigned int line_number);
void add_op(stack_t **head, unsigned int line_number);
void nop_op(stack_t **head, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);

#endif

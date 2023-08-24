#include "monty.h"

/**
 * read_line - Function that reads the line in monty file and execs it
 * @stack: pointer to the top of the stack structure
 * Return: void
 */

void read_line(stack_t **stack)
{
	size_t n = 0;
	int count = 0;
	ssize_t chars_read;
	char *opcode = NULL;
	char *delim = " \n\r\t\a";

	while ((chars_read = getline(&montycontext.line,
					&n, montycontext.file)) != -1)
	{
		count++;
		opcode = strtok(montycontext.line, delim);
		montycontext.argument = strtok(NULL, delim);
		if (opcode == NULL || *opcode == '#')
			continue;
		if (strcmp(opcode, "push") == 0 && montycontext.argument == NULL)
		{
			fprintf(stderr, "L%d: push requires an argument\n", count);
			free_linked_list(*stack);
			fclose(montycontext.file);
			free(montycontext.line);
			exit(EXIT_FAILURE);
		}
		execute_opcode(opcode, stack, count);
	}
}

/**
 * execute_opcode - Function that executes the opcode
 * @opcode: string conataining opcode name e.g push, pop, etc to be executed.
 * @stack: pointer to a pointer to the stack_t structure
 * @count: represents current line number of the opcode.
 * Return: void
 */

void execute_opcode(char *opcode, stack_t **stack, unsigned int count)
{
	int i;

instruction_t instructions[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pop", pop_op},
		{"pint", pint_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{NULL, NULL}
	};
	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, count);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
	free_linked_list(*stack);
	fclose(montycontext.file);
	free(montycontext.line);
	exit(EXIT_FAILURE);
}

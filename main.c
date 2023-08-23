#include "monty.h"

MontyContext montycontext;

/**
 * main - main monty program start
 * @argc: argument count
 * @argv: array of command line arguments.
 * Return: Always 0 on sucess, otherwise on failure
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	montycontext.file = fopen(argv[1], "r");
	/*Now check if teh file can be opened*/
	if (montycontext.file == NULL)
	{
		fprintf(stderr, "Error: Cant open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_line(&stack);
	fclose(montycontext.file);
	free(montycontext.line);
	free_linked_list(stack);
	exit(EXIT_SUCCESS);
}

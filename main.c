#include "monty.h"
/**
 * main - main monty program start
 * @argc: argument count
 * @argv: array of command line arguments.
 * Return: Always 0 on sucess, otherwise on failure
 */

MontyContext montycontext;

int main(int argc, char *argv[])
{
	stack_t *stack = create_stack();
	size_t arg_len;

	if (argc == 2)
	{
		montycontext.file = fopen(argv[1], "r");
		/*Now check if teh file can be opened*/
		if (montycontext.file == NULL)
		{
			fprintf(stderr, "Error: Cant open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		if (arg_len >= 2 && strcmp(argv[1] + arg_len - 2, ".m") == 0)
		{
			read_line(&stack);
			fclose(montycontext.file);
			free(montycontext.line);
			free_linked_list(stack);/*freeing memory  allocated during init*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			fprintf(stderr, "Error: Second argument must end with \".m\"\n");
			fclose(montycontext.file);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

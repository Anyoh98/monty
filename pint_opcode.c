#include "monty.h"
/**
 * pint_op - prints the top element to STDOUT and pops it off the stack
 * @head: pointer to the address of top element in the stack
 * @line_number: current line being read from the monty file
 */
void pint_op(stack_t **head, unsigned int line_number)
{
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(montycontext.line);
		free_linked_list(*head);
		fclose(montycontext.file);
		exit(EXIT_FAILURE);
	}

	/* If stack is not empty print elem. at the head of stack to stdout*/
	fprintf(stdout, "%d\n", (*head)->n);
}

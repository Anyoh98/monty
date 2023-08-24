#include "monty.h"

/**
 * add_op - adds the top two elements of the stack
 * @head: pointer to the address of the top of the stack
 * @line_number: line number of the opcode
 **/
void add_op(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(montycontext.line);
		free_linked_list(*head);
		fclose(montycontext.file);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n += (*head)->n;
	pop_op(&(*head), line_number);
}

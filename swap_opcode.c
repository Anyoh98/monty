#include "monty.h"

/**
 * swap_op - swaps the top two elements of the stack
 * @head: pointer to address of the top of the stack
 * @line_number: line number of the opcode
*/
void swap_op(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(montycontext.line);
		free_linked_list(*head);
		fclose(montycontext.file);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->next;
	(*head)->next = tmp->next;

	if (tmp->next != NULL)

	tmp->next->prev = *head;
	tmp->prev = NULL;
	tmp->next = *head;
	(*head)->prev = tmp;
	*head = tmp;
}

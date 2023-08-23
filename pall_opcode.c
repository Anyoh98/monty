#include "monty.h"

/**
 * pall_op - prints all elemnts in the stack
 * @stack: double pointer to the stack structure
 * @line_number: current line numbe rof opcdoe
 * Return: void
*/

void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (current == NULL) /*it is empty...*/
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

#include "monty.h"
/**
 * rotl_op - rotates the stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: current line number of opcode
 */

void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	/*check if stack is empty and next node is empty*/
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

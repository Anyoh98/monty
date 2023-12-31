#include "monty.h"
/**
 * rotr_op - Rotates the stack to the bottom
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file where the opcode appears
 */
void rotr_op(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;
	stack_t *last;

	current = *stack;
	last = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stack;
	current->prev = NULL;
	(*stack)->prev = current;
	*stack = current;
}

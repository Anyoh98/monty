#include "monty.h"
/**
 * div_op - function that divieds the second top element by the top element
 * @stack: pointer to the stack/top
 * @line_number: current line number of the opcode.
 */

void div_op(stack_t **stack, unsigned int line_number)
{
	int dividend, divisor, result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_linked_list(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	divisor = temp->n;
	pop_op(stack, line_number);
	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_linked_list(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	dividend = temp->n;
	result = dividend/divisor;
	temp->n = result;
}

#include "monty.h"
/**
 * pchar_op - prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */

void pchar_op(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_linked_list(*stack);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_linked_list(*stack);
		exit(EXIT_FAILURE);
	}
	/*use putchar to print the character*/
	putchar(value);
	putchar('\n');
}

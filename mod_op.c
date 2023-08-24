#include "monty.h"
/**
 * mod_op - function that computes modulus of second top and top elemnt
 * @stack: pointer to the stack/top
 * @line_number: current line numbe rof the opcode
 */

void mod_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_linked_list(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_linked_list(*stack);
		exit(EXIT_FAILURE);
	}
	/*calucalte and store reult in second elemnt*/
	(*stack)->next->n %= (*stack)->n;
	pop_op(stack, line_number);
}

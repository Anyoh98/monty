#include "monty.h"
/**
 * mul_op - fucntion multiplies 2nd top element and top elemnt in stack
 * @stack: pointer to the stack/top element
 * @line_number: line numbe rof the currnt opcode
 */

void mul_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_linked_list(*stack);
	exit(EXIT_FAILURE);
	}
	/*store result in second top element and remove the top elmt*/
	(*stack)->next->n *= (*stack)->n;
	pop_op(stack, line_number);
}

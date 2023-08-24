#include "monty.h"
/**
 * pstr_op - function that prints a string from the top upto 0 value.
 * @stack: pointer to the stack
 * @line_number: cureent line number of the opcode
 */

void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	for (; current != NULL && current->n != 0 &&
		current->n >= 0 && current->n <= 127; current = current->next)
	{
		if (current->n > 127 || current->n < 0)
		{
			fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);
			free_linked_list(*stack);
			exit(EXIT_FAILURE);
		}

		putchar(current->n);
	}
	/*dont forget the new line character*/
	putchar('\n');
	pop_op(stack, line_number);
}

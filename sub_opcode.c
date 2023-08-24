#include "monty.h"
/**
 * sub_op - subtracts top element from second top element
 * @stack: pointer to the stack and the head of the stack
 * @line_number: line number of the current opcode
 */

void sub_op(stack_t **stack, unsigned int line_number)
{
	/*Check if stack is emty or next element is empty*/
	stack_t *temp;
	int final_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_linked_list(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	final_result = (*stack)->next->n - (*stack)->n;
	/*)now store the reuslts in teh second element*/
	temp->next->n = final_result;
	pop_op(stack, line_number);
}

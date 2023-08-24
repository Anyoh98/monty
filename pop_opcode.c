#include "monty.h"
/**
 * pop_op - pops the element at the top of the stack
 * @head: pointer to the address of where top element is saved
 * @line_number: current line being read in monty script
 */
void pop_op(stack_t **head, unsigned int line_number)
{
	stack_t *tmp_top_node;

	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(montycontext.line);
		free_linked_list(*head);
		fclose(montycontext.file);
		exit(EXIT_FAILURE);
	}

	/**
	 * tmp_top_node points to the address where the second elem.
	 * of the stack is stored. Which will eventually become the new top elem.
	 */
	tmp_top_node = (*head)->next;
	/*Deallocates mem for the top stack, thereby popping the top element*/
	free(*head);

	/*sets the second element of the stack to be top*/
	(*head) = tmp_top_node;

	/*Checks if new_top_element isNOT  NULL and sets it's *prev to NULL*/
	if (*head)
		(*head)->prev = NULL;
}

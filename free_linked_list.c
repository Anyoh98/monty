#include "monty.h"
/**
 * free_linked_list - iterates through tthe lists and frees each node
 * @head: pointer to the head of the list and also pointer to stact_t struct
 * Return: void
 */

void free_linked_list(stack_t *head)
{
	stack_t *current;

	while (head != NULL) /*if the list is empty*/
	{
		current = head;
		head = head->next;
		free(current);
	}
}

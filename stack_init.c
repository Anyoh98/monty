#include "monty.h"

/**
 * create_stack - function that creates an empty stack
 * Return: Pointer to the newly create stack
 */

Stack *create_stack(void)
{
	Stack *stack; /*pointer stack that points to Stack structure*/

	stack = malloc(sizeof(Stack));/*stack hold mem addres of Stack structure*/
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stack->top = NULL;
	return (stack);
}

#include "monty.h"
/**
 * push_op - adds a new node on the stack
 * @head: pointer to the head of the stack.
 * @line_number: line number of the current opcode
 * Return: void.
 */

void push_op(stack_t **head, unsigned int line_number)
{
	int n;

	if (montycontext.argument == NULL || !isNumber(montycontext.argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_linked_list(*head);
		fclose(montycontext.file);
		free(montycontext.line);
		exit(EXIT_FAILURE);
	}
	n = atoi(montycontext.argument);
	if (add_newnode(head, n) == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_linked_list(*head);
		fclose(montycontext.file);
		free(montycontext.line);
		exit(EXIT_FAILURE);
	}

}

/**
 * isNumber - fucntion to check if argument is a digit
 * @str: argument to be checked
 * Return: True or false
 */

bool isNumber(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (false);
	}
	while (isspace(*str))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		str++;
	}
	while (*str != '\0')
	{
		if (!isdigit(*str))
		{
			return (false);
		}
		str++;
	}
	return (true);
}

/**
 * handle_error - functio that handle and prints the error message
 * @stack: pointer to pointer of the stack_t structure
 * @message: message to be printed
 * Return: void
 */

void handle_error(stack_t **stack, char *message)
{
	fprintf(stderr, "%s", message);
	free_linked_list(*stack);
	fclose(montycontext.file);
	free(montycontext.line);
	exit(EXIT_FAILURE);
}

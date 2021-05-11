#include "monty.h"

/**
  * push - push data to top of stack.
  * @stack: stack where data is pushed.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (isdigit(argument[0]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (new_node != NULL)
	{
		new_node->n = atoi(argument);
		new_node->prev = NULL;
		new_node->next = NULL;

		if (*stack == NULL)
			*stack = new_node;
		else
		{
			new_node->next = *stack;
			(*stack)->prev = new_node;
			*stack = new_node;
		}
	}
	else
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
}

/**
  * pint - prints the value at the top of the stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

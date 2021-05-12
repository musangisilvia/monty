#include "monty.h"

/**
  * push - push data to top of stack.
  * @stack: double pointer to stack.
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
  * pop - removes the element at the top of the stack
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack != NULL && (*stack)->next == NULL)
	{
		temp = *stack;
		free(temp);
		*stack = NULL;
	}
	else if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
  * swap - swaps the top two elements of the stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
  * add - adds the top two elements of the stack.
  * @stack: double pointer to stack;
  * @line_number: number of lines.
  *
  * Return: void.
  */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	(*stack)->n = sum;
}

/**
  * sub - subtracts the top element of the stack from the second top element.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = (*stack)->next->n - (*stack)->n;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	(*stack)->n = diff;
}

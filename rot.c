#include "monty.h"

/**
  * rotl - rotates the stack to the top.
  * @stack: double pointer to stack.
  * @line_number: number of lins.
  *
  * Return: void.
  */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL) /* to get to the last element of the list */
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

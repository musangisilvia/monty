#include "monty.h"
/**
  * pall - prints all arguments inserted.
  * @stack: double pointer to stack;
  * @line_number: number of lines.
  *
  * Return: void
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

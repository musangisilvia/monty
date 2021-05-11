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


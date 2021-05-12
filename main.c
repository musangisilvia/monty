#include "monty.h"

/**
  * main - entry point.
  * @argc: argument count.
  * @argv: argument vector.
  *
  * Return: 0.
  */
int main(int argc, char **argv)
{
	FILE *fptr;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int line_count = 1;
	char **tokens = NULL, *line = NULL;
	void (*op_func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fptr) != -1)
	{
		if (!strcmp(line, "\n"))
		{
			line_count++;
			continue;
		}
		tokens = break_line(line), op_func = get_opcode(tokens[0]);
		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, tokens[0]);
			exit(EXIT_FAILURE);
		}
		if (strcmp(tokens[0], "push") == 0 && tokens[1])
			argument = tokens[1];
		else if (!strcmp(tokens[0], "push") && !tokens[1])
			err(&stack, line_count);
		op_func(&stack, line_count), line_count++, free(tokens);
	}
	fclose(fptr);
	free(line), free_dlist(stack);
	return (0);
}

/**
  * err - print integer fault.
  * @stack: double pointer to stack;
  * @line_number: number of lines.
  *
  * Return: void.
  */
void err(stack_t **stack, unsigned int line_number)
{
	free_dlist(*stack);
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

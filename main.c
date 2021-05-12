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
		err(1);
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
		err(2, argv[1]);
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
			free(line), free(tokens), fclose(fptr), free_dlist(stack);
			err(3, line_count, tokens[0]);
		}
		if (strcmp(tokens[0], "push") == 0 && tokens[1])
			argument = tokens[1];
		else if (!strcmp(tokens[0], "push") && tokens[1] == NULL)
		{
			free(line), free(tokens), fclose(fptr), free_dlist(stack);
			err(5, line_count);
		}
		op_func(&stack, line_count), line_count++, free(tokens);
	}
	fclose(fptr), free(line), free_dlist(stack);
	return (0);
}

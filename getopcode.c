#include "monty.h"
/**
  * break_lines - make lines into tokens using spaces.
  * @line: line gotten
  *
  * Return: pointer to tokens.
  */
int break_lines(char line[])
{
	char *opc;
	int num;
	char *token = strtok(line, "\n\t ");
	
	opc = token;
	while (token)
	{
		token = strtok(NULL, "\n\t ");
		num = atoi(token);
	}
	i = check_opcode(opc, num);
	if (i == -1)
		return (-1);
	return (0);
}

/**
  * check_opcode - checks if opcode is valid
  * @opc: opcode.
  *
  * Return: -1 if not , else 0.
  */
int (*check_opcode(char *opc))(stack_t **stack, unsigned int line_number)
{
	
}

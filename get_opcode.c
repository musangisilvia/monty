#include "monty.h"
/**
  * get_opcode - checks whether the opcode exists.
  * @token: opcode passed.
  *
  * Return: pointer to function for opcode or NULL.
  */
void (*get_opcode(char *token))(stack_t **head, unsigned int line_number)
{
	instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};
	int i = 0;

	while (opc[i].opcode)
	{
		if (strcmp(opc[i].opcode, token) == 0)
			return (opc[i].f);
		i++;
	}
	free(token);
	return (NULL);
}

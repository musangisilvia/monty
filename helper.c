#include "monty.h"
/**
  * break_line - brak up the line read.
  * @line: line read.
  *
  * Return: array of strings .
  */
char **break_line(char *line)
{
	char *token = NULL;
	char **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * (sizeof(line) + 1));
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n ");
		i++;
	}
	return (tokens);
}

/**
  * free_dlist - frees a dlistint_t list.
  * @head: pointer to list;
  *
  * Return: void.
  */
void free_dlist(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

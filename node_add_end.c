#include "monty.h"
/**
 *node_end_add - adds a nod at the end
 *@head: head of the list
 *@n: data
 *Return: a pointer
 */

void node_end_add(stack_t **head, int n)
{
	stack_t *temp, *end;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->next = NULL;
	temp->n = n;
	if (!*head)
	{
		temp->prev = NULL;
		*head = temp;
		return;
	}
	end = *head;
	while (end->next)
		end = end->next;
	end->next = temp;
	temp->prev = end;
}

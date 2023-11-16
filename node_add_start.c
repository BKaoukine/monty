#include "monty.h"

/**
 *node_start_add - adds a node at the beginning
 *@head: head of the list
 *@n: data of the node
 *Return: a pointer to the new head
 */

void node_start_add(stack_t **head, int n)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	temp->prev = NULL;
	temp->next = *head;
	if (*head)
		(*head)->prev = temp;
	*head = temp;
}

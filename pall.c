#include "monty.h"

/**
 *pall - prints all the elements of a doubly linked list.
 *@head: head of the list
 */

void pall(stack_t **head, __attribute__ ((unused)) unsigned int lNum)
{
	stack_t *current = *head;

	if (!current)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

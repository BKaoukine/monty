#include "monty.h"

/**
 *pint - prints the value at the top of the stack.
 *@head: head of the list
 *@lNum: line number
 */

void pint(stack_t **head, unsigned int lNum)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lNum);
		fclose(glob_var.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

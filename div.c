#include "monty.h"
/**
 * op_div - Dividing two elements of stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void op_div(stack_t **head, unsigned int counter)
{
stack_t *aux;
int quotient, divisor;

aux = *head;

if (aux == NULL || aux->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(finfo.file);
free(finfo.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

if (aux->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(finfo.file);
free(finfo.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

divisor = aux->n;
aux = aux->next;

quotient = aux->n / divisor;
aux->n = quotient;
*head = aux;

free(*head);
}

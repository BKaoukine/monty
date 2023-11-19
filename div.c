#include "monty.h"
/**
 *div- Dividing two elements of stack
*@head: stack head
*@counter: line_number
*Return: no return
*/
void div(stack_t **head, unsigned int counter)
{
stack_t *aux;
int sus, nodes;

aux = *head;
for (nodes = 0; aux != NULL; nodes++)
aux = aux->next;
if (nodes < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(finfo.file);
free(finfo.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = *head;
if (aux->next->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(finfo.file);
free(finfo.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
sus = aux->n / aux->next->n;
aux->next->n = sus;
*head = aux->next;
free(aux);
}

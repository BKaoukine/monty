#include "monty.h"
/**
 * push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push(stack_t **head, unsigned int counter)
{
int n, j = 0, flag = 0;

if (finfo.arg)
{
if (finfo.arg[0] == '-')
j++;
for (; finfo.arg[j] != '\0'; j++)
{
if (finfo.arg[j] > 57 || finfo.arg[j] < 48)
flag = 1; }
if (flag == 1)
{ fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(finfo.file);
free(finfo.content);
free_stack(*head);
exit(EXIT_FAILURE); }}
else
{ fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(finfo.file);
free(finfo.content);
free_stack(*head);
exit(EXIT_FAILURE); }
n = atoi(finfo.arg);
if (finfo.lifi == 0)
addnode(head, n);
else
addqueue(head, n);
}

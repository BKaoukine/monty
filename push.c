#include "monty.h"

/**
 * is_digit - checks if it's a digit
 * @c: the one to be checked
 * Return: the digit
 */
int is_digit(char c)
{
return (c >= '0' && c <= '9');
}

/**
 * is_valid_number - checks if valid
 * @str: the one to be checked
 * Return: 0 or 1
 */
int is_valid_number(const char *str)
{
if (*str == '-' || *str == '+')
{
str++;
}

while (*str)
{
if (!is_digit(*str))
return (0);

str++;
}

return (1);
}

/**
 * is_valid_integer - checks if it's a valid integer
 * @str: the one to be checked
 * Return: 0 or 1
 */
int is_valid_integer(const char *str)
{
int value;
return (sscanf(str, "%d", &value) == 1);
}

/**
 * push - prints all the elements of a doubly linked list.
 * @head: head of the list
 * @lNum: line number
 */
void push(stack_t **head, unsigned int lNum)
{
int int_val;

if (!is_valid_integer(glob_var.argv))
{
fprintf(stderr, "L%d: usage: push integer\n", lNum);
fclose(glob_var.file);
_free_stack(*head);
exit(EXIT_FAILURE);
}

sscanf(glob_var.argv, "%d", &int_val);

if (glob_var.fifo == 0)
node_start_add(head, int_val);
else
node_end_add(head, int_val);
}

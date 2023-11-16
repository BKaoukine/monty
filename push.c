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
if (!is_valid_integer(glob_var.argv))
{
fprintf(stderr, "L%d: usage: push integer\n", lNum);
fclose(glob_var.file);
free_stack(*head);
exit(EXIT_FAILURE);
}

int int_val;
sscanf(glob_var.argv, "%d", &int_val);

if (glob_var.fifo == 0)
add_node(head, int_val);
else
add_node_end(head, int_val);
}

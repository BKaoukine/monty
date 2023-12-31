#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct file_info
{
char *arg;
FILE *file;
char *content;
int lifi;
}  file_info;
extern file_info finfo;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void push(stack_t **head, unsigned int number);
void pall(stack_t **head, unsigned int number);
void pint(stack_t **head, unsigned int number);
int op_execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void pop(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void op_div(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif
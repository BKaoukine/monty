#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>


#define MONTY_LENGHT 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct exte_var
{
	char *argv;
	FILE *file;
	unsigned int lNum;
	int fifo;
} exte_var;

extern exte_var glob_var;



/*Custom functions*/
char* readMontyInstruction(FILE *file);
void _free_stack(stack_t *head);
void pall(stack_t **head, unsigned int lNum);
void push(stack_t **head, unsigned int lNum);
void node_start_add(stack_t **head, int n);
void node_end_add(stack_t **head, int n);
void pint(stack_t **head, unsigned int lNum);

#endif
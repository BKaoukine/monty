#include "monty.h"
exte_var glob_var = {NULL, NULL, 0, 0};

/**
 * instruction - calls the right function
 * @opcode: the command
 * @stack: head of the list
 * @lNum: line number
 * Return: 0 for success
 */
int instruction(char *opcode, stack_t **stack, unsigned int lNum)
{
    unsigned int i = 0;
    instruction_t opstruct[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {NULL, NULL}
    };

    while (opstruct[i].opcode)
    {
        if (strcmp(opcode, opstruct[i].opcode) == 0)
        {
            opstruct[i].f(stack, lNum);
            return (0);
        }
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", lNum, opcode);
    return (1);
}

/**
 * main - main entry
 * @argc: arg count
 * @argv: arg vector
 * Return: EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *opcode;
    stack_t *stack = NULL;
    int n;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((opcode = readMontyInstruction(file)) != NULL)
    {
        n = instruction(opcode, &stack, glob_var.lNum);
        if (n == 1)
        {
            _free_stack(stack);
            fclose(file);
            exit(EXIT_FAILURE);
        }
        free(opcode);
    }

    fclose(file);

    return (0);
}

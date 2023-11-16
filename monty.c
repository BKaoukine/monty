#include "monty.h"
/**
 *instruction - calls the right function
*@opcode: the command
*@stack: head of the list
*@lNum: line number
*Return: 0 for success
*/
int instruction(char *opcode, stack_t **stack, unsigned int lNum)
{
unsigned int i = 0;
instruction_t opstruct[] = {
{"push", push}, {"pall", pall},
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
*main - main entry
*@argc: arg count
*@argv: arg vector
*Return: EXIT_SUCCESS
*/
int main(int argc, char *argv[])
{
FILE *file;
/*     char line[MONTY_LENGHT];*/
char *instruction;



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

while ((instruction = readMontyInstruction(file)) != NULL)
{
/* // Process each instruction (you can pass it to another function) */
printf("Instruction: %s\n", instruction);
free(instruction); /* // Free the memory allocated by getline */
}

fclose(file);

return (0); /* // Return success */


}

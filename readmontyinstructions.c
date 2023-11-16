#include "monty.h"
/**
 * readMontyInstruction - Reads a line from a Monty bytecode file.
 * @file: File pointer to the Monty bytecode file.
 *
 * Return: The read instruction as a string, or NULL if the end of file is
 * reached or an error occurs.
 */
char *readMontyInstruction(FILE *file)
{
char *instruction = NULL;
size_t len = 0;
ssize_t read;

read = getline(&instruction, &len, file);

if (read == -1 || feof(file))
{
free(instruction);
return (NULL);

if (instruction[read - 1] == '\n')
{
instruction[read - 1] = '\0';
}

return (instruction);
}

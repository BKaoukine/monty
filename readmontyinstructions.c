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
int i, j;

read = getline(&instruction, &len, file);
if (read == -1 || feof(file))
{
free(instruction);
return (NULL);
}
/* Remove trailing newline */
if (instruction[read - 1] == '\n')
{
instruction[read - 1] = '\0';
read--;
}

/* Remove leading whitespace */
i = 0;
while (isspace(instruction[i]))
{
i++;
}
/* Shift the remaining characters to the beginning */
for (j = 0; i < read; i++, j++)
{
instruction[j] = instruction[i];
}
instruction[j] = '\0';
/* Remove trailing whitespace */
i = j - 1;
while (i >= 0 && isspace(instruction[i]))
{
instruction[i] = '\0';
i--;
}

return (instruction);
}

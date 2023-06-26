#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 1024

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
FILE *file;
char line[MAX_LINE_LENGTH];
int line_number = 1;
stack_t *stack = NULL;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (fgets(line, sizeof(line), file) != NULL)
{
if (line[strlen(line) - 1] == '\n')
line[strlen(line) - 1] = '\0';
if (parse_line(line, line_number, &stack) == -1)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
free_stack(&stack);
fclose(file);
exit(EXIT_FAILURE);
}
line_number++;
}
free_stack(&stack);
fclose(file);
exit(EXIT_SUCCESS);
}

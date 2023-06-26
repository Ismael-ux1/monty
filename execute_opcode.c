#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * execute_opcode - Executes the appropriate opcode based on the given arguments
 * @opcode: The opcode to execute
 * @argument: The argument associated with the opcode
 * @line_number: The current line number in the file
 * @stack: Double pointer to the stack
 * Return: 0 on success, -1 on failure
 */
int execute_opcode(char *opcode, char *argument, unsigned int line_number, stack_t **stack)
{
if (strcmp(opcode, "push") == 0)
{
if (argument == NULL || !isdigit((unsigned char)argument[0]))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
return (-1);
}
push(stack, line_number, atoi(argument));
}
else if (strcmp(opcode, "pall") == 0)
pall(stack, line_number);
else if (strcmp(opcode, "pint") == 0)
pint(stack, line_number);
else if (strcmp(opcode, "pop") == 0)
pop(stack, line_number);
else if (strcmp(opcode, "swap") == 0)
swap(stack, line_number);
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
return (-1);
}
return (0);
}

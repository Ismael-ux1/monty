#include "monty.h"

/**
 * parse_line - Parses and executes a single line of Monty bytecode
 * @line: The line to parse and execute
 * @line_number: The current line number
 * @stack: Pointer to the stack
 * Return: 0 on success, -1 on failure
 */
int parse_line(char *line, int line_number, stack_t **stack)
{
char *opcode, *argument;
int status;
if (line == NULL || line[0] == '\0')
return (0);
opcode = strtok(line, " \t");
if (opcode == NULL)
return (0);
argument = strtok(NULL, " \t");
if (argument != NULL)
argument = strtok(argument, "\n");
status = execute_opcode(opcode, argument, line_number, stack);
if (status == -1)
return (-1);
return (0);
}

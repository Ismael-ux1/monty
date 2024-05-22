#include <monty.h>

/**
 * pstr - Prints the string starting at the top of the stack, followed by a new line.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the opcode appears
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;

		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

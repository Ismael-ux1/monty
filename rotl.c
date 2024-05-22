#include <stdio.h>
#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the opcode appears
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = first;
		while (last->next)
			last = last->next;

		last->next = first;
		first->prev = last;
		*stack = first->next;
		first->next = NULL;
		(*stack)->prev = NULL;
	}
}

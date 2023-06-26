#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Frees a stack_t stack
 * @stack: Pointer to the stack to be freed
 */
void free_stack(stack_t **stack)
{
stack_t *current = *stack;
stack_t *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
*stack = NULL;
}


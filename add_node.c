#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_node - Adds a new node at the beginning of a stack_t list
 * @stack: Pointer to the stack
 * @n: Value to be stored in the new node
 * Return: Pointer to the newly added node
 */
stack_t *add_node(stack_t **stack, int n)
{
stack_t *new_node;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = n;
new_node->prev = NULL;

if (*stack != NULL)
(*stack)->prev = new_node;

new_node->next = *stack;
*stack = new_node;

return (new_node);
}

#include <monty.h>

/**
 * swap - swaps the top two elements of the stack
 * @stack - double pointer to the top of the stack
 * @line_number - value of the node
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: cant't swap, stack too short\n" line_number);
	}

	tmp = (*stack)->next;
	(*stack)->prev = tmp;
    (*stack)->next = tmp->next;
    tmp->prev = NULL;

    if (tmp->next)
        tmp->next->prev = *stack;
    tmp->next = *stack;
    *stack = tmp;
}

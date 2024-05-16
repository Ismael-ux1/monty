#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number of the opcode in the file.
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    int result;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Add the top two elements of the stack */
    result = (*stack)->n + (*stack)->next->n;

    /* Remove the top element of the stack */
    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->n = result;
    free(temp);
}

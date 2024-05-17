#include <monty.h>

/**
 * sub - subtracts the top  element of the stack from the second top element
 * @stack: double pointer to the top of the stack
 * @line_number: value of the node
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack) = (*stack)->next;
    (*stack)->n -= temp->n;
    (*stack)->prev = NULL;
    free(temp);
}

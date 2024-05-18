#include <monty.h>

/**
 * div - divides the second top element of the stack by the top element
 * @stack: double pointer to the top of the stack
 * @line_number: value of the new node
 * Return: nothing
 */
void div(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* divide the second top element by the top element of the stack */
    (*stack)->next->n /= (*stack)->n;

    /* remove the top element of the stack */
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

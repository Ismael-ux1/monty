#include <monty.c>

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the top of the stack
 * @line_number: value of the node
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* multiply the top two elements of the stack */
    (*stack)->next->n *= (*stack)->n;

    /* remove the top element of the stack */
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

#include <monty.h>

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* compute the rest of the division */
    (*stack)->next->n %= (*stack)->n;

    /* remove the top element of the stack */
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

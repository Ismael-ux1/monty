#include <monty.h>

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the opcode appear
 */

void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *last, *temp;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    last = *stack;
    while (last->next)
        last = last->next;

    temp = last->prev;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = temp;
}

/* Example usage */
int main(void)
{
    stack_t *stack = NULL;

    /* Push some elements onto the stack */
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    /* Print the stack before rotation */
    print_stack(stack);

    /* Rotate the stack */
    rotr(&stack, 0);

    /* Print the stack after rotation */
    print_stack(stack);

    /* Clean up */
    free_stack(stack);
    return (0);
}

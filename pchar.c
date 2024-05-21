#include <monty.h>

/**
 * pchar - Prints the character at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the opcode appears
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    putchar((*stack)->n);
    putchar('\n');
}

/* Example usage */
int main(void)
{
    stack_t *stack = NULL; // Assume you have a stack implementation

    // Push an ASCII value onto the stack (e.g., 'A' = 65)
    // ...

    // Call pchar
    pchar(&stack, 1); // Assuming line number is 1

    // Clean up the stack
    // ...

    return (EXIT_SUCCESS);
}

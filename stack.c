#include "monty.h"
#include <stdio.h>

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @argument: Argument to push (integer)
 */
void push(stack_t **stack, unsigned int line_number, int push_value)
{
char push_value_str[MAX_ARGUMENT_SIZE];
int result = snprintf(push_value_str, MAX_ARGUMENT_SIZE, "%d", push_value);

if (result >= MAX_ARGUMENT_SIZE || result < 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
add_node(stack, push_value);
}

/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
stack_t *current = *stack;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = (*stack)->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(temp);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
int temp;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}

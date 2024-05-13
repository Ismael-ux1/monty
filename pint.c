#include <stdio.h>
#include <stdlib.h>
#include <monty.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * pint - prints the value at the top of the stack
 * @stack: doubly pointer to the head of the stack
 * @line_number: line number
 *
 * Return: void
 */

void pint(stack_s **stack, unsigned int line_number)
{
	/* check if stack is empty */
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* print the int at the top of the stack */
	printf("%d\n", (*stack)->n);
}

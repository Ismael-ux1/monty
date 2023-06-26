#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>

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

int _strcmp(char *opcode, char *list);
int parse_line(char *line, int line_number, stack_t **stack);
void free_stack(stack_t **stack);
int execute_opcode(char *opcode, char *argument, unsigned int line_number, stack_t **stack);
void push(stack_t **stack, unsigned int line_number, int push_value);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **stack, int n);
void execute(char *string[], stack_t *stack, int num_lines);
int nlfind(char *list);
void free_list(char *a[]);
int combfind(char *list, int ln);
#endif /* MONTY_H */

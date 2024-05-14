#include <stdio.h>
#include <stdlib.h>
#include <monty.h>

typedef struct stack_t {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void pop(Stack* stack, int line_number) {
    if (isStackEmpty(stack)) {
        printf("L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack->top--;
}

int main() {
    Stack* stack = createStack(100);
    int line_number = 1;

    /* Add some elements to the stack */
    /* stack->array[++stack->top] = 10; */

    /* Try to pop an element */
    pop(stack, line_number);

    return 0;
}

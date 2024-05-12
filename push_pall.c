#include <stdio.h>
#include <stdlib.h>
#include <monty.h>

/**
 * struct Node - defines a node in a stack
 * @data: The integer data of the node
 * @next: The next node in the stack
 */
typedef struct Node{
	int data;
	struct Node* next;
} Node;

/* The top of the stack */
Node* top = NULL;

/**
 * push - Pushes an element to the top of the stack
 * @data: The integer data to push onto the stack
 *
 * Return : void
 */
void push(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (!node) {
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE)
	}
	node->data = data;
	node->next = top;
	top = node;
}

/**
 * pall - Prints all the values on the stack, starting from the top of the stack
 *
 * Return: void
 */
void pall() {
    Node* temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

/**
 * main - Entry point
 *
 * Return: 0 on success
 */
int main() {
    push(1);
    push(2);
    push(3);
    pall();
    return 0;
}

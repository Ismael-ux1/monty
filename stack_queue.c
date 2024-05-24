#include <monty.h>
#include <stdio.h>

#define MAX_SIZE 100

// Stack structure
struct stack {
    int arr[MAX_SIZE];
    int top;
};

void initializeStack(struct stack* s) {
    s->top = -1;
}

int isStackFull(struct stack* s) {
    return s->top >= MAX_SIZE - 1;
}

int isStackEmpty(struct stack* s) {
    return s->top == -1;
}

void push(struct stack* s, int value) {
    if (!isStackFull(s)) {
        s->arr[++s->top] = value;
    }
}

int pop(struct stack* s) {
    if (!isStackEmpty(s)) {
        return s->arr[s->top--];
    }
    return -1; // Stack underflow
}

// Queue structure
struct queue {
    int arr[MAX_SIZE];
    int front, rear;
};

void initializeQueue(struct queue* q) {
    q->front = q->rear = -1;
}

int isQueueEmpty(struct queue* q) {
    return q->front == -1;
}

int isQueueFull(struct queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(struct queue* q, int value) {
    if (!isQueueFull(q)) {
        if (isQueueEmpty(q)) {
            q->front = q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % MAX_SIZE;
        }
        q->arr[q->rear] = value;
    }
}

int dequeue(struct queue* q) {
    if (!isQueueEmpty(q)) {
        int value = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX_SIZE;
        }
        return value;
    }
    return -1; // Queue is empty
}

// Switch between stack and queue modes
void switchMode(struct stack* s, struct queue* q) {
    int temp[MAX_SIZE];
    int i, count = 0;

    while (!isStackEmpty(s)) {
        temp[count++] = pop(s);
    }

    while (count > 0) {
        enqueue(q, temp[--count]);
    }
}

int main() {
    struct stack s;
    struct queue q;

    initializeStack(&s);
    initializeQueue(&q);

    // Example usage
    push(&s, 10);
    push(&s, 20);
    enqueue(&q, 30);

    printf("Popped from stack: %d\n", pop(&s));
    printf("Dequeued from queue: %d\n", dequeue(&q));

    // Switch to queue mode
    switchMode(&s, &q);

    // Now the top of the stack is the front of the queue
    printf("Top of stack (front of queue): %d\n", peek(&s));

    return 0;
}

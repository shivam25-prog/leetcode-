#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define stack structure
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Helper: create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Helper: push to stack
void pushStack(Stack* stack, int x) {
    stack->data[++stack->top] = x;
}

// Helper: pop from stack
int popStack(Stack* stack) {
    return stack->data[stack->top--];
}

// Helper: peek stack
int peekStack(Stack* stack) {
    return stack->data[stack->top];
}

// Helper: check if stack empty
bool isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

// Queue structure using two stacks
typedef struct {
    Stack* inStack;
    Stack* outStack;
} MyQueue;

// Create queue
MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->inStack = createStack(1000);
    q->outStack = createStack(1000);
    return q;
}

// Push element to back of queue
void myQueuePush(MyQueue* obj, int x) {
    pushStack(obj->inStack, x);
}

// Move elements if outStack is empty
void move(MyQueue* obj) {
    if (isEmptyStack(obj->outStack)) {
        while (!isEmptyStack(obj->inStack)) {
            pushStack(obj->outStack, popStack(obj->inStack));
        }
    }
}

// Removes element from front of queue
int myQueuePop(MyQueue* obj) {
    move(obj);
    return popStack(obj->outStack);
}

// Get front element
int myQueuePeek(MyQueue* obj) {
    move(obj);
    return peekStack(obj->outStack);
}

// Returns true if queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return isEmptyStack(obj->inStack) && isEmptyStack(obj->outStack);
}

// Free memory
void myQueueFree(MyQueue* obj) {
    free(obj->inStack->data);
    free(obj->inStack);
    free(obj->outStack->data);
    free(obj->outStack);
    free(obj);
}
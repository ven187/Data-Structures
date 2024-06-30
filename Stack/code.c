#include <stdio.h>
#include <stdbool.h>

#define STACK_MAX 10 // Maximum size of the stack

// Stack structure
typedef struct {
    int data[STACK_MAX]; // Array to store stack items
    int top; // Index of the top item
} Stack;

// Function prototypes
void initStack(Stack* stack);
bool push(Stack* stack, int item);
int pop(Stack* stack);
bool isEmpty(Stack* stack);
int topRet(Stack* stack);
void writeAll(Stack* stack);
void deleteAll(Stack* stack);
void writeAllNotDelete(Stack* stack);

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = 0; // Initialize the stack as empty
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top <= 0; // Return true if the stack is empty
}

// Push an item onto the stack
bool push(Stack* stack, int item) {
    if (stack->top >= STACK_MAX)
        return false; // Return false if the stack is full
    stack->data[stack->top] = item; // Add the item to the stack
    stack->top++; // Increment the top index
    return true;
}

// Pop an item from the stack
int pop(Stack* stack) {
    if (stack->top <= 0)
        return -1; // Return -1 if the stack is empty
    stack->top--; // Decrement the top index
    return stack->data[stack->top]; // Return the top item
}

// Return the top item without popping it
int topRet(Stack* stack) {
    if (stack->top <= 0)
        return -1; // Return -1 if the stack is empty
    return stack->data[stack->top - 1]; // Return the top item without popping it
}

// Delete all items in the stack
void deleteAll(Stack* stack) {
    stack->top = 0; // Reset the stack to empty
}

// Write all items and pop them
void writeAll(Stack* stack) {
    while (topRet(stack) != -1)
        printf("%d - ", pop(stack)); // Pop and print all items
    printf("\n");
}

// Write all items without popping them
void writeAllNotDelete(Stack* stack) {
    printf("Stack elements: ");
    for (int i = stack->top - 1; i >= 0; --i) {
        printf("%d", stack->data[i]);
        if (i > 0) {
            printf(" - ");
        }
    }
    printf("\n");
}

int main() {
    Stack myStack;
    initStack(&myStack);

    // Push items onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // Print all items without deleting them
    writeAllNotDelete(&myStack);

    // Print the top item
    printf("Top element of the stack: %d\n", topRet(&myStack));

    // Pop an item and print it
    int popped = pop(&myStack);
    printf("Popped element: %d\n", popped);

    // Check if the stack is empty and print the result
    if (isEmpty(&myStack)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }

    return 0;
}

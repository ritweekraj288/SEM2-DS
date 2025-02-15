#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100  // Maximum size of the stack

// Define the stack structure
struct stack {
    int stArr[MAXSIZE];
    int top;
};

typedef struct stack STACK;

// Function to create (initialize) the stack
void create(STACK *s) {
    s->top = -1;  // Stack is initially empty
    printf("Stack created with capacity %d\n", MAXSIZE);
}

// Function to push an element onto the stack
void push(STACK *s, int value) {
    if (s->top == MAXSIZE - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->stArr[++(s->top)] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack Underflow! Cannot pop element\n");
        return -1;  // Indicating underflow condition
    } else {
        int poppedValue = s->stArr[(s->top)--];
        printf("Popped %d from the stack\n", poppedValue);
        return poppedValue;
    }
}

// Function to peek the top element of the stack
int peek(STACK *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return -1;  // Indicating empty stack
    } else {
        printf("Top element is %d\n", s->stArr[s->top]);
        return s->stArr[s->top];
    }
}

// Function to check if the stack is full
int isFull(STACK *s) {
    if (s->top == MAXSIZE - 1) {
        return 1;  // Stack is full
    } else {
        return 0;  // Stack is not full
    }
}

// Function to check if the stack is empty
int isEmpty(STACK *s) {
    if (s->top == -1) {
        return 1;  // Stack is empty
    } else {
        return 0;  // Stack is not empty
    }
}

// Main function to demonstrate stack operations
int main() {
    STACK stack;
    int choice, value;

    create(&stack);  // Create an empty stack

    do {
        // Menu for stack operations
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if stack is full\n");
        printf("5. Check if stack is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                if (isFull(&stack)) {
                    printf("The stack is full\n");
                } else {
                    printf("The stack is not full\n");
                }
                break;
            case 5:
                if (isEmpty(&stack)) {
                    printf("The stack is empty\n");
                } else {
                    printf("The stack is not empty\n");
                }
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}    
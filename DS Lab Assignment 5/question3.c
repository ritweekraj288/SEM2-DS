#include <stdio.h>
#include <stdlib.h>

// Define the stack node structure
struct Node {
    int data;
    struct Node* next;
};

// Stack structure with a pointer to the top of the stack
typedef struct {
    struct Node* top;
} Stack;

// Function to create (initialize) the stack
void create(Stack* stack) {
    stack->top = NULL;  // Stack is initially empty
    printf("Stack created.\n");
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    // Assign value and adjust the next pointer
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;  // New node is now at the top
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow! Cannot pop element\n");
        return -1;  // Indicating underflow
    } else {
        struct Node* temp = stack->top;
        int poppedValue = temp->data;
        stack->top = stack->top->next;  // Move top to the next node
        free(temp);  // Free the memory of the popped node
        printf("Popped %d from the stack\n", poppedValue);
        return poppedValue;
    }
}

// Function to peek the top element of the stack
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;  // Indicating empty stack
    } else {
        printf("Top element is %d\n", stack->top->data);
        return stack->top->data;
    }
}

// Function to check if the stack is full
int isFull() {
    // Since we are using dynamic memory allocation, stack will not be full until system memory is exhausted
    return 0;  // Stack cannot be full unless there is a system memory failure
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    if (stack->top == NULL) {
        return 1;  // Stack is empty
    } else {
        return 0;  // Stack is not empty
    }
}

// Main function to demonstrate stack operations
int main() {
    Stack stack;
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
                if (isFull()) {
                    printf("The stack is full (though this is unlikely with dynamic memory allocation)\n");
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

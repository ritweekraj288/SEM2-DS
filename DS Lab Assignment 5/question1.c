#include <stdio.h>
#include <stdlib.h>

// Structure to define a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert an element at a specific position
void insertAtPosition(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = data;

    // Case 1: Empty list, insert the first element
    if (head == NULL) {
        newNode->next = newNode; // Point to itself
        head = newNode;
        printf("Inserted %d at position %d\n", data, position);
        return;
    }

    // Case 2: Insert at the beginning
    if (position == 1) {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        printf("Inserted %d at the beginning\n", data);
        return;
    }

    // Case 3: Insert at the specified position
    int count = 1;
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count == position - 1) {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d at position %d\n", data, position);
    } else {
        printf("Invalid position!\n");
    }
}

// Function to insert an element at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }

    printf("Inserted %d at the beginning\n", data);
}

// Function to insert an element at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    printf("Inserted %d at the end\n", data);
}

// Function to delete an element from a specific position
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 1;

    if (position == 1) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
        printf("Deleted element at position %d\n", position);
        return;
    }

    while (count < position && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count == position) {
        prev->next = temp->next;
        free(temp);
        printf("Deleted element at position %d\n", position);
    } else {
        printf("Invalid position!\n");
    }
}

// Function to delete the first element
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    struct Node* last = head;

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
        free(temp);
    }

    printf("Deleted the first element\n");
}

// Function to delete the last element
void deleteLast() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }

    printf("Deleted the last element\n");
}

// Function to display the circular linked list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d \t ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, position;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at specific position\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Delete at specific position\n");
        printf("5. Delete the first element\n");
        printf("6. Delete the last element\n");
        printf("7. Display list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteLast();
                break;
            case 7:
                display();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
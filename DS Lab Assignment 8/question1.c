#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int prior;
    struct node* next;
};


int isEmpty(struct node* front) {
    return (front == NULL);
}


void enqueue(struct node** front, struct node** rear, int num, int prior) {
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed");
        return;
    }

    newNode->data = num;
    newNode->prior = prior;
    newNode->next = NULL;

    
    if (*front == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        struct node* temp = *front;
        struct node* prev = NULL;

        
        while (temp != NULL && temp->prior >= newNode->prior) {
            prev = temp;
            temp = temp->next;
        }

        
        if (prev == NULL) {
            newNode->next = *front;
            *front = newNode;
        } else if (temp == NULL) {
            
            prev->next = newNode;
            *rear = newNode;
        } else {
            
            prev->next = newNode;
            newNode->next = temp;
        }
    }
}


void dequeue(struct node** front, struct node** rear) {
    if (isEmpty(*front)) {
        printf("\nQueue is empty\n");
        return;
    }

    struct node* temp = *front;
    printf("%d is dequeued\n", temp->data);

    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;  
    }

    free(temp);
}


void peek(struct node* front) {
    if (isEmpty(front)) {
        printf("\nNo peek value, queue is empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}


void display(struct node* front) {
    if (isEmpty(front)) {
        printf("\nQueue is empty\n");
        return;
    }

    struct node* temp = front;
    while (temp != NULL) {
        printf("(%d, %d)\t", temp->data, temp->prior);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;
    int choice, num, prior;

    while (1) {
        printf("\n1 to enqueue");
        printf("\n2 to dequeue");
        printf("\n3 to peek");
        printf("\n4 to display");
        printf("\n0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("\nThank you...\n");
                exit(0);
            case 1:
                printf("\nEnter the value to be enqueued: ");
                scanf("%d", &num);
                printf("Enter priority: ");
                scanf("%d", &prior);
                enqueue(&front, &rear, num, prior);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                peek(front);
                break;
            case 4:
                display(front);
                break;
            default:
                printf("\nInvalid entry\n");
        }
    }

    return 0;
}

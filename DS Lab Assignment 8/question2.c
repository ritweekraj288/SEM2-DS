#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

int isFull(struct node*new){
    if(new==NULL){
        return 1;
    }
    return 0;
}

int isEmpty(struct node**front,struct node**rear){
    if(*front==NULL){
        return 1;
    }
    return 0;
}

void enqueue(struct node**front,struct node**rear,int num){
    struct node*new=malloc(sizeof(struct node));
    if(isFull(new)){
        printf("\nqueue is full");
        return;
    }
    new->data=num;
    new->next=NULL;
    if(*front==NULL){
        *front=new;
        *rear=new;
        return;
    }
    (*rear)->next=new;
    *rear=new;
}

void dequeue(struct node**front,struct node**rear){
    if(isEmpty(front,rear)){
        printf("\nalready empty");
        return;
    }
    struct node*temp=*front;
    if(*rear==*front){
        printf("%d is dequeued",temp->data);
        free(temp);
        *rear=NULL;
        *front=NULL;
        return;
    }
    *front=(*front)->next;
    printf("%d is dequeued",temp->data);
    free(temp);    
}

void peek(struct node**front,struct node**rear){
    if(isEmpty(front,rear)){
        printf("\nno peek value as empty");
        return;
    }
    printf("%d",(*front)->data);
}

void display(struct node**front,struct node**rear){
    if(isEmpty(front,rear)){
        printf("\nempty queue");
        return;
    }
    struct node*temp=*front;
    printf("%d\t",temp->data);
    temp=temp->next;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct node*rear=NULL;
    struct node*front=NULL;
    int choice,num,prior;
    while(1){
        printf("\n1 to enqueue");
        printf("\n2 to dequeue");
        printf("\n3 to peek");
        printf("\n4 to display");
        printf("\n0 to exit");
        printf("\nenter your choice:\t");
        scanf("%d",&choice);
        switch(choice){
            case 0:printf("\nthankyou...");
                   exit(0);
                   break;
            case 1:printf("\nenter the value to be enqueued:\t");
                   scanf("%d",&num);
                   enqueue(&front,&rear,num);
                   break;
            case 2:dequeue(&front,&rear);
                   break;
            case 3:peek(&front,&rear);
                   break;
            case 4:display(&front,&rear);
                   break;
            default:printf("\ninvalid entry");
                    break;                 

        }

    }


}
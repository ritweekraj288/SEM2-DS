//QUEUE USING LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

int isEmpty(struct node**rear){
    if(*rear==NULL){
        return 1;
    }
    return 0;
}

int isFull(struct node**new){
    if(*new==NULL){
        return 1;
    }
    return 0;
}

void enqueue(struct node**rear,struct node**front,int data){
    struct node*new=malloc(sizeof(struct node));
    if(isFull(&new)){
        printf("\nqueue is full");
        return;
    }
    new->data=data;
    new->next=NULL;
    if(*rear==NULL){
        *rear=new;
        *front=new;
        return;
    }
    (*rear)->next=new;
    *rear=new;
}

void dequeue(struct node**rear,struct node**front){
    struct node*temp=*front;
    if(isEmpty(&temp)){
        printf("\nalready empty");
        return;
    }else if(*front==*rear){
        printf("\nelement to be dequeued is %d",temp->data);
        free(temp);
        *rear=NULL;
        *front=NULL;
        return;
    }
    printf("\nelement to be dequeued is %d",temp->data);
    (*front)=(*front)->next;
    free(temp);
    temp=NULL;
}

void peek(struct node**front){
    struct node*temp=*front;
    if(isEmpty(&temp)){
        printf("\nempty queue so no peek value");
        return;
    }
    printf("\npeek value is %d",(*front)->data);
}

void display(struct node**rear,struct node**front){
    struct node*temp=*front;
    if(*rear==NULL){
        printf("empty queue");
        return;
    }else if(*rear==*front){
        printf("%d",temp->data);
        return;
    }
    printf("%d\t",temp->data);
    while(temp!=*rear){
        temp=temp->next;
        printf("%d\t",temp->data);
    }
}

int main(){
    struct node*rear=NULL;
    struct node*front=NULL;
    int n,data;
    printf("\nenter the number of entries:\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the data:\t");
        scanf("%d",&data);
        enqueue(&rear,&front,data);
    }
    display(&rear,&front);
    printf("\nenter the number of elements to be dequeued:\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        dequeue(&rear,&front);
    }
    printf("\n");
    display(&rear,&front);
    printf("\n");

    return 0;
}
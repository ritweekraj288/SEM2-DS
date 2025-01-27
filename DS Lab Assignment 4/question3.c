//CHECKING FOR LOOP IN THE LINKEDLIST OR NOT

#include<stdio.h>
#include<stdlib.h>

//STRUCTURE FOR NODE

struct node{
    int data;
    struct node*next;
};

//FUNCTION TO ADD LIST ELEMENTS

void InsertAtBegin(struct node**head,int num){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    new->next=NULL;
    if(*head==NULL){
        *head=new;
    }else{
        new->next=*head;
        *head=new;
    }
}

//FUNCTION TO CREATE A LOOPING OR SINGLY LINKED LIST DEPENDING UPON USER

void ChoiceLoop(struct node**head,int n){
    printf("to make a singly linked list press 0 or to make a looping linked list press 1\t");
    int option;
    scanf("%d",&option);
    if(option==1){
        struct node*temp=*head,*store;
        store=*head;
        for(int i=0;i<n-1;i++){
            temp=temp->next;
        }
        temp->next=store;
    }

}

//FUNCTION TO PRINT LINKED LIST

void print(struct node**head,int n){
    struct node*temp=*head;
    for(int i=0;i<n;i++){
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}

//FUNCTION TO CHECK IF THE LINKED LIST FROMS A LOOP OR NOT

void CheckLoop(struct node**head,int n){
    struct node*temp=*head;
    for(int i=0;i<n-1;i++){
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("\nit is a singly linked list");
    }else{
        printf("\nit is a circular linked list");
    }
}



//MAIN FUNCTION

int main(){

    //LINKED LIST CREATION

    struct node*head=NULL;
    int n;
    printf("enter the number of elements\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        printf("enter the element\t");
        scanf("%d",&num);
        InsertAtBegin(&head,num);
    }

    //TAKING CHOICE OF USER FOR TYPE OF LINKED LIST

    ChoiceLoop(&head,n);

    //PRINTING LIST

    printf("\nentered list elements are:\t");
    print(&head,n);

    //FINDING FOR LOOP

    CheckLoop(&head,n);
    printf("\n");

    return 0;
}
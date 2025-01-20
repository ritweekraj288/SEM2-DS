//INSERTING A NEW NODE IN THE BEGINNING OF A SINGLY LINKED LIST 

#include<stdio.h>
#include<stdlib.h>

//STRUCTURE FOR LINK LIST

struct node{
    int data;
    struct node* next;
};

//FUNCTION TO ADD DATA IN BEGINNING

void AtTheBeginning(struct node**head,int num){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=num;

    if(*head==NULL){
        *head=new;
    }else{
       new->next=*head;
       *head=new;
    }
}

//FUNCTION TO DISPLAY

void display(struct node**head){
    struct node*temp=*head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

//MAIN FUNCTION

int main(){
    struct node*head=NULL;//head of linkrd list

    //USER ENTRY

    printf("enter the number of elements you want to enter\t");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       int num;
       printf("enter the number\t");
       scanf("%d",&num);
       AtTheBeginning(&head,num);
    }

    //DISPLAYING LINKED LIST

    printf("elements of the linked lists are:");
    display(&head);

    //ADDING A NEW NODE IN THE BEGINNING

    int num;
    printf("\nenter the data of new node\t");
    scanf("%d",&num);
    AtTheBeginning(&head,num);

    //DISPLAYING FINAL RESULT

    printf("elements of the linked lists are:");
    display(&head);
    printf("\n");



    return 0;
}
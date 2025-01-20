//COPYING ARRAY ELEMENTS TO A LINKED LIST

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

    //ARRAY ENTRY FROM USER

    printf("enter the number of elements you want to enter\t");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
       printf("enter the number\t");
       scanf("%d",&arr[i]);
    }

    //DISPLAYING ARRAY ELEMENTS

    printf("elements of the array are:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }  

    //COPYING ARRAY ELEMENTS TO LINKED LIST

    struct node*head=NULL;//head of linked list
    for(int i=n-1;i>=0;i--){
        AtTheBeginning(&head,arr[i]);
    }

    //DISPLAYING FINAL RESULT

    printf("\nelements of the linked lists are:\t");
    display(&head);
    printf("\n");

    return 0;
}
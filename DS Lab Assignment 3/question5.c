//LINKED LIST TO ARRAY

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

//FUNCTION FOR ARRAY TO LINKED LIST

void ArrayToList(struct node**head,int arr[],int n){
    struct node*temp=*head;
    int i=0;
    while(temp!=NULL){
        arr[i]=temp->data;
        temp=temp->next;
        i++;
    }

}

//MAIN FUNCTION

int main(){
    struct node*head=NULL;//head of linkrd list

    


    //USER ENTRY FOR LINKED LIST

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

    //ARRAY TO LINKED LIST

    int arr[n];
    ArrayToList(&head,arr,n);

    //PRINTING ARRAY ELEMENTS

    printf("\nelements of array are:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");

    return 0;
}
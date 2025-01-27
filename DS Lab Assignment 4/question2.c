//REMOVING DUPLICATE ELEMENTS FROM LINKEDLIST 

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

//FUNCTION TO PRINT LINKED LIST

void print(struct node**head,int n){
    struct node*temp=*head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}

//FUNCTION TO REMOVE DUPLICATE ELEMENTS

void RemoveDuplicate(struct node**head,int n){
    struct node*temp1=*head,*temp2,*previous;
    while(temp1!=NULL){
        previous=temp1;
        temp2=temp1->next;
        while(temp2!=NULL){
            if(temp1->data==temp2->data){
                previous->next=temp2->next;
                free(temp2);
                temp2=temp2->next;

            }else{
                previous=previous->next;
                temp2=temp2->next;
            }
        }
        temp1=temp1->next;
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

    //PRINTING LIST

    printf("\nentered list elements are:\t");
    print(&head,n);

    //REMOVING DUPLICATE ELEMENTS

    RemoveDuplicate(&head,n);

    //PRINTING FINAL RESULT

    printf("\nafter removing duplicate elements the list:\t");
    print(&head,n);
    printf("\n");

    return 0;
}
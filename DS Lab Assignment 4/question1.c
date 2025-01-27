//ROTATION OF A GIVEN LINKED LIST

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

//FUNCTION TO ROTATE LINKED LIST

void rotate(struct node**head,int n,int k){
    for(int i=0;i<k;i++){
        struct node*temp=*head;
        int store=temp->data;
        struct node*tempactual=temp;
        for(int i=0;i<n;i++){
            if(i==n-1){
                tempactual->data=store;
            }else{
                temp=temp->next;
                tempactual->data=temp->data;
                tempactual=tempactual->next;
            }
            
        }

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

    //PERFORMING ROTATION
    
    printf("\nenter the number through which to rotate the linkedlist\t");
    int k;
    scanf("%d",&k);
    rotate(&head,n,k);

    //PRINTING FINAL RESULT

    printf("after rotating the list:\t");
    print(&head,n);

    return 0;
}
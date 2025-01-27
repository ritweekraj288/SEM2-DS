//CREATION OF DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>

//STRUCTURE FOR NODE

struct node{
    int data;
    struct node*next;
    struct node*previous;
};

//FUNCTION TO INSERT IN THE BEGINNING

void insertAtFirst(struct node**head,struct node**tail,int num){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    new->next=NULL;
    new->previous=NULL;
    if(*head==NULL&&*tail==NULL){
        *head=new;
        *tail=new;
    }else{
        struct node*temp=*head;
        temp->previous=new;
        new->next=*head;
        *head=new;
    }
}

//FUNCTION TO INSERT AT THE END

void insertAtEnd(struct node**head,struct node**tail,int num){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    new->next=NULL;
    new->previous=NULL;
    if(*head==NULL&&*tail==NULL){
        *head=new;
        *tail=new;
    }else{
        struct node*temp=*tail;
        temp->next=new;
        new->previous=*tail;
        *tail=new;
    }
}

//FUNCTION TO INSERT ELEMENT IN THE MIDDLE

void insertAtMiddle(struct node**head,struct node**tail,int n,int num){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    new->next=NULL;
    new->previous=NULL;
    struct node*temp=*head;
    for(int i=0;i<n-1;i++){
        temp=temp->next;
    }
    new->next=temp->next;
    new->previous=temp;
    temp->next->previous=new;
    temp->next=new;
}

//FUNCTION TO INSERT DATA AFTER A PARTICULAR NODE

void insertAfterNode(struct node**head,int node,int num){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    new->next=NULL;
    new->previous=NULL;
    struct node*temp=*head;
    for(int i=0;i<node-1;i++){
        temp=temp->next;
    }
    new->next=temp->next;
    new->previous=temp;
    temp->next->previous=new;
    temp->next=new;
}

//FUNCTION TO PRINT THE DOUBLY LINKED LIST

void display(struct node**head){
    struct node*temp=*head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

//MAIN FUNCTION

int main(){
    struct node*head=NULL;
    struct node*tail=NULL;

    //USER ENTRIES IN THE BEGINNING

    printf("enter the number of entries you want to make in beginning\t");
    int n1;
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("enter the element\t");
        int num;
        scanf("%d",&num);
        insertAtFirst(&head,&tail,num);
    }

    //PRINTING THE DOUBLY LINKED LIST

    display(&head);

    //USER ENTRIES IN THE ENDING

    printf("\nenter the number of entries you want to make in ending\t");
    int n2;
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("enter the element\t");
        int num;
        scanf("%d",&num);
        insertAtEnd(&head,&tail,num);
    }

    //PRINTING THE DOUBLY LINKED LIST

    display(&head);

    //USER ENTRIES IN THE MIDDLE

    printf("\nenter the element to be inserted in the middle\t");
    int num;
    scanf("%d",&num);
    insertAtMiddle(&head,&tail,(n1+n2)/2,num);

    //PRINTING THE DOUBLY LINKED LIST

    display(&head);

    //USER ENTRIES AFTER A PARTICULAR NODE

    printf("\nenter the data to be added\t");
    scanf("%d",&num);
    printf("\nenter the node number after which you want to enter\n");
    int node;
    scanf("%d",&node);
    insertAfterNode(&head,node,num);

    //PRINTING THE DOUBLY LINKED LIST

    display(&head);
    printf("\n");

    return 0;
}
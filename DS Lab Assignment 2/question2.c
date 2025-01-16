//INTEGER POINTERS AS STRUCTURE MEMBERS

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("enter the number of integers to store");
    scanf("%d",&n);

    //CREATING INTEGER POINTERS AND ALLOCATING MEMORY DYNAMICALLLY

    int* str=(int*)malloc(n*sizeof(int));
    int* copy=(int*)malloc(n*sizeof(int));

    //INPUT FROM USER

    printf("enter the elements");
    for(int i=0;i<n;i++){
        scanf("%d",&str[i]);
    }

    //DISPLAYING ENETERED ELEMENTS

    printf("entered elements are\n");
    for(int i=0;i<n;i++){
        printf("%d\t",str[i]); 
    }

    //CREATING RESULTANT STRUCTURE

    for(int i=0;i<n;i++){
        if(i==0||i==n-1||i%2==0){
            copy[i]=str[i];
        }else{
            copy[i]=str[i-1]*str[i+1];
        }
    }

   
    //PRINTING FINAL RESULT

    printf("\nfinal structure is\n");
    for(int i=0;i<n;i++){
        printf("%d\t",copy[i]); 
    }

    return 0;
}
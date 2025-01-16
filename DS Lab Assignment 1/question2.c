//inversion of array

#include<stdio.h>

int main(){
    int n;
    printf("enter the number of elements in array");
    scanf("%d",&n);
    int arr[n];

    //taking the entry of the elements of array from user

    for(int i=0;i<n;i++){
        printf("enter the element");
        scanf("%d",&arr[i]);
    }

    //calculating number of inversion pairs
 
    int inversion=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                inversion++;
            }
        }
    }

    //printing the total count of inversion

    printf("total number of inversions are %d \n",inversion);

    return 0;
}

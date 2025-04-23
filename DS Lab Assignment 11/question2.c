// Given an array of non-negative integers, implement the Counting Sort algorithm to sort the array in ascending order.

#include<stdio.h>

int main(){
    int n;
    printf("enter the size of array\t");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("entered array is : \t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    //maximum element for size of count array
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    //count array
    int countarr[max+1];
    for(int i=0;i<max+1;i++){
        countarr[i]=0;
    }
    for(int i=0;i<n;i++){
        countarr[arr[i]]++;
    }
    printf("\nelements of count array is : \t");
    for(int i=0;i<max+1;i++){
         printf("%d\t",countarr[i]);
    }
    //position array
    int positionarr[max+1];
    positionarr[0]=countarr[0];
    for(int i=1;i<max+1;i++){
        positionarr[i]=positionarr[i-1]+countarr[i];
    }
    printf("\nelements of position array is : \t");
    for(int i=0;i<max+1;i++){
         printf("%d\t",positionarr[i]);
    }
    //final array
    int finalarr[n];
    for(int i=n-1;i>=0;i--){
        positionarr[arr[i]]--;
        finalarr[positionarr[arr[i]]]=arr[i];
    }
    printf("\nelements of final sorted array is : \t");
    for(int i=0;i<n;i++){
         printf("%d\t",finalarr[i]);
    }
    return 0;
}
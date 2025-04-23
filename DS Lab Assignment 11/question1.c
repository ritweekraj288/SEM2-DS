//Find the kth smallest element in an array using quicksort.

#include<stdio.h>

int Partition(int arr[],int start,int end){
    int index=start-1;
    int pivot=arr[end];
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            index++;
            int temp=arr[i];
            arr[i]=arr[index];
            arr[index]=temp;
        }
    }
    index++;
    int temp=arr[index];
    arr[index]=arr[end];
    arr[end]=temp;
    return index;
}

void QuickSort(int arr[],int start,int end,int k){
    if(start<end){
        int pvindex=Partition(arr,start,end);
        if(pvindex==k-1){
            printf("\n%dth smallest element is %d",k,arr[pvindex]);
            return;
        }
        else if(pvindex<k-1){
            QuickSort(arr,pvindex+1,end,k);
        }
        else{
            QuickSort(arr,start,pvindex-1,k);
        }
    }
}

int main(){
    int n,k;
    printf("enter the length of array\t");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("entered array is:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("enter the value of k\t");
    scanf("%d",&k);
    QuickSort(arr,0,n-1,k);
    return 0;
}
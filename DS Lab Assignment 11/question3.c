//Given an array of non-negative integers, implement the Radix Sort algorithm to sort the array in ascending order.

#include<stdio.h>

int main(){
    int n;
    printf("enter the number of elements:\t");
    scanf("%d",&n);
    int a[n],b[n];
    printf("\nenter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nentered array is:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    //max element
    int max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    int maxdigit=0;
    int num=max;
    while(num!=0){
        maxdigit++;
        num/=10;
    }
    printf("\nsince maximum number id %d we need to have %d counting sort loop",max,maxdigit);
    for(int i=0;i<maxdigit;i++){
        //count array
        int countarr[10];
        for(int j=0;j<10;j++){
            countarr[j]=0;
        }
        for(int j=0;j<n;j++){
            int element=a[j];
            for(int k=0;k<i;k++){
                element/=10;
            }
            element%=10;
            countarr[element]++;
        }
        //position arary
        int positionarr[10];
        for(int j=0;j<10;j++){
            positionarr[j]=0;
        }
        positionarr[0]=countarr[0];
        for(int j=1;j<10;j++){
            positionarr[j]=positionarr[j-1]+countarr[j];
        }
        //storing in another array
        for(int j=n-1;j>=0;j--){
            int element=a[j];
            for(int k=0;k<i;k++){
                element/=10;
            }
            element%=10;
            positionarr[element]--;
            b[positionarr[element]]=a[j];
        }
        //updating the original array
        for(int j=0;j<n;j++){
            a[j]=b[j];
        }
        printf("after loop %d",i+1);
        if(i==n-1){
            printf("\nfinal array after radix sort is:\t");
            for(int j=0;j<n;j++){
                printf("%d\t",a[j]);
            }
            break;
        }
        printf("\nnew updated array is:\t");
        for(int j=0;j<n;j++){
            printf("%d\t",a[j]);
        }
    }
    return 0;
}
#include<stdio.h>

void merge(int a[],int lb,int mid,int ub){
    int i,j,k;
    int b[ub-lb+1];
    i=lb;
    j=mid+1;
    k=0;
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=ub){
        b[k++]=a[j++];
    }

    for(i=lb,j=0;i<=ub;i++,j++){
        a[i]=b[j];
    }
}

void mergesort(int a[],int lb,int ub){
    if(lb<ub){
        int mid;
        mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

int main(){
    int n;
    printf("enter the number of elements:\t");
    scanf("%d",&n);
    printf("\nenter the elements:\n");
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nbefore merge sort array is:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    mergesort(a,0,n-1);
    printf("\nafter merge sort array is:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}
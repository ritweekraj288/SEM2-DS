#include<stdio.h>

int main(){
    int n;
    printf("enter the number of elements\t");
    scanf("%d",&n);
    int a[n];
    printf("\nenter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nbefore bubble sorting array is : \t");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nafter bubble sorting array is : \t");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}
//bitonic array


#include<stdio.h>


int main(){
    printf("enter the number of elements in array");
    int n;
    scanf("%d",&n);
    int arr[n];

    //entering array elements from the user

    for(int j=0;j<n;j++){
        printf("enter the element");
        scanf("%d",&arr[j]);
    }
    char status='T';

    //checking for ascending part in bitonic array

    int i;
    for(int m=0;m<n;m++){
        if(arr[m]<=arr[m+1]){
            continue;
        }else{
            i=m;
            break;
        }
    }


    //checking for the decending part in bitonic array

    for(int m=i+1;m<n;m++){
        if(arr[m]>=arr[m+1]){
            continue;
        }else{
            status='F';
            break;
        }
    }

    //checking if the array entered is entirely ascending or descending or not

    char status_asc='t'; //to check status of ascending

    for(int m=0;m<n-1;m++){
        if(arr[m]<=arr[m+1]){
            continue;
        }else{
            status_asc='f';
        }
    }

    char status_des='t';
    for(int m=0;m<n-1;m++){
        if(arr[m]>=arr[m+1]){
            continue;
        }else{
            status_des='f';
        }
    }


    //checking entered array is bitonic or not

    if(status=='T'&&status_asc=='f'&&status_des=='f'){
        printf("passed array is bitonic \n");
        printf("maximum value from the array is %d \n",arr[i]);
    }else{
        printf("passed array is not bitonic \n");
    }

    
}
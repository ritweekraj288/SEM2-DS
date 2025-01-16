//array of structures

#include<stdio.h>
#include<string.h>


//structure to store student informations

struct student{
    int rollno;
    char name[100];
    float marks;
};


int main(){
    int n;
    printf("enter the number of students");
    scanf("%d",&n);
    struct student std[n];
    
    //taking entries from the user

    for(int i=0;i<n;i++){
        printf("enter roll number");
        scanf("%d",&std[i].rollno);
        printf("enter name");
        char namee[100];
        scanf("%s",namee);
        strcpy(std[i].name,namee);
        printf("enter marks");
        scanf("%f",&std[i].marks);
    }

    //printing the entered details 

    for(int i=0;i<n;i++){
        printf("RECORD NUMBER %d \n",i+1);
        printf("entered roll number %d \n",std[i].rollno);
        printf("entered name %s \n",std[i].name);
        printf("enter marks %f \n",std[i].marks);
    }

    return 0;
}
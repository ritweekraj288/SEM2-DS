//MULTIPLICATION OF TWO MATRICES USING FUNCTIONS

#include<stdio.h>
#include<stdlib.h>

//FUNCTION DECLARATION

void enter(int row,int col,int **mat);//to take input from user
void display(int row,int col,int **mat);//to display matrix 
void multi(int row1,int col1,int row2,int col2,int **mat1,int **mat2,int **matmul);//to perform matrix multiplication


//MAIN FUNCTION

int main(){
    //ENTRING ROWS AND COLUMNS FROM USER

    int row1,col1,row2,col2;
    printf("enter number of rows and columns for matrix 1\n");
    scanf("%d%d",&row1,&col1);
    printf("enter number of rows and columns for matrix 2\n");
    scanf("%d%d",&row2,&col2);

    //CHECKING IF MATRIX MULTIPCATION IS POSSIBLE OR NOT

    if(col1!=row2){
        printf("multiplication not possible\n");
        return 0;
    }else{

        //ARRAY MATRIX DECLARATION
         
        int **mat1;//matrix 1
        int **mat2;//matrix 2
        int **matmul;//resultant matrix after multiplication

        //DYNAMIC MEMORY ALLOCATION

        mat1=(int**)malloc(row1*sizeof(int*));
        mat2=(int**)malloc(row2*sizeof(int*));
        matmul=(int**)malloc(row1*sizeof(int*));
        for(int i=0;i<row1;i++){
            mat1[i]=(int*)malloc(col1*sizeof(int));
        }
        for(int i=0;i<row2;i++){
            mat2[i]=(int*)malloc(col2*sizeof(int));
        }
        for(int i=0;i<row1;i++){
            matmul[i]=(int*)malloc(col2*sizeof(int));
        }

        //CALLING FUNCTIONS TO PERFORM MATRIX MULTIPLICATION
        
        printf("enter the elements of matrix 1\n");
        enter(row1,col1,mat1);
        printf("\nmartix 1 is :\n");
        display(row1,col1,mat1);
        printf("enter the elements of matrix 2\n");
        enter(row2,col2,mat2);
        printf("\nmartix 2 is :\n");
        display(row2,col2,mat2);

        //DISPLAYING FINAL MATRIX AFTER MULTIPLICATION

        multi(row1,row2,col1,col2,mat1,mat2,matmul);
        printf("resultant matrix is\n");
        display(row1,col2,matmul);
        

        

    }

    return 0;
}

//FUNCTIONS DEFINITION

void enter(int row,int col,int **mat){
    for(int i=0;i<row;i++){
        printf("enter elements of %d row\t",i+1);
        for(int j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void display(int row,int col,int **mat){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void multi(int row1,int col1,int row2,int col2,int **mat1,int **mat2,int **matmul){
    // Initialize the result matrix to zero
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            matmul[i][j] = 0;
        }
    }

    // Matrix multiplication logic
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                matmul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
   

}


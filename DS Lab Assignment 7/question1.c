//EVALUATION OF POSTFIX EXPRESSION

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max 100

int operand[max];
int top=-1;

void entryPlusEval(){
    int ch,num,op1,op2;
    char sign;
    printf("\n1 to enter number");
    printf("\n2 to enter sign");
    printf("\n0 to exit");
    printf("\nchoice:\t");
    scanf("%d",&ch);
    while(ch!=0){
        if(ch==1){
            printf("\nenter number:\t");
            scanf("%d",&num);
            top+=1;
            operand[top]=num;
        }else if(ch==2){
            printf("\nenter sign:\t");
            scanf("%s",&sign);
            op1=operand[top];
            top-=1;
            op2=operand[top];
            switch(sign){
                case '+':operand[top]=op1+op2;
                         break;
                case '-':operand[top]=op1-op2;
                         break;
                case '*':operand[top]=op1*op2;
                         break;
                case '/':operand[top]=op1*op2;
                         break;
                case '^':operand[top]=pow(op1,op2);
                         break;
            }   
            
        }
        printf("\n1 to enter number");
        printf("\n2 to enter sign");
        printf("\n0 to exit");
        printf("\nchoice:\t");
        scanf("%d",&ch);
    }
    printf("\nevaluated result is %d",operand[top]);
    printf("\n");
    
}

int main(){
    entryPlusEval();
    return 0;
}
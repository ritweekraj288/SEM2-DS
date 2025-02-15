//INFIX TO POSTFIX USING STACK

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxsize 100

char infix[maxsize];
char stack[maxsize];
char postfix[maxsize];
int top=-1;

void push(char symbol){
    top+=1;
    stack[top]=symbol;
}

char pop(){
    char symbol=stack[top];
    top-=1;
    return symbol;
}

int precedence(char symbol){
    switch(symbol){
        case '^':return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 1;
    }
    return -1;
}

void InToPost(){
    char symbol,next;
    int j=0;
    for(int i=0;i<strlen(infix);i++){
        symbol=infix[i];
        switch(symbol){
            case '(':push(symbol);
                    break;
            case ')':next=pop();
                     while(next!='('){
                         postfix[j++]=next;
                         next=pop();
                     }
                     break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':while(top!=-1&&precedence(stack[top])>=precedence(symbol)){
                        postfix[j++]=stack[top];
                        top-=1;
                    }
                    push(symbol);
                    break;
            default:postfix[j++]=symbol;
                    break;
        }  
    }
    while(top!=-1){
        symbol=pop();
        postfix[j++]=symbol;
    }
}

void PrintPost(){
    int i=0;
    while(postfix[i]!='\0'){
        printf("%c\t",postfix[i]);
        i++;
    }
}

int main(){
    int n;
    printf("enter infix epression:\t");
    gets(infix);

    InToPost();
    PrintPost();
    printf("\n");

    return 0;


}
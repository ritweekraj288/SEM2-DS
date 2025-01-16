//BANK MANAGEMENT APPLICATION

#include<stdio.h>
#include<string.h>

//CREATING STRUCTURE

struct BankMgmt{
    int AccNumber;
    char CustName[100];
    int AvlBalance;
    char AccType[100];
}bm[100];//bank management

//FUNTIONS DECLARATION

void withdrawal(int ano,int wd,int n);
void deposit(int ano,int dp,int n);
void avbal(int ano,int n);


int main(){
    printf("\nenter the number of coustomers\t");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nenter account number\t");
        scanf("%d",&bm[i].AccNumber);
        printf("\nenter customer name\t");
        char name[100];
        scanf("%s",name);
        strcpy(bm[i].CustName,name);
        printf("\nenter available balance\t");
        scanf("%d",&bm[i].AvlBalance);
        printf("\nenter account type\t");
        char atype[100];//account type
        scanf("%s",atype);
        strcpy(bm[i].AccType,atype);
    }


    printf("\nWELCOME TO BANK MANGEMENT APPLICATION\n");//headline

    //TAKING BASIC CREDENTIALS

    int ano;//account number
    printf("\nenter your account number\t");
    scanf("%d",&ano);

    //DISPLAYING OPTIONS

    printf("\nchoose the option\n");//to print options
    printf("1. Withdrawal\n");
    printf("2. Deposit\n");
    printf("3. Display Balance\n");
    printf("4. Exit");

    //TAKING OPTION
    printf("\nenter your option\t");
    int op;//option
    scanf("%d",&op);
    if(op==1||op==2||op==3||op==4){
        while(op==1||op==2||op==3||op==4){
            if(op==4){
                break;
            }else{
                if(op==1){
                    int wd;//withdrawal
                    printf("\nenter the withdrawal amount\t");
                    scanf("%d",&wd);
                    withdrawal(ano,wd,n);
                }else if(op==2){
                    int dp;//deposit
                    printf("\nenter the deposited amount\t");
                    scanf("%d",&dp);
                    deposit(ano,dp,n);
                }else if(op==3){
                    avbal(ano,n);
                }
            }
            printf("\nenter your next option\t");
            scanf("%d",&op);
        }


    }else{
        printf("\ninvalid option");
    }
    printf("\nTHANKYOU FOR VISIT");

    return 0;
}

void withdrawal(int ano,int wd,int n){
    for(int i=0;i<n;i++){
        if(bm[i].AccNumber==ano){
            bm[i].AvlBalance-=wd;
            printf("\naccount number:\t%d",bm[i].AccNumber);
            printf("\nname:\t%s",bm[i].CustName);
            printf("\taccount type:\t%s",bm[i].AccType);
            printf("\nyour new account balance is %d",bm[i].AvlBalance);
        }
    }
}

void deposit(int ano,int dp,int n){
    for(int i=0;i<n;i++){
        if(bm[i].AccNumber==ano){
            bm[i].AvlBalance+=dp;
            printf("\naccount number:\t%d",bm[i].AccNumber);
            printf("\nname:\t%s",bm[i].CustName);
            printf("\naccount type:\t%s",bm[i].AccType);
            printf("\nyour new account balance is %d",bm[i].AvlBalance);
        }
    }
}

void avbal(int ano,int n){
    for(int i=0;i<n;i++){
        if(bm[i].AccNumber==ano){
            printf("\naccount number:\t%d",bm[i].AccNumber);
            printf("\nname:\t%s",bm[i].CustName);
            printf("\naccount type:\t%s",bm[i].AccType);
            printf("\nyour current account balance is %d",bm[i].AvlBalance);
        }
    }
}
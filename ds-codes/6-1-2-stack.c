#include<stdio.h>

void push(int a[],int n,int* top, int itm){
    if(*top==n-1){
        printf("\nOverflow! Max size reached.");
        return;
    }
    *top+=1;
    a[*top]=itm;
    printf("\nPushed item: %d",itm);
}
void pop(int a[],int* top){
    if(*top==-1){
        printf("\nUnderflow! Stack is empty.");
        return;
    }
    printf("\nPopped item: %d",a[*top]);
    *top-=1;
}

int main(){
    printf("\n=== Stack Implementation ===\n");

    int n;
    printf("\nEnter max stack size: ");
    scanf("%d",&n);
    int a[n],top=-1;

    do{
        printf("\nChoose action:");
        printf("\n1. Push\n2. Pop\n3. Exit\n");
        printf("\nEnter your choice: ");
        
        int x;
        scanf("%d",&x);

        if(x==1){
            int itm;
            printf("\nEnter item to push: ");
            scanf("%d",&itm);
            push(a,n,&top,itm);
        }
        else if(x==2) pop(a,&top);
        else if(x==3) break;
        else{
            printf("\nInvalid choice!");
        }
        printf("\nUpdated stack: ");
        for(int i=0;i<=top;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }while(1);

    printf("\n");
    return 0;
}
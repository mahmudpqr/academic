#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void add(node *nd[],int n){
    printf("enter elements: ");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        nd[i]=malloc(sizeof(node));
        nd[i]->data=x;
    }
}
void link(node *nd[],int n){
    for(int i=0;i<n-1;i++)
        nd[i]->next=nd[i+1];
    nd[n-1]->next=NULL;
}
void print(node *st){
    printf("the list: ");
    node *t=st;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
}
void delall(node *st){
    node *t1=st;
    while(t1!=NULL){
        node *t2=t1->next;
        free(t1);
        t1=t2;
    }
}
void insbeg(node **st,int itm){
    node *nnd=malloc(sizeof(node));
    nnd->data=itm;
    nnd->next=*st;
    *st=nnd;
}

int main(){
    int x;
    do{
        int n;
        printf("enter number of elements: ");
        scanf("%d",&n);

        node *nd[n];
        add(nd,n);
        link(nd,n);
        node* st=nd[0];

        print(st);
        delall(st);

        printf("\n\ntry again? (1/0): ");
        scanf("%d",&x);
    }while(x==1);
    return 0;
}

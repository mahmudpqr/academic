#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void add(node *nd[],int n){
    printf("enter elements in ascending order: ");
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
int search(node *st,int itm){
    node *t=st;
    int cnt=1;
    while(t!=NULL){
        if(t->data==itm)
            return cnt;
        if(t->data>itm)
            return 0;
        cnt++;
        t=t->next;
    }
    return 0;
}

int main(){
    int n;
    printf("enter number of elements: ");
    scanf("%d",&n);

    node *nd[n];
    add(nd,n);
    link(nd,n);
    node* st=nd[0];

    int x;
    do{
        print(st);

        int itm;
        printf("\nitem to search: ");
        scanf("%d",&itm);

        int pos=search(st,itm);
        if(pos==0)
            printf("not found");
        else
            printf("found at node #%d",pos);

        printf("\n\ntry again? (1/0): ");
        scanf("%d",&x);
    }while(x==1);
    delall(st);
    return 0;
}

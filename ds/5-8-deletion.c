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
void del(node **st,int pos){
    if(*st==NULL)
        return;
    if(pos==1){
        node *t=*st;
        *st=(*st)->next;
        free(t);
        return;
    }
    int cnt=1;
    node *t1=*st;
    while(t1!=NULL&&t1->next!=NULL){
        if(cnt==pos-1){
            node *t2=t1->next;
            t1->next=t2->next;
            free(t2);
            return;
        }
        cnt++;
        t1=t1->next;
    }
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
        int pos;
        printf("target node to delete: ");
        scanf("%d",&pos);

        del(&st,pos);
        print(st);

        printf("\n\ntry again? (1/0): ");
        scanf("%d",&x);
    }while(x==1);
    delall(st);
    return 0;
}

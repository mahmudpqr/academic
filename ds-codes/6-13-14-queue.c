#include<stdio.h>

void insert(int a[],int n,int* f,int* r,int itm){
    if(*f==0&&*r==n-1||*f==*r+1){
        printf("\nOverflow! Max size reached.");
        return;
    }
    if(*f==-1){
        *f=0;
        *r=0;
    }
    else if(*r==n-1) *r=0;
    else *r+=1;

    a[*r]=itm;
    printf("\nInserted item: %d",itm);
}
void delete(int a[],int n,int* f,int* r){
    if(*f==-1){
        printf("\nUnderflow! Queue is empty.");
        return;
    }
    printf("\nDeleted item: %d",a[*f]);
    if(*f==*r){
        *f=-1;
        *r=-1;
    }
    else if(*f==n-1) *f=0;
    else *f+=1;
}

int main(){
    printf("\n=== Queue Implementation ===\n");

    int n;
    printf("\nEnter max queue size: ");
    scanf("%d",&n);
    int a[n],f=-1,r=-1;

    do{
        printf("\nChoose action:");
        printf("\n1. Insert\n2. Delete\n3. Exit\n");
        printf("\nEnter your choice: ");
        
        int x;
        scanf("%d",&x);

        if(x==1){
            int itm;
            printf("\nEnter item to Insert: ");
            scanf("%d",&itm);
            insert(a,n,&f,&r,itm);
        }
        else if(x==2){
            delete(a,n,&f,&r);
        }
        else if(x==3) break;
        else{
            printf("\nInvalid choice!");
        }
        printf("\nUpdated queue: ");
        if(f!=-1){
            int i=f;
            while(1){
                printf("%d ",a[i]);
                
                if(i==r) break;
                else if(i==n-1) i=0;
                else i+=1;
            }
        }
        printf("\n");
    }while(1);

    printf("\n");
    return 0;
}
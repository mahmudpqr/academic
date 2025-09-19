#include<stdio.h>

void insort(int a[],int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(temp<a[j]&&j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int min(int a[],int n,int i){
    int m=a[i];
    int loc=i;
    for(int j=i+1;j<n;j++){
        if(a[j]<m){
            m=a[j];
            loc=j;
        }
    }
    return loc;
}
void selsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int loc=min(a,n,i);
        int temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
}

int main(){
    printf("\n=== Number Sorting Program ===\n");

    int x;
    do{
        int n;
        printf("\nHow many numbers would you like to sort? : ");
        scanf("%d",&n);
        printf("\n");
        
        int a[n];
        for(int i=0;i<n;i++){
            printf("Enter number #%d: ",i+1);
            scanf("%d",&a[i]);
        }
        printf("\nChoose algorithm:");
        printf("\n1. Insertion Sort\n2. Selection Sort\n");
        printf("\nEnter your choice: ");
        int c;
        scanf("%d",&c);

        if(c==1) insort(a,n);
        else if(c==2) selsort(a,n);

        printf("\nSorted in ascending order: ");
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n\nEnter 1 to try again, 0 to quit: ");
        scanf("%d",&x);
    }while(x==1);

    printf("\n");
    return 0;
}
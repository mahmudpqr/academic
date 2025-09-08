#include<stdio.h>

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
    int x;
    do{
        int n;
        printf("\nenter array length: ");
        scanf("%d",&n);

        int a[n];
        printf("enter elements: ");
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        selsort(a,n);

        printf("sorted array: ");
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\ntry again? (1/0): ");
        scanf("%d",&x);
    }while(x==1);

    printf("\n");
    return 0;
}
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
        insort(a,n);

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
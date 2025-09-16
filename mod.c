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
    printf("\n=== Number Sorting Program ===\n");

    int x;
    do{
        
        int n;
        printf("\nHow many numbers would you like to sort? : ");
        scanf("%d",&n);
        printf("\n");
        
        int a[n];
        for(int i=0;i<n;i++){
            printf("Enter Number #%d: ",i+1);
            scanf("%d",&a[i]);
        }
        insort(a,n);

        printf("\nSorted in Ascending Order: ");
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n\nEnter 1 to try again, 0 to quit: ");
        scanf("%d",&x);
    }while(x==1);

    printf("\n");
    return 0;
}
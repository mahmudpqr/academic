#include<iostream>
using namespace std;

void del(int a[],int*n,int k){
    for(int i=k-1;i<*n-1;i++)
        a[i]=a[i+1];
    (*n)--;
}
int main(){
    int a[10]={2,5,4,7,1,1,5,3,6,7};
    int n=10,x;
    do{
        cout<< "the array: ";
        for(int i=0;i<n;i++)
            cout<<a[i]<< " ";

        int k;
        cout<< "\nenter position to delete: ";
        cin>>k;

        del(a,&n,k);
        cout<< "\nafter deletion: ";
        for(int i=0;i<n;i++)
            cout<<a[i]<< " ";

        cout<< "\n\ntry again? (1/0): ";
        cin>>x;
    }while(x==1);
    return 0;
}

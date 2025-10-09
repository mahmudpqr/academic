#include<iostream>
using namespace std;

void ins(int a[],int*n,int k,int item){
    for(int i=*n-1;i>=k-1;i--)
        a[i+1]=a[i];
    a[k-1]=item;
    (*n)++;
}
int main(){
    int a[30]={2,5,4,7,1,1,5,3,6,7};
    int n=10,x;
    do{
        cout<< "the array: ";
        for(int i=0;i<n;i++)
            cout<<a[i]<< " ";

        int k,item;
        cout<< "\nenter position & item to insert: ";
        cin>>k>>item;

        ins(a,&n,k,item);
        cout<< "\nafter insertion: ";
        for(int i=0;i<n;i++)
            cout<<a[i]<< " ";

        cout<< "\n\ntry again? (1/0): ";
        cin>>x;
    }while(x==1);
    return 0;
}

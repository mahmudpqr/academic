#include<iostream>
using namespace std;

int bsearch(int n,int a[],int b){
    int low=0,up=n-1;
    while(low<=up){
        int mid=(low+up)/2;

        if(a[mid]==b)
            return mid+1;
        if(a[mid]>b)
            up=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
int main(){
    int x;
    do{
        int n;
        cout<< "enter array size: ";
        cin>>n;

        int a[n];
        cout<< "enter sorted array elements: ";
        for(int i=0;i<n;i++)
            cin>>a[i];

        int b;
        cout<< "enter item to search: ";
        cin>>b;

        int p=bsearch(n,a,b);
        if(p==-1)
            cout<< "not found";
        else
            cout<< "found at position "<<p;

        cout<< "\n\ntry again? (1/0): ";
        cin>>x;
    }while(x==1);
}

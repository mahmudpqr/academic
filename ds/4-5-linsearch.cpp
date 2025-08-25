#include<iostream>
using namespace std;

int lsearch(int n,int a[],int b){
    for(int i=0;i<n;i++){
        if(a[i]==b)
            return i+1;
    }
    return 0;
}
int main(){
    int x;
    do{
        int n;
        cout<< "enter array size: ";
        cin>>n;

        int a[n];
        cout<< "enter array elements: ";
        for(int i=0;i<n;i++)
            cin>>a[i];

        int b;
        cout<< "enter item to search: ";
        cin>>b;

        int p=lsearch(n,a,b);
        if(p==0)
            cout<< "not found";
        else
            cout<< "found at position "<<p;

        cout<< "\n\ntry again? (1/0): ";
        cin>>x;
    }while(x==1);
    return 0;
}

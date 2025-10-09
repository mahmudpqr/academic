#include<iostream>
#include<algorithm>
using namespace std;

void bsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
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

        bsort(a,n);
        cout<< "\nsorted in ascending order:\n";
        for(int i=0;i<n;i++)
            cout<<a[i]<< " ";

        cout<< "\n\ntry again? (1/0): ";
        cin>>x;
    }while(x==1);
    return 0;
}

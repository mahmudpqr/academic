#include<iostream>
#include <cstdint>
using namespace std;

int main(){
    int x;
    int a[10]={2,5,4,7,1,1,5,3,6,7};
    do{
        uintptr_t b=(uintptr_t)&a[0];

        cout<< "the array: ";
        for(int i=0;i<10;i++)
            cout<<a[i]<< " ";

        cout<< "\n\nbase(arr): "<<b<<endl;
        cout<< "word size, w: 4 (int)"<<endl;
        cout<< "lower bound: 0"<<endl;

        int k;
        cout<< "enter index, k: ";
        cin>>k;

        uintptr_t loc=b+4*k;
        cout<< "\nloc(arr[k]): "<<loc;

        cout<< "\n\ntry again? (1/0): ";
        cin>>x;
    } while(x==1);
    return 0;
}

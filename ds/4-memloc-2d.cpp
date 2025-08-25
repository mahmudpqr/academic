#include<iostream>
#include <cstdint>
using namespace std;

int main(){
    int x;
    int a[3][4]={{1,7,5,4},{2,8,6,3},{2,0,1,9}};
    do{
        uintptr_t b=(uintptr_t)&a[0][0];

        cout<< "the 2D array:\n";
        for(int i=0;i<3;i++){
            for(int h=0;h<4;h++)
                cout<<a[i][h]<< " ";
            cout<<endl;
        }
        cout<< "\nbase(arr): "<<b<<endl;
        cout<< "word size, w: 4 (int)"<<endl;
        cout<< "lower bound: 0"<<endl;

        int j,k;
        cout<< "enter indices, j, k: ";
        cin>>j>>k;

        char y;
        cout<< "column/row-major-order (c/r): ";
        cin>>y;

        if(y=='c'){
            uintptr_t loc=b+4*(3*k+j);
            cout<< "\nloc(arr[j,k]): "<<loc;
        }
        else if(y=='r'){
            uintptr_t loc=b+4*(4*j+k);
            cout<< "\nloc(arr[j,k]): "<<loc;
        }
        cout<< "\n\ntry again? (1/0): ";
        cin>>x;
    } while(x==1);
    return 0;
}

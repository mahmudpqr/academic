#include<iostream>
using namespace std;

int main(){
    int x;
    int a[10]={2,5,4,7,1,1,5,3,6,7};
    do{
        cout<< "before increment: ";
        for(int i=0;i<10;i++)
            cout<<a[i]<< " ";

        for(int i=0;i<10;i++)
            a[i]++;
        cout<< "\nafter increment: ";
        for(int i=0;i<10;i++)
            cout<<a[i]<< " ";

        cout<< "\n\ntry again? (1/0): ";
        cin>>x;
    } while(x==1);
    return 0;
}

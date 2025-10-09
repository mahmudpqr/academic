#include<iostream>
using namespace std;

int main(){
    int x;
    do{
        int m,n,p,q;
        cout<< "enter 1st matrix dimensions: ";
        cin>>m>>n;
        cout<< "enter 2nd matrix dimensions: ";
        cin>>p>>q;

        if(n==p){
            int a[m][n];
            cout<< "\nenter 1st matrix elements:\n";
            for(int i=0;i<m;i++){
                cout<< "row "<<i+1<< ": ";
                for(int j=0;j<n;j++)
                    cin>>a[i][j];
            }
            int b[p][q];
            cout<< "\nenter 2nd matrix elements:\n";
            for(int i=0;i<p;i++){
                cout<< "row "<<i+1<< ": ";
                for(int j=0;j<q;j++)
                    cin>>b[i][j];
            }
            int c[m][q];
            for(int i=0;i<m;i++){
                for(int j=0;j<q;j++){
                    c[i][j]=0;
                    for(int k=0;k<n;k++)
                        c[i][j]+=a[i][k]*b[k][j];
                }
            }
            cout<< "\nresultant matrix:\n";
            for(int i=0;i<m;i++){
                for(int j=0;j<q;j++)
                    cout<<c[i][j]<< " ";
                cout<<endl;
            }
        }
        else
            cout<< "\nmultiplication not possible\n";

        cout<< "\ntry again? (1/0): ";
        cin>>x;
    }while(x==1);
    return 0;
}

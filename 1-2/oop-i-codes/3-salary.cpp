#include<iostream>
using namespace std;

class employee{
    string name;
    int id;
    int basic;
    static int x;

public:
    employee(){}
    employee(string a,int b,int c){
        name=a;
        id=b;
        basic=c;
    }
    float gross(){
        return basic+basic*0.15;
    }
    void display(){
        cout<< "name: "<<name<<endl;
        cout<< "id: "<<id<<endl;
        cout<< "basic salary: "<<basic<<endl;
        cout<< "gross salary: "<<gross()<<endl;
    }
    static void total(int nn){
        x=nn;
    }
    static void total(){
        cout<< "\ntotal employees: "<<x<<endl;
    }

}e[20];
int employee::x;

int main(){
    int n;
    cout<< "enter number of employees: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin.ignore();
        cout<< "\nemployee #"<<i+1<<endl;

        string nam;
        cout<< "enter name: ";
        getline(cin,nam);

        int idd;
        cout<< "enter id: ";
        cin>>idd;

        int bas;
        cout<< "enter basic salary: ";
        cin>>bas;

        e[i]=employee(nam,idd,bas);
    }
    employee::total(n);
    employee::total();

    for(int i=0;i<n;i++){
        cout<< "\nemployee #"<<i+1<<endl;
        e[i].display();
    }
    return 0;
}

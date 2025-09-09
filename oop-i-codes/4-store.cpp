#include<iostream>
using namespace std;

class product{
    int id;
    string name;
    int price;
    int qty;
    string msg;
    static int x;

public:
    product(){}
    product(int a,string b,int c,int d){
        id=a;
        name=b;
        price=c;
        qty=d;
        msg="n/a";
    }
    void update(int q){
        qty+=q;
    }
    void update(string m,int q){
        msg=m;
        qty+=q;
    }
    int value(){
        return qty*price;
    }
    void display(){
        cout<< "id: "<<id<<endl;
        cout<< "name: "<<name<<endl;
        cout<< "price: "<<price<<endl;
        cout<< "quantity: "<<qty<<endl;
        cout<< "restock message: "<<msg<<endl;
        cout<< "stock value: "<<value()<<endl;
    }
    static void total(int nn){
        x=nn;
    }
    static void total(){
        cout<< "\ntotal products: "<<x<<endl;
    }
}p[20];
int product::x;

int main(){
    int n;
    cout<< "enter number of products: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<< "\nproduct #"<<i+1<<endl;

        int idd;
        cout<< "enter id: ";
        cin>>idd;
        cin.ignore();

        string nam;
        cout<< "enter name: ";
        getline(cin,nam);

        int pri;
        cout<< "enter price: ";
        cin>>pri;

        int qua;
        cout<< "enter quantity: ";
        cin>>qua;

        p[i]=product(idd,nam,pri,qua);
        product(idd,nam,pri,qua);
    }
    char yn;
    cout<< "\nupdate stock? (y/n): ";
    cin>>yn;

    if(yn=='y'){
        int num;
        cout<< "enter product number: ";
        cin>>num;

        int qq;
        cout<< "enter restock quantity: ";
        cin>>qq;
        cin.ignore();

        string reas;
        cout<< "reason (0 to skip): ";
        getline(cin,reas);

        if(reas=="0")
            p[num-1].update(qq);
        else
            p[num-1].update(reas,qq);
    }
    product::total(n);
    product::total();

    for(int i=0;i<n;i++){
        cout<< "\nproduct #"<<i+1<<endl;
        p[i].display();
    }
    return 0;
}

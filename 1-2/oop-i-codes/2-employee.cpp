#include<iostream>
using namespace std;

class employee{
    int id;
    string name;
    string dept;
    float salary;

public:
    void input(){
        cout<< "enter id: ";
        cin>>id;
        cin.ignore();
        cout<< "enter name: ";
        getline(cin,name);
        cout<< "enter dept: ";
        getline(cin,dept);
        cout<< "enter monthly salary: ";
        cin>>salary;
    }
    void bonus(){
        if(salary>50000)
            cout<< "bonus: "<<salary*0.1<<endl;
        else
            cout<< "bonus: "<<salary*0.05<<endl;
    }
    float annual(){
        return salary*12;
    }
    void display(){
        cout<< "\nemployee info:\n";
        cout<< "id: "<<id<<endl;
        cout<< "name: "<<name<<endl;
        cout<< "dept: "<<dept<<endl;
        cout<< "monthly salary: "<<salary<<endl;
        bonus();
        cout<< "annual salary: "<<annual()<<endl;
    }
}e;
int main(){
    e.input();
    e.display();
    return 0;
}

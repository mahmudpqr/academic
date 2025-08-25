#include<iostream>
using namespace std;

class student{
    int id;
    string name;
    float marks;

public:
    void input(){
        cout<< "enter id: ";
        cin>>id;
        cin.ignore();
        cout<< "enter name: ";
        getline(cin,name);
        cout<< "enter marks: ";
        cin>>marks;
    }
    char grd(){
        if(marks>=90)
            return 'A';
        else if(marks>=80)
            return 'B';
        else if(marks>=70)
            return 'C';
        else if(marks>=60)
            return 'D';
        else
            return 'F';
    }
    void display(){
        cout<< "\nstudent details:\n";
        cout<< "id: "<<id<<endl;
        cout<< "name: "<<name<<endl;
        cout<< "marks: "<<marks<<endl;
        cout<< "grade: "<<grd()<<endl;
    }
}s;

int main(){
    s.input();
    s.display();
    return 0;
}

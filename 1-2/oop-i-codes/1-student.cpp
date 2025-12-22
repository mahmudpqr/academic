#include <iostream>
#include <string>

using namespace std;

class student {
    int id;
    string name;
    float marks;

    public:
    void input();
    void display();
};

void student::input() {
    cout << "\nenter details:";
    cout << "\nenter id: ";
    cin >> id;

    cout << "enter name: ";
    cin.ignore();
    getline(cin, name);

    cout << "enter marks: ";
    cin >> marks;
}

void student::display() {
    cout << "\nstudent details:";
    cout << "\nid: " << id;
    cout << "\nname: " << name;
    cout << "\nmarks: " << marks;
}

int main() {
    student s1;
    s1.input();
    s1.display();
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class employee {
    int id;
    string name;
    string dept;
    float salary;

    public:
    void input();
    void display();
    float bonus();

    float annualsalary() {
        return salary * 12;
    }
};

void employee::input() {
    cout << "\nenter details:";
    cout << "\nenter id: ";
    cin >> id;

    cout << "enter name: ";
    cin.ignore();
    getline(cin, name);

    cout << "enter dept: ";
    getline(cin, dept);

    cout << "enter salary: ";
    cin >> salary;
}

float employee::bonus() {
    if (salary > 50000) {
        return 0.1 * salary;
    } else {
        return 0.05 * salary;
    }
}

void employee::display() {
    cout << "\nemployee details:";
    cout << "\nid: " << id;
    cout << "\nname: " << name;
    cout << "\ndept:" << dept;
    cout << "\nsalary: " << salary;
    cout << "\nannual salary: " << annualsalary();
    cout << "\nbonus: " << bonus();
}

int main() {
    employee e1;
    e1.input();
    e1.display();
    return 0;
}
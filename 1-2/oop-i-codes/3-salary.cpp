#include <iostream>
#include <string>

using namespace std;

class employee {
    int id;
    string name;
    double basic;
    static int count;

    public:
    employee() {}

    employee(int i, string n, double b) : id(i), name(n), basic(b) {
        count++;
    }

    double gross() {
        return basic + basic * 0.15;
    }

    static int getcount() {
        return count;
    }

    void display();
};

int employee::count = 0;

void employee::display() {
    cout << "\nemployee details:";
    cout << "\nid: " << id;
    cout << "\nname: " << name;
    cout << "\nbasic: " << basic;
    cout << "\ngross: " << gross() << "\n";
}

int main() {
    employee e[20];

    int x;
    while (1) {
        cout << "\n1. add employee";
        cout << "\n2. display info";
        cout << "\n3. total employees";
        cout << "\n4. exit";

        cout << "\nenter choice: ";
        cin >> x;

        if (x == 1) {
            cout << "\nenter details:";

            int id;
            cout << "\nenter id: ";
            cin >> id;

            string name;
            cout << "enter name: ";
            cin.ignore();
            getline(cin, name);

            double basic;
            cout << "enter basic: ";
            cin >> basic;

            int i = employee::getcount();
            e[i] = employee(id, name, basic);
        } else if (x == 2) {
            for (int i = 0; i < employee::getcount(); i++) {
                e[i].display();
            }
        } else if (x == 3) {
            cout << "\ntotal employees: " << employee::getcount() << "\n";
        } else if (x == 4) break;
    }

    return 0;
}
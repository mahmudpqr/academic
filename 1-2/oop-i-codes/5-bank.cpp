#include <iostream>
#include <string>
#include <vector>

using namespace std;

class account {
    int num = 0;
    string name = "";
    double bal = 0;
    string msg = "";

    public:
    account() {}
    account(int nu, string na, double b) : num(nu), name(na), bal(b) {}
    
    void deposit(double amt) {
        bal += amt;
    }

    void deposit(double amt, string m) {
        bal += amt;
        msg = m;
    }

    double interest(double rate = 5) {
        return bal * rate / 100;
    }

    void display();
    friend void transfer(double amt, account& x, account& y);
};

inline void account::display() {
    cout << "\naccount details:";
    cout << "\nac no: " << num;
    cout << "\nname: " << name;
    cout << "\nbalance: " << bal;
    cout << "\ndeposit message: " << msg;
    cout << "\nyearly interest: " << interest() << "\n";
}

void transfer(double amt, account& x, account& y) {
    x.bal -= amt;
    y.bal += amt;
}

int main() {
    vector<account> a;

    int x;
    while(1) {
        cout << "\n1. add account";
        cout << "\n2. display info";
        cout << "\n3. deposit";
        cout << "\n4. transfer";
        cout << "\n5. exit";

        cout << "\nenter choice: ";
        cin >> x;

        if (x == 1) {
            cout << "\nenter details:";

            int num;
            cout << "\nenter ac no: ";
            cin >> num;

            string name;
            cout << "enter name: ";
            cin.ignore();
            getline(cin, name);

            double bal;
            cout << "enter balance: ";
            cin >> bal;

            a.emplace_back(num, name, bal);
        } else if (x == 2) {
            for (auto& x : a) {
                x.display();
            }
        } else if (x == 3) {
            int i;
            cout << "\nenter index: ";
            cin >> i;

            if (i < 0 || i >= a.size()) {
                cout << "\nnot found\n";
            } else {
                double amt;
                cout << "enter amount: ";
                cin >> amt;

                string msg;
                cout << "enter message (0 to skip): ";
                cin.ignore();
                getline(cin, msg);

                if (msg == "0") {
                    a[i].deposit(amt);
                } else {
                    a[i].deposit(amt, msg);
                }
            }
        } else if (x == 4) {
            int i, j;
            cout << "\nenter indices (from, to): ";
            cin >> i >> j;

            if (i < 0 || i >= a.size() || j < 0 || j >= a.size()) {
                cout << "\nnot found\n";
            } else {
                double amt;
                cout << "enter amount: ";
                cin >> amt;

                transfer(amt, a[i], a[j]);
            }
        } else if (x == 5) break;
    }

    return 0;
}
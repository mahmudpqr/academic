#include <iostream>
#include <string>
#include <vector>

using namespace std;

class customer {
    protected:
    int id = 0;
    string name = "";

    public:
    customer() {}
    customer(int i, string n) : id(i), name(n) {}

    int getid() {
        return id;
    }

    void displaycustomer();
};

class savingsaccount : virtual public customer {
    protected:
    double bal = 0, rate = 0;

    public:
    savingsaccount() {}
    savingsaccount(double b, double r) : bal(b), rate(r) {}

    void deposit(double amt) {
        bal += amt;
        calculateinterest();
        cout << "\ndeposited: " << amt << " | balance: " << bal << "\n";
    }

    double calculateinterest() {
        return bal * rate / 100;
    }

    void displaysavings();
};

class loanaccount : virtual public customer {
    protected:
    double loan = 0, emi = 0;

    public:
    loanaccount() {}
    loanaccount(double l) : loan(l) {
        calculateemi();
    }

    void calculateemi() {
        emi = loan / 12;
    }

    void displayloan();
};

class accountholder : public savingsaccount, public loanaccount {
    public:
    accountholder() {}
    accountholder(int i, string n, double b, double r, double l) : customer(i, n), savingsaccount(b, r), loanaccount(l) {}

    void displayall();
    friend void comparesavings(accountholder& x, accountholder& y);
    friend void loansummary(accountholder& x);
};

void customer::displaycustomer() {
    cout << "\naccount details:";
    cout << "\ncustomer id: " << id;
    cout << "\nname: " << name;
}

void savingsaccount::displaysavings() {
    cout << "\nbalance: " << bal;
    cout << "\ninterest rate: " << rate;
    cout << "\nyearly interest: " << calculateinterest();
}

void loanaccount::displayloan() {
    cout << "\nloan: " << loan;
    cout << "\nemi (1 year): " << emi << "\n";
}

void accountholder::displayall() {
    displaycustomer();
    displaysavings();
    displayloan();
}

void comparesavings(accountholder& x, accountholder& y) {
    cout << "\nsavings comparison:";

    if (x.bal > y.bal) {
        cout << "\n" << x.name << " (" << x.bal << ") has higher balance than " << y.name << " (" << y.bal << ")\n";
    } else if (x.bal < y.bal) {
        cout << "\n" << y.name << " (" << y.bal << ") has higher balance than " << x.name << " (" << x.bal << ")\n";
    } else {
        cout << "\n" << x.name << " and " << y.name << " have equal balances (" << x.bal << ")\n";
    }
}

void loansummary(accountholder& x) {
    cout << "\nloan summary:";

    x.displaycustomer();
    x.displayloan();
}

vector<accountholder> a;

accountholder* findaccount(int id) {
    for (auto& x : a) {
        if (x.getid() == id) return &x;
    }

    return nullptr;
}

int main() {
    a.emplace_back(1150, "ahmed sheikh", 422000, 4, 93000);
    a.emplace_back(3620, "mishkat alvi", 127000, 3, 56000);

    int x;
    while (1) {
        cout << "\nbanking system menu:";
        cout << "\n1. add account";
        cout << "\n2. deposit";
        cout << "\n3. display info";
        cout << "\n4. compare savings";
        cout << "\n5. loan summary";
        cout << "\n6. exit";

        cout << "\nenter choice: ";
        cin >> x;

        if (x == 1) {
            cout << "\nenter details:";

            int id;
            cout << "\nenter customer id: ";
            cin >> id;

            if (findaccount(id) != nullptr) {
                cout << "\nnot available\n";
                continue;
            }

            string name;
            cout << "enter name: ";
            cin.ignore();
            getline(cin, name);

            double bal;
            cout << "enter balance: ";
            cin >> bal;

            double rate;
            cout << "enter rate: ";
            cin >> rate;

            double loan;
            cout << "enter loan: ";
            cin >> loan;

            a.emplace_back(id, name, bal, rate, loan);
            cout << "\naccount added\n";
        } else if (x == 2) {
            int id;
            cout << "\nenter id: ";
            cin >> id;

            accountholder* ptr = findaccount(id);

            if (ptr == nullptr) {
                cout << "\nnot found\n";
                continue;
            }

            double amt;
            cout << "enter amount: ";
            cin >> amt;

            ptr->deposit(amt);
        } else if (x == 3) {
            int id;
            cout << "\nenter id: ";
            cin >> id;

            accountholder* ptr = findaccount(id);

            if (ptr == nullptr) {
                cout << "\nnot found\n";
                continue;
            }

            ptr->displayall();
        } else if (x == 4) {
            int id1, id2;
            cout << "\nenter 1st and 2nd id: ";
            cin >> id1 >> id2;

            accountholder* ptr1 = findaccount(id1);
            accountholder* ptr2 = findaccount(id2);

            if (ptr1 == nullptr || ptr2 == nullptr) {
                cout << "\nnot found\n";
                continue;
            }

            comparesavings(*ptr1, *ptr2);
        } if (x == 5) {
            int id;
            cout << "\nenter id: ";
            cin >> id;

            accountholder* ptr = findaccount(id);

            if (ptr == nullptr) {
                cout << "\nnot found\n";
                continue;
            }

            loansummary(*ptr);
        } else if (x == 6) {
            cout << "\nexiting banking system\n";
            break;
        }
    }

    return 0;
}
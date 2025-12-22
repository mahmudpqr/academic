#include <iostream>
#include <string>
#include <vector>

using namespace std;

class person {
    protected:
    int id = 0;
    string name = "";

    public:
    person() {}
    person(int i, string n) : id(i), name(n) {}

    int getid() {
        return id;
    }

    void displayperson();
};

class medicalrecord : virtual public person {
    protected:
    string dis = "";
    double cost = 0;

    public:
    medicalrecord() {}
    medicalrecord(string d, double c) : dis(d), cost(c) {}

    void addcost(double amt) {
        cost += amt;
        cout << "\nadded: " << amt << " | total cost: " << cost << "\n";
    }

    double calculatecoverage() {
        return cost * 0.3;
    }

    void displaycost();
    void displaymedical();
};

class insurancepolicy : virtual public person {
    protected:
    int num = 0;
    double prem = 0;

    public:
    insurancepolicy() {}
    insurancepolicy(int n, double p) : num(n), prem(p) {}
    
    double calculatepremium() {
        return prem * 12;
    }

    void displaypolicy();
};

class patient : public medicalrecord, public insurancepolicy {
    public:
    patient() {}
    patient(int i, string n, string d, double c, int nu, double p) : person(i, n), medicalrecord(d, c), insurancepolicy(nu, p) {}

    void displayall();
    friend void comparecosts(patient& x, patient& y);
    friend void generatebill(patient& x);
};

void person::displayperson() {
    cout << "\npatient details:";
    cout << "\npatient id: " << id;
    cout << "\nname: " << name;
}

void medicalrecord::displaycost() {
    cout << "\ntreatment cost :" << cost;
    cout << "\ninsurance coverage: " << calculatecoverage();
    cout << "\nnet payable amount: " << cost - calculatecoverage() << "\n";
}

void medicalrecord::displaymedical() {
    cout << "\ndisease: " << dis;
    cout << "\ntreatment cost: " << cost;
    cout << "\ninsurance coverage: " << calculatecoverage();
}

void insurancepolicy::displaypolicy() {
    cout << "\npolicy no: " << num;
    cout << "\nmonthly premium: " << prem;
    cout << "\nyearly premium: " << calculatepremium() << "\n";
}

void patient::displayall() {
    displayperson();
    displaymedical();
    displaypolicy();
}

void comparecosts(patient& x, patient& y) {
    cout << "\ncosts comparison:";

    if (x.cost > y.cost) {
        cout << "\n" << x.name << " (" << x.cost << ") has higher cost than " << y.name << " (" << y.cost << ")\n";
    } else if (x.cost < y.cost) {
        cout << "\n" << y.name << " (" << y.cost << ") has higher cost than " << x.name << " (" << x.cost << ")\n";
    } else {
        cout << "\n" << x.name << " and " << y.name << " have equal costs (" << x.cost << ")\n";
    }
}

void generatebill(patient& x) {
    cout << "\npatient bill:\n";

    x.displayperson();
    x.displaycost();
}

vector<patient> p;

patient* findpatient(int id) {
    for (auto& x : p) {
        if (x.getid() == id) return &x; 
    }

    return nullptr;
}

int main() {
    p.emplace_back(1150, "ahmed sheikh", "arthritis", 350000, 4460, 3000);
    p.emplace_back(3620, "mishkat alvi", "pneumonia", 190000, 2080, 2000);

    int x;
    while (1) {
        cout << "\nhealthcare menu:";
        cout << "\n1. add patient";
        cout << "\n2. add treatment cost";
        cout << "\n3. display info";
        cout << "\n4. compare costs";
        cout << "\n5. generate bill";
        cout << "\n6. exit";

        cout << "\nenter choice: ";
        cin >> x;

        if (x == 1) {
            cout << "\nenter details:";

            int id;
            cout << "\nenter patient id: ";
            cin >> id;

            if (findpatient(id) != nullptr) {
                cout << "\nnot available\n";
                continue;
            }

            string name;
            cout << "enter name: ";
            cin.ignore();
            getline(cin, name);

            string dis;
            cout << "enter disease: ";
            getline(cin, dis);

            double cost;
            cout << "enter treatment cost: ";
            cin >> cost;

            int num;
            cout << "enter policy no: ";
            cin >> num;

            double prem;
            cout << "enter monthly premium: ";
            cin >> prem;

            p.emplace_back(id, name, dis, cost, num, prem);
            cout << "\npatient added\n";
        } else if (x == 2) {
            int id;
            cout << "\nenter id: ";
            cin >> id;

            patient* ptr = findpatient(id);

            if (ptr == nullptr) {
                cout << "\nnot found\n";
                continue;
            }

            double amt;
            cout << "enter amount: ";
            cin >> amt;

            ptr->addcost(amt);
        } else if (x == 3) {
            int id;
            cout << "\nenter id: ";
            cin >> id;

            patient* ptr = findpatient(id);

            if (ptr == nullptr) {
                cout << "\nnot found\n";
                continue;
            }

            ptr->displayall();
        } else if (x == 4) {
            int id1, id2;
            cout << "\nenter 1st and 2nd id: ";
            cin >> id1 >> id2;

            patient* ptr1 = findpatient(id1);
            patient* ptr2 = findpatient(id2);

            if (ptr1 == nullptr || ptr2 == nullptr) {
                cout << "\nnot found\n";
                continue;
            }

            comparecosts(*ptr1, *ptr2);
        } if (x == 5) {
            int id;
            cout << "\nenter id: ";
            cin >> id;

            patient* ptr = findpatient(id);

            if (ptr == nullptr) {
                cout << "\nnot found\n";
                continue;
            }

            generatebill(*ptr);
        } else if (x == 6) {
            cout << "\nexiting healthcare system\n";
            break;
        }
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class product {
    int id;
    string name;
    double price;
    int stock;
    string msg;
    static int count;

    public:
    product() {}
    
    product(int i, string n, double p, int s) : id(i), name(n), price(p), stock(s) {
        count++;
    }

    void updatestock(int qty) {
        stock += qty;
    }

    void updatestock(string m, int qty) {
        stock += qty;
        msg = m;
    }

    double value() {
        return price * stock;
    }

    static int getcount() {
        return count;
    }

    void display();
};

int product::count;

void product::display() {
    cout << "\nproduct details:";
    cout << "\nid: " << id;
    cout << "\nname: " << name;
    cout << "\nprice: " << price;
    cout << "\nstock: " << stock;
    cout << "\nrestock message: " << msg;
    cout << "\nstock value: " << value() << "\n";
}

int main() {
    product p[20];

    int x;
    while (1) {
        cout << "\n1. add product";
        cout << "\n2. display info";
        cout << "\n3. restock";
        cout << "\n4. total products";
        cout << "\n5. exit";

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

            double price;
            cout << "enter price: ";
            cin >> price;
            
            int stock;
            cout << "enter stock: ";
            cin >> stock;

            int i = product::getcount();
            p[i] = product(id, name, price, stock);
        } else if (x == 2) {
            for (int i = 0; i < product::getcount(); i++){
                p[i].display();
            }
        } else if (x == 3) {
            int i;
            cout << "\nenter index: ";
            cin >> i;

            if (i < 0 || i >= product::getcount()) {
                cout << "\nnot found\n";
            } else {
                int qty;
                cout << "enter qty: ";
                cin >> qty;

                string msg;
                cout << "enter message (0 to skip): ";
                cin.ignore();
                getline(cin, msg);

                if (msg == "0") {
                    p[i].updatestock(qty);
                } else {
                    p[i].updatestock(msg, qty);
                }
            }
        } else if (x == 4) {
            cout << "\ntotal products: " << product::getcount() << "\n";
        } else if (x == 5) break;
    }

    return 0;
}


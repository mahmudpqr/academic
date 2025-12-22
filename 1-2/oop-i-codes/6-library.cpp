#include <iostream>
#include <string>
#include <vector>

using namespace std;

class book {
    int id = 0;
    string title = "";
    string author = "";
    bool avl = 1;
    int days = 0;

    public:
    book() {}
    book(int i, string t, string a) : id(i), title(t), author(a) {}

    bool available() {
        return avl;
    }

    int getdays() {
        return days;
    }

    void issuebook(int d = 14) {
        avl = 0;
        days = d;
    }

    void returnbook() {
        avl = 1;
    }

    void display();
    friend void compare(book& x, book& y);
};

inline void book::display() {
    cout << "\nbook details:";
    cout << "\nid: " << id;
    cout << "\ntitle: " << title;
    cout << "\nauthor: " << author << "\n";
}

void compare(book& x, book& y) {
    x.display();
    y.display();
}

book duplicate(book& x) {
    return x;
}

int main() {
    vector<book> b;

    int x;
    while (1) {
        cout << "\n1. add book";
        cout << "\n2. display info";
        cout << "\n3. availability";
        cout << "\n4. issue";
        cout << "\n5. return";
        cout << "\n6. compare";
        cout << "\n7. duplicate";
        cout << "\n8. exit";

        cout << "\nenter choice: ";
        cin >> x;

        if (x == 1) {
            cout << "\nenter details:";

            int id;
            cout << "\nenter id: ";
            cin >> id;

            string title;
            cout << "enter title: ";
            cin.ignore();
            getline(cin, title);

            string author;
            cout << "enter author: ";
            getline(cin, author);

            b.emplace_back(id, title, author);
        } else if (x == 2) {
            for (auto& x : b) {
                x.display();
            }

        } else if (x == 3) {
            int i;
            cout << "\nenter index: ";
            cin >> i;

            if (i < 0 || i >= b.size()) {
                cout << "\nnot found\n";
            } else {
                if (b[i].available()) {
                    cout << "\navailable\n";
                } else {
                    cout << "\nissued for days: " << b[i].getdays() << "\n";
                }
            }
        } else if (x == 4) {
            int i;
            cout << "\nenter index: ";
            cin >> i;

            if (i < 0 || i >= b.size()) {
                cout << "\nnot found\n";
            } else {
                b[i].issuebook();
            }
        } else if (x == 5) {
            int i;
            cout << "\nenter index: ";
            cin >> i;

            if (i < 0 || i >= b.size()) {
                cout << "\nnot found\n";
            } else {
                b[i].returnbook();
            }
        } else if (x == 6) {
            int i, j;
            cout << "\nenter indices: ";
            cin >> i >> j;

            if (i < 0 || i >= b.size() || j < 0 || j >= b.size()) {
                cout << "\nnot found\n";
            } else {
                compare(b[i], b[j]);
            }
        } else if (x == 7) {
            int i;
            cout << "\nenter index: ";
            cin >> i;

            if (i < 0 || i >= b.size()) {
                cout << "\nnot found\n";
            } else {
                book b1 = duplicate(b[i]);
                b.push_back(b1);
            }
        } else if (x == 8) break;
    }

    return 0;
}
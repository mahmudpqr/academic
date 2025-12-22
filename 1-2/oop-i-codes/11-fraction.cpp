#include <iostream>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void format(int& num, int& den) {
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

class fraction {
    int num = 0, den = 1;

    public:
    fraction() {};
    fraction(int n, int d) : num(n), den(d) {
        int g = gcd(num, den);

        num = num / g;
        den = den / g;
        format(num, den);
    }

    void display() {
        cout << num << "/" << den;
    }

    friend fraction operator+(fraction& a, fraction b);
    friend fraction operator-(fraction& a, fraction b);
    friend fraction operator*(fraction& a, fraction b);
    friend fraction operator/(fraction& a, fraction b);
};

fraction operator+(fraction& a, fraction b) {
    fraction temp;

    temp.den = a.den * b.den;
    temp.num = a.num * b.den + b.num * a.den;
    
    int g = gcd(temp.num, temp.den);

    temp.num = temp.num / g;
    temp.den = temp.den / g;
    format(temp.num, temp.den);

    return temp;
}

fraction operator-(fraction& a, fraction b) {
    fraction temp;

    temp.den = a.den * b.den;
    temp.num = a.num * b.den - b.num * a.den;
    
    int g = gcd(temp.num, temp.den);

    temp.num = temp.num / g;
    temp.den = temp.den / g;
    format(temp.num, temp.den);

    return temp;
}

fraction operator*(fraction& a, fraction b) {
    fraction temp;

    temp.den = a.den * b.den;
    temp.num = a.num * b.num;
    
    int g = gcd(temp.num, temp.den);

    temp.num = temp.num / g;
    temp.den = temp.den / g;
    format(temp.num, temp.den);

    return temp;
}

fraction operator/(fraction& a, fraction b) {
    fraction temp;

    temp.den = a.den * b.num;
    temp.num = a.num * b.den;
    
    int g = gcd(temp.num, temp.den);

    temp.num = temp.num / g;
    temp.den = temp.den / g;
    format(temp.num, temp.den);

    return temp;
}

int main() {
    int x;
    while (1) {
        cout << "\n1. enter";
        cout << "\n2. exit";

        cout << "\nenter choice: ";
        cin >> x;

        if (x == 1) {
            int n1, d1, n2, d2;

            cout << "\nenter f1 (num, den): ";
            cin >> n1 >> d1;
            cout << "enter f2 (num, den): ";
            cin >> n2 >> d2;

            if (d1 == 0 || d2 == 0) {
                cout << "denominator 0";
                continue;
            }

            fraction f1(n1, d1), f2(n2, d2), temp;

            cout << "\nf1 = ";
            f1.display();
            cout << "\nf2 = ";
            f2.display();

            temp = f1 + f2;
            cout << "\nf1 + f2 = ";
            temp.display();
            
            temp = f1 - f2;
            cout << "\nf1 - f2 = ";
            temp.display();

            temp = f1 * f2;
            cout << "\nf1 * f2 = ";
            temp.display();

            temp = f1 / f2;
            cout << "\nf1 / f2 = ";
            temp.display();

            cout << "\n";
        } else if (x == 2) break;
    }

    return 0;
}
#include <iostream>
using namespace std;

int gcd(int x, int y) {
    if (x == y) return x;

    int min;
    if (x < y) {
        min = x;
    } else {
        min = y;
    }

    int g = 1;
    for (int i = 1; i <= min; i++) {
        if (x % i == 0 && y % i ==0) {
            g = i;
        }
    }
    return g;
}

class FRACTION {
    int numerator;
    int denominator;

public:
    FRACTION() {}
    FRACTION (int num, int denom) {
        numerator = num;
        denominator = denom;
    }

    int getNum() {
        return numerator;
    }

    int getDenom() {
        return denominator;
    }

    FRACTION operator+(FRACTION f) {
        FRACTION result;
        result.denominator = this->denominator * f.denominator;
        result.numerator = result.denominator / this->denominator * this->numerator + result.denominator / f.denominator * f.numerator;

        int g = gcd(result.numerator, result.denominator);
        result.numerator = result.numerator / g;
        result.denominator = result. denominator / g;

        if (result.denominator < 0) {
            result.denominator = - result.denominator;
            result.numerator = - result.numerator;
        }

        return result;
    }

    FRACTION operator-(FRACTION f) {
        FRACTION result;
        result.denominator = this->denominator * f.denominator;
        result.numerator = result.denominator / this->denominator * this->numerator - result.denominator / f.denominator * f.numerator;

        int g = gcd(result.numerator, result.denominator);
        result.numerator = result.numerator / g;
        result.denominator = result. denominator / g;

        if (result.denominator < 0) {
            result.denominator = - result.denominator;
            result.numerator = - result.numerator;
        }

        return result;
    }

    FRACTION operator*(FRACTION f) {
        FRACTION result;
        result.denominator = this->denominator * f.denominator;
        result.numerator = this->numerator * f.numerator;

        int g = gcd(result.numerator, result.denominator);
        result.numerator = result.numerator / g;
        result.denominator = result. denominator / g;

        if (result.denominator < 0) {
            result.denominator = - result.denominator;
            result.numerator = - result.numerator;
        }

        return result;
    }

    FRACTION operator/(FRACTION f) {
        FRACTION result;
        result.denominator = this->denominator * f.numerator;
        result.numerator = this->numerator * f.denominator;

        int g = gcd(result.numerator, result.denominator);
        result.numerator = result.numerator / g;
        result.denominator = result. denominator / g;

        if (result.denominator < 0) {
            result.denominator = - result.denominator;
            result.numerator = - result.numerator;
        }

        return result;
    }
};

int main() {
    int x1, y1;
    cout << "\nEnter numerator and denominator of f1: ";
    cin >> x1 >> y1;
    if (y1 == 0) {
        cout << "\nDenominator cannot be zero!\n\n";
        return 1;
    }

    int x2, y2;
    cout << "\nEnter numerator and denominator of f2: ";
    cin >> x2 >> y2;
    if (y2 == 0) {
        cout << "\nDenominator cannot be zero!\n\n";
        return 1;
    }

    FRACTION f1(x1, y1), f2(x2,y2);

    FRACTION a = f1 + f2;
    FRACTION b = f1 - f2;
    FRACTION c = f1 * f2;
    FRACTION d = f1 / f2;

    cout << "\nf1 = " << f1.getNum() << " / " << f1.getDenom();
    cout << "\nf2 = " << f2.getNum() << " / " << f2.getDenom();

    cout << "\n\nf1 + f2 = " << a.getNum() << " / " << a.getDenom();
    cout << "\nf1 - f2 = " << b.getNum() << " / " << b.getDenom();
    cout << "\nf1 * f2 = " << c.getNum() << " / " << c.getDenom();
    cout << "\nf1 / f2 = " << d.getNum() << " / " << d.getDenom() << "\n\n";

    return 0;
}

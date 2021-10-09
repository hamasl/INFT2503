#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

/// Funksjon for å skrive ut en brøk. friend av klassen Fraction.
ostream &operator<<(ostream &out, const Fraction &fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

void print(const string &text, const Fraction &broek) {
    cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;

    print("a = ", a);
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    b += a;
    ++c;
    d *= d;

    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    c = a + b - d * a;
    c = -c;

    print("c = ", c);

    if (a + b != c + d)
        cout << "a + b != c + d" << endl;
    else
        cout << " a + b == c + d" << endl;
    while (b > a)
        b -= a;
    print("b = ", b);

    Fraction fraction1(10,20);
    print("fraction1 = ", fraction1);
    print("5 - fraction1 = ", 5 - fraction1);
    print("fraction1 - 5 = ", fraction1 - 5);

    return 0;
}

// Utskrift:
// a = 1 / 2
// b = 3 / 4
// c = 5 / 1
// d = 2 / 3
// b = 5 / 4
// c = 6 / 1
// d = 4 / 9
// c = -55 / 36
// a + b != c + d
// b = 1 / 4

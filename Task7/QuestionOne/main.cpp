#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

/// Funksjon for å skrive ut en brøk. friend av klassen Fraction.
ostream &operator<<(ostream &out, const Fraction &fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

int main() {
    Fraction fraction(10, 20);
    cout << "5 - fraction = " << 5 - fraction << endl;
    cout << "fraction - 5 = " << fraction - 5 << endl;
}

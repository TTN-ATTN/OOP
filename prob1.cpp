#include <bits/stdc++.h>
using namespace std;

int n, d;

/**
 * Simplifies the fraction by dividing both the n and d by their greatest common divisor (gcd).
 * Input: None
 * Output: Simplified fraction by modifying the n and d.
 */
void Simplify() {
    int gcd = __gcd(abs(n), abs(d));
    n /= gcd;
    d /= gcd;
}

/**
 * Prints the fraction in the simplest form.
 * Input: None
 * Output: Displays the fraction or integer.
 */
void Print() {
    if (n % d == 0) {
        cout << n / d << endl;
    } else {
        cout << n << "/" << d << endl;
    }
    cout << endl;
}


int main() {
    cout << "Enter the numerator: ";
    cin >> n;
    cout << "Enter the denominator: ";
    cin >> d;

    while(d == 0) {
        cout << "Denominator cannot be zero!";
        cout << "\nEnter the denominator: ";
        cin >> d;
    }

    if(d < 0) {
        n = -n;
        d = -d;
    }

    cout << "Fraction: ";
    Simplify();
    Print();

    return 0;
}

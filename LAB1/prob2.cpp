#include <bits/stdc++.h>
using namespace std;

/**
 * Simplifies the fraction by dividing both the n and d by their greatest common divisor (gcd).
 * Input: n, d - integer
 * Output: None
 */
void Simplify(int &n, int &d) {
    if (d < 0) {
        n = -n;
        d = -d;
    }
    int gcd = __gcd(abs(n), abs(d));
    n /= gcd;
    d /= gcd;
}

/**
 * Prints the fraction in the simplest form.
 * Input: n, d - integer
 * Output: Displays the fraction or integer.
 */
void Print(int n, int d) {
    if (n % d == 0) {
        cout << n / d << endl;
    } else {
        cout << n << "/" << d << endl;
    }
}

/**
 * Check if d is zero
 * Input: d - integer;
 * Output: error if d is zero
 */

int main() {
    int n1, d1, n2, d2;
    cout << "Enter numerator 1: ";
    cin >> n1;
    cout << "Enter denominator 1: ";
    cin >> d1;
    while (d1 == 0) {
        cout << "Invalid denominator!\nEnter denominator 1:";
        cin >> d1;
    }

    cout << "Enter numerator 2: ";
    cin >> n2;
    cout << "Enter denominator 2: ";
    cin >> d2;
    while (d2 == 0) {
        cout << "Invalid denominator!\nEnter denominator 2: ";
        cin >> d2;
    }

    Simplify(n1, d1);
    Simplify(n2, d2);
    cout << "Two fractions are: \n";
    Print(n1, d1);
    Print(n2, d2);
    cout << endl;
    if (n1 * d2 == n2 * d1) {
        cout << "Two fractions are equal." << endl;
    } else if (n1 * d2 > n2 * d1) {
        cout << "The greater fraction is: ";
        Print(n1, d1);
    } else {
        cout << "The greater fraction is: ";
        Print(n2, d2);
    }
    return 0;
}

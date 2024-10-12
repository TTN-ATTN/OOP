#include <bits/stdc++.h>
using namespace std;

/**
 * Simplifies the fraction by dividing both the n and d by their greatest common divisor (gcd).
 * Input: n, d - integer
 * Output: None
 */
void Simplify(int &n, int &d) {
    if(d < 0) {
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
void Check(int d) {
    if(d == 0) {
        cout << "Denominator cannot be zero!";
        exit(1);
    }
}

/**
 * Calculate the sum of two fractions
 * Input: n1,d1,n2,d2 - integer
 * Output: The fraction sum
 */
void Sum(int n1, int d1, int n2, int d2) {
    int n = n1*d2+n2*d1;
    int d = d1*d2;
    Simplify(n,d);
    cout << "Sum of two fractions: ";
    Print(n,d);
}

/**
 * Calculate the difference of two fractions
 * Input: n1,d1,n2,d2 - int
 * Output: The fraction difference
 */
void Difference(int n1, int d1, int n2, int d2) {
    int n = n1*d2-n2*d1;
    int d = d1*d2;
    Simplify(n,d);
    cout << "Difference of two fraction: ";
    Print(n,d);
}

/**
 * Calculate the product of two fractions
 * Input: n1,d1,n2,d2 - integer
 * Output: The fraction product
 */
void Product(int n1, int d1, int n2, int d2) {
    int n = n1*n2;
    int d = d1*d2;
    Simplify(n,d);
    cout << "Product of two fractions: ";
    Print(n,d);
}

/**
 * Calculate the quotation of two fractions
 * Input: n1,d1,n2,d2 - integer
 * Output: The fraction quotation
 */
void Quotation(int n1, int d1, int n2, int d2) {
    if(n2 == 0) {
        cout << "Divisor cannot be zero";
        exit(1);
    }
    int n = n1*d2;
    int d = n2*d1;
    Simplify(n,d);
    cout << "Quotation of two fractions: ";
    Print(n,d);
}

int main() {
    int n1, d1, n2, d2;
    cout << "Enter numerator 1: ";
    cin >> n1;
    cout << "Enter denominator 1: ";
    cin >> d1;
    while(d1 == 0) {
        cout << "Invalid denominator!\nEnter denominator 1:";
        cin >> d1;
    }
    cout << "Enter numerator 2: ";
    cin >> n2;
    cout << "Enter denominator 2: ";
    cin >> d2;
    while(d2 == 0) {
        cout << "Invalid denominator!\nEnter denominator 2: ";
        cin >> d2;
    }

    Simplify(n1,d1);
    Simplify(n2,d2);

    cout << "Two fractions are: \n";
    Print(n1, d1);
    Print(n2, d2);
    cout << endl;

    Sum(n1,d1,n2,d2);
    Difference(n1,d1,n2,d2);
    Product(n1,d1,n2,d2);
    Quotation(n1,d1,n2,d2);
    return 0;
}

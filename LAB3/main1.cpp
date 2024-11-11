#include <iostream>
#include "PhanSo.h"
using namespace std;

/**
 * Prints the result of a fraction operation.
 * @param c The operation symbol.
 * @param p1 The first fraction.
 * @param p2 The second fraction.
 * @param result The result of the operation.
 */
void Print(string c, PhanSo p1, PhanSo p2, PhanSo result) {
    cout << p1 << " " << c << " " << p2 << " = " << result << endl;
}

/**
 * Prints the result of a fraction comparison.
 * @param c The comparison symbol.
 * @param p1 The first fraction.
 * @param p2 The second fraction.
 * @param result The result of the comparison.
 */
void Print(string c, PhanSo p1, PhanSo p2, bool result) {
    cout << p1 << " " << c << " " << p2 << " = " << (result ? "True" : "False") << endl;
}

int main() {
    PhanSo ps1, ps2;
    cout << "Enter the first fraction: ";
    cin >> ps1;
    cout << "Enter the second fraction: ";
    cin >> ps2;

    bool eq = ps1 == ps2;
    Print("==", ps1, ps2, eq);

    bool neq = ps1 != ps2;
    Print("!=", ps1, ps2, neq);

    bool gt = ps1 > ps2;
    Print(">", ps1, ps2, gt);

    bool ge = ps1 >= ps2;
    Print(">=", ps1, ps2, ge);

    bool lt = ps1 < ps2;
    Print("<", ps1, ps2, lt);

    bool le = ps1 <= ps2;
    Print("<=", ps1, ps2, le);

    PhanSo sum = ps1 + ps2;
    Print("+", ps1, ps2, sum);

    PhanSo diff = ps1 - ps2;
    Print("-", ps1, ps2, diff);

    PhanSo prod = ps1 * ps2;
    Print("*", ps1, ps2, prod);

    PhanSo quot = ps1 / ps2;
    Print("/", ps1, ps2, quot);

    return 0;
}
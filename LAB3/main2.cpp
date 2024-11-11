#include <iostream>
#include "SoPhuc.h"
using namespace std;

/**
 * Prints the result of a complex number operation.
 * @param c The operation symbol.
 * @param sp1 The first complex number.
 * @param sp2 The second complex number.
 * @param result The result of the operation.
 */
void Print(string c, SoPhuc sp1, SoPhuc sp2, SoPhuc result) {
    cout << "("<< sp1 << ") " << c << " (" << sp2 << ") = " << result << endl;
}

/**
 * Prints the result of a complex number comparison.
 * @param c The comparison symbol.
 * @param sp1 The first complex number.
 * @param sp2 The second complex number.
 * @param result The result of the comparison.
 */
void Print(string c, SoPhuc sp1, SoPhuc sp2, bool result) {
    cout << "(" << sp1 << ") " << c << " (" << sp2 << ") = " << (result ? "True" : "False") << endl;
}

int main() {
    SoPhuc sp1, sp2;
    cout << "Nhap so phuc 1: ";
    cin >> sp1;
    cout << "Nhap so phuc 2: ";
    cin >> sp2;

    SoPhuc sum = sp1 + sp2;
    Print("+", sp1, sp2, sum);

    SoPhuc diff = sp1 - sp2;
    Print("-", sp1, sp2, diff);

    SoPhuc prod = sp1 * sp2;
    Print("*", sp1, sp2, prod);

    SoPhuc quot;
    try {
        quot = sp1 / sp2;
        Print("/", sp1, sp2, quot);
    } catch (const std::invalid_argument& e) {
        cerr << e.what() << endl;
    }

    bool eq = sp1 == sp2;
    Print("==", sp1, sp2, eq);

    bool neq = sp1 != sp2;
    Print("!=", sp1, sp2, neq);

    return 0;
}
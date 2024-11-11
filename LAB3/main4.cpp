#include <iostream>
#include "NgayThangNam.h"
using namespace std;

int main() {
    NgayThangNam nt1, nt2;
    cout << "Nhap ngay thang nam 1 (dd/mm/yyyy): ";
    cin >> nt1;

    cout << "Nhap ngay thang nam 2 (dd/mm/yyyy): ";
    cin >> nt2;

    cout << "Nhap so ngay de tinh toan: ";
    int n;
    cin >> n;

    cout << nt1 << " + " << n << " = " << nt1 + n << endl;

    cout << nt1 << " - " << n << " = " << nt1 - n << endl;

    cout << nt2 << " + " << n << " = " << nt2 + n << endl;

    cout << nt2 << " - " << n << " = " << nt2 - n << endl;

    cout << "Khoang cach giua 2 ngay: " << abs(nt1 - nt2) << " ngay\n";

    cout <<  nt1 << "++ = ";
    ++nt1;
    cout << nt1 << endl;

    cout << nt1 << "-- = ";
    --nt1;
    cout << nt1 << endl;

    bool eq = nt1 == nt2;
    cout << "nt1 == nt2: " << (eq ? "True" : "False") << endl;

    bool neq = nt1 != nt2;
    cout << "nt1 != nt2: " << (neq ? "True" : "False") << endl;

    bool gt = nt1 > nt2;
    cout << "nt1 > nt2: " << (gt ? "True" : "False") << endl;

    bool ge = nt1 >= nt2;
    cout << "nt1 >= nt2: " << (ge ? "True" : "False") << endl;

    bool lt = nt1 < nt2;
    cout << "nt1 < nt2: " << (lt ? "True" : "False") << endl;

    bool le = nt1 <= nt2;
    cout << "nt1 <= nt2: " << (le ? "True" : "False") << endl;

    return 0;
}
#include <bits/stdc++.h>
#include "ThoiGian.h"
using namespace std;

int main() {
    ThoiGian tg1, tg2;
    cout << "Nhap thoi gian thu nhat: ";
    cin >> tg1;
    cout << "Nhap thoi gian thu hai: ";
    cin >> tg2;

    cout << "Nhap so giay de tinh toan: ";
    int n;
    cin >> n;

    cout << tg1 << " + " << tg2 << " = ";
    ThoiGian sum = tg1 + tg2;
    cout << sum << endl;

    cout << tg1 << " - " << tg2 << " = ";
    ThoiGian diff = tg1 - tg2;
    cout << diff << endl;

    cout << tg1 << " + " << n << " = ";
    ThoiGian add = tg1 + n;
    cout << add << endl;

    cout << tg1 << " - " << n << " = ";
    ThoiGian sub = tg1 - n;
    cout << sub << endl;

    cout << "++" << tg1 << " = ";
    ++tg1;
    cout << tg1 << endl;

    cout << "--" << tg1 << " = ";
    --tg1;
    cout << tg1 << endl;

    bool eq = tg1 == tg2;
    cout << "tg1 == tg2: " << (eq ? "True" : "False") << endl;

    bool neq = tg1 != tg2;
    cout << "tg1 != tg2: " << (neq ? "True" : "False") << endl;

    bool gt = tg1 > tg2;
    cout << "tg1 > tg2: " << (gt ? "True" : "False") << endl;

    bool ge = tg1 >= tg2;
    cout << "tg1 >= tg2: " << (ge ? "True" : "False") << endl;

    bool lt = tg1 < tg2;
    cout << "tg1 < tg2: " << (lt ? "True" : "False") << endl;

    bool le = tg1 <= tg2;
    cout << "tg1 <= tg2: " << (le ? "True" : "False") << endl;

    return 0;
}
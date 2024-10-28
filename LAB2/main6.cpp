#include <iostream>
#include "Tamgiac.h"

using namespace std;

int main() {
    Tamgiac tg;
    tg.Nhap2();

    float goc, doDai;
    cin >> goc >> doDai;

    tg.TinhTien(goc, doDai);
    tg.Xuat2();

    return 0;
}
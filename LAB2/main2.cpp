#include <iostream>
#include "Tamgiac.h"

using namespace std;

int main() {
    Tamgiac tg;
    tg.Nhap();
    tg.Xuat();

    cout << "Tinh tien tam giac (dx=2, dy=3):" << endl;
    tg.TinhTien(2, 3);
    tg.Xuat();

    cout << "Phong to tam giac (k=2):" << endl;
    tg.PhongTo(2);
    tg.Xuat();

    cout << "Thu nho tam giac (k=2):" << endl;
    tg.ThuNho(2);
    tg.Xuat();

    cout << "Quay tam giac (goc=45 do):" << endl;
    tg.Quay(45);
    tg.Xuat();

    return 0;
}
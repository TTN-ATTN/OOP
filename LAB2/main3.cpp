#include <iostream>
#include "Dagiac.h"

using namespace std;

int main() {
    Dagiac dg;
    dg.Nhap();
    dg.Xuat();

    cout << "Tinh tien da giac (dx=2, dy=3):" << endl;
    dg.TinhTien(2, 3);
    dg.Xuat();

    cout << "Phong to da giac (k=2):" << endl;
    dg.PhongTo(2);
    dg.Xuat();

    cout << "Thu nho da giac (k=2):" << endl;
    dg.ThuNho(2);
    dg.Xuat();

    cout << "Quay da giac (goc=45 do):" << endl;
    dg.Quay(45);
    dg.Xuat();

    return 0;
}
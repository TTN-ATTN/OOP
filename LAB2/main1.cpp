#include <bits/stdc++.h>
#include "Diem.h"
using namespace std;

int main() {
    Diem A(1, 2);
    cout << "Diem ban dau: ";
    A.Xuat();
    A.TinhTien(3, 4);
    cout << "Diem sau khi tinh tien: ";
    A.Xuat();
    cout << "Hoanh do: " << A.GetHoanhDo() << endl;
    cout << "Tung do: " << A.GetTungDo() << endl;
    A.SetHoanhDo(5);
    A.SetTungDo(6);
    cout << "Diem sau khi set hoanh do va tung do: ";
    A.Xuat();
    return 0;
}
#include <iostream>
#include "Thisinh.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;

    Thisinh* ds = new Thisinh[n];

    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin thi sinh thu " << i + 1 << ":" << endl;
        ds[i].Nhap();
    }

    cout << "\nDanh sach thi sinh co tong diem > 15:" << endl;
    for (int i = 0; i < n; ++i) {
        if (ds[i].Tong() > 15) {
            ds[i].Xuat();
            cout << endl;
        }
    }

    float maxScore = 0;
    int maxIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (ds[i].Tong() > maxScore) {
            maxScore = ds[i].Tong();
            maxIndex = i;
        }
    }

    if (maxIndex != -1) {
        cout << "Thi sinh co tong diem cao nhat:" << endl;
        ds[maxIndex].Xuat();
        if (ds[maxIndex].getMSSV() == "23521090") {
            cout << "Thi sinh co diem cao nhat co MSSV la ban." << endl;
        }
    }

    delete[] ds;
    return 0;
}
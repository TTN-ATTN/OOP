#include <iostream>
#include "Diem.h"

using namespace std;

int main() {
    float hoanh, tung;
    cin >> hoanh >> tung;

    Diem point(hoanh, tung);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x == 1) {
            point.SetHoanhDo(point.GetHoanhDo() * 2);
            point.SetTungDo(point.GetTungDo() * 2);
        } else if (x == 2) {
            point.SetHoanhDo(0);
            point.SetTungDo(0);
        } else if (x == 3) {
            int k, d;
            cin >> k >> d;
            if (k == 0) {
                point.TinhTien(d, 0);
            } else {
                point.TinhTien(0, d);
            }
        }
    }

    point.Xuat();

    return 0;
}
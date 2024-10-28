#include <iostream>
#include "Dagiac.h"

using namespace std;

int main() {
    Dagiac polygon;
    polygon.Nhap2();
    cout << polygon.DienTich() << endl;
    return 0;
}
#include "phong.h"
#include <iostream>
using namespace std;
int main(){
    Deluxe d1, d2;
    Premium p1, p2;
    Business b1;

    d1.Nhap();
    d2.Nhap();
    p1.Nhap();
    p2.Nhap();
    b1.Nhap();

    int doanhThuMax = 0;
    Phong *phongMax = nullptr;
    Phong *phong[5] = {&d1, &d2, &p1, &p2, &b1};

    for(int i = 0; i < 5; i++){
        phong[i]->TinhDoanhThu();
        if(phong[i]->getDoanhThu() > doanhThuMax){
            doanhThuMax = phong[i]->getDoanhThu();
            phongMax = phong[i];
        }
    }

    cout << "Phong co doanh thu lon nhat: \n";
    phongMax->Xuat();
}
#ifndef DAGIAC_H
#define DAGIAC_H

#include "Diem.h"

class Dagiac {
private:
    int n;
    Diem *Dinh;

public:
    Dagiac();
    ~Dagiac();

    void Nhap();
    void Nhap2();
    void Xuat();
    void TinhTien(int dX, int dY);
    void PhongTo(float k);
    void ThuNho(float k);
    void Quay(float goc);
    float DienTich();
};

#endif //DAGIAC_H
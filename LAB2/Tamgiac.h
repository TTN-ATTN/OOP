#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h"

class Tamgiac {
private:
    Diem A, B, C;

public:
    void Nhap();
    void Nhap2();
    void Xuat();
    void Xuat2();
    void TinhTien(int dX, int dY);
    void TinhTien(float goc, float doDai);
    void PhongTo(float k);
    void ThuNho(float k);
    void Quay(float goc);
};

#endif //TAMGIAC_H
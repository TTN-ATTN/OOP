#ifndef THISINH_H
#define THISINH_H

#include <string>

class Thisinh {
private:
    std::string Ten;
    std::string MSSV;
    int iNgay, iThang, iNam;
    float fToan, fVan, fAnh;

public:
    void Nhap();
    void Xuat();
    float Tong();
    std::string getMSSV();
};

#endif // THISINH_H
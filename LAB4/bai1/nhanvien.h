#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <string>

using namespace std;

class NhanVien {
private:
    string maNV;
    string hoTen;
    int luongCoBan;
public:
    NhanVien(string maNV = "", string hoTen = "", int luongCoBan = 0) : maNV(maNV), hoTen(hoTen), luongCoBan(luongCoBan) {}
    virtual void Nhap();
    virtual void Xuat();
    int getLuongCoBan();
    string getMaNV();
    string getHoTen();
    virtual int TienThuong() = 0;
};

class QuanLy : public NhanVien {
private:
    int tiLeThuong;
public:
    QuanLy(string maNV = "", string hoTen = "", int luongCoBan = 0, int tiLeThuong = 0) : NhanVien(maNV, hoTen, luongCoBan), tiLeThuong(tiLeThuong) {}
    void Nhap();
    void Xuat();
    int TienThuong();
};

class KySu : public NhanVien {
private:
    int soGioLamThem;
public:
    KySu(string maNV = "", string hoTen = "", int luongCoBan = 0, int soGioLamThem = 0) : NhanVien(maNV, hoTen, luongCoBan), soGioLamThem(soGioLamThem) {}
    void Nhap();
    void Xuat();
    int TienThuong();
};

#endif // NHANVIEN_H
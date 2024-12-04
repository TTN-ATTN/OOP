#include "nhanvien.h"
#include <iostream>

using namespace std;

void NhanVien::Nhap() {
    cout << "Nhap ma nhan vien: ";
    cin >> maNV;
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
}

int NhanVien::getLuongCoBan() {
    return luongCoBan;
}

string NhanVien::getMaNV() {
    return maNV;
}

string NhanVien::getHoTen() {
    return hoTen;
}

void NhanVien::Xuat() {
    cout << "Ma nhan vien: " << getMaNV() << endl;
    cout << "Ho ten: " << getHoTen() << endl;
    cout << "Luong co ban: " << getLuongCoBan() << endl;
}

void QuanLy::Nhap() {
    cout << "Nhap thong tin quan ly: \n" ;
    NhanVien::Nhap();
    cout << "Nhap ti le thuong: ";
    cin >> tiLeThuong;
    cout << endl;
}

void QuanLy::Xuat() {
    cout << "Thong tin quan ly: \n";
    NhanVien::Xuat();
    cout << "Tien thuong: " << TienThuong() << "\n\n";
}

int QuanLy::TienThuong() {
    return (getLuongCoBan() * tiLeThuong) / 100;
}

void KySu::Nhap() {
    cout << "Nhap thong tin ky su: \n";
    NhanVien::Nhap();
    cout << "Nhap so gio lam them: ";
    cin >> soGioLamThem;
    cout << endl;
}

void KySu::Xuat() {
    cout << "Thong tin ky su: \n";
    NhanVien::Xuat();
    cout << "Tien thuong: " << TienThuong() << "\n\n";
}

int KySu::TienThuong() {
    return soGioLamThem * 100000;
}
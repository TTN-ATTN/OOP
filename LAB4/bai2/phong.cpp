#include "phong.h"
#include <iostream>

using namespace std;

void Business::TinhDoanhThu() {
    doanhThu = getSoDem() * 300000;
}

void Premium::TinhDoanhThu() {
    doanhThu = getSoDem() * 500000 + getPhiDichVu();
}

void Deluxe::TinhDoanhThu() {
    doanhThu = getSoDem() * 750000 + getPhiDichVu() + getPhiPhucVu();
}

void Business::Nhap() {
    cout << "Nhap thong tin phong Business: \n";
    cout << "Nhap ma phong: ";
    cin >> maPhong;
    cout << "Nhap so dem: ";
    cin >> soDem;
    cout << endl;
}

void Business::Xuat() {
    cout << "Phong Business\n";
    cout << "Ma phong: " << getMaPhong();
    cout << "\nSo dem: " << getSoDem() << "\nDoanh thu: " << getDoanhThu() << "\n\n";
}

void Premium::Nhap() {
    cout << "Nhap thong tin phong Premium: \n";
    cout << "Nhap ma phong: ";
    cin >> maPhong;
    cout << "Nhap so dem: ";
    cin >> soDem;
    cout << "Nhap phi dich vu: ";
    cin >> phiDichVu;
    cout << endl;
}

void Premium::Xuat() {
    cout << "Phong Premium \n";
    cout << "Ma phong: " << getMaPhong();
    cout << "\nSo dem: " << getSoDem() << "\nPhi dich vu: " << getPhiDichVu() << "\nDoanh thu: " << getDoanhThu() << "\n\n";
}

void Deluxe::Nhap() {
    cout << "Nhap thong tin phong Deluxe: \n";
    cout << "Nhap ma phong: ";
    cin >> maPhong;
    cout << "Nhap so dem: ";
    cin >> soDem;
    cout << "Nhap phi dich vu: ";
    cin >> phiDichVu;
    cout << "Nhap phi phuc vu: ";
    cin >> phiPhucVu;
    cout << endl;
}

void Deluxe::Xuat() {
    cout << "Phong Deluxe\n";
    cout << "Ma phong: " << getMaPhong();
    cout << "\nSo dem: " << getSoDem() << "\nPhi dich vu: " << getPhiDichVu() << "\nPhi phuc vu: " << getPhiPhucVu() << ", Doanh thu: " << getDoanhThu() << "\n\n";
}
#include "Tamgiac.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Prompts the user to input the coordinates of the vertices A, B, and C.
 */
void Tamgiac::Nhap() {
    int x, y;
    cout << "Nhap toa do dinh A: ";
    cin >> x >> y;
    A = Diem(x, y);

    cout << "Nhap toa do dinh B: ";
    cin >> x >> y;
    B = Diem(x, y);

    cout << "Nhap toa do dinh C: ";
    cin >> x >> y;
    C = Diem(x, y);
}

/**
 * Reads the coordinates of the vertices A, B, and C from the input.
 */
void Tamgiac::Nhap2() {
    float x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    A = Diem(x1, y1);
    B = Diem(x2, y2);
    C = Diem(x3, y3);
}

/**
 * Prints the coordinates of the vertices A, B, and C.
 */
void Tamgiac::Xuat() {
    cout << "Dinh A: ";
    A.Xuat();
    cout << "Dinh B: ";
    B.Xuat();
    cout << "Dinh C: ";
    C.Xuat();
}

/**
 * Prints the coordinates of the vertices A, B, and C without labels.
 */
void Tamgiac::Xuat2() {
    A.Xuat();
    B.Xuat();
    C.Xuat();
}

/**
 * Translates the triangle by a given distance in x and y directions.
 * @param dX - The distance to move in the x direction.
 * @param dY - The distance to move in the y direction.
 */
void Tamgiac::TinhTien(int dX, int dY) {
    A.TinhTien(dX, dY);
    B.TinhTien(dX, dY);
    C.TinhTien(dX, dY);
}

/**
 * Translates the triangle by a given distance and angle.
 * @param goc - The angle in degrees.
 * @param doDai - The distance to move.
 */
void Tamgiac::TinhTien(float goc, float doDai) {
    A.TinhTien(goc, doDai);
    B.TinhTien(goc, doDai);
    C.TinhTien(goc, doDai);
}

/**
 * Scales the triangle by a given factor with respect to the origin (0,0).
 * @param k - The scaling factor.
 */
void Tamgiac::PhongTo(float k) {
    A.SetHoanhDo(A.GetHoanhDo() * k);
    A.SetTungDo(A.GetTungDo() * k);
    B.SetHoanhDo(B.GetHoanhDo() * k);
    B.SetTungDo(B.GetTungDo() * k);
    C.SetHoanhDo(C.GetHoanhDo() * k);
    C.SetTungDo(C.GetTungDo() * k);
}

/**
 * Shrinks the triangle by a given factor with respect to the origin (0,0).
 * @param k - The shrinking factor.
 */
void Tamgiac::ThuNho(float k) {
    A.SetHoanhDo(A.GetHoanhDo() / k);
    A.SetTungDo(A.GetTungDo() / k);
    B.SetHoanhDo(B.GetHoanhDo() / k);
    B.SetTungDo(B.GetTungDo() / k);
    C.SetHoanhDo(C.GetHoanhDo() / k);
    C.SetTungDo(C.GetTungDo() / k);
}

/**
 * Rotates the triangle by a given angle around the origin (0,0).
 * @param goc - The angle in degrees.
 */
void Tamgiac::Quay(float goc) {
    float rad = goc * M_PI / 180;
    int x, y;

    x = A.GetHoanhDo() * cos(rad) - A.GetTungDo() * sin(rad);
    y = A.GetHoanhDo() * sin(rad) + A.GetTungDo() * cos(rad);
    A.SetHoanhDo(x);
    A.SetTungDo(y);

    x = B.GetHoanhDo() * cos(rad) - B.GetTungDo() * sin(rad);
    y = B.GetHoanhDo() * sin(rad) + B.GetTungDo() * cos(rad);
    B.SetHoanhDo(x);
    B.SetTungDo(y);

    x = C.GetHoanhDo() * cos(rad) - C.GetTungDo() * sin(rad);
    y = C.GetHoanhDo() * sin(rad) + C.GetTungDo() * cos(rad);
    C.SetHoanhDo(x);
    C.SetTungDo(y);
}
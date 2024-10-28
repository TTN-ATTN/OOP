#include "Dagiac.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Default constructor for Dagiac class.
 * Initializes n to 0 and Dinh to nullptr.
 */
Dagiac::Dagiac() : n(0), Dinh(nullptr) {}

/**
 * Destructor for Dagiac class.
 * Deletes the dynamically allocated array of vertices.
 */
Dagiac::~Dagiac() {
    delete[] Dinh;
}

/**
 * Prompts the user to input the number of vertices and their coordinates.
 */
void Dagiac::Nhap() {
    cout << "Nhap so dinh cua da giac: ";
    cin >> n;
    Dinh = new Diem[n];
    for (int i = 0; i < n; ++i) {
        int x, y;
        cout << "Nhap toa do dinh " << i + 1 << ": ";
        cin >> x >> y;
        Dinh[i] = Diem(x, y);
    }
}

/**
 * Reads the number of vertices and their coordinates from the input.
 */
void Dagiac::Nhap2() {
    cin >> n;
    Dinh = new Diem[n];
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        Dinh[i] = Diem(x, y);
    }
}

/**
 * Prints the coordinates of the vertices.
 */
void Dagiac::Xuat() {
    for (int i = 0; i < n; ++i) {
        cout << "Dinh " << i + 1 << ": ";
        Dinh[i].Xuat();
    }
}

/**
 * Translates the polygon by a given distance in x and y directions.
 * @param dX - The distance to move in the x direction.
 * @param dY - The distance to move in the y direction.
 */
void Dagiac::TinhTien(int dX, int dY) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].TinhTien(dX, dY);
    }
}

/**
 * Scales the polygon by a given factor with respect to the origin (0,0).
 * @param k - The scaling factor.
 */
void Dagiac::PhongTo(float k) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() * k);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() * k);
    }
}

/**
 * Shrinks the polygon by a given factor with respect to the origin (0,0).
 * @param k - The shrinking factor.
 */
void Dagiac::ThuNho(float k) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() / k);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() / k);
    }
}

/**
 * Rotates the polygon by a given angle around the origin (0,0).
 * @param goc - The angle in degrees.
 */
void Dagiac::Quay(float goc) {
    float rad = goc * M_PI / 180;
    for (int i = 0; i < n; ++i) {
        int x = Dinh[i].GetHoanhDo() * cos(rad) - Dinh[i].GetTungDo() * sin(rad);
        int y = Dinh[i].GetHoanhDo() * sin(rad) + Dinh[i].GetTungDo() * cos(rad);
        Dinh[i].SetHoanhDo(x);
        Dinh[i].SetTungDo(y);
    }
}

/**
 * Calculates the area of the polygon using the Shoelace formula.
 * @return The area of the polygon.
 */
float Dagiac::DienTich() {
    float area = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += Dinh[i].GetHoanhDo() * Dinh[j].GetTungDo();
        area -= Dinh[j].GetHoanhDo() * Dinh[i].GetTungDo();
    }
    return fabs(area) / 2.0;
}
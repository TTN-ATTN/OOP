#include <cmath>
#include <iostream>
#include "Diem.h"
using namespace std;

/**
 * Default constructor for Diem class.
 * Initializes iHoanh and iTung to 0.
 */
Diem::Diem() {
    iHoanh = 0;
    iTung = 0;
}

/**
 * Parameterized constructor for Diem class.
 * @param Hoanh - The x-coordinate.
 * @param Tung - The y-coordinate.
 */
Diem::Diem(float Hoanh, float Tung) {
    iHoanh = Hoanh;
    iTung = Tung;
}

/**
 * Copy constructor for Diem class.
 * @param x - The Diem object to copy from.
 */
Diem::Diem(const Diem &x) {
    iHoanh = x.iHoanh;
    iTung = x.iTung;
}

/**
 * Gets the y-coordinate (Tung Do).
 * @return The y-coordinate.
 */
float Diem::GetTungDo() {
    return iTung;
}

/**
 * Gets the x-coordinate (Hoanh Do).
 * @return The x-coordinate.
 */
float Diem::GetHoanhDo() {
    return iHoanh;
}

/**
 * Sets the y-coordinate (Tung Do).
 * @param Tung - The new y-coordinate.
 */
void Diem::SetTungDo(int Tung) {
    iTung = Tung;
}

/**
 * Sets the x-coordinate (Hoanh Do).
 * @param Hoanh - The new x-coordinate.
 */
void Diem::SetHoanhDo(int Hoanh) {
    iHoanh = Hoanh;
}

/**
 * Prints the coordinates of the point.
 */
void Diem::Xuat() {
    cout << "(" << iHoanh << ", " << iTung << ")" << endl;
}

/**
 * Translates the point by a given distance in x and y directions.
 * @param dX - The distance to move in the x direction.
 * @param dY - The distance to move in the y direction.
 */
void Diem::TinhTien(int dX, int dY) {
    iHoanh += dX;
    iTung += dY;
}

/**
 * Translates the point by a given distance and angle.
 * @param goc - The angle in degrees.
 * @param doDai - The distance to move.
 */
void Diem::TinhTien(float goc, float doDai) {
    float rad = goc * 3.14 / 180.0;
    iHoanh += doDai * cos(rad);
    iTung += doDai * sin(rad);
}
#include "Thisinh.h"
#include <iostream>

using namespace std;

/**
 * Prompts the user to input the details of the student.
 * This includes name, student ID (MSSV), date of birth, and scores for Math, Literature, and English.
 */
void Thisinh::Nhap() {
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, Ten);
    cout << "Nhap MSSV: ";
    cin >> MSSV;
    cout << "Nhap ngay sinh (ngay thang nam): ";
    cin >> iNgay >> iThang >> iNam;
    cout << "Nhap diem Toan: ";
    cin >> fToan;
    cout << "Nhap diem Van: ";
    cin >> fVan;
    cout << "Nhap diem Anh: ";
    cin >> fAnh;
}

/**
 * Prints the details of the student.
 * This includes name, student ID (MSSV), date of birth, scores for Math, Literature, and English, and the total score.
 */
void Thisinh::Xuat() {
    cout << "Ten: " << Ten << endl;
    cout << "MSSV: " << MSSV << endl;
    cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << endl;
    cout << "Diem Toan: " << fToan << endl;
    cout << "Diem Van: " << fVan << endl;
    cout << "Diem Anh: " << fAnh << endl;
    cout << "Tong diem: " << Tong() << endl;
}

/**
 * Calculates the total score of the student.
 * @return The sum of the scores for Math, Literature, and English.
 */
float Thisinh::Tong() {
    return fToan + fVan + fAnh;
}

/**
 * Gets the student ID (MSSV) of the student.
 * @return The student ID (MSSV).
 */
std::string Thisinh::getMSSV() {
    return MSSV;
}
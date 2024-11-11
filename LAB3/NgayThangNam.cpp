#include "NgayThangNam.h"
#include <iostream>
#include <iomanip>
using namespace std;

NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(0001) {}

NgayThangNam::NgayThangNam(int nam, int thang, int ngay) : iNgay(ngay), iThang(thang), iNam(nam) {}

bool NgayThangNam::is_leap_year(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int NgayThangNam::days_in_month(int month, int year) const {
    static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month - 1];
}

int NgayThangNam::date_to_days() const {
    int total_days = 0;
    for (int y = 1; y < iNam; ++y) {
        total_days += is_leap_year(y) ? 366 : 365;
    }
    for (int m = 1; m < iThang; ++m) {
        total_days += days_in_month(m, iNam);
    }
    total_days += iNgay - 1;
    return total_days;
}

void NgayThangNam::days_to_date(int total_days) {
    iNam = 1;
    while (total_days >= (is_leap_year(iNam) ? 366 : 365)) {
        total_days -= is_leap_year(iNam) ? 366 : 365;
        ++iNam;
    }
    iThang = 1;
    while (total_days >= days_in_month(iThang, iNam)) {
        total_days -= days_in_month(iThang, iNam);
        ++iThang;
    }
    iNgay = total_days + 1;
}

NgayThangNam NgayThangNam::operator +(int ngay) const {
    int total_days = date_to_days() + ngay;
    NgayThangNam result;
    result.days_to_date(total_days);
    return result;
}

NgayThangNam NgayThangNam::operator -(int ngay) const {
    int total_days = date_to_days() - ngay;
    NgayThangNam result;
    result.days_to_date(total_days);
    return result;
}

int NgayThangNam::operator -(const NgayThangNam& nt) const {
    return date_to_days() - nt.date_to_days();
}

NgayThangNam& NgayThangNam::operator ++() {
    *this = *this + 1;
    return *this;
}

NgayThangNam& NgayThangNam::operator --() {
    *this = *this - 1;
    return *this;
}

bool NgayThangNam::operator ==(const NgayThangNam& nt) const {
    return date_to_days() == nt.date_to_days();
}

bool NgayThangNam::operator !=(const NgayThangNam& nt) const {
    return !(*this == nt);
}

bool NgayThangNam::operator >=(const NgayThangNam& nt) const {
    return date_to_days() >= nt.date_to_days();
}

bool NgayThangNam::operator <=(const NgayThangNam& nt) const {
    return date_to_days() <= nt.date_to_days();
}

bool NgayThangNam::operator >(const NgayThangNam& nt) const {
    return date_to_days() > nt.date_to_days();
}

bool NgayThangNam::operator <(const NgayThangNam& nt) const {
    return date_to_days() < nt.date_to_days();
}

istream& operator >>(istream& is, NgayThangNam& nt) {
    char sep;
    is >> nt.iNgay >> sep >> nt.iThang >> sep>>nt.iNam;
    while (nt.iNgay < 1 || nt.iThang < 1 || nt.iThang > 12 || nt.iNam < 1 || nt.iNgay > nt.days_in_month(nt.iThang, nt.iNam)
        || nt.iNam < 1) {
        cout << "Ngay thang nam khong hop le!\n Vui long nhap lai: ";
        is >> nt.iNgay >>sep>> nt.iThang >>sep>> nt.iNam;
    }
    return is;
}

ostream& operator <<(ostream& os, const NgayThangNam& nt) {
    os << setfill('0') << setw(2) << nt.iNgay << "/"
       << setfill('0') << setw(2) << nt.iThang << "/"
       << nt.iNam;
    return os;
}
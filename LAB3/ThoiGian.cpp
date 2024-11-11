#include "ThoiGian.h"
#include <iomanip>

ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

ThoiGian::ThoiGian(int h, int m, int s) : iGio(h), iPhut(m), iGiay(s) {}

ThoiGian ThoiGian::operator +(const ThoiGian& tg) const {
    int totalSeconds = (iGio + tg.iGio) * 3600 + (iPhut + tg.iPhut) * 60 + (iGiay + tg.iGiay);
    return ThoiGian(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
}

ThoiGian ThoiGian::operator -(const ThoiGian& tg) const {
    int totalSeconds = (iGio * 3600 + iPhut * 60 + iGiay) - (tg.iGio * 3600 + tg.iPhut * 60 + tg.iGiay);
    if (totalSeconds < 0) totalSeconds += 24 * 3600; // Handle negative time difference
    return ThoiGian(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
}

ThoiGian ThoiGian::operator +(int seconds) const {
    int totalSeconds = iGio * 3600 + iPhut * 60 + iGiay + seconds;
    totalSeconds %= 24 * 3600; // Wrap around 24 hours
    return ThoiGian(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
}

ThoiGian ThoiGian::operator -(int seconds) const {
    int totalSeconds = iGio * 3600 + iPhut * 60 + iGiay - seconds;
    if (totalSeconds < 0) totalSeconds += 24 * 3600; // Handle negative time difference
    return ThoiGian(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
}

bool ThoiGian::operator ==(const ThoiGian& tg) const {
    if(iGio==24 && iPhut==0 && iGiay==0 && tg.iGio==0 && tg.iPhut==0 && tg.iGiay==0) return true;
    if(iGio==0 && iPhut==0 && iGiay==0 && tg.iGio==24 && tg.iPhut==0 && tg.iGiay==0) return true;
    return iGio == tg.iGio && iPhut == tg.iPhut && iGiay == tg.iGiay;
}

bool ThoiGian::operator !=(const ThoiGian& tg) const {
    return !(*this == tg);
}

bool ThoiGian::operator >(const ThoiGian& tg) const {
    return iGio * 3600 + iPhut * 60 + iGiay > tg.iGio * 3600 + tg.iPhut * 60 + tg.iGiay;
}

bool ThoiGian::operator >=(const ThoiGian& tg) const {
    return *this > tg || *this == tg;
}

bool ThoiGian::operator <(const ThoiGian& tg) const {
    return !(*this >= tg);
}

bool ThoiGian::operator <=(const ThoiGian& tg) const {
    return !(*this > tg);
}

ThoiGian& ThoiGian::operator ++() {
    *this = *this + 1;
    return *this;
}

ThoiGian ThoiGian::operator ++(int) {
    ThoiGian temp = *this;
    ++(*this);
    return temp;
}

ThoiGian& ThoiGian::operator --() {
    *this = *this - 1;
    return *this;
}

ThoiGian ThoiGian::operator --(int) {
    ThoiGian temp = *this;
    --(*this);
    return temp;
}

std::istream& operator >>(std::istream& is, ThoiGian& tg) {
    char sep;
    is >> tg.iGio >> sep >> tg.iPhut >> sep >> tg.iGiay;
    return is;
}

std::ostream& operator <<(std::ostream& os, const ThoiGian& tg) {
    os << std::setw(2) << std::setfill('0') << tg.iGio << ":"
       << std::setw(2) << std::setfill('0') << tg.iPhut << ":"
       << std::setw(2) << std::setfill('0') << tg.iGiay;
    return os;
}
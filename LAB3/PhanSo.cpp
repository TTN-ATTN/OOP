#include "PhanSo.h"
#include <bits/stdc++.h>
using namespace std;

PhanSo::PhanSo() : iTu(0), iMau(1) {}

PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
    if (iMau == 0) {
        throw invalid_argument("Denominator cannot be zero!");
    }
    rut_gon();
}

void PhanSo::rut_gon() {
    int gcd = __gcd(iTu, iMau);
    iTu /= gcd;
    iMau /= gcd;
    if(iMau < 0) {
        iMau = -iMau;
        iTu = -iTu;
    }
}

PhanSo PhanSo::operator +(PhanSo ps) {
    int tu = iTu * ps.iMau + ps.iTu * iMau;
    int mau = iMau * ps.iMau;
    return PhanSo(tu, mau);
}

PhanSo PhanSo::operator -(PhanSo ps) {
    int tu = iTu * ps.iMau - ps.iTu * iMau;
    int mau = iMau * ps.iMau;
    return PhanSo(tu, mau);
}

PhanSo PhanSo::operator *(PhanSo ps) {
    int tu = iTu * ps.iTu;
    int mau = iMau * ps.iMau;
    return PhanSo(tu, mau);
}

PhanSo PhanSo::operator /(PhanSo ps) {
    if (ps.iTu == 0) {
        throw invalid_argument("Cannot divide by zero");
    }
    int tu = iTu * ps.iMau;
    int mau = iMau * ps.iTu;
    return PhanSo(tu, mau);
}

bool PhanSo::operator ==(PhanSo ps) {
    return iTu == ps.iTu && iMau == ps.iMau;
}

bool PhanSo::operator !=(PhanSo ps) {
    return !(*this == ps);
}

bool PhanSo::operator >(PhanSo ps) {
    return iTu * ps.iMau > ps.iTu * iMau;
}

bool PhanSo::operator >=(PhanSo ps) {
    return *this > ps || *this == ps;
}

bool PhanSo::operator <(PhanSo ps) {
    return !(*this >= ps);
}

bool PhanSo::operator <=(PhanSo ps) {
    return !(*this > ps);
}

istream& operator >>(istream &is, PhanSo& ps) {
    int tu, mau;
    is >> tu >> mau;
    while(mau==0) {
        cout << "Mau so phai khac 0!Nhap lai: ";
        is >> tu >> mau;
    }
    ps = PhanSo(tu, mau);
    return is;
}

ostream& operator <<(ostream &os, PhanSo& ps) {
    if(ps.iTu % ps.iMau == 0) {
        os << ps.iTu / ps.iMau;
        return os;
    }
    os << ps.iTu << "/" << ps.iMau;
    return os;
}

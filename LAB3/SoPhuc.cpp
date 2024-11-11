#include "SoPhuc.h"
#include <bits/stdc++.h>
using namespace std;

SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

SoPhuc::SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

SoPhuc SoPhuc::operator +(const SoPhuc& sp) const {
    return SoPhuc(dThuc + sp.dThuc, dAo + sp.dAo);
}

SoPhuc SoPhuc::operator -(const SoPhuc& sp) const {
    return SoPhuc(dThuc - sp.dThuc, dAo - sp.dAo);
}

SoPhuc SoPhuc::operator *(const SoPhuc& sp) const {
    return SoPhuc(dThuc * sp.dThuc - dAo * sp.dAo, dThuc * sp.dAo + dAo * sp.dThuc);
}

SoPhuc SoPhuc::operator /(const SoPhuc& sp) const {
    if (sp.dThuc == 0 && sp.dAo == 0) {
        throw invalid_argument("Cannot divide by zero");
    }
    double denominator = sp.dThuc * sp.dThuc + sp.dAo * sp.dAo;
    return SoPhuc((dThuc * sp.dThuc + dAo * sp.dAo) / denominator, (dAo * sp.dThuc - dThuc * sp.dAo) / denominator);
}

bool SoPhuc::operator ==(const SoPhuc& sp) const {
    return dThuc == sp.dThuc && dAo == sp.dAo;
}

bool SoPhuc::operator !=(const SoPhuc& sp) const {
    return !(*this == sp);
}

istream& operator >>(istream &is, SoPhuc&sp) {
    double r, i;
    is >> r >> i;
    sp = SoPhuc(r,i);
    return is;
}

ostream& operator <<(ostream &os, const SoPhuc& sp) {
    os << sp.dThuc << (sp.dAo >= 0 ? " + " : " ") << sp.dAo << "i";
    return os;
}

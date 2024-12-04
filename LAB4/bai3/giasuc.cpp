#include "giasuc.h"
#include <cstdlib>
#include <ctime>

GiaSuc::GiaSuc(int soLuong, const std::string& tiengKeu)
    : soLuong(soLuong), tiengKeu(tiengKeu) {}

std::string GiaSuc::phatTiengKeu() const {
    return tiengKeu;
}

int GiaSuc::getSoLuong() const {
    return soLuong;
}

void GiaSuc::tangSoLuong(int soCon) {
    soLuong += soCon;
}

Bo::Bo(int soLuong) : GiaSuc(soLuong, "Bò: Ò...") {}

int Bo::sinhCon() {
    return rand() % 4 + 1;
}

int Bo::choSua() {
    return rand() % 21;
}

Cuu::Cuu(int soLuong) : GiaSuc(soLuong, "Cừu: Be...") {}

int Cuu::sinhCon() {
    return rand() % 3 + 1;
}

int Cuu::choSua() {
    return rand() % 6;
}

De::De(int soLuong) : GiaSuc(soLuong, "Dê: E...") {}

int De::sinhCon() {
    return rand() % 3 + 1;
}

int De::choSua() {
    return rand() % 11;
}

#ifndef GIASUC_H
#define GIASUC_H

#include <string>
#include <vector>

class GiaSuc {
protected:
    int soLuong;
    std::string tiengKeu; 
public:
    GiaSuc(int soLuong, const std::string& tiengKeu);
    virtual ~GiaSuc() {}

    virtual int sinhCon() = 0; 
    virtual int choSua() = 0; 
    virtual std::string phatTiengKeu() const;

    int getSoLuong() const;
    void tangSoLuong(int soCon); 
};

class Bo : public GiaSuc {
public:
    Bo(int soLuong);
    int sinhCon() override;
    int choSua() override;
};

class Cuu : public GiaSuc {
public:
    Cuu(int soLuong);
    int sinhCon() override;
    int choSua() override;
};

class De : public GiaSuc {
public:
    De(int soLuong);
    int sinhCon() override;
    int choSua() override;
};

#endif

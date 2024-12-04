#ifndef PHONG_H
#define PHONG_H
class Phong {
protected:
    int maPhong;
    int soDem;
    int doanhThu;
public:
    Phong(int s = 0) : soDem(s), doanhThu(0), maPhong(0) {}
    virtual ~Phong() {}
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
    virtual void TinhDoanhThu() = 0;
    int getMaPhong() const { return maPhong; }
    int getDoanhThu() const { return doanhThu; }
    int getSoDem() const { return soDem; }
};

class Business : public Phong {
public:
    Business(int s = 0) : Phong(s) {}
    void Nhap();
    void Xuat();
    void TinhDoanhThu();
};

class Premium : public Phong {
protected:
    int phiDichVu;
public:
    Premium(int s = 0, int pdv = 0) : Phong(s), phiDichVu(pdv) {}
    void Nhap();
    void Xuat();
    void TinhDoanhThu();
    int getPhiDichVu() const { return phiDichVu; }
};

class Deluxe : public Premium {
private:
    int phiPhucVu;
public:
    Deluxe(int s = 0, int pdv = 0, int ppv = 0) : Premium(s, pdv), phiPhucVu(ppv) {}
    void Nhap();
    void Xuat();
    void TinhDoanhThu();
    int getPhiPhucVu() const { return phiPhucVu; }
};

#endif // PHONG_H
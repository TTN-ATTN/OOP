    #ifndef DIEM_H
    #define DIEM_H

    class Diem {
    private:
        float iHoanh;
        float iTung;

    public:
        Diem();
        Diem(float Hoanh, float Tung);
        Diem(const Diem &x);

        float GetTungDo();
        float GetHoanhDo();

        void SetTungDo(int Tung);
        void SetHoanhDo(int Hoanh);

        void Xuat();
        void TinhTien(int dX, int dY);
        void TinhTien(float goc, float doDai);
    };


    #endif //DIEM_H

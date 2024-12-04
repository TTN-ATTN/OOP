#include "giasuc.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
    srand(time(0)); 

    int soBo, soCuu, soDe;
    cout << "Nhập số lượng bò ban đầu: ";
    cin >> soBo;
    cout << "Nhập số lượng cừu ban đầu: ";
    cin >> soCuu;
    cout << "Nhập số lượng dê ban đầu: ";
    cin >> soDe;

    Bo bo(soBo);
    Cuu cuu(soCuu);
    De de(soDe);

    vector<GiaSuc*> danhSach = {&bo, &cuu, &de};

    cout << "\nTiếng kêu trong nông trại:\n";
    for (auto gs : danhSach) {
        for (int i = 0; i < gs->getSoLuong(); ++i) {
            cout << gs->phatTiengKeu() << "\n";
        }
    }

    int tongSua = 0;
    int tongCon = soBo + soCuu + soDe;
    for (auto gs : danhSach) {
        int soConSinh = gs->sinhCon();
        gs->tangSoLuong(soConSinh);
        tongCon += soConSinh;
        int sua = gs->choSua();
        tongSua += sua;
    }

    cout <<  "\nSố lượng gia súc ban đầu: " << soBo + soCuu + soDe << " con.\n";
    cout << "\nSố lượng gia súc sau sinh: " << tongCon << " con.\n";
    cout << "\nTổng số lít sữa: " << tongSua << " lít.\n";

    return 0;
}

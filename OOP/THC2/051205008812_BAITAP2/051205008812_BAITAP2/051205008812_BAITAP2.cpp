#include "CauhoiTN.h"
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

bool giongnhau(CauhoiTN Cauhoi1, CauhoiTN Cauhoi2)
{
    if (Cauhoi1.question == Cauhoi2.question) {
        return true;
    }
    else return false;
}

int main()
{
    cout << "\t----- 0512 0500 8812 -  Huynh Vu Nhat Linh -----\n";
    
    vector <CauhoiTN> tn1(2);
    for (int i = 0; i < tn1.size(); i++) {
        tn1[i].nhap();//Nhap cau hoi
    }
    //Ghi cau hoi vao file
    {
        ofstream f;
        f.open("DETHI.TTN"); f.close();
        f.open("DETHI.TTN", ios::app);
        for (int i = 0; i < tn1.size(); i++) {
            tn1[i].ghifile(f);
        }
        f.close();
    }
    vector <CauhoiTN> tn2(2);
    //Doc cau hoi tu file
    {
        ifstream f;
        f.open("DETHI.TTN");
        for (int i = 0; i < tn2.size(); i++) {
            tn2[i].docfile(f);
        }
        f.close();
    }

    int opt;
    do {
        cout << "\t--------- MENU ---------\n";
        cout << "\t1. Thi Trac Nghiem\n";
        cout << "\t2. Xem De Thi\n";
        cout << "\t3. Thoat Chuong Trinh\n";

        cin >> opt;

        switch (opt)
        {
        case 1:
            for (int i = 0; i < tn2.size(); i++) {
                tn2[i].kiemtra();
            }
            break;
        case 2:
            for (int i = 0; i < tn2.size(); i++) {
                tn2[i].xuat();
            }
            break;
        default:
            break;
        }
    } while (opt != 3);    


    
}


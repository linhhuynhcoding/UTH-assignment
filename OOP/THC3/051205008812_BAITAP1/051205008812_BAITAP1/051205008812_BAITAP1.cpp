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

void NhapCauHoi() {
    int soluong;
    cout << "Nhap so luong cau hoi : ";
    cin >> soluong; 
    cin.ignore();
    vector <CauhoiTN> tn1(soluong);
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
}

void LayCauHoi(vector <CauhoiTN>& tn2) {
    //Doc cau hoi tu file
    {
        ifstream f;
        f.open("DETHI.TTN");
        string tmp_str;
        while (!f.eof()) {
            CauhoiTN tmp;
            if (tmp.docfile(f) == true) {
                tmp.xuat();
                tn2.push_back(tmp);
            }
        }
        f.close();
    }
    return;
}

int main()
{
    cout << "\t----- 0512 0500 8812 -  Huynh Vu Nhat Linh -----\n";   

    int opt;
    do {
        cout << "\t--------- MENU ---------\n";
        cout << "\t1. Thi Trac Nghiem\n";
        cout << "\t2. Xem De Thi\n";
        cout << "\t3. Nhap De Thi\n";
        cout << "\t4. Thoat Chuong Trinh\n";

        cin >> opt;

        vector <CauhoiTN> tn;
        switch (opt)
        {
        case 1:
        {
            LayCauHoi(tn);
            int NoCorrectAns = 0;
            for (int i = 0; i < tn.size(); i++) {
                if (tn[i].kiemtra() == true) {
                    NoCorrectAns++;
                };
            }
            cout << "Ban da tra loi dung " << NoCorrectAns << " cau hoi.\n";
            break;
        }            
        case 2:
            LayCauHoi(tn);
            for (int i = 0; i < tn.size(); i++) {
                cout << i + 1 << " . ";
                tn[i].xuat();
            }
            break;
        case 3:
            NhapCauHoi();
            break;
        default:
            cout << "THOAT CHUONG TRINH!\n";
            break;
        }
    } while (opt != 4);    


    
}


#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(string tieude)
{
    this->tieude = tieude;
}

void Menu::themLuachon(string luachon)
{
    dsLuachon.push_back(luachon);
}

void Menu::xuat()
{
    cout << "\n-----"<< tieude <<"-----\n";
    for (int i = 0; i < dsLuachon.size(); i++)
        cout << i << ". " << dsLuachon[i] << endl;
}

int Menu::chon()
{
    int ch;
    do {
        xuat();
        cout << "Moi chon?";
        cin >> ch;
        //xoa ky tu xuong dong de cac lenh getline sau nay khong bi anh huong
        string tmp;
        getline(cin, tmp);
        if (ch < 0 || ch >= dsLuachon.size())
            cout << "Chon sai, moi chon lai!!!\n";
    } while (ch<0 || ch>=dsLuachon.size());//Lap lai neu user chon sai
    return ch;
}

#pragma once
#include <vector>
#include <string>

using namespace std;

class Menu
{
private:
	string tieude;
	vector<string> dsLuachon; //danh sach cac lua chon
public:
	Menu(string tieude);
	void themLuachon(string luachon);//them mot chuc nang cho thuc don
	void xuat();//xuat danh sach cac lua chon
	int chon();// xuat danh sach cac muc va cho nguoi dung nhap lua chon
};


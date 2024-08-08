#pragma once
#include "Bieuthuc.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"
#include <iostream>
#include <vector>
using namespace std;
class Dethi {
private:
    vector<Bieuthuc> ds; //Chứa danh sách các câu hỏi là các biểu thức
public:
    Dethi(int n1, int n2, int n3, int level = 1); //Sinh danh sách gồm n1 biểu thức chỉ gồm phép cộng,
    // n2 biểu thức chỉ gồm phép trừ, và
   // n3 biểu thức chỉ gồm phép nhân.
    vector<Bieuthuc> danhsach() { return ds; }
    void xuat(ostream& output = cout); // xuất danh sách các câu hỏi ra màn hình, các câu hỏi có dạng a # b = ?
    int danhgia(istream& input = cin); //đọc n1+n2+n3 câu trả lời từ istream (có thể từ cin hoặc file), trả về số câu đúng.
};


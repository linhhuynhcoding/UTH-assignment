#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
class SinhVien
{
private:
    string fullName;
public:
    SinhVien() {

    }
    SinhVien(string name) {
        this->fullName = name;
    }
    friend ofstream operator << (ofstream ofs, SinhVien a) {
        ofs << a.fullName << " ";
        return ofs;
    }
};


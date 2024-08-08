#include <iostream>
#include <fstream>
#include <vector>
#include "Fraction.h"
using namespace std;

int main(){
    string filename;
    cin >> filename;
    filebuf f;
    f.open(filename, ios::in);
    istream in(&f);

    vector<Fraction> a;
    in >> a;
    sort(a.begin(), a.end());
    cout << a[0] << endl << a[a.size() - 1];
    return 0;
}
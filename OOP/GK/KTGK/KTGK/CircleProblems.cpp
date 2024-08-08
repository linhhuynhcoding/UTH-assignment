#include "CircleProblems.h"
#include "Circle.h"
#include "Ring.h"
#include <fstream>
#include <vector>
#include <algorithm>


void CircleProblems::ProblemA(const string filename)
{
    filebuf f;
    f.open(filename, ios::in);
    istream in(&f);
    int n;
    in >> n;
    vector <Circle> a(n);
    for (int i = 0; i < n; i++) {
        int x, y, r;
        in >> x >> y >> r;
        a[i] = Circle(x, y, r);
    }
    sort(a.begin(), a.end(), [](const Circle& x, const Circle& y) {
        return (x.getR() < y.getR());
        });
    for (Circle c : a) {
        cout << c << "\n";
    }
}

void CircleProblems::ProblemB(const string filename)
{
    filebuf f;
    f.open(filename, ios::in);
    istream in(&f);
    int n;
    in >> n;
    vector <Circle> a(n);
    vector <Circle> res;

    for (int i = 0; i < n; i++) {
        int x, y, r;
        in >> x >> y >> r;
        a[i] = Circle(x, y, r);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (a[i] & a[j]) {
                res.push_back(a[i]);
                break;
            }
        }
    }
    sort(res.begin(), res.end(), [](const Circle& x, const Circle& y) {
        return (x.getR() < y.getR());
        });
    for (Circle c : res) {
        cout << c << "\n";
    }
}

void CircleProblems::ProblemC(const string filename)
{
    filebuf f;
    f.open(filename, ios::in);
    istream in(&f);
    int n;
    in >> n;
    vector <Circle> a(n);
    vector <Ring> b;
    //vector <bool> flag(n, vector <bool>(n, false));

    for (int i = 0; i < n; i++) {
        int x, y, r;
        in >> x >> y >> r;
        a[i] = Circle(x, y, r);
    }
    for (int i = 0; i + 1< n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j) continue;
            if (a[i] == a[j] && a[i].getR() != a[j].getR()) {
                b.push_back({ a[i], a[j].getR() });
            }
        }
    }
    cout << b.size() << "\n";
}

void CircleProblems::ProblemD(const string filename)
{
    filebuf f;
    f.open(filename, ios::in);
    istream in(&f);
    int n;
    in >> n;
    vector <Circle> a(n);
    vector <Ring> b;
    //vector <bool> flag(n, vector <bool>(n, false));

    for (int i = 0; i < n; i++) {
        int x, y, r;
        in >> x >> y >> r;
        a[i] = Circle(x, y, r);
    }
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j) continue;
            if (a[i] == a[j] && a[i].getR() != a[j].getR()) {
                b.push_back({ a[i], a[j].getR() });
            }
        }
    }
    int m = 0;
    for (Ring x : b) m = max(m, x.width());
    for (Ring x : b) {
        if (x.width() == m) {
            cout << x << "\n";
        }
    }

}

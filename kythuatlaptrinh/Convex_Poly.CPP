#include <bits/stdc++.h>
using namespace std;

struct Point
{
    float x, y;
};

pair<float, float> findCoso(Point p1, Point p2)
{
    if (p2.x == p1.x)
        return {p1.x, 0};

    float b = (p1.y * p2.x - p2.y * p1.x) / (p2.x - p1.x);
    float a = (p1.y - b) / p1.x;

    return {a, b};
}

// kiểm tra có tồn tại đường thẳng ngoài cùng đa giác đi qua điểm p1 và p2
int checkSide(int p1, int p2, int numsofPoint, vector<Point> Points)
{
    // trả về 0 nếu tồn tại 3 điểm thẳng hàng
    // trả về 1 nếu không tồn tại đường thẳng ngoài cùng đa giác
    // trả về 2 nếu tồn tại đường thẳng ngoài cùng đa giác

    // tìm cơ số a, b của đường thẳng đi qua p1, p2
    pair<float, float> segment = findCoso(Points[p1], Points[p2]);
    float a = segment.first;
    float b = segment.second;
    //đường thẳng có dạng : y = ax + b

    int sideA = 0;
    int sideB = 0;

    for (int i = 0; i < numsofPoint; i++)
    {
        if (i == p1 || i == p2)
            continue;
        float x = Points[i].x;
        float y = Points[i].y;

        float checkValue = a * x - y + b;

        if (a == (float)0)
        {
            if (y > b)
                checkValue = 1;
            else if (y == b)
                checkValue = 0;
            else
                checkValue = -1;
        }
        else if (b == y)
        {
            if (x > a)
                checkValue = 1;
            else if (x == a)
                checkValue = 0;
            else
                checkValue = -1;
        }

        if (checkValue == 0) // trả về 0 nếu tồn tại 3 điểm thẳng hàng
            return 0;
        else if (checkValue > 0)
            sideA++;
        else
            sideB++;

        if (sideA * sideB != 0)
            return 1; // trả về 1 nếu không tồn tại đường thẳng ngoài cùng đa giác
    }

    // trả về 2 nếu tồn tại đường thẳng ngoài cùng đa giác
    return 2;
}

bool Convex_Poly(int numsofPoint, vector<Point> Points)
{
    // Nếu tồn tại đường thẳng đi qua 3 điểm => đa giác lõm
    // Nếu tồn tại điểm không nằm trên đường thẳng ngoài cùng => đa giác lõm

    for (int i = 0; i < numsofPoint; i++)
    {
        bool flag = false;
        for (int j = 0; j < numsofPoint; j++)
        {
            if (j == i)
                continue;
            int check = checkSide(i, j, numsofPoint, Points);

            // Nếu tồn tại đường thẳng đi qua 3 điểm => đa giác lõm
            if (check == 0)
                return false;
            else if (check == 2)
            {
                flag = true;
                break;
            }
        }
        // Nếu tồn tại điểm không nằm trên đường thẳng ngoài cùng => đa giác lõm
        if (flag == false)
            return false;
    }
    return true;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int numsofPoint;
    cin >> numsofPoint;
    vector<Point> Points(numsofPoint);

    for (auto &p : Points)
    {
        cin >> p.x >> p.y;
    }

    if (Convex_Poly(numsofPoint, Points))
        cout << "Da giac Loi";
    else
        cout << "Da giac lom";
}
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    float x, y;
};

struct Line
{
    float a, b;
    float c = 1;

    // Tìm đường thẳng từ 2 điểm bất kỳ
    Line findCoso(Point p1, Point p2)
    {
        if (p2.x == p1.x)
            return {1, 0, -p1.x};
        if (p2.y == p1.y)
            return {0, 1, -p1.y};

        if (p1.y * p2.x == p2.y * p1.x)
        {
            float a = -p1.y / p1.x;
            return {a, 1, 0};
        }

        float a = (p1.y - p2.y) / (p1.x * p2.y - p2.x * p1.y);
        float b;
        if (p1.y == 0)
            b = (-1 - a * p2.x) / p2.y;
        else
            b = (-1 - a * p1.x) / p1.y;

        return {a, b, 1};
    }
};

struct Polygon
{
    int numsofPoint;
    Point *listofPoints;

// nhập đa giác
    void inputPolygon()
    {
        cin >> numsofPoint;
        listofPoints = new Point[numsofPoint];

        for (int i = 0; i < numsofPoint; i++)
        {
            cin >> (listofPoints + i)->x >> (listofPoints + i)->y;
        }
    }

// kiểm tra có tồn tại đường thẳng ngoài cùng đa giác đi qua điểm p1 và p2
    int checkSide(int p1, int p2)
    {
        // trả về 0 nếu tồn tại 3 điểm thẳng hàng
        // trả về 1 nếu không tồn tại đường thẳng ngoài cùng đa giác
        // trả về 2 nếu tồn tại đường thẳng ngoài cùng đa giác

        // tìm cơ số a, b, c của đường thẳng đi qua p1, p2
        // đường thẳng có dạng : ax + by + c = 0
        Line line = line.findCoso(listofPoints[p1], listofPoints[p2]);
        float a = line.a;
        float b = line.b;
        float c = line.c;

        int sideA = 0;
        int sideB = 0;
        for (int i = 0; i < numsofPoint; i++)
        {
            if (i == p1 || i == p2)
                continue;
            float x = listofPoints[i].x;
            float y = listofPoints[i].y;

            float checkValue = a * x + b * y + c;

            if (checkValue == 0) // trả về 0 nếu tồn tại 3 điểm thẳng hàng
            {
                cout << "Ton tai 3 diem thang hang : ";
                cout << "(" << listofPoints[p1].x << ", " << listofPoints[p1].y << ") ";
                cout << "(" << listofPoints[p2].x << ", " << listofPoints[p2].y << ") ";
                cout << "(" << listofPoints[i].x << ", " << listofPoints[i].y << ") ";
                return 0;
            }
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

// kiểm tra đa giác lỗi hay lõm
    bool Convex_Poly()
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
                int check = checkSide(i, j);
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
            {
                cout << "Ton tai diem khong nam tren duong thang ngoai cung bat ky : ";
                cout << "(" << listofPoints[i].x << ", " << listofPoints[i].y << ") ";

                return false;
            }
        }
        return true;
    }
};


int main()
{
    // freopen("in.txt", "r", stdin);
    
    Polygon polygon ;
    polygon.inputPolygon() ;

    if (polygon.Convex_Poly())
        cout << "Da giac Loi";
    else
        cout << "\nDa giac lom";
}
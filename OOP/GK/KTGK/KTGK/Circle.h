#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class Circle
{
protected:
	int x, y;
	int r;//bán kính
public:
	Circle(); //Hàm khởi tạo không có tham số, tạo Circle mặc định (0,0,1)
	Circle(int x0, int y0, int r0);//Hàm khởi tạo có 3 tham số
	Circle(int r);//Ham khoi tao 1 tham số, tạo Circle (0,0,r)
	Circle(const Circle& p); //copy constructor
	//hàm get đã cài đặt sẵn
	int getX() const { return x; }
	int getY() const { return y; }
	int getR() const { return r; }
	//Toán tử chèn, xuất theo dạng (x,y,r)
	friend ostream& operator<< (ostream& out, const Circle& p);
	//Toán tử tách, cho phép nhập 1 đường tròn dạng (x,y,r)
	friend istream& operator>> (istream& in, Circle& p);
	//Toán tử - tính khoảng cách tâm, c1-c2 là khoảng cách giữa 2 tâm của c1 và c2
	friend double operator-(const Circle& p1, const Circle& p2);
	//Toán tử ==,!= dùng để kiểm tra 2 đường tròn có trùng tâm/khác tâm không
	friend bool operator==(const Circle& p1, const Circle& p2);
	friend bool operator!=(const Circle& p1, const Circle& p2);
	// So sánh 2 bán kính, dùng để sắp xếp
	bool operator<(const Circle& c2) const;// trả về true nếu bán kính bé hơn bán kính đường tròn c2

	// Các toán tử sau dùng để kiểm tra vị trí tương đối của hai đường tròn
	bool operator&(const Circle& c2) const;//kiểm tra đường tròn này cắt đường tròn c2
	//c1&c2 : kiểm tra c1 cắt c2
};
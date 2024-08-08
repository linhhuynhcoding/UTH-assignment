#include "Circle.h"

Circle::Circle()
{
	r = 1;
	x = y = 0;
}

Circle::Circle(int x0, int y0, int r0)
{
	x = x0;
	y = y0;
	r = r0;
}

Circle::Circle(int r)
{
	x = y = 0;
	this->r = r;
}

Circle::Circle(const Circle& p)
{
	x = p.getX();
	y = p.getY();
	r = p.getR();
}

bool Circle::operator<(const Circle& c2) const
{
	return (this->r < c2.getR());
}


bool Circle::operator&(const Circle& c2) const
{
	
	double kc = *this - c2;
	if (kc < abs(c2.getR() - this->r)) return false;
	//if (min(c2.getR(), this->r) + kc == max(c2.getR(), this->r) + kc) {
	//	return false;
	//}
	return (this->r + c2.getR() > kc);
}

ostream& operator<<(ostream& out, const Circle& p)
{
	out << "(" << p.getX() << "," << p.getY() << "," << p.getR() << ")";
	return out;
}

istream& operator>>(istream& in, Circle& p)
{
	string s;
	//in >> s;
	//p = Circle(s[1] - '0', s[3] - '0', s[5] - '0');
	return in;
}

double operator-(const Circle& p1, const Circle& p2)
{
	return sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
}

bool operator==(const Circle& p1, const Circle& p2)
{
	if (p1.getX() == p2.getX() && p1.getY() == p2.getY()) {
		return true;
	}
	else
		return false;
}

bool operator!=(const Circle& p1, const Circle& p2)
{
	if (p1.getX() == p2.getX() && p1.getY() == p2.getY()) {
		return false;
	}
	else
		return true;
}

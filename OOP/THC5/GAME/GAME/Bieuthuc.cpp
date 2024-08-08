#include "Bieuthuc.h"
#include <cstdlib>

using namespace std;

Bieuthuc::Bieuthuc(int level)
{
	switch (level)
	{
	case 1:
	{
		this->a = 1 + rand() % 10 ;
		this->b = 1 + rand() % 10 ;
		this->pheptoan = '+';
		return;
	}
	case 2:
	{
		char pt[2] = { '+', '-' };
		this->a = 1 + rand() % 10;
		this->b = 1 + rand() % 10;
		this->pheptoan = pt[rand() % 2];
		return;
	}
	case 3:
	{
		char pt[3] = { '+', '-', '*'};
		this->a = 1 + rand() % 10;
		this->b = 1 + rand() % 10;
		this->pheptoan = pt[rand() % 3];
		return;
	}
	case 4:
	{
		char pt[2] = { '+', '-' };
		this->a = 10 + rand() % 91;
		this->b = 10 + rand() % 91;
		this->pheptoan = pt[rand() % 2];
		return;
	}
	default:
	{
		char pt[3] = { '+', '-', '*' };
		this->a = 10 + rand() % 91 ;
		this->b = 10 + rand() % 91 ;
		this->pheptoan = pt[rand() % 3];
		return;
	}
	}
}

bool Bieuthuc::kiemtra(float traloi)
{
	return abs(traloi - this->giatri()) < 0.00000001f;
}

float Bieuthuc::giatri()
{
	if (this->pheptoan == '+')
		return this->a + this->b;
	else if (this->pheptoan == '-')
		return this->a - this->b;
	else
		return this->a * this->b;
}

ostream& operator<<(ostream& out, Bieuthuc bt)
{
	out << bt.a << " " << bt.pheptoan << " " << bt.b;
	return out;
}

#pragma once
#include "Bieuthuc.h"
#include "Fraction.h"

class BieuthucPS : public Bieuthuc
{
protected:
	Fraction a, b;
public:
	BieuthucPS(int level);
	friend ostream& operator<<(ostream& out, BieuthucPS bt);
	bool kiemtra(Fraction traloi);
	Fraction giatri();
};

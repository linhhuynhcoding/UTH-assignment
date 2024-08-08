#include "BieuthucPS.h"
#include "Fraction.h"


BieuthucPS::BieuthucPS(int level):Bieuthuc(level)
{
	char pt[3] = {'+', '-', '*'};
	if (level == 1) {
		pheptoan = pt[0];
	}
	else if (level == 2 || level == 4) {
		pheptoan = pt[rand() % 2];
	}
	else {
		pheptoan = pt[rand() % 3];
	}
	if (level < 4) {
		a = Fraction(10);
		b = Fraction(10);
	}
	else {
		a = Fraction(100);
		b = Fraction(100);
	}
}
bool BieuthucPS::kiemtra(Fraction traloi)
{
	return traloi == this->giatri();
}
Fraction BieuthucPS::giatri()
{
	return (this->a + this->b);
}
;

ostream& operator<<(ostream& out, BieuthucPS bt)
{
	out << bt.a << " + " << bt.b;
	return out;
}

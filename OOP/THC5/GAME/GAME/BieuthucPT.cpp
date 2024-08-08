#include "BieuthucPT.h"
#include "Bieuthuc.h"

BieuthucPT::BieuthucPT(int level):Bieuthuc(level)
{
	this->bt1 = new Bieuthuc(level);
	this->bt2 = new Bieuthuc(level);
	this->a = bt1->giatri();
	this->b = bt2->giatri();
	//cout << a << " " << b << "\n";
};
ostream& operator<<(ostream& out, BieuthucPT bt)
{
	out << "(" << * bt.bt1 << ") " << bt.pheptoan << " (" << *bt.bt2 << ")";
	return out;
}

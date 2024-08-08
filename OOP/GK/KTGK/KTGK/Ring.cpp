#include "Ring.h"

Ring::Ring(int x, int y, int r, int r2):Circle(x, y, min(r, r2))
{
	this->r2 = max(r2, r);
}

Ring::Ring(const Circle& c1, int r2):Circle(c1.getX(), c1.getY(), min(c1.getR(), r2))
{
	this->r2 = max(r2, c1.getR());
}

int Ring::width() const
{
	return (r2 - this->getR());
}

ostream& operator<<(ostream& out, const Ring& p)
{
	out << "(" << p.getX() << "," << p.getY() << "," << p.getR() << "," << p.getR2() << ")";
	return out;
}

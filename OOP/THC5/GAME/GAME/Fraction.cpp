#include "Fraction.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (a * b == 0) return 1;
	if (a < b) swap(a, b);
	while (a % b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return b;
}

Fraction::Fraction()
{
	this->numerator = nullptr;
	this->denominator = nullptr;
}

Fraction::Fraction(int tuso, int mauso)
{
	this->numerator = tuso;
	this->denominator = mauso;
	this->nomalize();
	
}

Fraction::Fraction(int random)
{
	this->numerator = rand() % random;
	this->denominator = rand() % random;
	while (this->denominator == 0)
		this->denominator = rand() % random;
	this->nomalize();
}

void Fraction::nomalize()
{
	if (this->denominator == 0) {
		this->numerator = 0;
		this->denominator = 1;
		return;
	}
	if (this->denominator < 0) {
		this->denominator *= -1;
		this->numerator *= -1;
	}
	int uocchung = gcd(abs(this->denominator), abs(this->numerator));
	this->numerator /= uocchung;
	this->denominator /= uocchung;
	return;
}

Fraction& Fraction::operator++()
{
	this->numerator += this->denominator;
	//this->nomalize();
	
	return *this;
}

const Fraction Fraction::operator++(int)
{
	Fraction before(this->numerator, this->denominator); 

	this->numerator += this->denominator;
	this->nomalize();

	return before;
}

Fraction& Fraction::operator--()
{
	this->numerator -= this->denominator;
	this->nomalize();

	return *this;
}

const Fraction Fraction::operator--(int)
{
	Fraction before(this->numerator, this->denominator);

	this->numerator -= this->denominator;
	this->nomalize();

	return before;
}


ostream& operator<<(ostream& out, const Fraction& f)
{
	out << f.numerator << "/" << f.denominator;
	return out;
}

istream& operator>>(istream& in, vector<Fraction>& f)
{
	int n;
	in >> n;
	f.resize(n);
	for (int i = 0; i < n; i++) {
		in >> f[i].numerator >> f[i].denominator;
	}
	return in;
}


const Fraction operator+(Fraction& f1, Fraction& f2)
{
	return Fraction(f1.numerator*f2.denominator + f1.denominator *f2.numerator, f1.denominator*f2.denominator);
}

const Fraction operator-(Fraction& f1, Fraction& f2)
{
	return Fraction(f1.numerator * f2.denominator - f1.denominator * f2.numerator, f1.denominator * f2.denominator);
}

const Fraction operator*(Fraction& f1, Fraction& f2)
{
	return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);

}

const Fraction operator/(Fraction& f1, Fraction& f2)
{
	return Fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);

}

bool Fraction::operator==(const Fraction& right)
{
	return (this->numerator == right.numerator && this->denominator == right.denominator);
}

bool Fraction::operator!=(const Fraction& right)
{
	return !(this->numerator == right.numerator && this->denominator == right.denominator);
}

bool Fraction::operator<(const Fraction& right)
{	
	return (this->numerator * right.denominator - this->denominator * right.numerator < 0);
}

bool Fraction::operator>(const Fraction& right)
{
	return (this->numerator * right.denominator - this->denominator * right.numerator > 0);

}


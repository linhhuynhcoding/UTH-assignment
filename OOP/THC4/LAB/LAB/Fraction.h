#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
class Fraction
{
private:
	// Tu so
	int numerator;
	// Mau so
	int denominator;
public:
	Fraction();
	Fraction(int, int);
	Fraction(int random);
	void nomalize();
	friend ostream& operator<<(ostream& out, const Fraction& f);
	friend istream& operator>>(istream& out, vector<Fraction> &f);

	Fraction& operator++();
	const Fraction operator++(int);

	Fraction& operator--();
	const Fraction operator--(int);

	friend const Fraction operator+(Fraction& f1, Fraction& f2);
	friend const Fraction operator-(Fraction& f1, Fraction& f2);
	friend const Fraction operator*(Fraction& f1, Fraction& f2);
	friend const Fraction operator/(Fraction& f1, Fraction& f2);

	bool operator == (const Fraction& right);
	bool operator != (const Fraction& right);
	bool operator < (const Fraction& right);
	bool operator > (const Fraction& right);


};


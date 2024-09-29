//PhanTu.cpp
#include "PhanTu.h"
#include <iostream>

using namespace std;

PhanTu::PhanTu()
{
	this->coso = nullptr;
	this->somu = nullptr;
	this->next = nullptr;
}

void PhanTu::GanCoso(int _coso)
{
	this->coso = _coso;
	return;
}

void PhanTu::GanSomu(int _somu)
{
	this->somu = _somu;
}

void PhanTu::GanNext(PhanTu* _next)
{
	this->next = _next;
	return;
}

int PhanTu::LayCoso()
{
	return this->coso;
}

int PhanTu::LaySomu()
{
	return this->somu;
}

PhanTu* PhanTu::LayNext()
{
	return this->next;
}

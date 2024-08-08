#include "MyData.h"
bool MyData::operator== (KeyData b) {
	if (this->hoten == b.getValue())
		return true;
	else
		return false;
};

bool MyData::operator!= (KeyData b) {
	if (this->hoten != b.getValue())
		return true;
	else
		return false;
}
string MyData::toString()
{
	return this->hoten + "|" + this->email + "|" + this->mssv;
}
;

MyData::MyData()
{
	this->hoten = "";
	this->email = "";
	this->mssv = "";
}

MyData::MyData(string hoten, string email, string mssv)
{
	this->hoten = hoten;
	this->email = email;
	this->mssv = mssv;
}

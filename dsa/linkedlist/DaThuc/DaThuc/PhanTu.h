//PhanTu.h

#pragma once
class PhanTu
{
private:
	int coso;
	int somu;
	PhanTu* next;
public:
	PhanTu();
	void GanCoso(int);
	void GanSomu(int);
	void GanNext(PhanTu*);

	int LayCoso();
	int LaySomu();
	PhanTu* LayNext();
};


#include "Dethi.h"

Dethi::Dethi(int n1, int n2, int n3, int level)
{
	while (n1--) {
		BieuthucCong cong = BieuthucCong(level);
		this->ds.push_back(cong);
	}
	while (n2--) {
		BieuthucTru tru = BieuthucTru(level);
		this->ds.push_back(tru);
	}
	while (n3--) {
		BieuthucNhan nhan = BieuthucNhan(level);
		this->ds.push_back(nhan);
	}
	return;
}

void Dethi::xuat(ostream& output)
{
	for (Bieuthuc bt : this->ds) {
		output << bt << " =  ? \n";
	}
}

int Dethi::danhgia(istream& input)
{
	int cnt = 0;
	for (Bieuthuc bt : this->ds) {		
		float tmp_traloi;
		cin >> tmp_traloi;
		if (bt.kiemtra(tmp_traloi)) cnt++;
	}
	return cnt;
	
}

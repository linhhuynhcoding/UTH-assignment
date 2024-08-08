#pragma once
#include "Circle.h"
class Ring : public Circle
{
protected:
	int r2;
public:
	int getR2()const { return r2; }

	Ring(int x, int y, int r, int r2);//Khởi tạo Ring có tâm (x,y) và hai bán kính r và r2 (đảm bảo r<=r2, nếu ngược lại thì hoán đổi)
	Ring(const Circle& c1, int r2); //Khởi tạo Ring có tâm của c1 và bán kính r của c1 và r2
	// Lưu ý: với hàm khởi tạo cần đảm bảo r<=r2, nếu ngược lại thì hoán đổi.

	friend ostream& operator<<(ostream& out, const Ring& p); //Xuất Ring theo dạng (x,y,r,r2)
	int width() const;//Độ dày của Ring (hiệu của 2 bán kính)

	//Cài đặt lại các toán tử đánh giá vị trí tương đối của hai Ring theo yêu cầu
	//vị trí tương đối của 2 Ring được đánh giá qua 2 đường tròn bao ngoài của các Ring đó (các đường tròn có bán kính lớn r2)


};
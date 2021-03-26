// vectors: overloading operators example

#include <iostream>
using namespace std;

class CVector{
  public:
    int x,y;
		CVector () {x=0;y=0;};
		// 函數名稱 CVector (constructor)
		CVector (int,int);
		// 函數 operator+ 返回 CVector 類型的值
		CVector operator + (CVector);
};

CVector::CVector (int a, int b) {
 	x = a;
 	y = b;
}

CVector CVector::operator+ (CVector param) {
 	CVector temp;
 	temp.x = x + param.x;
 	temp.y = y + param.y;
 	return temp;
}

int main() {
	CVector a (3,1);
	CVector b (1,2);
	CVector c;
	// c = a + b;
	c = a.operator+ (b);
	cout << c.x << "," << c.y;
	return 0;
}

#include <iostream>
using namespace std;

class rectangle{
	private:
		double x,y;
	public:
		// constructor
		rectangle(double,double);
		// overload
		rectangle();
			
		double area(void){
			return (x * y);	
		}
};

rectangle::rectangle(double a,double b){
	x=a;
	y=b;
}

rectangle::rectangle(){
	x=5;
	y=5;
}

int main() {
	rectangle rect(2.5,7);
	// CRectangle rectb(); --> wrong!
	rectangle rectb;
	cout<<"area: "<<rect.area()<<endl;
	cout<<"area: "<<rectb.area()<<endl;
	
	return 0;
}

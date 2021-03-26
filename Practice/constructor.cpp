// example on constructor and destructor

#include <iostream>
using namespace std;

class rectangle{
		private:
			double *x,*y;
		public:
			// constructor
			rectangle(double,double);
			// destructor
			~rectangle();
			
			double area(void){
				return (*x * *y);	
			}
	};

rectangle::rectangle(double a,double b){
	x=new double;
	y=new double;
	
	*x=a;
	*y=b;
}

rectangle::~rectangle(){
	delete x;
	delete y;
}

int main() {
	rectangle rect(2.5,7);
	cout<<"area: "<<rect.area()<<endl;
	
	return 0;
}

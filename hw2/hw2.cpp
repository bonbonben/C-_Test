#include<iostream>
#include"rational.h"
using namespace std;


int main()
{
    Rational r1(6,5),r2(7),r3;
	cout<<"r1="<<r1<<"\nr2="<<r2<<"\nr3="<<r3<<endl;
	cout<<"r3  ";
	cin>>r3;
	cout<<"r1+r2="<<r1+r2<<"\tr1-r2="<<r1-r2<<endl;
	cout<<"r1*r2="<<r1*r2<<"\tr1/r2="<<r1/r2<<endl;
	cout<<"r1==r2 is "<<(r1==r2?"TRUE":"FALSE")<<endl; 
	cout<<"r1>r2 is "<<(r1>r2?"TRUE":"FALSE")<<endl;
	cout<<"r1>=r2 is "<<(r1>=r2?"TRUE":"FALSE")<<endl;
	cout<<"r1<r2 is "<<(r1<r2?"TRUE":"FALSE")<<endl;
	cout<<"r1<=r2 is "<<(r1<=r2?"TRUE":"FALSE")<<endl;
	return 0;
}

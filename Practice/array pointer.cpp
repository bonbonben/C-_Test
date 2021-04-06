#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int i=0;
	int array[5];
	
	for(i=0;i<5;++i)
	{
		array[i]=i;
	}
	
	cout << "==============================" << endl;
	for(i=0;i<5;++i)
	{
		cout << "array[" << i << "]=" << array[i] <<endl;
	}
	cout << "==============================" << endl;
	for(i=0;i<5;++i)
	{
		cout << "*(array+" << i << ")=" << *(array+i) <<endl;
	}
	cout << "==============================" << endl;
	for(i=0;i<5;++i)
	{
		cout << "&array[" << i << "]=" << &array[i] <<endl;
	}cout << "==============================" << endl;
	for(i=0;i<5;++i)
	{
		cout << "(array+" << i << ")=" << (array+i) <<endl;
	}
	
	//int *ptr=&array[0];
	int *ptr=array;
	
	cout << "==============================" << endl;
	for(i=0;i<5;++i)
	{
		cout << "ptr[" << i << "]=" << ptr[i] <<endl;
	}
	cout << "==============================" << endl;
	for(i=0;i<5;++i)
	{
		cout << "*(ptr+" << i << ")=" << *(ptr+i) <<endl;
	}
	cout << "==============================" << endl;
	for(i=0;i<5;++i)
	{
		cout << "&ptr[" << i << "]=" << &ptr[i] <<endl;
	}cout << "==============================" << endl;
	for(i=0;i<5;++i)
	{
		cout << "(ptr+" << i << ")=" << (ptr+i) <<endl;
	}
	
	return 0;
}

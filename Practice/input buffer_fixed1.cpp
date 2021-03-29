// C++ Code to explain how "cin.ignore(numeric_limits <streamsize>::max(),'\n');" discards the input buffer
#include<iostream>
// for <streamsize>
#include<ios>
// for numeric_limits
#include<limits>
using namespace std;
  
int main()
{
    int a;
    char str[80];
    
    cin >> a;
    
    // discards the input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    cin.getline(str, 80);
    
    cout << a << endl;
    
    // Printing string : This will print string now
    cout << str << endl;
    
    return 0;
}

// C++ Code to explain how "cin >> ws" discards the input buffer along with initial white spaces of string
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int a;
    string s;
    
    cin >> a;
    
    // Discards the input buffer and intial white spaces of string
    cin >> ws;
    
    getline(cin, s);
    
    // Printing string : will execute print a and s
    cout << a << endl;
    cout << s << endl;
    
    return 0;
}

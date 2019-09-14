#include<iostream>
#include<string>
#include"zipcode.h"
using namespace std;

int a[5],b;
int main()
{
int d;
string BarCode;
cout<<"請選擇動作(0:結束程式;1:輸入字串；2:輸入整數)";
cin>>d;
    switch(d)
    {
        case 1:
        {
            cin>>BarCode;
            if(BarCode.length()!=27||(BarCode[0]!='1')||(BarCode[26]!='1') )cout<<"You enter a wrong code."<<endl;
            else
            {
                ZipCode A(BarCode.substr(1,5)),B(BarCode.substr(6,5)),C(BarCode.substr(11,5)),D(BarCode.substr(16,5)),E(BarCode.substr(21,5));
                if((A.erro+B.erro+C.erro+D.erro+E.erro)==0)
                {
                    cout<<"in num: "<<A.getnumber()<<B.getnumber()<<C.getnumber()<<D.getnumber()<<E.getnumber()<<endl;
                    cout<<"in str: ";
                    A.getString();B.getString();C.getString();D.getString();E.getString();
                    cout<<endl;
                }
                else cout<<"You enter a wrong code."<<endl;


            }
            break;
        }
        case 2:
        {
            int num;
            cin>>num;
            if(num>99999||num<0)
            {
                cout<<"error"<<endl;
            }
            else
            {
                ZipCode A((num/10000)),B((num%10000)/1000),C((num%1000)/100),D((num%100)/10),E(num%10);
                cout<<num<<endl;
                cout<<1;
                A.getString(),B.getString(),C.getString(),D.getString(),E.getString();
                cout<<1<<endl;
                break;
            }
        }
    }
return 0;
}

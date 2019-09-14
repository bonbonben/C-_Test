#include<iostream>
#include<string>
#include"zipcode.h"
ZipCode::ZipCode(int num)
{   erro=0;
    b=num;
}
ZipCode::ZipCode(string bar)
{
    erro=0;
    int one_num=0,wrong=0;
    for(int i=0;i<5;i++)
    {
        a[i]=(int)(bar[i]-'0');
        if(a[i]==1)one_num++;
        if(a[i]!=1&&a[i]!=0)wrong++;
    }
    if((one_num==2)&&(wrong==0))decode();
    else{erro++;}
}
void ZipCode::encode()
{
        switch(b)
        {
        case 0:{cout<<"11000";break;}
        case 1:{cout<<"00011";break;}
        case 2:{cout<<"00101";break;}
        case 3:{cout<<"00110";break;}
        case 4:{cout<<"01001";break;}
        case 5:{cout<<"01010";break;}
        case 6:{cout<<"01100";break;}
        case 7:{cout<<"10001";break;}
        case 8:{cout<<"10010";break;}
        case 9:{cout<<"10100";break;}
        }
}
void ZipCode::decode()
{
    b=a[0]*7+a[1]*4+a[2]*2+a[3]*1+a[4]*0;
    if(b==11)b=0;
}
int ZipCode::getnumber()
{
    return b;
}
void ZipCode::getString()
{
    encode();
}

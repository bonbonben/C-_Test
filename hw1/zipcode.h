#ifndef ZIPCODE_H_INCLUDED
#define ZIPCODE_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
class ZipCode
{
    public:
        int erro;
        ZipCode(int);
        ZipCode(string);
        void getString();
        int getnumber();
    private:
        void encode();
        void decode();
        int a[5],b;

};
#endif // ZIPCODE_H_INCLUDED


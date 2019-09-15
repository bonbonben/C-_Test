#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED
#include<iostream>
using namespace std;
class Rational
{
    friend ostream &operator<<(ostream &,const Rational &);
    friend istream &operator>>(istream &,Rational &);
    public:
        Rational();
        Rational(int);
        Rational(int,int);
        Rational operator+(Rational &);
        Rational operator-(Rational &);
        Rational operator*(Rational &);
        Rational operator/(Rational &);
        bool operator==( Rational &);
        bool operator>(Rational &);
        bool operator>=(Rational &);
        bool operator<(Rational &);
        bool operator<=(Rational &);
        int getnumerator();
        int getdenominator();
    private:
        int numerator,denominator;
        void positive();
        int gcd(int ,int);
};
#endif // RATIONAL_H_INCLUDED

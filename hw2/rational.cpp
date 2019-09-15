#include<iostream>
#include"rational.h"
void Rational::positive()
{
    if(denominator<0)
    {
        denominator*=(-1);
        numerator*=(-1);
    }
    int Gcd=gcd(numerator<0?-numerator:numerator,denominator);
    denominator/=Gcd;
    numerator/=Gcd;
}


int Rational::getnumerator()
{
    return numerator;
}
int Rational::getdenominator()
{
    return denominator;
}

ostream &operator<<(ostream &output,const Rational &object)
{
    output<<object.numerator<<"/"<<object.denominator;
    return output;
}

istream &operator>>(istream &input,Rational &object)
{
    input>>object.numerator;
    input.ignore();
    input>>object.denominator;
    object.positive();
    return input;
}

Rational::Rational():numerator(0),denominator(1)
{}
Rational::Rational(int n,int d):numerator(n),denominator(d)
{positive();}
Rational::Rational(int wholeNumber):numerator(wholeNumber),denominator(1)
{}



int Rational::gcd(int data1,int data2)
{
    if(data2==0)return data1;
    return gcd(data2,data1%data2);
}

Rational Rational::operator+(Rational &object)
{
    int n,d;
    d=denominator*object.getdenominator();
    n=numerator*object.getdenominator()+denominator*object.getnumerator();
    Rational result(n,d);
    return result;
}

Rational Rational::operator-(Rational &object)
{
    int n,d;
    d=denominator*object.getdenominator();
    n=numerator*object.getdenominator()-denominator*object.getnumerator();
    Rational result(n,d);
    return result;
}

Rational Rational::operator*(Rational &object)
{
    int n,d;
    d=denominator*object.getdenominator();
    n=numerator*object.getnumerator();
    Rational result(n,d);
    return result;
}

Rational Rational::operator/(Rational &object)
{
    int n,d;
    d=denominator*object.getnumerator();
    n=numerator*object.getdenominator();
    Rational result(n,d);
    return result;
}

bool Rational::operator==(Rational &object)
{
    if(numerator==object.getnumerator()&&denominator==object.getdenominator())return true;
    return false;
}

bool Rational::operator>(Rational &object)
{
    if(numerator*object.getdenominator()>denominator*object.getnumerator())return true;
    return false;
}
bool Rational::operator>=(Rational &object)
{
    if((*this)==object||(*this)>object)return true;
    return false;
}
bool Rational::operator<(Rational &object)
{
    return !((*this)>object);
}

bool Rational::operator<=(Rational &object)
{
    if((*this)==object||(*this)<object)return true;
    return false;
}

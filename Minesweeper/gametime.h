#ifndef GAMETIME_H
#define GAMETIME_H
#include<ctime>
class gametime
{
public:
void set();
void pass();
int getHr();
int getMin();
int getSec();
private:
time_t start;
time_t now;
int nowHr;
int nowMin;
int nowSec;
void record();
};
#endif // TIME_H_INCLUDED

#include<ctime>
#include"gametime.h"
void gametime::set()
{
    start=time(NULL);
    now=start;
    record();
}
void gametime::pass()
{
    now=time(NULL);
    record();
}
int gametime::getHr()
{
    return nowHr;
}
int gametime::getMin()
{
    return nowMin;
}
int gametime::getSec()
{
    return nowSec;
}
void gametime::record()
{
    nowHr=(int)((now-start)/3600);
    nowMin=(int)((now-start)%3600/60);
    nowSec=(int)((now-start)%60);
}

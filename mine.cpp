#include<iostream>
#include"mine.h"

char mine::openMap(int y,int x)
{
    return map[y][x];
}
void mine::setmine(int r,int c,int b)
{
    row=r;
    col=c;
    count=b;
    bomb(b);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(map[i][j]=='b'){continue;}
            else{saveNum(i,j);}
        }
    }
}
void mine::bomb(int n)
{
    int y;int x;
    srand(time(NULL));
    for(int num=n;num>=1;num--)
    {
        x=(rand()%col);
        y=(rand()%row);
        if(map[y][x]=='b')
        {
            num++;
            continue;
        }
        else{map[y][x]='b';}
    }
}

void mine::saveNum(int r,int c)
{
    int minrow=((r==0)?r:r-1);
    int maxrow=((r>=row)?r:r+1);
    int mincol=((c==0)?c:c-1);
    int maxcol=((c>=col)?c:c+1);
    map[r][c]='0';
    for(int i=minrow;i<=maxrow;i++)
    {
        for(int j=mincol;j<=maxcol;j++)
        {
            if(map[i][j]=='b')map[r][c]++;
        }
    }
}



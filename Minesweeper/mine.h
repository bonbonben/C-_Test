#ifndef MINE_H
#define MINE_H
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<ctime>
class mine
{
public:
char openMap(int,int);
void setmine(int,int,int);
void touch(int,int);
private:
char map[32][32];
int row,col,count;
void bomb(int);
void saveNum(int,int);
};
#endif // MINE_H_INCLUDED

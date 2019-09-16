#include"ncurses.h"
#include<iostream>
#include"mine.h"
#include"gametime.h"
#include<fstream>
using namespace std;
void spread(char map[][32],mine &,int,int,int,int);
int main()
{

fstream file;

int height,width,bombnum,flagnum=0,step=0;
int c,y=1,x=1,ch,hour,minute,second,open,flag,lose=0,win=0,sf=0;
char checkbomb='b';
char scrmap[32][32];
mine play; 
gametime clock;
cout<<"welcome to minesweeper!\n"<<"please select your level:\n"<<"1.9*9 mine with 10 bombs\n"<<"2.9*16 mine with 20 bombs\n"<<"3.16*16 mine with 40 bombs\n"<<"4.16*30 mine with 99 bombs\n"<<"5.30*30 mine with 150 bombs\n"<<endl;
cout<<"enter your choise :"<<endl;
cin>>ch;
switch(ch)
{
	case 1 :{height=9;width=9;bombnum=10;break;}
	case 2 :{height=9;width=16;bombnum=20;break;}
	case 3 :{height=16;width=16;bombnum=40;break;}
	case 4 :{height=16;width=30;bombnum=99;break;}
	case 5 :{height=30;width=30;bombnum=150;break;}
}
play.setmine(height,width,bombnum);
scrmap[0][0]='*';
scrmap[0][width+1]='*';
scrmap[height+1][0]='*';
scrmap[height+1][width+1]='*';
for(int i=1;i<=height;i++)
{
	scrmap[i][0]='|';
}
for(int j=1;j<=width;j++)
{
	scrmap[0][j]='-';
}
for(int i=1;i<=height;i++)
{
    scrmap[i][width+1]='|';
}
for(int j=1;j<=width;j++)
{
    scrmap[height+1][j]='-';
}

for(int i=1;i<height+1;i++)
{
	for(int j=1;j<width+1;j++)
	{
		scrmap[i][j]='.';
	}
}
initscr();
noecho();
cbreak();
nodelay(stdscr,TRUE);
keypad(stdscr,TRUE);
int go_on=TRUE;
clock.set();
mvprintw(1,width+5,"press 'o' to open,'f' to flag,'e'to exit");
start_color();
init_pair(1,COLOR_RED,COLOR_GREEN);
init_pair(2,COLOR_YELLOW,COLOR_BLACK);
init_pair(3,COLOR_BLUE,COLOR_BLACK);
init_pair(4,COLOR_RED,COLOR_BLACK);
init_pair(5,COLOR_GREEN,COLOR_BLACK);
while(go_on)
{
	sf=0;
	step=0;
	flagnum=0;
	open=0;
	for(int i=1;i<height+1;i++)
	{
		for(int j=1;j<width+1;j++)
		{
			if(scrmap[i][j]=='f')flagnum++;
		}
	}
	mvprintw(2,width+5,"flag=%3d",flagnum);
	if(flagnum!=0)
	{
		attron(COLOR_PAIR(5));
		mvprintw(2,width+5,"flag=%3d",flagnum);	
		attroff(COLOR_PAIR(5));
	}
	for(int i=0;i<height+2;i++)
	{
		for(int j=0;j<width+2;j++)
		{
			attron(COLOR_PAIR(2));	
			mvaddch(i,j,scrmap[i][j]);
			attroff(COLOR_PAIR(2));
		}
	}
	for(int i=1;i<height+1;i++)
    {
        for(int j=1;j<width+1;j++)
        {	
			if(scrmap[i][j]=='f')
            {
				attron(COLOR_PAIR(4));
                mvaddch(i,j,scrmap[i][j]);
                attroff(COLOR_PAIR(4));
			}
			else if(scrmap[i][j]!='f')
			{
				attron(COLOR_PAIR(3));
				mvaddch(i,j,scrmap[i][j]);
				attroff(COLOR_PAIR(3));
			}
        }
    }
	clock.pass();
	move(y,x);
	refresh();
	while((c=getch())==ERR)
	{
		clock.pass();
		hour=clock.getHr();
		minute=clock.getMin();
		second=clock.getSec();
		mvprintw(3,width+5,"time: %2d:%2d:%2d",hour,minute,second);
		move(y,x);
		refresh();
	}
	switch(c)
	{
		case KEY_LEFT:{--x;x=(x<1)?x+width:x;break;}
		case KEY_RIGHT:{++x;x=(x>width)?x-width:x;break;}
		case KEY_UP:{--y;y=(y<1)?y+height:y;break;}
		case KEY_DOWN:{++y;y=(y>height)?y-height:y;break;}
		case 'o':{if(scrmap[y][x]=='f'){open=0;}else if(scrmap[y][x]!='f'){open=1;}break;}
		case 'e':{go_on=FALSE;break;}
		case 'f':{if(scrmap[y][x]=='.'){scrmap[y][x]='f';}else if(scrmap[y][x]='f'){scrmap[y][x]='.';}break;}
	}
	/*mvprintw(4,width+5,"step=%3d",step);
    if(step!=0)
    {
        attron(COLOR_PAIR(5));
        mvprintw(4,width+5,"step=%3d",step);
        attroff(COLOR_PAIR(5));
    }*/
	if(open==1)
	{
		spread(scrmap,play,height,width,y,x);
		if(scrmap[y][x]=='b'){lose=1;}	
	}
	for(int i=1;i<height+1;i++)
    {
        for(int j=1;j<width+1;j++)
        {
			 mvaddch(i,j,play.openMap(i-1,j-1));
        }
    }			
	refresh();
	if(lose==1)
	{
		for(int i=1;i<height+1;i++)
		{
			for(int j=1;j<width+1;j++)
			{
				if(checkbomb==play.openMap(i-1,j-1)){scrmap[i][j]=play.openMap(i-1,j-1);}
				mvaddch(i,j,scrmap[i][j]);
				if(scrmap[i][j]=='b')
				{
				attron(COLOR_PAIR(1));
				mvaddch(i,j,scrmap[i][j]);
				attroff(COLOR_PAIR(1));
				}
			}
		}
		refresh();
		nodelay(stdscr,FALSE);
		go_on=0;
		attron(A_BLINK);
		mvprintw(5,width+5,"You lose!");
		attroff(A_BLINK);
		mvprintw(6,width+5,"Press any bottom to exit!");
		getch();
	}
	for(int i=1;i<height+1;i++)
	{
		for(int j=1;j<width+1;j++)
		{
			if(scrmap[i][j]=='.'||scrmap[i][j]=='f')sf++;
		}
	}
	if(sf==bombnum)win=1;
	if(win==1)
	{
		nodelay(stdscr,FALSE);
		go_on=0;
		attron(A_BLINK);
		mvprintw(5,width+5,"You win!");
		attroff(A_BLINK);
		mvprintw(6,width+5,"Press any bottom to exit!");
		getch();
	}

if(lose==1||win==1)
{
	file.open("Mine.txt",ios::out);
	for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            file<<play.openMap(i,j);
		}
		file<<'\n';
	}
}

}
endwin();
return 0;
}
void spread(char map[][32],mine &play,int height,int width,int y,int x)
{
    if(map[y][x]!='.'||y<1||x<1||y>height||x>width)
    {
        return;
    }
    map[y][x]=play.openMap(y-1,x-1);
	if(map[y][x]=='0')
    {
    spread(map,play,height,width,y-1,x);
    spread(map,play,height,width,y-1,x+1);
    spread(map,play,height,width,y-1,x-1);
    spread(map,play,height,width,y,x+1);
    spread(map,play,height,width,y,x-1);
    spread(map,play,height,width,y+1,x);
    spread(map,play,height,width,y+1,x-1);
    spread(map,play,height,width,y+1,x+1);
    }
}



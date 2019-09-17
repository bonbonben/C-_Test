#include <iostream>
#include <ncurses/curses.h>
#include <ctime>
#include <cstdlib>
#include "cube.hpp"
using namespace std;

static double background[21][22];

void print(int m, int n, int p[4][8])
{
   //覆蓋背景
    for(int b=0;b<20;b++)
       {
         for(int a=0;a<20;a++)
            {
               mvprintw(6+a,31+b," ");
            }
       }


   //印背景
   for(int a=0;a<22;a++)
   {
      for(int b=0;b<21;b++)
      {
         if(background[b][a] == 1)
         {
           attron(COLOR_PAIR(1));
           mvprintw(6+b,30+a," ");
           attroff(COLOR_PAIR(1));
         }

        else if(background[b][a] == 2)
        {
           attron(COLOR_PAIR(2));
           mvprintw(6+b,30+a," ");
           attroff(COLOR_PAIR(2));
        }

        else if(background[b][a] == 3)
        {
           attron(COLOR_PAIR(3));
           mvprintw(6+b,30+a," ");
           attroff(COLOR_PAIR(3));
        }

        else if(background[b][a] == 4)
        {
           attron(COLOR_PAIR(4));
           mvprintw(6+b,30+a," ");
           attroff(COLOR_PAIR(4));
        }

        else if(background[b][a] == 5)
        {
           attron(COLOR_PAIR(5));
           mvprintw(6+b,30+a," ");
           attroff(COLOR_PAIR(5));
        }

        else if(background[b][a] == 6)
        {
           attron(COLOR_PAIR(6));
           mvprintw(6+b,30+a," ");
           attroff(COLOR_PAIR(6));
        }

        else if(background[b][a] == 7)
        {
           attron(COLOR_PAIR(7));
           mvprintw(6+b,30+a," ");
           attroff(COLOR_PAIR(7));
        }
      }
   }


   //印邊框
   attron(COLOR_PAIR(6));
   mvaddstr(5,30,"                      ");
   mvaddstr(26,30,"                      ");
   for(int a=0;a<20;a++)
   {
      mvaddstr(6+a,30," ");
      mvaddstr(6+a,51," ");
   }
   attroff(COLOR_PAIR(6));


   //印方塊
   for(int b=0;b<4;b++)
      {
         for(int a=0;a<8;a++)
            {
               if(p[b][a] == 1)
                  {
                      if(n>=10)
                     {
                         attron(COLOR_PAIR(1));
                         mvprintw(n-4+b,m+a," ");
                         attroff(COLOR_PAIR(1));
                     }
                  }

               if(p[b][a] == 2)
                  {
                      if(n>=10)
                     {
                         attron(COLOR_PAIR(2));
                         mvprintw(n-4+b,m+a," ");
                         attroff(COLOR_PAIR(2));
                     }
                  }

               if(p[b][a] == 3)
                  {
                      if(n>=10)
                     {
                         attron(COLOR_PAIR(3));
                         mvprintw(n-4+b,m+a," ");
                         attroff(COLOR_PAIR(3));
                     }
                  }

               if(p[b][a] == 4)
                  {
                      if(n>=10)
                     {
                         attron(COLOR_PAIR(4));
                         mvprintw(n-4+b,m+a," ");
                         attroff(COLOR_PAIR(4));
                     }
                  }

               if(p[b][a] == 5)
                  {
                      if(n>=10)
                     {
                         attron(COLOR_PAIR(5));
                         mvprintw(n-4+b,m+a," ");
                         attroff(COLOR_PAIR(5));
                     }
                  }

               if(p[b][a] == 6)
                  {
                      if(n>=10)
                     {
                         attron(COLOR_PAIR(6));
                         mvprintw(n-4+b,m+a," ");
                         attroff(COLOR_PAIR(6));
                     }
                  }

               if(p[b][a] == 7)
                  {
                      if(n>=10)
                     {
                         attron(COLOR_PAIR(7));
                         mvprintw(n-4+b,m+a," ");
                         attroff(COLOR_PAIR(7));
                     }
                  }

            }
      }
}//print()

//判斷能不能右移
bool checkright(int v, int w, int r[4][8])
{
   for(int b =0;b<8;b++)
   {
      for(int a=0;a<4;a++)
      {
          if(r[a][b]!=0 && background[w-10+a][9+v-39+b+1]!=0 )
          {
             return true;
          }
      }
   }
}//checkright()

//判斷能不能左移
bool checkleft(int j, int k, int l[4][8])
{
   for(int b =7;b>=0;b--)
   {
      for(int a=0;a<4;a++)
      {
          if(l[a][b]!=0 && background[k-10+a][9+j-39+b-1]!=0)
          {
             return true;
          }
      }
   }
}//checkleft()

int main()
{
   int width,height;
   double u, v, x ,y;
   int xx, yy, c, go_on, go_on2;
   srand(time(NULL));

   initscr();
   cbreak();
   noecho();
   keypad(stdscr, TRUE);
   nodelay(stdscr, TRUE);
   getmaxyx(stdscr, height, width);

   MINO_O my1;
   MINO_I my2;
   MINO_J my3;
   MINO_L my4;
   MINO_Z my5;
   MINO_S my6;
   MINO_T my7;
   MINO_O *mm;

   my1.setcube_O();
   my2.setcube_I();
   my3.setcube_J();
   my4.setcube_L();
   my5.setcube_Z();
   my6.setcube_S();
   my7.setcube_T();

   //顏色
   start_color();
   init_pair(1, COLOR_RED, COLOR_RED);
   init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
   init_pair(3, COLOR_GREEN, COLOR_GREEN);
   init_pair(4, COLOR_BLUE, COLOR_BLUE);
   init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
   init_pair(6, COLOR_CYAN, COLOR_CYAN);
   init_pair(7, COLOR_WHITE, COLOR_WHITE);
   init_pair(8, COLOR_YELLOW, COLOR_BLACK);
   init_pair(9, COLOR_GREEN, COLOR_BLACK);

   //背景陣列數值皆設為0
   for(int b=0;b<22;b++)
   {
      for(int a=0;a<21;a++)
      {
         background[a][b] = 0;
      }
   }


   //左右牆為8
   for(int a=0;a<20;a++)
   {
      background[a][0] = 8;
      background[a][21] = 8;
   }

   //下面為9
   for(int a=0;a<22;a++)
   {
      background[20][a] = 9;
   }

   bool stopstart = true;
   int t = 0;
   int t2 = 0;

   //時間
   time_t tstart,tnow;
      tstart = time(NULL);

   v = 1;
   go_on2 = 1;
   int grade = 0;
   int s = 8000;

   while (go_on2)
   {
      go_on = 1;
      x = 39;
      y = 10;
      int r;
      bool boolright = false, boolleft = false;

      r = rand() % 7+1;
      int mino[4][8];
      //mvprintw(3,1,"%d",r);

switch (r)
{
   case 1 :
      mm=&my1;
      for(int a=0;a<8;a++)
      {
         for(int b=0;b<4;b++)
         {
            mino[b][a] = my1.getcube(b, a);
         }
      }
      break;

   case 2 :
      mm=&my2;
      for(int a=0;a<8;a++)
      {
         for(int b=0;b<4;b++)
         {
            mino[b][a] = my2.getcube(b, a);
         }
      }
      break;

   case 3 :
      mm=&my3;
      for(int a=0;a<8;a++)
      {
         for(int b=0;b<4;b++)
         {
            mino[b][a] = my3.getcube(b, a);
         }
      }
      break;

   case 4 :
      mm=&my4;
      for(int a=0;a<8;a++)
      {
         for(int b=0;b<4;b++)
         {
            mino[b][a] = my4.getcube(b, a);
         }
      }
      break;

   case 5 :
      mm=&my5;
      for(int a=0;a<8;a++)
      {
         for(int b=0;b<4;b++)
         {
            mino[b][a] = my5.getcube(b, a);
         }
      }
      break;

   case 6 :
      mm=&my6;
      for(int a=0;a<8;a++)
      {
         for(int b=0;b<4;b++)
         {
           mino[b][a] = my6.getcube(b, a);
         }
      }
      break;

   case 7 :
      mm=&my7;
      for(int a=0;a<8;a++)
      {
         for(int b=0;b<4;b++)
         {
           mino[b][a] = my7.getcube(b, a);
         }
      }
      break;
} //switch

bool stopnow = true;


while (go_on)
{

   c = getch();

   if(stopnow == true)
   {

   time(&tnow);

   attron(COLOR_PAIR(5));
   mvaddstr(6, 60, "                 ");
   mvaddstr(11, 60, "                 ");

   for(int a=7;a<11;a++)
   {
      mvaddstr(a, 60 ," ");
      mvaddstr(a, 76 ," ");
   }
   attroff(COLOR_PAIR(5));

   attron(COLOR_PAIR(8));
   mvaddstr(8, 63,"TIME : ");
   mvprintw(8, 70, "%d", t2 + tnow - tstart);
   mvaddstr(9, 63, "GRADE : ");
   mvprintw(9, 71, "%d", grade);
   attroff(COLOR_PAIR(8));

   attron(COLOR_PAIR(5));
   mvaddstr(13, 60, "                                   ");
   mvaddstr(26, 60, "                                   ");

   for(int a=14;a<26;a++)
   {
      mvaddstr(a, 60 ," ");
      mvaddstr(a, 94 ," ");
   }

   attroff(COLOR_PAIR(5));

   attron(COLOR_PAIR(9));
   mvaddstr(15, 63, "KEY_DOWN : mino falls down");
   mvaddstr(16, 63, "KEY_LEFT : mino moves left");
   mvaddstr(17, 63, "KEY_RIGHT : mino moves right");
   mvaddstr(18, 63, "KEY_UP : turn the mino");
   mvaddstr(20, 63, "P : pause");
   mvaddstr(21, 63, "C : continue");
   mvaddstr(22, 63, "U : speed up");
   mvaddstr(23, 63, "D : speed down");
   mvaddstr(24, 63, "Q : quit the game");
   attron(COLOR_PAIR(9));

   xx = x;
   yy = y;

   int lonly = 0, lonly2 = 0;

   //判斷方塊寬度
   for(int a=0, b=0;a<8;a++)
   {
      if(mino[b][a] == 0 && mino[b+1][a] == 0 && mino[b+2][a] == 0 && mino[b+3][a] == 0)
      {
         lonly = a - 3;
         break;
      }
      if(a==7) lonly = a - 2;
   }
   //mvprintw(0,0,"%d",lonly);

   //判斷方塊長度
   for(int a=3, b=0;a>=0;a--)
   {
      if(mino[a][b]!=0 || mino[a][b+1]!=0 || mino[a][b+2]!=0 || mino[a][b+3]!=0 || mino[a][b+4]!=0 || mino[a][b+5]!=0 || mino[a][b+6]!=0 || mino[a][b+7]!=0)
      {
         lonly2 = 3 - a;
         break;
      }
   }
   // mvprintw(0,0,"%d",lonly2);

   print(x, y, mino);

   //消行
   for(int a=19;a>0;a--)
   {
      if(background[a][1]!= 0 && background[a][2]!= 0 && background[a][3]!= 0 && background[a][4]!= 0 && background[a][5]!= 0 && background[a][6]!= 0 && background[a][7]!= 0 && background[a][8]!= 0 && background[a][9]!= 0 && background[a][10]!= 0 && background[a][11]!= 0 && background[a][12]!= 0 && background[a][13]!= 0 && background[a][14]!= 0 && background[a][15]!= 0 && background[a][16]!= 0 && background[a][17]!= 0 && background[a][18]!= 0 && background[a][19]!= 0 && background[a][20]!= 0)
      {
         int c;
         c = a;
         for(c;c>0;c--)
         {
            for(int b=1;b<21;b++)
            {
               background[c][b] = background[c-1][b];
            }
         }

         if(s >= 8000)
         {
            grade = grade + 10;
         }

        if(s == 6000)
         {
            grade = grade + 15;
         }

         if(s == 4000)
         {
            grade = grade + 20;
         }

         if(s == 2000)
         {
            grade = grade + 25;
         }
      }
   }

    for(int a=1;a<21;a++)
   {
      if(background[0][a]!= 0 && background[1][a]!= 0 && background[2][a]!= 0 && background[3][a]!= 0 && background[4][a]!= 0 && background[5][a]!= 0 && background[6][a]!= 0 && background[7][a]!= 0 && background[8][a]!= 0 && background[9][a]!= 0 && background[10][a]!= 0 && background[11][a]!= 0 && background[12][a]!= 0 && background[13][a]!= 0 && background[14][a]!= 0 && background[15][a]!= 0 && background[16][a]!= 0 && background[17][a]!= 0 && background[18][a]!= 0 && background[19][a]!= 0 &&  background[20][a]!= 0)
      {
         go_on = 0;
         go_on2 = 0;
         stopnow = false;

         attron(COLOR_PAIR(1));
         mvaddstr(15, 33, "        ");
         mvaddstr(16, 33, "  ");
         mvaddstr(17, 33, "  ");
         mvaddstr(17, 37,"    ");
         mvaddstr(18, 33, "  ");
         mvaddstr(18, 39, "  ");
         mvaddstr(19, 33, "        ");
         attroff(COLOR_PAIR(1));
      }
   }

   y += v/s;

   for(int a=0;a<4;a++)
   {
      for(int b=0;b<8;b++)
      {
          if(mino[a][b]!=0 && background[yy-10+1+a][9+xx-39+b]!=0)
          {
             for(int c=0;c<4;c++)
             {
                for(int d=0;d<8;d++)
                {
                   if(mino[c][d]!=0)
                   background[yy-10+c][9+xx-39+d] = mino[c][d];
                }
             }
             go_on = 0;
          }
      }
   }

  /* for(int b=0;b<22;b++)
   {
      for(int a=0;a<21;a++)
      {
          if(background[a][b] == 0)
          mvprintw(6+a,60+b,"0");

          else if(background[a][b] == 1)
          mvprintw(6+a,60+b,"1");

          else if(background[a][b] == 2)
          mvprintw(6+a,60+b,"2");

          else if(background[a][b] == 3)
          mvprintw(6+a,60+b,"3");

          else if(background[a][b] == 4)
          mvprintw(6+a,60+b,"4");

          else if(background[a][b] == 5)
          mvprintw(6+a,60+b,"5");

          else if(background[a][b] == 6)
          mvprintw(6+a,60+b,"6");

          else if(background[a][b] == 7)
          mvprintw(6+a,60+b,"7");

          else if(background[a][b] == 8)
          mvprintw(6+a,60+b,"8");

          else if(background[a][b] == 9)
          mvprintw(6+a,60+b,"9");

      }
   }
*/

   while (x < 31)  x = 31;
   while (x > 48 - lonly)  x = 48 - lonly;
   while (y > 29 + lonly2 - 2)  y = 29 + lonly2 - 2;

}//stopnow

      switch (c)
         {
            case KEY_LEFT:
               boolleft = checkleft(xx, yy, mino);
               if(boolleft != true)
                  x = x-2; break;

            case KEY_RIGHT:
               boolright = checkright(xx, yy, mino);
               if(boolright != true)
                  x = x+2; break;

            case KEY_UP:
               mm->turn();
               for(int a=0;a<8;a++)
               {
                  for(int b=0;b<4;b++)
                  {
                     mino[b][a] = mm->getcube(b, a);
                  }
               }
               break;
            case KEY_DOWN: ++y; break;

            case 'P':
              stopstart = false;
              stopnow = false;
              t2 = t2 + tnow - tstart;

              attron(COLOR_PAIR(2));
              mvaddstr(6, 1, "      ");
              mvaddstr(7, 1, "  ");
              mvaddstr(7, 5, "  ");
              mvaddstr(8, 1, "      ");
              mvaddstr(9, 1, "  ");
              mvaddstr(10,1, "  ");

              mvaddstr(6, 10, "  ");
              mvaddstr(7, 8, "  ");
              mvaddstr(7, 12, "  ");
              mvaddstr(8, 8, "      ");
              mvaddstr(9, 8, "  ");
              mvaddstr(9, 12, "  ");
              mvaddstr(10, 8, "  ");
              mvaddstr(10, 12, "  ");

              mvaddstr(6, 15, "  ");
              mvaddstr(6, 19, "  ");
              mvaddstr(7, 15, "  ");
              mvaddstr(7, 19, "  ");
              mvaddstr(8, 15, "  ");
              mvaddstr(8, 19, "  ");
              mvaddstr(9, 15, "  ");
              mvaddstr(9, 19, "  ");
              mvaddstr(10, 15, "      ");

              mvaddstr(13, 10,"      ");
              mvaddstr(14, 10,"  ");
              mvaddstr(15, 10,"      ");
              mvaddstr(16, 14,"  ");
              mvaddstr(17, 10,"      ");

              mvaddstr(13, 17, "      ");
              mvaddstr(14, 17, "  ");
              mvaddstr(15, 17, "      ");
              mvaddstr(16, 17, "  ");
              mvaddstr(17, 17, "      ");

              mvaddstr(17, 24, " ");
              mvaddstr(17, 26, " ");
              mvaddstr(17, 28, " ");

              attroff(COLOR_PAIR(2));

              break;

            case 'p':
              stopstart = false;
              stopnow = false;
              t2 = t2 +tnow - tstart;

              attron(COLOR_PAIR(2));
              mvaddstr(6, 1, "      ");
              mvaddstr(7, 1, "  ");
              mvaddstr(7, 5, "  ");
              mvaddstr(8, 1, "      ");
              mvaddstr(9, 1, "  ");
              mvaddstr(10,1, "  ");

              mvaddstr(6, 10, "  ");
              mvaddstr(7, 8, "  ");
              mvaddstr(7, 12, "  ");
              mvaddstr(8, 8, "      ");
              mvaddstr(9, 8, "  ");
              mvaddstr(9, 12, "  ");
              mvaddstr(10, 8, "  ");
              mvaddstr(10, 12, "  ");

              mvaddstr(6, 15, "  ");
              mvaddstr(6, 19, "  ");
              mvaddstr(7, 15, "  ");
              mvaddstr(7, 19, "  ");
              mvaddstr(8, 15, "  ");
              mvaddstr(8, 19, "  ");
              mvaddstr(9, 15, "  ");
              mvaddstr(9, 19, "  ");
              mvaddstr(10, 15, "      ");

              mvaddstr(13, 10,"      ");
              mvaddstr(14, 10,"  ");
              mvaddstr(15, 10,"      ");
              mvaddstr(16, 14,"  ");
              mvaddstr(17, 10,"      ");

              mvaddstr(13, 17, "      ");
              mvaddstr(14, 17, "  ");
              mvaddstr(15, 17, "      ");
              mvaddstr(16, 17, "  ");
              mvaddstr(17, 17, "      ");

              mvaddstr(17, 24, " ");
              mvaddstr(17, 26, " ");
              mvaddstr(17, 28, " ");

              attroff(COLOR_PAIR(2));

              break;

            case 'C':
              stopnow = true;
              tstart = time(NULL);

              for(int a=6; a<18; a++)
              {
                 for(int b=0;b<30;b++)
                 {
                    mvaddstr(a, b, " ");
                 }
              }
              break;

            case 'c':
              stopnow = true;
              tstart = time(NULL);

              for(int a=6; a<18; a++)
              {
                 for(int b=0;b<30;b++)
                 {
                    mvaddstr(a, b, " ");
                 }
              }
              break;

            case 'u' :
              if (s > 3000)
              {
                 s = s - 2000;
              }
              break;

            case 'U' :
              if (s > 3000)
              {
                 s = s - 2000;
              }
              break;

            case 'd' :
               s = s + 2000;
               break;

            case 'D' :
               s = s + 2000;
               break;


            case 'Q': go_on = 0; go_on2 = 0;// quit
            case 'q': go_on = 0; go_on2 = 0;break;
         } // switch (c)
move(0, 0);
} // while (go_on)

}//while (go_on2)

      endwin();
      return 0;
}//main

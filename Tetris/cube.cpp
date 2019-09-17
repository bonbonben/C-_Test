//cube.cpp
#include"cube.h"

void MINO_O::setcube_O()
{
   num = 1;
   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         mino_1[a][b] = mino_2[a][b] =  mino_3[a][b] = mino_4[a][b] = 0;

   mino_1[0][0] = mino_1[0][1] = mino_1[0][2] = mino_1[0][3] = 1;
   mino_1[1][0] = mino_1[1][1] = mino_1[1][2] = mino_1[1][3] = 1;

   mino_2[0][0] = mino_2[0][1] = mino_2[0][2] = mino_2[0][3] = 1;
   mino_2[1][0] = mino_2[1][1] = mino_2[1][2] = mino_2[1][3] = 1;

   mino_3[0][0] = mino_3[0][1] = mino_3[0][2] = mino_3[0][3] = 1;
   mino_3[1][0] = mino_3[1][1] = mino_3[1][2] = mino_3[1][3] = 1;

   mino_4[0][0] = mino_4[0][1] = mino_4[0][2] = mino_4[0][3] = 1;
   mino_4[1][0] = mino_4[1][1] = mino_4[1][2] = mino_4[1][3] = 1;

   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         nowcube[a][b] = mino_1[a][b];

}

int MINO_O::getcube(int i, int j)
{
   return nowcube[i][j];
}

void MINO_O::turn()
{
   num++;
   if(num == 5)
      num = 1;

   switch(num)
   {
       case 1:
            for(int b=0;b<8;b++)
               for(int a=0;a<4;a++)
                  nowcube[a][b] = mino_1[a][b];
            break;

       case 2:
            for(int b=0;b<8;b++)
               for(int a=0;a<4;a++)
                  nowcube[a][b] = mino_2[a][b];
            break;

       case 3:
            for(int b=0;b<8;b++)
               for(int a=0;a<4;a++)
                  nowcube[a][b] = mino_3[a][b];
            break;

       case 4:
            for(int b=0;b<8;b++)
               for(int a=0;a<4;a++)
                  nowcube[a][b] = mino_4[a][b];
            break;
   }
}


void MINO_I::setcube_I()
{
   num = 1;
   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         mino_1[a][b] = mino_2[a][b] =  mino_3[a][b] = mino_4[a][b] = 0;

   mino_1[0][0] = mino_1[0][1] = mino_1[0][2] = mino_1[0][3] = 2;
   mino_1[0][4] = mino_1[0][5] = mino_1[0][6] = mino_1[0][7] = 2;

   mino_2[0][0] = mino_2[0][1] = mino_2[1][0] = mino_2[1][1] = 2;
   mino_2[2][0] = mino_2[2][1] = mino_2[3][0] = mino_2[3][1] = 2;

   mino_3[0][0] = mino_3[0][1] = mino_3[0][2] = mino_3[0][3] = 2;
   mino_3[0][4] = mino_3[0][5] = mino_3[0][6] = mino_3[0][7] = 2;

   mino_4[0][0] = mino_4[0][1] = mino_4[1][0] = mino_4[1][1] = 2;
   mino_4[2][0] = mino_4[2][1] = mino_4[3][0] = mino_4[3][1] = 2;

   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         nowcube[a][b] = mino_1[a][b];

}

void MINO_J::setcube_J()
{
   num = 1;
   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         mino_1[a][b] = mino_2[a][b] =  mino_3[a][b] = mino_4[a][b] = 0;

   mino_1[0][0] = mino_1[0][1] = mino_1[1][0] = mino_1[1][1] = 3;
   mino_1[1][2] = mino_1[1][3] = mino_1[1][4] = mino_1[1][5] = 3;

   mino_2[0][0] = mino_2[0][1] = mino_2[0][2] = mino_2[0][3] = 3;
   mino_2[1][0] = mino_2[1][1] = mino_2[2][0] = mino_2[2][1] = 3;

   mino_3[0][0] = mino_3[0][1] = mino_3[0][2] = mino_3[0][3] = 3;
   mino_3[0][4] = mino_3[0][5] = mino_3[1][4] = mino_3[1][5] = 3;

   mino_4[0][2] = mino_4[0][3] = mino_4[1][2] = mino_4[1][3] = 3;
   mino_4[2][0] = mino_4[2][1] = mino_4[2][2] = mino_4[2][3] = 3;

   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         nowcube[a][b] = mino_1[a][b];

}

void MINO_L::setcube_L()
{
   num = 1;
   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         mino_1[a][b] = mino_2[a][b] =  mino_3[a][b] = mino_4[a][b] = 0;

   mino_1[0][4] = mino_1[0][5] = mino_1[1][0] = mino_1[1][1] = 4;
   mino_1[1][2] = mino_1[1][3] = mino_1[1][4] = mino_1[1][5] = 4;

   mino_2[0][0] = mino_2[0][1] = mino_2[1][0] = mino_2[1][1] = 4;
   mino_2[2][0] = mino_2[2][1] = mino_2[2][2] = mino_2[2][3] = 4;

   mino_3[0][0] = mino_3[0][1] = mino_3[0][2] = mino_3[0][3] = 4;
   mino_3[0][4] = mino_3[0][5] = mino_3[1][0] = mino_3[1][1] = 4;

   mino_4[0][0] = mino_4[0][1] = mino_4[0][2] = mino_4[0][3] = 4;
   mino_4[1][2] = mino_4[1][3] = mino_4[2][2] = mino_4[2][3] = 4;

   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         nowcube[a][b] = mino_1[a][b];

}

void MINO_Z::setcube_Z()
{
   num = 1;
   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         mino_1[a][b] = mino_2[a][b] =  mino_3[a][b] = mino_4[a][b] = 0;

   mino_1[0][0] = mino_1[0][1] = mino_1[0][2] = mino_1[0][3] = 5;
   mino_1[1][2] = mino_1[1][3] = mino_1[1][4] = mino_1[1][5] = 5;

   mino_2[0][2] = mino_2[0][3] = mino_2[1][0] = mino_2[1][1] = 5;
   mino_2[1][2] = mino_2[1][3] = mino_2[2][0] = mino_2[2][1] = 5;

   mino_3[0][0] = mino_3[0][1] = mino_3[0][2] = mino_3[0][3] = 5;
   mino_3[1][2] = mino_3[1][3] = mino_3[1][4] = mino_3[1][5] = 5;

   mino_4[0][2] = mino_4[0][3] = mino_4[1][0] = mino_4[1][1] = 5;
   mino_4[1][2] = mino_4[1][3] = mino_4[2][0] = mino_4[2][1] = 5;

   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         nowcube[a][b] = mino_1[a][b];

}

void MINO_S::setcube_S()
{
   num = 1;
   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         mino_1[a][b] = mino_2[a][b] =  mino_3[a][b] = mino_4[a][b] = 0;

   mino_1[0][2] = mino_1[0][3] = mino_1[0][4] = mino_1[0][5] = 6;
   mino_1[1][0] = mino_1[1][1] = mino_1[1][2] = mino_1[1][3] = 6;

   mino_2[0][0] = mino_2[0][1] = mino_2[1][0] = mino_2[1][1] = 6;
   mino_2[1][2] = mino_2[1][3] = mino_2[2][2] = mino_2[2][3] = 6;

   mino_3[0][2] = mino_3[0][3] = mino_3[0][4] = mino_3[0][5] = 6;
   mino_3[1][0] = mino_3[1][1] = mino_3[1][2] = mino_3[1][3] = 6;

   mino_4[0][0] = mino_4[0][1] = mino_4[1][0] = mino_4[1][1] = 6;
   mino_4[1][2] = mino_4[1][3] = mino_4[2][2] = mino_4[2][3] = 6;

   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         nowcube[a][b] = mino_1[a][b];

}

void MINO_T::setcube_T()
{
   num = 1;
   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         mino_1[a][b] = mino_2[a][b] =  mino_3[a][b] = mino_4[a][b] = 0;

   mino_1[0][2] = mino_1[0][3] = mino_1[1][0] = mino_1[1][1] = 7;
   mino_1[1][2] = mino_1[1][3] = mino_1[1][4] = mino_1[1][5] = 7;

   mino_2[0][0] = mino_2[0][1] = mino_2[1][0] = mino_2[1][1] = 7;
   mino_2[1][2] = mino_2[1][3] = mino_2[2][0] = mino_2[2][1] = 7;

   mino_3[0][0] = mino_3[0][1] = mino_3[0][2] = mino_3[0][3] = 7;
   mino_3[0][4] = mino_3[0][5] = mino_3[1][2] = mino_3[1][3] = 7;

   mino_4[0][2] = mino_4[0][3] = mino_4[1][0] = mino_4[1][1] = 7;
   mino_4[1][2] = mino_4[1][3] = mino_4[2][2] = mino_4[2][3] = 7;

   for(int b=0;b<8;b++)
      for(int a=0;a<4;a++)
         nowcube[a][b] = mino_1[a][b];

}

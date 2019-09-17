#ifndef CUBE1_H_INCLUDED
#define CUBE1_H_INCLUDED
//MINO_O.hpp
class MINO_O
{
public:
   int mino_1[4][8];
   int mino_2[4][8];
   int mino_3[4][8];
   int mino_4[4][8];
   int nowcube[4][8];
   int num;

   void setcube_O();
   int getcube(int, int);
   void turn();

};

//MINO_I.hpp
class MINO_I : public MINO_O
{
public:
      void setcube_I();
};

//MINO_J.hpp
class MINO_J : public MINO_O
{
public:
      void setcube_J();
};

//MINO_L.hpp
class MINO_L : public MINO_O
{
public:
      void setcube_L();
};

//MINO_Z.hpp
class MINO_Z : public MINO_O
{
public:
      void setcube_Z();
};

//MINO_S.hpp
class MINO_S : public MINO_O
{
public:
      void setcube_S();
};

//MINO_T.hpp
class MINO_T : public MINO_O
{
public:
      void setcube_T();
};


#endif // CUBE1_H_INCLUDED

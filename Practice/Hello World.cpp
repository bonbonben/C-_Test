#include <iostream>

class temp
{
  public:
    void test2()
    {
      std::cout << "Hello World!\n" << std::endl;
    }
};

void test()
{
  std::cout << "Hello World!" << std::endl;
}

int main()
{
  temp t;
  
  std::cout << "Hello World!" << std::endl;
  printf("Hello World!\n");
  fprintf(stdout, "Hello World!\n");
  test();
  t.test2();
  
  return 0;
}

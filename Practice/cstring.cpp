#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  char arr[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
  cout << "end of char array has \\0: " << arr << "\n" << endl;

  char src[11] = "0123456789";
  char dest[11];
  memcpy(dest, src, sizeof(src));
  cout << "memcpy result: " << dest << "\n";
  memmove(dest, src, sizeof(src));
  cout << "memmove result: " << dest << "\n";
  memset(dest, 0, sizeof(src));
  cout << "memset  result: " << dest << "\n";
  strcpy(dest, src);
  cout << "strcpy  result: " << dest << "\n";
  memmove(dest + 4, dest + 3, 3);
  cout << "move 345 to 456: " << dest << "\n" << endl;

  char *pch;
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  memcpy(&a[4], a, sizeof(int) * 6);
  cout << "copy 012345 to 456789: ";
  for (int i = 0; i < 10; i++)
  {
    cout << a[i];
  }
  cout << "\n";
  memmove(&a[4], a, sizeof(int) * 6);
  cout << "move 012301 to 012345: ";
  for (int i = 0; i < 10; i++)
  {
    cout << a[i];
  }
  cout << "\n" << endl;

  pch = (char*)memchr(arr, '6', 10);
  if(pch != NULL)
  {
    cout << "'6' found at position " << (pch - arr + 1) << " in char array" << "\n";
  }
  else
  {
    cout << "no found" << "\n";
  }
  memset(arr,'a',5);
  cout << "replace 12345 with a: ";
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i];
  }
  cout << endl;

  return 0;
}

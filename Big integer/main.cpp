#include <iostream>
#include <string>

#include "./inc/Big_Integer.h"

#include <sys/time.h>

using namespace std;

void from_string_test();

BigInt str0[500000];

int main(const int argc, const char **argv)
{
  from_string_test();

  return 0;
}

void from_string_test()
{
  //performance testing
  struct timeval start, end;
  gettimeofday(&start, NULL);

  for (int i = 0; i < 500000; ++i)
  {
    str0[i].from_string("170141183460469231731687303715884105727");
  }

  gettimeofday(&end, NULL);
  printf("Time taken: %ld micro seconds\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));

  //for (int i = 0; i < 5000; ++i)
  //{
  //  str0[i].Debug1("str1");
  //}

  cout << "\n//====================================//" << endl;
  BigInt str1;
  str1.from_string("170141183460469231731687303715884105727");
  str1.Debug1("str1");

  str1.from_string("18446744073709551616");
  str1.Debug1("str1");

  str1.from_string("9223372036854775808");
  str1.Debug1("str1");

  str1.from_string("1");
  str1.Debug1("str1");

  str1.from_string("0");
  str1.Debug1("str1");

  str1.from_string("-0");
  str1.Debug1("str1");

  str1.from_string("-1");
  str1.Debug1("str1");

  str1.from_string("-9223372036854775808");
  str1.Debug1("str1");

  str1.from_string("-18446744073709551616");
  str1.Debug1("str1");

  str1.from_string("-170141183460469231731687303715884105728");
  str1.Debug1("str1");

  str1.from_string("1234567890123456789012345678901234567890");
  str1.Debug1("str1");

  str1.from_string("-1234567890123456789012345678901234567890");
  str1.Debug1("str1");

  str1.from_string("170141183460469231731687303715884105726");
  str1.Debug1("str1");

  str1.from_string("170141183460469231731687303715884105728");
  str1.Debug1("str1");

  str1.from_string("-170141183460469231731687303715884105729");
  str1.Debug1("str1");

  str1.from_string("-170141183460469231731687303715884105727");
  str1.Debug1("str1");

  str1.from_string("340282366920938463463374607431768211455");
  str1.Debug1("str1");

  str1.from_string("-340282366920938463463374607431768211455");
  str1.Debug1("str1");

  str1.from_string("340282366920938463463374607431768211456");
  str1.Debug1("str1");

  str1.from_string("-340282366920938463463374607431768211456");
  str1.Debug1("str1");

  return;
}

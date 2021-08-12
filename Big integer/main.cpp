#include <iostream>
#include <string>
#include <ctime>

#include "./inc/Big_Integer.h"

#include <sys/time.h>

using namespace std;

void constructor_test();

void from_string_test();
void to_string_test();

void addition_test();
void subtraction_test();
void multiplication_test();
void div_mod_test();

void shl_test();
void shr_test();

void unary_plus_test();
void unary_minus_test();

void basic_assignment_operator_test();

void addition_operator_test();
void subtraction_operator_test();
void multiplication_operator_test();
void division_modulo_operator_test();
void addition_assignment_operator_test();
void subtraction_assignment_operator_test();
void multiplication_assignment_operator_test();
void division_assignment_operator_test();
void modulo_assignment_operator_test();

void compare_equalto_test();
void compare_lessthan_test();
void increment_prefix_test();
void increment_postfix_test();
void decrement_prefix_test();
void decrement_postfix_test();

void equal_to_operator_test();
void not_equal_to_operator_test();
void greater_than_operator_test();
void less_than_operator_test();
void greater_than_or_equal_to_operator_test();
void less_than_or_equal_to_operator_test();

void logical_negation_test();
void logical_AND_test();
void logical_OR_test();
void bitwise_NOT_test();
void bitwise_AND_test();
void bitwise_OR_test();
void bitwise_XOR_test();
void bitwise_AND_assignment_operator_test();
void bitwise_OR_assignment_operator_test();
void bitwise_XOR_assignment_operator_test();

void bitwise_left_shift_int32_test();
void bitwise_left_shift_bigint_test();
void bitwise_right_shift_int32_test();
void bitwise_right_shift_bigint_test();
void bitwise_left_shift_int32_assignment_operator_test();
void bitwise_left_shift_bigint_assignment_operator_test();
void bitwise_right_shift_int32_assignment_operator_test();
void bitwise_right_shift_bigint_assignment_operator_test();

void istream_ostream_operator_test();

void sign_test();

int g_error_count = 0;
bool g_test_exception_from_str = false;
bool g_test_exception_div = false;

void check_value(BigInt value, uint64_t elm3, uint64_t elm2, uint64_t elm1, uint64_t elm0, int line, bool& _result)
{
//  BigInt answer_elm3((uint64_t)elm3);
//  answer_elm3 = answer_elm3 << 192;
//  BigInt answer_elm2((uint64_t)elm2);
//  answer_elm2 = answer_elm2 << 128;
//  BigInt answer_elm1((uint64_t)elm1);
//  answer_elm1 = answer_elm1 << 64;
//  BigInt answer_elm0((uint64_t)elm0);
//  BigInt answer;
//  answer = answer_elm3 + answer_elm2 + answer_elm1 + answer_elm0;
  uint64_t elms[] = {elm0, elm1, elm2, elm3};
  //if (value != answer)
  if (!value.debug(elms))
  {
    ++g_error_count;
    cout << endl;
    cout << "ERROR at line " << line << " !" << endl;
    cout << hex << "expecting output : " << elm3 << " " << elm2 << " " << elm1 << " " << elm0 << dec << endl;
    cout << "retrieved output : " << endl;
    value.debug();
    cout << endl;
    _result = false;
  }
  return;
}

void check_value(bool input, bool expect, int line, bool& _result)
{
  if (input != expect)
  {
    ++g_error_count;
    cout << endl;
    cout << "ERROR at line " << line << " !" << endl;
    cout << "expecting output : " << expect << endl;
    cout << "retrieved output : " << input << endl;
    cout << endl;
    _result = false;
  }
  return;
}

void check_value(string input, string expect, int line, bool& _result)
{
  if (input != expect)
  {
    ++g_error_count;
    cout << endl;
    cout << "ERROR at line " << line << " !" << endl;
    cout << "expecting output : " << expect << endl;
    cout << "retrieved output : " << input << endl;
    cout << endl;
    _result = false;
  }
  return;
}

int main(const int argc, const char **argv)
{
  time_t t1 = time(NULL);

  cout << "max = 57896044618658097711785492504343953926634992332820282019728792003956564819967" << endl;
  cout << "min = -57896044618658097711785492504343953926634992332820282019728792003956564819968" << endl << endl;

  constructor_test();

  basic_assignment_operator_test();
  from_string_test();
  to_string_test();

  addition_test();
  addition_operator_test();
  addition_assignment_operator_test();
  subtraction_test();
  subtraction_operator_test();
  subtraction_assignment_operator_test();

  multiplication_test();
  multiplication_operator_test();
  multiplication_assignment_operator_test();
  div_mod_test();
  division_modulo_operator_test();
  division_assignment_operator_test();
  modulo_assignment_operator_test();

  unary_plus_test();
  unary_minus_test();

  shl_test();
  shr_test();
  bitwise_left_shift_int32_test();
  bitwise_left_shift_bigint_test();
  bitwise_right_shift_int32_test();
  bitwise_right_shift_bigint_test();
  bitwise_left_shift_int32_assignment_operator_test();
  bitwise_left_shift_bigint_assignment_operator_test();
  bitwise_right_shift_int32_assignment_operator_test();
  bitwise_right_shift_bigint_assignment_operator_test();

  increment_prefix_test();
  increment_postfix_test();
  decrement_prefix_test();
  decrement_postfix_test();

  compare_equalto_test();
  compare_lessthan_test();
  equal_to_operator_test();
  not_equal_to_operator_test();
  greater_than_operator_test();
  greater_than_or_equal_to_operator_test();
  less_than_operator_test();
  less_than_or_equal_to_operator_test();
  logical_negation_test();
  logical_AND_test();
  logical_OR_test();

  bitwise_NOT_test();
  bitwise_AND_test();
  bitwise_OR_test();
  bitwise_XOR_test();
  bitwise_AND_assignment_operator_test();
  bitwise_OR_assignment_operator_test();
  bitwise_XOR_assignment_operator_test();
//  istream_ostream_operator_test();

  sign_test();

  cout << "TOTAL ERROR COUNT : " << g_error_count << endl;

  time_t t2 = time(NULL);

  cout << "elapsed time: " << (t2 - t1) << " sec(s)..." << endl;
  return 0;
}

void constructor_test()
{
  bool _result = true;
  cout << "\n==[[constructor_test]]==================================" << endl << endl;

  // constructor test

  // Case : BigInt()
  cout << "Case : BigInt()" << endl;
  BigInt a1;
  check_value(a1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : BigInt(12345)
  cout << "Case : BigInt(12345)" << endl;
  BigInt a2(12345);
  check_value(a2, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3039), (int)__LINE__, _result);

  // constructor test (copy)

  // Case : BigInt(BigInt)
  cout << "Case : BigInt(BigInt(12345))" << endl;
  BigInt a3(a2);
  check_value(bool(a3 == a2), true, (int)__LINE__, _result);

  cout << "Case : BigInt(BigInt(0))" << endl;
  a2 = 0;
  BigInt a4(a2);
  check_value(bool(a4 == a2), true, (int)__LINE__, _result);

  cout << "Case : BigInt(BigInt(1))" << endl;
  a2 = 1;
  BigInt a5(a2);
  check_value(bool(a5 == a2), true, (int)__LINE__, _result);

  cout << "Case : BigInt(BigInt(-1))" << endl;
  a2 = -1;
  BigInt a6(a2);
  check_value(bool(a6 == a2), true, (int)__LINE__, _result);

  cout << "Case : BigInt(BigInt(\"57896044618658097711785492504343953926634992332820282019728792003956564819967\"))" << endl;
  a2.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  BigInt a7(a2);
  check_value(bool(a7 == a2), true, (int)__LINE__, _result);

  cout << "Case : BigInt(BigInt(\"-57896044618658097711785492504343953926634992332820282019728792003956564819968\"))" << endl;
  a2.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  BigInt a8(a2);
  check_value(bool(a8 == a2), true, (int)__LINE__, _result);

  // constructor test (int32_t)

  // Case : BigInt((int32_t)0)
  cout << "Case : BigInt((int32_t)0)" << endl;
  BigInt a32_1((int32_t)(0));
  check_value(a32_1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : BigInt((int32_t)1)
  cout << "Case : BigInt((int32_t)1)" << endl;
  BigInt a32_2((int32_t)(1));
  check_value(a32_2, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : BigInt((int32_t)-1)
  cout << "Case : BigInt((int32_t)-1)" << endl;
  BigInt a32_3((int32_t)(-1));
  check_value(a32_3, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : BigInt((int32_t)2)
  cout << "Case : BigInt((int32_t)2)" << endl;
  BigInt a32_4((int32_t)(2));
  check_value(a32_4, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : BigInt((int32_t)-2)
  cout << "Case : BigInt((int32_t)-2)" << endl;
  BigInt a32_5((int32_t)(-2));
  check_value(a32_5, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : BigInt((int32_t)2147483647)
  cout << "Case : BigInt((int32_t)2147483647)" << endl;
  BigInt a32_6((int32_t)(2147483647));
  check_value(a32_6, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)0x000000007FFFFFFF, (int)__LINE__, _result);

  // Case : BigInt((int32_t)-2147483648)
  cout << "Case : BigInt((int32_t)-2147483648)" << endl;
  BigInt a32_7((int32_t)(-2147483648));
  check_value(a32_7, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (int)__LINE__, _result);


  // constructor test (int64_t)

  // Case : BigInt((int64_t)(0))
  cout << "Case : BigInt((int64_t)(0))" << endl;
  BigInt a64_1((int64_t)(0));
  check_value(a64_1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : BigInt((int64_t)(1))
  cout << "Case : BigInt((int64_t)(1))" << endl;
  BigInt a64_2((int64_t)(1));
  check_value(a64_2, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : BigInt((int64_t)(-1))
  cout << "Case : BigInt((int64_t)(-1))" << endl;
  BigInt a64_3((int64_t)(-1));
  check_value(a64_3, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : BigInt((int64_t)(2))
  cout << "Case : BigInt((int64_t)(2))" << endl;
  BigInt a64_4((int64_t)(2));
  check_value(a64_4, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : BigInt((int64_t)(-2))
  cout << "Case : BigInt((int64_t)(-2))" << endl;
  BigInt a64_5((int64_t)(-2));
  check_value(a64_5, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : BigInt((int64_t)(2147483647))
  cout << "Case : BigInt((int64_t)(2147483647))" << endl;
  BigInt a64_6((int64_t)(2147483647));
  check_value(a64_6, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)0x000000007FFFFFFF, (int)__LINE__, _result);

  // Case : BigInt((int64_t)(-2147483648))
  cout << "Case : BigInt((int64_t)(-2147483648))" << endl;
  BigInt a64_7((int64_t)(-2147483648));
  check_value(a64_7, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (int)__LINE__, _result);

  // Case : BigInt((int64_t)(2147483648))
  cout << "Case : BigInt((int64_t)(2147483648))" << endl;
  BigInt a64_8((int64_t)(2147483648));
  check_value(a64_8, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)0x0000000080000000, (int)__LINE__, _result);

  // Case : BigInt((int64_t)(-2147483649))
  cout << "Case : BigInt((int64_t)(-2147483649))" << endl;
  BigInt a64_9((int64_t)(-2147483649));
  check_value(a64_9, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF7FFFFFFF, (int)__LINE__, _result);

  // Case : BigInt((int64_t)(9223372036854775807))
  cout << "Case : BigInt((int64_t)(9223372036854775807))" << endl;
  BigInt a64_10((int64_t)(9223372036854775807));
  check_value(a64_10, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : BigInt((int64_t)(-9223372036854775808))
  cout << "Case : BigInt((int64_t)(-9223372036854775808))" << endl;
  BigInt a64_11((int64_t)(-9223372036854775808));
  check_value(a64_11, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  // constructor test (uint64_t)

  // Case : BigInt((uint64_t)0)
  cout << "Case : BigInt((uint64_t)0)" << endl;
  BigInt au64_1((uint64_t)(0));
  check_value(au64_1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : BigInt((uint64_t)1)
  cout << "Case : BigInt((uint64_t)1)" << endl;
  BigInt au64_2((uint64_t)(1));
  check_value(au64_2, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : BigInt((uint64_t)2)
  cout << "Case : BigInt((uint64_t)2)" << endl;
  BigInt au64_3((uint64_t)(2));
  check_value(au64_3, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : BigInt((uint64_t)2147483647)
  cout << "Case : BigInt((uint64_t)2147483647)" << endl;
  BigInt au64_4((uint64_t)(2147483647));
  check_value(au64_4, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)0x000000007FFFFFFF, (int)__LINE__, _result);

  // Case : BigInt((uint64_t)2147483648)
  cout << "Case : BigInt((uint64_t)2147483648)" << endl;
  BigInt au64_5((uint64_t)(2147483648));
  check_value(au64_5, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)0x0000000080000000, (int)__LINE__, _result);

  // Case : BigInt((uint64_t)9223372036854775807)
  cout << "Case : BigInt((uint64_t)9223372036854775807)" << endl;
  BigInt au64_6((uint64_t)(9223372036854775807));
  check_value(au64_6, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : BigInt((uint64_t)9223372036854775808)
  cout << "Case : BigInt((uint64_t)9223372036854775808)" << endl;
  BigInt au64_7((uint64_t)(9223372036854775808));
  check_value(au64_7, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  // Case : BigInt((uint64_t)(18446744073709551615))
  cout << "Case : BigInt((uint64_t)(18446744073709551615))" << endl;
  BigInt au64_8((uint64_t)(18446744073709551615));
  check_value(au64_8, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // constructor test (from_string)

  cout << "Case : BigInt(\"57896044618658097711785492504343953926634992332820282019728792003956564819967\") (max value)" << endl;
  BigInt astr_1("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(astr_1, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"57896044618658097711785492504343953926634992332820282019728792003956564819968\") (max+1 overflow)" << endl;
  BigInt astr_2("57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(astr_2, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"57896044618658097711785492504343953926634992332820282019728792003956564819966\") (max-1)" << endl;
  BigInt astr_3("57896044618658097711785492504343953926634992332820282019728792003956564819966");
  check_value(astr_3, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-57896044618658097711785492504343953926634992332820282019728792003956564819968\") (min value)" << endl;
  BigInt astr_4("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(astr_4, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-57896044618658097711785492504343953926634992332820282019728792003956564819967\") (min+1)" << endl;
  BigInt astr_5("-57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(astr_5, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-57896044618658097711785492504343953926634992332820282019728792003956564819969\") (min-1 overflow)" << endl;
  BigInt astr_6("-57896044618658097711785492504343953926634992332820282019728792003956564819969");
  check_value(astr_6, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"1\")" << endl;
  BigInt astr_7("1");
  check_value(astr_7, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"0\")" << endl;
  BigInt astr_8("0");
  check_value(astr_8, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-0\")" << endl;
  BigInt astr_9("-0");
  check_value(astr_9, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-1\")" << endl;
  BigInt astr_10("-1");
  check_value(astr_10, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"6277101735386680763835789423207666416102355444464034512896\") (2^192)" << endl;
  BigInt astr_11("6277101735386680763835789423207666416102355444464034512896");
  check_value(astr_11, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"6277101735386680763835789423207666416102355444464034512897\") (2^192+1)" << endl;
  BigInt astr_12("6277101735386680763835789423207666416102355444464034512897");
  check_value(astr_12, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"6277101735386680763835789423207666416102355444464034512895\") (2^192-1)" << endl;
  BigInt astr_13("6277101735386680763835789423207666416102355444464034512895");
  check_value(astr_13, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"340282366920938463463374607431768211456\") (2^128)" << endl;
  BigInt astr_14("340282366920938463463374607431768211456");
  check_value(astr_14, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"340282366920938463463374607431768211457\") (2^128+1)" << endl;
  BigInt astr_15("340282366920938463463374607431768211457");
  check_value(astr_15, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"340282366920938463463374607431768211455\") (2^128-1)" << endl;
  BigInt astr_16("340282366920938463463374607431768211455");
  check_value(astr_16, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"18446744073709551616\") (2^64)" << endl;
  BigInt astr_17("18446744073709551616");
  check_value(astr_17, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"18446744073709551617\") (2^64+1)" << endl;
  BigInt astr_18("18446744073709551617");
  check_value(astr_18, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"18446744073709551615\") (2^64-1)" << endl;
  BigInt astr_19("18446744073709551615");
  check_value(astr_19, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"9223372036854775808\") (2^63)" << endl;
  BigInt astr_20("9223372036854775808");
  check_value(astr_20, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);


  cout << "Case : BigInt(\"9223372036854775809\") (2^63+1)" << endl;
  BigInt astr_21("9223372036854775809");
  check_value(astr_21, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);


  cout << "Case : BigInt(\"9223372036854775807\") (2^63-1)" << endl;
  BigInt astr_22("9223372036854775807");
  check_value(astr_22, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-9223372036854775808\") (-2^63)" << endl;
  BigInt astr_23("-9223372036854775808");
  check_value(astr_23, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-9223372036854775807\") (-2^63+1)" << endl;
  BigInt astr_24("-9223372036854775807");
  check_value(astr_24, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-9223372036854775809\") (-2^63-1)" << endl;
  BigInt astr_25("-9223372036854775809");
  check_value(astr_25, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x7FFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-170141183460469231731687303715884105728\") (-2^127)" << endl;
  BigInt astr_26("-170141183460469231731687303715884105728");
  check_value(astr_26, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-170141183460469231731687303715884105727\") (-2^127+1)" << endl;
  BigInt astr_27("-170141183460469231731687303715884105727");
  check_value(astr_27, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-170141183460469231731687303715884105729\") (-2^127-1)" << endl;
  BigInt astr_28("-170141183460469231731687303715884105729");
  check_value(astr_28, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-3138550867693340381917894711603833208051177722232017256448\") (-2^191)" << endl;
  BigInt astr_29("-3138550867693340381917894711603833208051177722232017256448");
  check_value(astr_29, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-3138550867693340381917894711603833208051177722232017256447\") (-2^191+1)" << endl;
  BigInt astr_30("-3138550867693340381917894711603833208051177722232017256447");
  check_value(astr_30, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"-3138550867693340381917894711603833208051177722232017256449\") (-2^191-1)" << endl;
  BigInt astr_31("-3138550867693340381917894711603833208051177722232017256449");
  check_value(astr_31, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"115792089237316195423570985008687907853269984665640564039457584007913129639936\") (2^256)" << endl;
  BigInt astr_32("115792089237316195423570985008687907853269984665640564039457584007913129639936");
  check_value(astr_32, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"115792089237316195423570985008687907853269984665640564039457584007913129639937\") (2^256+1)" << endl;
  BigInt astr_33("115792089237316195423570985008687907853269984665640564039457584007913129639937");
  check_value(astr_33, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"115792089237316195423570985008687907853269984665640564039457584007913129639935\") (2^256-1)" << endl;
  BigInt astr_34("115792089237316195423570985008687907853269984665640564039457584007913129639935");
  check_value(astr_34, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"115792089237316195423570985008687907853269984665640564039457584007913129639936\") (-2^256)" << endl;
  BigInt astr_35("115792089237316195423570985008687907853269984665640564039457584007913129639936");
  check_value(astr_35, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"115792089237316195423570985008687907853269984665640564039457584007913129639937\") (-2^256+1)" << endl;
  BigInt astr_36("115792089237316195423570985008687907853269984665640564039457584007913129639937");
  check_value(astr_36, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"115792089237316195423570985008687907853269984665640564039457584007913129639935\") (-2^256-1)" << endl;
  BigInt astr_37("115792089237316195423570985008687907853269984665640564039457584007913129639935");
  check_value(astr_37, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : BigInt(\"123456789123456789123456789123456789123456789123456789123456789123456789\")" << endl;
  BigInt astr_38("123456789123456789123456789123456789123456789123456789123456789123456789");
  // 11E3444E0718 6473F6C29BFB5CD6 99549E6C50200673 C72870B684045F15
  check_value(astr_38, (uint64_t)(0x11E3444E0718), (uint64_t)(0x6473F6C29BFB5CD6), (uint64_t)(0x99549E6C50200673), (uint64_t)(0xC72870B684045F15), (int)__LINE__, _result);


  cout << "Case : BigInt(\"1000000000000000000\")" << endl;
  //0DE0B6B3A7640000
  BigInt astr_39("1000000000000000000");
  check_value(astr_39, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0DE0B6B3A7640000), (int)__LINE__, _result);


  cout << "Case : BigInt(\"1000000000000000000000000000000000000\")" << endl;
  //00C097CE7BC90715 B34B9F1000000000
  BigInt astr_40("1000000000000000000000000000000000000");
  check_value(astr_40, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00C097CE7BC90715), (uint64_t)(0xB34B9F1000000000), (int)__LINE__, _result);


  cout << "Case : BigInt(\"1000000000000000000000000000000000000000000000000000000\")" << endl;
  //000A70C3C40A64E6 C51999090B65F67D 9240000000000000
  BigInt astr_41("1000000000000000000000000000000000000000000000000000000");
  check_value(astr_41, (uint64_t)(0), (uint64_t)(0x000A70C3C40A64E6), (uint64_t)(0xC51999090B65F67D), (uint64_t)(0x9240000000000000), (int)__LINE__, _result);


  cout << "Case : BigInt(\"1000000000000000000000000000000000000000000000000000000000000000000000000\")" << endl;
  //000090E40FBEEA1D 3A4ABC8955E946FE 31CDCF66F634E100 0000000000000000
  BigInt astr_42("1000000000000000000000000000000000000000000000000000000000000000000000000");
  check_value(astr_42, (uint64_t)(0x000090E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E100), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"10000000000000000000\")" << endl;
  //8AC7230489E80000
  BigInt astr_43("10000000000000000000");
  check_value(astr_43, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8AC7230489E80000), (int)__LINE__, _result);


  cout << "Case : BigInt(\"100000000000000000000000000000000000000\")" << endl;
  //4B3B4CA85A86C47A 098A224000000000
  BigInt astr_44("100000000000000000000000000000000000000");
  check_value(astr_44, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x4B3B4CA85A86C47A), (uint64_t)(0x098A224000000000), (int)__LINE__, _result);


  cout << "Case : BigInt(\"1000000000000000000000000000000000000000000000000000000000\")" << endl;
  //28C87CB5C89A2571 EBFDCB54864ADA83 4A00000000000000
  BigInt astr_45("1000000000000000000000000000000000000000000000000000000000");
  check_value(astr_45, (uint64_t)(0), (uint64_t)(0x28C87CB5C89A2571), (uint64_t)(0xEBFDCB54864ADA83), (uint64_t)(0x4A00000000000000), (int)__LINE__, _result);


  cout << "Case : BigInt(\"10000000000000000000000000000000000000000000000000000000000000000000000000000\")" << endl;
  //161BCCA7119915B5 0764B4ABE8652979 7775A5F171951000 0000000000000000
  BigInt astr_46("10000000000000000000000000000000000000000000000000000000000000000000000000000");
  check_value(astr_46, (uint64_t)(0x161BCCA7119915B5), (uint64_t)(0x0764B4ABE8652979), (uint64_t)(0x7775A5F171951000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : BigInt(\"+0\")" << endl;
  BigInt astr_47("+0");
  check_value(astr_47, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : BigInt(\"+1\")" << endl;
  BigInt astr_48("+1");
  check_value(astr_48, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : BigInt(\"+57896044618658097711785492504343953926634992332820282019728792003956564819967\")" << endl;
  BigInt astr_49("+57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(astr_49, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 18446744090889420790" << endl;
  BigInt astr_50("18446744090889420790");
  check_value(astr_50, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  cout << "Case : 340282367237851113354411261159737917430" << endl;
  BigInt astr_51("340282367237851113354411261159737917430");
  check_value(astr_51, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  cout << "Case : 6277101741232687310096859794050872225688152709929820487670" << endl;
  BigInt astr_52("6277101741232687310096859794050872225688152709929820487670");
  check_value(astr_52, (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  cout << "Case : 115792089345155982035679628574721847873087472922163349794284472197617045995510" << endl;
  BigInt astr_53("115792089345155982035679628574721847873087472922163349794284472197617045995510");
  check_value(astr_53, (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  cout << "Case : 340282367237851113335964517068848496640" << endl;
  BigInt astr_54("340282367237851113335964517068848496640");
  check_value(astr_54, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 6277101741232687309756577426813021112333741448770082570240" << endl;
  BigInt astr_55("6277101741232687309756577426813021112333741448770082570240");
  check_value(astr_55, (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 115792089345155982029402526833489160562990613128112477568596319487687225507840" << endl;
  BigInt astr_56("115792089345155982029402526833489160562990613128112477568596319487687225507840");
  check_value(astr_56, (uint64_t)(0x3FFFFFFF6), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 48040846506148948440156104884446846804848515651106441641510" << endl;
  BigInt astr_57("48040846506148948440156104884446846804848515651106441641510");
  check_value(astr_57, (uint64_t)(0x7), (uint64_t)(0xA741D72F4158CD38), (uint64_t)(0x3C8DFF4FA4E2BAB6), (uint64_t)(0xAA368097EB3DBE26), (int)__LINE__, _result);

  cout << "Case : 800408450565014854845303501640894984056160549840635022160484840855201605140" << endl;
  BigInt astr_58("800408450565014854845303501640894984056160549840635022160484840855201605140");
  check_value(astr_58, (uint64_t)(0x1C503DF7A9E652E), (uint64_t)(0xAAFE06E4D5D5DB42), (uint64_t)(0x785611DE6AB9D456), (uint64_t)(0x22CE55DCFE236614), (int)__LINE__, _result);

  cout << "Case : 888888888888888888888888888888888888888888888888888888888888888888888888888" << endl;
  BigInt astr_59("888888888888888888888888888888888888888888888888888888888888888888888888888");
  check_value(astr_59, (uint64_t)(0x1F717E156E5C90A), (uint64_t)(0x670EA3F8866F6465), (uint64_t)(0xD1BAD02C379B78E3), (uint64_t)(0x8E38E38E38E38E38), (int)__LINE__, _result);

  cout << "Case : 890851506489406015610140515106848413551061564066446410" << endl;
  BigInt astr_60("890851506489406015610140515106848413551061564066446410");
  check_value(astr_60, (uint64_t)(0), (uint64_t)(0x94D0955FF8590), (uint64_t)(0xEDB9E496C67D0D17), (uint64_t)(0x576946A387E13C4A), (int)__LINE__, _result);

  cout << "Case : 877892520000000000000000000000000000545151514354541563464654654" << endl;
  BigInt astr_61("877892520000000000000000000000000000545151514354541563464654654");
  check_value(astr_61, (uint64_t)(0x22250), (uint64_t)(0x58E515E8359DD501), (uint64_t)(0x7FEC079B75A23875), (uint64_t)(0x89522FFC94941F3E), (int)__LINE__, _result);

  cout << "Case : 44444444444444433333333333222222222222222222222221111111111111111111100000" << endl;
  BigInt astr_62("44444444444444433333333333222222222222222222222221111111111111111111100000");
  check_value(astr_62, (uint64_t)(0x192798112516D8), (uint64_t)(0x599B51BB057531BD), (uint64_t)(0x65CC1E00A0C4951B), (uint64_t)(0x63DA1C4D4D1C4660), (int)__LINE__, _result);

  cout << "Case : 11111111122222222223333333355555558888888888888889999999999666666666" << endl;
  BigInt astr_63("11111111122222222223333333355555558888888888888889999999999666666666");
  check_value(astr_63, (uint64_t)(0x69819D6D), (uint64_t)(0x4027A067D27EC1BC), (uint64_t)(0x73333C94E1C45369), (uint64_t)(0xBBAED20550C9BCAA), (int)__LINE__, _result);

  if (g_test_exception_from_str)
  {
    cout << "Case : BigInt(\"-123456789123456789+hellohowareyou\")" << endl;
    BigInt astr_51("-123456789123456789hellohowareyou");
    check_value(astr_51, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFE4964B4532FA0EB), (int)__LINE__, _result);
  }

  if (_result)
  {
    cout << "\nconstructor_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}


void basic_assignment_operator_test()
{
  BigInt a, b, c;
  bool _result = true;

  cout << "\n==[[basic_assignment_operator(=)_test]]==================================" << endl << endl;

  cout << "Case : a = 1, b = a; c = -1, b = c, a = b" << endl;
  a = 1;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b = a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c = -1;
  b = c;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a = b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : a = 1234567890, b = a; c = -123456789, b = c, a = b" << endl;
  a = 1234567890;
  b = a;
  c = -123456789;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)1234567890, (int)__LINE__, _result);
  b = c;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFF8A432EB, (int)__LINE__, _result);
  a = b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFF8A432EB, (int)__LINE__, _result);

  cout << "Case : a = (2^64-1), b = a; c = (2^128-1), b = c, a = b" << endl;
  a.from_string("18446744073709551615");
  b = a;
  c.from_string("340282366920938463463374607431768211455");
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b = c;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a = b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : a = (2^192-1), b = a; c = (2^255-1), b = c, a = b" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512895");
  b = a;
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(b, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b = c;
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a = b;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : a = max, b = a; c = min, b = c, a = b" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = a;
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b = c;
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a = b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbasic_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void from_string_test()
{
  BigInt str1;
  bool _result = true;

  cout << "\n==[[from_string_test]]==================================" << endl << endl;

  cout << "Case : 57896044618658097711785492504343953926634992332820282019728792003956564819967 (max value)" << endl;
  str1.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(str1, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 57896044618658097711785492504343953926634992332820282019728792003956564819968 (max+1 overflow)" << endl;
  str1.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(str1, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 57896044618658097711785492504343953926634992332820282019728792003956564819966 (max-1)" << endl;
  str1.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819966");
  check_value(str1, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);


  cout << "Case : -57896044618658097711785492504343953926634992332820282019728792003956564819968 (min value)" << endl;
  str1.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(str1, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -57896044618658097711785492504343953926634992332820282019728792003956564819967 (min+1)" << endl;
  str1.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(str1, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : -57896044618658097711785492504343953926634992332820282019728792003956564819969 (min-1 overflow)" << endl;
  str1.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819969");
  check_value(str1, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 1" << endl;
  str1.from_string("1");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : 0" << endl;
  str1.from_string("0");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -0" << endl;
  str1.from_string("-0");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -1" << endl;
  str1.from_string("-1");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 6277101735386680763835789423207666416102355444464034512896 (2^192)" << endl;
  str1.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value(str1, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 6277101735386680763835789423207666416102355444464034512897 (2^192+1)" << endl;
  str1.from_string("6277101735386680763835789423207666416102355444464034512897");
  check_value(str1, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : 6277101735386680763835789423207666416102355444464034512895 (2^192-1)" << endl;
  str1.from_string("6277101735386680763835789423207666416102355444464034512895");
  check_value(str1, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 340282366920938463463374607431768211456 (2^128)" << endl;
  str1.from_string("340282366920938463463374607431768211456");
  check_value(str1, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 340282366920938463463374607431768211457 (2^128+1)" << endl;
  str1.from_string("340282366920938463463374607431768211457");
  check_value(str1, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : 340282366920938463463374607431768211455 (2^128-1)" << endl;
  str1.from_string("340282366920938463463374607431768211455");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 18446744073709551616 (2^64)" << endl;
  str1.from_string("18446744073709551616");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 18446744073709551617 (2^64+1)" << endl;
  str1.from_string("18446744073709551617");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : 18446744073709551615 (2^64-1)" << endl;
  str1.from_string("18446744073709551615");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 9223372036854775808 (2^63)" << endl;
  str1.from_string("9223372036854775808");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);


  cout << "Case : 9223372036854775809 (2^63+1)" << endl;
  str1.from_string("9223372036854775809");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);


  cout << "Case : 9223372036854775807 (2^63-1)" << endl;
  str1.from_string("9223372036854775807");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : -9223372036854775808 (-2^63)" << endl;
  str1.from_string("-9223372036854775808");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);


  cout << "Case : -9223372036854775807 (-2^63+1)" << endl;
  str1.from_string("-9223372036854775807");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);


  cout << "Case : -9223372036854775809 (-2^63-1)" << endl;
  str1.from_string("-9223372036854775809");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x7FFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : -170141183460469231731687303715884105728 (-2^127)" << endl;
  str1.from_string("-170141183460469231731687303715884105728");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -170141183460469231731687303715884105727 (-2^127+1)" << endl;
  str1.from_string("-170141183460469231731687303715884105727");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : -170141183460469231731687303715884105729 (-2^127-1)" << endl;
  str1.from_string("-170141183460469231731687303715884105729");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : -3138550867693340381917894711603833208051177722232017256448 (-2^191)" << endl;
  str1.from_string("-3138550867693340381917894711603833208051177722232017256448");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -3138550867693340381917894711603833208051177722232017256447 (-2^191+1)" << endl;
  str1.from_string("-3138550867693340381917894711603833208051177722232017256447");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : -3138550867693340381917894711603833208051177722232017256449 (-2^191-1)" << endl;
  str1.from_string("-3138550867693340381917894711603833208051177722232017256449");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 115792089237316195423570985008687907853269984665640564039457584007913129639936 (2^256)" << endl;
  str1.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639936");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 115792089237316195423570985008687907853269984665640564039457584007913129639937 (2^256+1)" << endl;
  str1.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639937");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : 115792089237316195423570985008687907853269984665640564039457584007913129639935 (2^256-1)" << endl;
  str1.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639935");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 115792089237316195423570985008687907853269984665640564039457584007913129639936 (-2^256)" << endl;
  str1.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639936");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 115792089237316195423570985008687907853269984665640564039457584007913129639937 (-2^256+1)" << endl;
  str1.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639937");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);


  cout << "Case : 115792089237316195423570985008687907853269984665640564039457584007913129639935 (-2^256-1)" << endl;
  str1.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639935");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 123456789123456789123456789123456789123456789123456789123456789123456789" << endl;
  str1.from_string("123456789123456789123456789123456789123456789123456789123456789123456789");
  // 11E3444E0718 6473F6C29BFB5CD6 99549E6C50200673 C72870B684045F15
  check_value(str1, (uint64_t)(0x11E3444E0718), (uint64_t)(0x6473F6C29BFB5CD6), (uint64_t)(0x99549E6C50200673), (uint64_t)(0xC72870B684045F15), (int)__LINE__, _result);


  cout << "Case : 1000000000000000000" << endl;
  //0DE0B6B3A7640000
  str1.from_string("1000000000000000000");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0DE0B6B3A7640000), (int)__LINE__, _result);


  cout << "Case : 1000000000000000000000000000000000000" << endl;
  //00C097CE7BC90715 B34B9F1000000000
  str1.from_string("1000000000000000000000000000000000000");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00C097CE7BC90715), (uint64_t)(0xB34B9F1000000000), (int)__LINE__, _result);


  cout << "Case : 1000000000000000000000000000000000000000000000000000000" << endl;
  //000A70C3C40A64E6 C51999090B65F67D 9240000000000000
  str1.from_string("1000000000000000000000000000000000000000000000000000000");
  check_value(str1, (uint64_t)(0), (uint64_t)(0x000A70C3C40A64E6), (uint64_t)(0xC51999090B65F67D), (uint64_t)(0x9240000000000000), (int)__LINE__, _result);


  cout << "Case : 1000000000000000000000000000000000000000000000000000000000000000000000000" << endl;
  //000090E40FBEEA1D 3A4ABC8955E946FE 31CDCF66F634E100 0000000000000000
  str1.from_string("1000000000000000000000000000000000000000000000000000000000000000000000000");
  check_value(str1, (uint64_t)(0x000090E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E100), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 10000000000000000000" << endl;
  //8AC7230489E80000
  str1.from_string("10000000000000000000");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8AC7230489E80000), (int)__LINE__, _result);


  cout << "Case : 100000000000000000000000000000000000000" << endl;
  //4B3B4CA85A86C47A 098A224000000000
  str1.from_string("100000000000000000000000000000000000000");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x4B3B4CA85A86C47A), (uint64_t)(0x098A224000000000), (int)__LINE__, _result);


  cout << "Case : 1000000000000000000000000000000000000000000000000000000000" << endl;
  //28C87CB5C89A2571 EBFDCB54864ADA83 4A00000000000000
  str1.from_string("1000000000000000000000000000000000000000000000000000000000");
  check_value(str1, (uint64_t)(0), (uint64_t)(0x28C87CB5C89A2571), (uint64_t)(0xEBFDCB54864ADA83), (uint64_t)(0x4A00000000000000), (int)__LINE__, _result);


  cout << "Case : 10000000000000000000000000000000000000000000000000000000000000000000000000000" << endl;
  //161BCCA7119915B5 0764B4ABE8652979 7775A5F171951000 0000000000000000
  str1.from_string("10000000000000000000000000000000000000000000000000000000000000000000000000000");
  check_value(str1, (uint64_t)(0x161BCCA7119915B5), (uint64_t)(0x0764B4ABE8652979), (uint64_t)(0x7775A5F171951000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : +0" << endl;
  str1.from_string("+0");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : +1" << endl;
  str1.from_string("+1");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 01" << endl;
  str1.from_string("01");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : +01" << endl;
  str1.from_string("+01");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -01" << endl;
  str1.from_string("-01");
  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : +57896044618658097711785492504343953926634992332820282019728792003956564819967" << endl;
  str1.from_string("+57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(str1, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 18446744090889420790" << endl;
  str1.from_string("18446744090889420790");
  check_value(str1, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  cout << "Case : 340282367237851113354411261159737917430" << endl;
  str1.from_string("340282367237851113354411261159737917430");
  check_value(str1, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  cout << "Case : 6277101741232687310096859794050872225688152709929820487670" << endl;
  str1.from_string("6277101741232687310096859794050872225688152709929820487670");
  check_value(str1, (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  cout << "Case : 115792089345155982035679628574721847873087472922163349794284472197617045995510" << endl;
  str1.from_string("115792089345155982035679628574721847873087472922163349794284472197617045995510");
  check_value(str1, (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  cout << "Case : 340282367237851113335964517068848496640" << endl;
  str1.from_string("340282367237851113335964517068848496640");
  check_value(str1, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 6277101741232687309756577426813021112333741448770082570240" << endl;
  str1.from_string("6277101741232687309756577426813021112333741448770082570240");
  check_value(str1, (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 115792089345155982029402526833489160562990613128112477568596319487687225507840" << endl;
  str1.from_string("115792089345155982029402526833489160562990613128112477568596319487687225507840");
  check_value(str1, (uint64_t)(0x3FFFFFFF6), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 48040846506148948440156104884446846804848515651106441641510" << endl;
  str1.from_string("48040846506148948440156104884446846804848515651106441641510");
  check_value(str1, (uint64_t)(0x7), (uint64_t)(0xA741D72F4158CD38), (uint64_t)(0x3C8DFF4FA4E2BAB6), (uint64_t)(0xAA368097EB3DBE26), (int)__LINE__, _result);

  cout << "Case : 800408450565014854845303501640894984056160549840635022160484840855201605140" << endl;
  str1.from_string("800408450565014854845303501640894984056160549840635022160484840855201605140");
  check_value(str1, (uint64_t)(0x1C503DF7A9E652E), (uint64_t)(0xAAFE06E4D5D5DB42), (uint64_t)(0x785611DE6AB9D456), (uint64_t)(0x22CE55DCFE236614), (int)__LINE__, _result);

  cout << "Case : 888888888888888888888888888888888888888888888888888888888888888888888888888" << endl;
  str1.from_string("888888888888888888888888888888888888888888888888888888888888888888888888888");
  check_value(str1, (uint64_t)(0x1F717E156E5C90A), (uint64_t)(0x670EA3F8866F6465), (uint64_t)(0xD1BAD02C379B78E3), (uint64_t)(0x8E38E38E38E38E38), (int)__LINE__, _result);

  cout << "Case : 890851506489406015610140515106848413551061564066446410" << endl;
  str1.from_string("890851506489406015610140515106848413551061564066446410");
  check_value(str1, (uint64_t)(0), (uint64_t)(0x94D0955FF8590), (uint64_t)(0xEDB9E496C67D0D17), (uint64_t)(0x576946A387E13C4A), (int)__LINE__, _result);

  cout << "Case : 877892520000000000000000000000000000545151514354541563464654654" << endl;
  str1.from_string("877892520000000000000000000000000000545151514354541563464654654");
  check_value(str1, (uint64_t)(0x22250), (uint64_t)(0x58E515E8359DD501), (uint64_t)(0x7FEC079B75A23875), (uint64_t)(0x89522FFC94941F3E), (int)__LINE__, _result);

  cout << "Case : 44444444444444433333333333222222222222222222222221111111111111111111100000" << endl;
  str1.from_string("44444444444444433333333333222222222222222222222221111111111111111111100000");
  check_value(str1, (uint64_t)(0x192798112516D8), (uint64_t)(0x599B51BB057531BD), (uint64_t)(0x65CC1E00A0C4951B), (uint64_t)(0x63DA1C4D4D1C4660), (int)__LINE__, _result);

  cout << "Case : 11111111122222222223333333355555558888888888888889999999999666666666" << endl;
  str1.from_string("11111111122222222223333333355555558888888888888889999999999666666666");
  check_value(str1, (uint64_t)(0x69819D6D), (uint64_t)(0x4027A067D27EC1BC), (uint64_t)(0x73333C94E1C45369), (uint64_t)(0xBBAED20550C9BCAA), (int)__LINE__, _result);

//  cout << "Case : +-1" << endl;
//  str1.from_string("+-1");
//  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


//  cout << "Case : -123456789123456789hellohowareyou" << endl;
//  str1.from_string("-123456789123456789hellohowareyou");
//  check_value(str1, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFE4964B4532FA0EB), (int)__LINE__, _result);


  if (_result)
  {
    cout << "\nfrom_string_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void to_string_test()
{
  BigInt i;
  BigInt str1;
  bool _result = true;
  string str_i;
  string str_o;

  cout << "\n==[[to_string_test]]==================================" << endl << endl;

  cout << "Case : 57896044618658097711785492504343953926634992332820282019728792003956564819967 (max value)" << endl;
  str_i = "57896044618658097711785492504343953926634992332820282019728792003956564819967";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 57896044618658097711785492504343953926634992332820282019728792003956564819966 (max-1)" << endl;
  str_i = "57896044618658097711785492504343953926634992332820282019728792003956564819966";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 57896044618658097711785492504343953926634992332820282019728792003956564819968 (max+1 overflow)" << endl;
  str_i = "57896044618658097711785492504343953926634992332820282019728792003956564819968";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "-57896044618658097711785492504343953926634992332820282019728792003956564819968", __LINE__, _result);

  cout << "Case : -57896044618658097711785492504343953926634992332820282019728792003956564819968 (min value)" << endl;
  str_i = "-57896044618658097711785492504343953926634992332820282019728792003956564819968";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -57896044618658097711785492504343953926634992332820282019728792003956564819967 (min+1)" << endl;
  str_i = "-57896044618658097711785492504343953926634992332820282019728792003956564819967";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -57896044618658097711785492504343953926634992332820282019728792003956564819969 (min-1 overflow)" << endl;
  str_i = "-57896044618658097711785492504343953926634992332820282019728792003956564819969";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "57896044618658097711785492504343953926634992332820282019728792003956564819967", __LINE__, _result);

  cout << "Case : 1" << endl;
  str_i = "1";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 0" << endl;
  str_i = "0";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : +1" << endl;
  str_i = "+1";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "1", __LINE__, _result);

  cout << "Case : +0" << endl;
  str_i = "+0";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "0", __LINE__, _result);

  cout << "Case : -0" << endl;
  str_i = "-0";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "0", __LINE__, _result);

  cout << "Case : -1" << endl;
  str_i = "-1";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 6277101735386680763835789423207666416102355444464034512896 (2^192)" << endl;
  str_i = "6277101735386680763835789423207666416102355444464034512896";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 6277101735386680763835789423207666416102355444464034512897 (2^192+1)" << endl;
  str_i = "6277101735386680763835789423207666416102355444464034512897";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 6277101735386680763835789423207666416102355444464034512895 (2^192-1)" << endl;
  str_i = "6277101735386680763835789423207666416102355444464034512895";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 340282366920938463463374607431768211456 (2^128)" << endl;
  str_i = "340282366920938463463374607431768211456";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 340282366920938463463374607431768211457 (2^128+1)" << endl;
  str_i = "340282366920938463463374607431768211457";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 340282366920938463463374607431768211455 (2^128-1)" << endl;
  str_i = "340282366920938463463374607431768211455";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 18446744073709551616 (2^64)" << endl;
  str_i = "18446744073709551616";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 18446744073709551617 (2^64+1)" << endl;
  str_i = "18446744073709551617";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 18446744073709551615 (2^64-1)" << endl;
  str_i = "18446744073709551615";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 9223372036854775808 (2^63)" << endl;
  str_i = "9223372036854775808";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 9223372036854775809 (2^63+1)" << endl;
  str_i = "9223372036854775809";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 9223372036854775807 (2^63-1)" << endl;
  str_i = "9223372036854775807";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -9223372036854775808 (-2^63)" << endl;
  str_i = "-9223372036854775808";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -9223372036854775807 (-2^63+1)" << endl;
  str_i = "-9223372036854775807";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -9223372036854775809 (-2^63-1)" << endl;
  str_i = "-9223372036854775809";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -170141183460469231731687303715884105728 (-2^127)" << endl;
  str_i = "-170141183460469231731687303715884105728";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -170141183460469231731687303715884105727 (-2^127+1)" << endl;
  str_i = "-170141183460469231731687303715884105727";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -170141183460469231731687303715884105729 (-2^127-1)" << endl;
  str_i = "-170141183460469231731687303715884105729";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -3138550867693340381917894711603833208051177722232017256448 (-2^191)" << endl;
  str_i = "-3138550867693340381917894711603833208051177722232017256448";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -3138550867693340381917894711603833208051177722232017256447 (-2^191+1)" << endl;
  str_i = "-3138550867693340381917894711603833208051177722232017256447";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -3138550867693340381917894711603833208051177722232017256449 (-2^191-1)" << endl;
  str_i = "-3138550867693340381917894711603833208051177722232017256449";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 115792089237316195423570985008687907853269984665640564039457584007913129639936 (2^256 overflow)" << endl;
  str_i = "115792089237316195423570985008687907853269984665640564039457584007913129639936";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "0", __LINE__, _result);

  cout << "Case : 115792089237316195423570985008687907853269984665640564039457584007913129639937 (2^256+1 overflow)" << endl;
  str_i = "115792089237316195423570985008687907853269984665640564039457584007913129639937";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "1", __LINE__, _result);

  cout << "Case : 115792089237316195423570985008687907853269984665640564039457584007913129639935 (2^256-1 overflow)" << endl;
  str_i = "115792089237316195423570985008687907853269984665640564039457584007913129639935";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "-1", __LINE__, _result);

  cout << "Case : -115792089237316195423570985008687907853269984665640564039457584007913129639936 (-2^256 overflow)" << endl;
  str_i = "-115792089237316195423570985008687907853269984665640564039457584007913129639936";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "0", __LINE__, _result);

  cout << "Case : -115792089237316195423570985008687907853269984665640564039457584007913129639935 (-2^256+1 overflow)" << endl;
  str_i = "-115792089237316195423570985008687907853269984665640564039457584007913129639935";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "1", __LINE__, _result);

  cout << "Case : -115792089237316195423570985008687907853269984665640564039457584007913129639937 (-2^256-1 overflow)" << endl;
  str_i = "-115792089237316195423570985008687907853269984665640564039457584007913129639937";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, "-1", __LINE__, _result);

  cout << "Case : 123456789123456789123456789123456789123456789123456789123456789123456789" << endl;
  str_i = "123456789123456789123456789123456789123456789123456789123456789123456789";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -1000000000000000000" << endl;
  str_i = "-1000000000000000000";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -1000000000000000000000000000000000000" << endl;
  str_i = "-1000000000000000000000000000000000000";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -1000000000000000000000000000000000000000000000000000000" << endl;
  str_i = "-1000000000000000000000000000000000000000000000000000000";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : -1000000000000000000000000000000000000000000000000000000000000000000000000" << endl;
  str_i = "-1000000000000000000000000000000000000000000000000000000000000000000000000";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 10000000000000000000" << endl;
  //8AC7230489E80000
  str_i = "10000000000000000000";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 100000000000000000000000000000000000000" << endl;
  //4B3B4CA85A86C47A 098A224000000000
  str_i = "100000000000000000000000000000000000000";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 1000000000000000000000000000000000000000000000000000000000" << endl;
  //28C87CB5C89A2571 EBFDCB54864ADA83 4A00000000000000
  str_i = "1000000000000000000000000000000000000000000000000000000000";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 10000000000000000000000000000000000000000000000000000000000000000000000000000" << endl;
  //161BCCA7119915B5 0764B4ABE8652979 7775A5F171951000 0000000000000000
  str_i = "10000000000000000000000000000000000000000000000000000000000000000000000000000";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 11111111111111111111111111111111111111111111111111111111111111111111111111111" << endl;
  str_i = "11111111111111111111111111111111111111111111111111111111111111111111111111111";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 22222222222222222222222222222222222222222222222222222222222222222222222222222" << endl;
  str_i = "22222222222222222222222222222222222222222222222222222222222222222222222222222";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 33333333333333333333333333333333333333333333333333333333333333333333333333333" << endl;
  str_i = "33333333333333333333333333333333333333333333333333333333333333333333333333333";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 44444444444444444444444444444444444444444444444444444444444444444444444444444" << endl;
  str_i = "44444444444444444444444444444444444444444444444444444444444444444444444444444";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 55555555555555555555555555555555555555555555555555555555555555555555555555555" << endl;
  str_i = "55555555555555555555555555555555555555555555555555555555555555555555555555555";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 450275045205420452045024524024020454020450244502425045204524502" << endl;
  str_i = "450275045205420452045024524024020454020450244502425045204524502";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 78948979784899474897998748954984987499489749874989874987984988749879887898" << endl;
  str_i = "78948979784899474897998748954984987499489749874989874987984988749879887898";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 1650351089480156104847894148504809484869640684698406840684698498496848" << endl;
  str_i = "1650351089480156104847894148504809484869640684698406840684698498496848";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 89498989874907098490849840561684941651645651035161540845165465465465" << endl;
  str_i = "89498989874907098490849840561684941651645651035161540845165465465465";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 79846584146511450640551468486041053231006584658605650166504165635168" << endl;
  str_i = "79846584146511450640551468486041053231006584658605650166504165635168";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 13333333333322222222211111111155555555588888888899999999777777777" << endl;
  str_i = "13333333333322222222211111111155555555588888888899999999777777777";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  cout << "Case : 8888888777777775555555566666666622222211111111144444444323332156" << endl;
  str_i = "8888888777777775555555566666666622222211111111144444444323332156";
  str1.from_string(str_i);
  str_o = str1.to_string();
  check_value(str_o, str_i, __LINE__, _result);

  if (_result)
  {
    cout << "\nto_string_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}


void addition_test()
{
  BigInt a, b, c;
  bool _result = true;
  cout << "\n==[[addition_add()_test]]==================================" << endl << endl;

  // Case : 1 + 1
  cout << "Case : 1 + 1" << endl;
  b = 1;
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : 1 + 0
  cout << "Case : 1 + 0" << endl;
  b = 1;
  c = 0;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : 1 + -1
  cout << "Case : 1 + -1" << endl;
  b = 1;
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -1 + 1
  cout << "Case : -1 + 1" << endl;
  b = -1;
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -1 + 0
  cout << "Case : -1 + 0" << endl;
  b = -1;
  c = 0;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -1 + -1
  cout << "Case : -1 + -1" << endl;
  b = -1;
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : 0 + 1
  cout << "Case : 0 + 1" << endl;
  b = 0;
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : 0 + 0
  cout << "Case : 0 + 0" << endl;
  b = 0;
  c = 0;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 0 + -1
  cout << "Case : 0 + -1" << endl;
  b = 0;
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 1 + 2
  cout << "Case : 1 + 2" << endl;
  b = 1;
  c = 2;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  // Case : 1 + -2
  cout << "Case : 1 + -2" << endl;
  b = 1;
  c = -2;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -1 + 2
  cout << "Case : -1 + 2" << endl;
  b = -1;
  c = 2;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -1 + -2
  cout << "Case : -1 + -2" << endl;
  b = -1;
  c = -2;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  // Case : (2^63) + (2^63)
  cout << "Case : (2^63) + (2^63)" << endl;
  b.from_string("9223372036854775808");
  c.from_string("9223372036854775808");
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^127) + (2^127)
  cout << "Case : (2^127) + (2^127)" << endl;
  b.from_string("170141183460469231731687303715884105728");
  c.from_string("170141183460469231731687303715884105728");
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^191) + (2^191)
  cout << "Case : (2^191) + (2^191)" << endl;
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  c.from_string("3138550867693340381917894711603833208051177722232017256448");
  a.add(b, c);
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) + (2^253)
  cout << "Case : (2^254) + (2^253)" << endl;
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  c.from_string("14474011154664524427946373126085988481658748083205070504932198000989141204992");
  a.add(b, c);
  check_value(a, (uint64_t)(0x6000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) + (2^254)
  cout << "Case : (2^254) + (2^254)" << endl;
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  c.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a.add(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^64-1) + 1
  cout << "Case : (2^64-1) + 1" << endl;
  b.from_string("18446744073709551615");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^64-1) + -1
  cout << "Case : (2^64-1) + -1" << endl;
  b.from_string("18446744073709551615");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : (2^128-1) + 1
  cout << "Case : (2^128-1) + 1" << endl;
  b.from_string("340282366920938463463374607431768211455");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^128-1) + -1
  cout << "Case : (2^128-1) + -1" << endl;
  b.from_string("340282366920938463463374607431768211455");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : (2^192-1) + 1
  cout << "Case : (2^192-1) + 1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512895");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^192-1) + -1
  cout << "Case : (2^192-1) + -1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512895");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : (2^64) + 1
  cout << "Case : (2^64) + 1" << endl;
  b.from_string("18446744073709551616");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^64) + -1
  cout << "Case : (2^64) + -1" << endl;
  b.from_string("18446744073709551616");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : (2^128) + 1
  cout << "Case : (2^128) + 1" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^128) + -1
  cout << "Case : (2^128) + -1" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : (2^192) + 1
  cout << "Case : (2^192) + 1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^192) + -1
  cout << "Case : (2^192) + -1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -(2^64-1) + 1
  cout << "Case : -(2^64-1) + 1" << endl;
  b.from_string("-18446744073709551615");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(2), (int)__LINE__, _result);

  // Case : -(2^64-1) + -1
  cout << "Case : -(2^64-1) + -1" << endl;
  b.from_string("-18446744073709551615");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -(2^128-1) + 1
  cout << "Case : -(2^128-1) + 1" << endl;
  b.from_string("-340282366920938463463374607431768211455");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : -(2^128-1) + -1
  cout << "Case : -(2^128-1) + -1" << endl;
  b.from_string("-340282366920938463463374607431768211455");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -(2^192-1) + 1
  cout << "Case : -(2^192-1) + 1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512895");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : -(2^192-1) + -1
  cout << "Case : -(2^192-1) + -1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512895");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -(2^64) + 1
  cout << "Case : -(2^64) + 1" << endl;
  b.from_string("-18446744073709551616");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -(2^64) + -1
  cout << "Case : -(2^64) + -1" << endl;
  b.from_string("-18446744073709551616");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -(2^128) + 1
  cout << "Case : -(2^128) + 1" << endl;
  b.from_string("-340282366920938463463374607431768211456");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -(2^128) + -1
  cout << "Case : -(2^128) + -1" << endl;
  b.from_string("-340282366920938463463374607431768211456");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -(2^192) + 1
  cout << "Case : -(2^192) + 1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512896");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -(2^192) + -1
  cout << "Case : -(2^192) + -1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512896");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : max + 1
  cout << "Case : max + 1" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : max + -1
  cout << "Case : max + -1" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : min + 1
  cout << "Case : min + 1" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c = 1;
  a.add(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : min + -1
  cout << "Case : min + -1" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c = -1;
  a.add(b, c);
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 1 + max
  cout << "Case : 1 + max" << endl;
  b = 1;
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a.add(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -1 + max
  cout << "Case : -1 + max" << endl;
  b = -1;
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a.add(b, c);
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : 1 + min
  cout << "Case : 1 + min" << endl;
  b = 1;
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a.add(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -1 + min
  cout << "Case : -1 + min" << endl;
  b = -1;
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a.add(b, c);
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : min + max
  cout << "Case : min + max" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : max + min
  cout << "Case : max + min" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 9000000000000000000 + 8000000000000000000
  cout << "Case : 9000000000000000000 + 8000000000000000000" << endl;
  b = (uint64_t)(9000000000000000000);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7CE66C50E2840000), (int)__LINE__, _result);
  c = (uint64_t)(8000000000000000000);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x6F05B59D3B200000), (int)__LINE__, _result);
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xEBEC21EE1DA40000), (int)__LINE__, _result);

  // Case : 9000000000000000000 + 18446744073709551615
  cout << "Case : 9000000000000000000 + 18446744073709551615" << endl;
  b = (uint64_t)(9000000000000000000);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7CE66C50E2840000), (int)__LINE__, _result);
  c = (uint64_t)(18446744073709551615);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x7CE66C50E283FFFF), (int)__LINE__, _result);

  // Case : -1 + -1000000000000000
  cout << "Case : -1 + -1000000000000000" << endl;
  b = -1;
  c = (int64_t)(-1000000000000000);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B398000), (int)__LINE__, _result);
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B397FFF), (int)__LINE__, _result);

  // Case : 2......2 + 1......1
  cout << "Case : 2......2 + 1......1" << endl;
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a.add(b, c);
  check_value(a, (uint64_t)(0x49B1FF823AA8F306), (uint64_t)(0x18A504E7B15134EA), (uint64_t)(0x38DD7E7A25463555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  // Case : 3......3 + 1......1
  cout << "Case : 3......3 + 1......1" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a.add(b, c);
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // Case : 3......3 + 2......2
  cout << "Case : 3......3 + 2......2" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.add(b, c);
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // Case : 4......4 + 2......2
  cout << "Case : 4......4 + 2......2" << endl;
  b.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.add(b, c);
  check_value(a, (uint64_t)(0x9363FF047551E60C), (uint64_t)(0x314A09CF62A269D4), (uint64_t)(0x71BAFCF44A8C6AAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  // Case : 2......2 + -1......1
  cout << "Case : 2......2 + -1......1" << endl;
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a.add(b, c);
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 3......3 + -1......1
  cout << "Case : 3......3 + -1......1" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a.add(b, c);
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 3......3 + -2......2
  cout << "Case : 3......3 + -2......2" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.add(b, c);
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 4......4 + -2......2
  cout << "Case : 4......4 + -2......2" << endl;
  b.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.add(b, c);
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : -1......1 + 2......2
  cout << "Case : -1......1 + 2......2" << endl;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.add(b, c);
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -1......1 + 3......3
  cout << "Case : -1......1 + 3......3" << endl;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a.add(b, c);
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : -2......2 + 3......3
  cout << "Case : -2......2 + 3......3" << endl;
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a.add(b, c);
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -2......2 + 4......4
  cout << "Case : -2......2 + 4......4" << endl;
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  a.add(b, c);
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 876543218765432187654321876543218765432187654321876543218765432187654321 + 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 + 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  b.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  c.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  a.add(b, c);
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 123456781234567812345678123456781234567812345678123456781234567812345678 + 876543218765432187654321876543218765432187654321876543218765432187654321
  cout << "Case : 123456781234567812345678123456781234567812345678123456781234567812345678 + 876543218765432187654321876543218765432187654321876543218765432187654321" << endl;
  b.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  c.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  a.add(b, c);
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 9838263505978427528 + 8608480567731124088
  cout << "Case : 9838263505978427528 + 8608480567731124088" << endl;
  b.from_string("9838263505978427528");
  c.from_string("8608480567731124088");
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 181483929024500513847133123963609712776 + 158798437896437949616241483468158498680
  cout << "Case : 181483929024500513847133123963609712776 + 158798437896437949616241483468158498680" << endl;
  b.from_string("181483929024500513847133123963609712776");
  c.from_string("158798437896437949616241483468158498680");
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 3347787592206229740712421025710755421921256237047485073544 + 2929314143180451023123368397496910994181099207416549439352
  cout << "Case : 3347787592206229740712421025710755421921256237047485073544 + 2929314143180451023123368397496910994181099207416549439352" << endl;
  b.from_string("3347787592206229740712421025710755421921256237047485073544");
  c.from_string("2929314143180451023123368397496910994181099207416549439352");
  a.add(b, c);
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 + 54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 + 54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  b.from_string("61755780926568637559237858671300217521743991821674967487710711470887002474632");
  c.from_string("54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -9838263505978427528 + -8608480567731124088
  cout << "Case : -9838263505978427528 + -8608480567731124088" << endl;
  b.from_string("-9838263505978427528");
  c.from_string("-8608480567731124088");
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -181483929024500513847133123963609712776 + -158798437896437949616241483468158498680
  cout << "Case : -181483929024500513847133123963609712776 + -158798437896437949616241483468158498680" << endl;
  b.from_string("-181483929024500513847133123963609712776");
  c.from_string("-158798437896437949616241483468158498680");
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -3347787592206229740712421025710755421921256237047485073544 + -2929314143180451023123368397496910994181099207416549439352
  cout << "Case : -3347787592206229740712421025710755421921256237047485073544 + -2929314143180451023123368397496910994181099207416549439352" << endl;
  b.from_string("-3347787592206229740712421025710755421921256237047485073544");
  c.from_string("-2929314143180451023123368397496910994181099207416549439352");
  a.add(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 + -54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 + -54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  b.from_string("-61755780926568637559237858671300217521743991821674967487710711470887002474632");
  c.from_string("-54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a.add(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 3347787592206229740712421025710755421921256237047485073544 + 57896044618658097708437704912137724185922571307109526597807535766909079746424
  cout << "Case : 3347787592206229740712421025710755421921256237047485073544 + 57896044618658097708437704912137724185922571307109526597807535766909079746424" << endl;
  b.from_string("3347787592206229740712421025710755421921256237047485073544");
  c.from_string("57896044618658097708437704912137724185922571307109526597807535766909079746424");
  a.add(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -3347787592206229740712421025710755421921256237047485073544 + -57896044618658097708437704912137724185922571307109526597807535766909079746424
  cout << "Case : -3347787592206229740712421025710755421921256237047485073544 + -57896044618658097708437704912137724185922571307109526597807535766909079746424" << endl;
  b.from_string("-3347787592206229740712421025710755421921256237047485073544");
  c.from_string("-57896044618658097708437704912137724185922571307109526597807535766909079746424");
  a.add(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\naddition_add()_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void addition_operator_test()
{
  BigInt a, b, c;
  bool _result = true;
  cout << "\n==[[addition_operator(+)_test]]==================================" << endl << endl;

  // Case : 1 + 1
  cout << "Case : 1 + 1" << endl;
  b = 1;
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : 1 + 0
  cout << "Case : 1 + 0" << endl;
  b = 1;
  c = 0;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : 1 + -1
  cout << "Case : 1 + -1" << endl;
  b = 1;
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -1 + 1
  cout << "Case : -1 + 1" << endl;
  b = -1;
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -1 + 0
  cout << "Case : -1 + 0" << endl;
  b = -1;
  c = 0;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -1 + -1
  cout << "Case : -1 + -1" << endl;
  b = -1;
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : 0 + 1
  cout << "Case : 0 + 1" << endl;
  b = 0;
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : 0 + 0
  cout << "Case : 0 + 0" << endl;
  b = 0;
  c = 0;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 0 + -1
  cout << "Case : 0 + -1" << endl;
  b = 0;
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 1 + 2
  cout << "Case : 1 + 2" << endl;
  b = 1;
  c = 2;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  // Case : 1 + -2
  cout << "Case : 1 + -2" << endl;
  b = 1;
  c = -2;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -1 + 2
  cout << "Case : -1 + 2" << endl;
  b = -1;
  c = 2;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -1 + -2
  cout << "Case : -1 + -2" << endl;
  b = -1;
  c = -2;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  // Case : (2^63) + (2^63)
  cout << "Case : (2^63) + (2^63)" << endl;
  b.from_string("9223372036854775808");
  c.from_string("9223372036854775808");
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^127) + (2^127)
  cout << "Case : (2^127) + (2^127)" << endl;
  b.from_string("170141183460469231731687303715884105728");
  c.from_string("170141183460469231731687303715884105728");
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^191) + (2^191)
  cout << "Case : (2^191) + (2^191)" << endl;
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  c.from_string("3138550867693340381917894711603833208051177722232017256448");
  a = b + c;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) + (2^253)
  cout << "Case : (2^254) + (2^253)" << endl;
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  c.from_string("14474011154664524427946373126085988481658748083205070504932198000989141204992");
  a = b + c;
  check_value(a, (uint64_t)(0x6000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) + (2^254)
  cout << "Case : (2^254) + (2^254)" << endl;
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  c.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a = b + c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^64-1) + 1
  cout << "Case : (2^64-1) + 1" << endl;
  b.from_string("18446744073709551615");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^64-1) + -1
  cout << "Case : (2^64-1) + -1" << endl;
  b.from_string("18446744073709551615");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : (2^128-1) + 1
  cout << "Case : (2^128-1) + 1" << endl;
  b.from_string("340282366920938463463374607431768211455");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^128-1) + -1
  cout << "Case : (2^128-1) + -1" << endl;
  b.from_string("340282366920938463463374607431768211455");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : (2^192-1) + 1
  cout << "Case : (2^192-1) + 1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512895");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^192-1) + -1
  cout << "Case : (2^192-1) + -1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512895");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : (2^64) + 1
  cout << "Case : (2^64) + 1" << endl;
  b.from_string("18446744073709551616");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^64) + -1
  cout << "Case : (2^64) + -1" << endl;
  b.from_string("18446744073709551616");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : (2^128) + 1
  cout << "Case : (2^128) + 1" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^128) + -1
  cout << "Case : (2^128) + -1" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : (2^192) + 1
  cout << "Case : (2^192) + 1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^192) + -1
  cout << "Case : (2^192) + -1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -(2^64-1) + 1
  cout << "Case : -(2^64-1) + 1" << endl;
  b.from_string("-18446744073709551615");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(2), (int)__LINE__, _result);

  // Case : -(2^64-1) + -1
  cout << "Case : -(2^64-1) + -1" << endl;
  b.from_string("-18446744073709551615");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -(2^128-1) + 1
  cout << "Case : -(2^128-1) + 1" << endl;
  b.from_string("-340282366920938463463374607431768211455");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : -(2^128-1) + -1
  cout << "Case : -(2^128-1) + -1" << endl;
  b.from_string("-340282366920938463463374607431768211455");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -(2^192-1) + 1
  cout << "Case : -(2^192-1) + 1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512895");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : -(2^192-1) + -1
  cout << "Case : -(2^192-1) + -1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512895");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -(2^64) + 1
  cout << "Case : -(2^64) + 1" << endl;
  b.from_string("-18446744073709551616");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -(2^64) + -1
  cout << "Case : -(2^64) + -1" << endl;
  b.from_string("-18446744073709551616");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -(2^128) + 1
  cout << "Case : -(2^128) + 1" << endl;
  b.from_string("-340282366920938463463374607431768211456");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -(2^128) + -1
  cout << "Case : -(2^128) + -1" << endl;
  b.from_string("-340282366920938463463374607431768211456");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -(2^192) + 1
  cout << "Case : -(2^192) + 1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512896");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -(2^192) + -1
  cout << "Case : -(2^192) + -1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512896");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : max + 1
  cout << "Case : max + 1" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : max + -1
  cout << "Case : max + -1" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : min + 1
  cout << "Case : min + 1" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c = 1;
  a = b + c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : min + -1
  cout << "Case : min + -1" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c = -1;
  a = b + c;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 1 + max
  cout << "Case : 1 + max" << endl;
  b = 1;
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a = b + c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -1 + max
  cout << "Case : -1 + max" << endl;
  b = -1;
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a = b + c;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : 1 + min
  cout << "Case : 1 + min" << endl;
  b = 1;
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a = b + c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -1 + min
  cout << "Case : -1 + min" << endl;
  b = -1;
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a = b + c;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : min + max
  cout << "Case : min + max" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : max + min
  cout << "Case : max + min" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 9000000000000000000 + 8000000000000000000
  cout << "Case : 9000000000000000000 + 8000000000000000000" << endl;
  b = (uint64_t)(9000000000000000000);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7CE66C50E2840000), (int)__LINE__, _result);
  c = (uint64_t)(8000000000000000000);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x6F05B59D3B200000), (int)__LINE__, _result);
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)0xEBEC21EE1DA40000, (int)__LINE__, _result);

  // Case : 9000000000000000000 + 18446744073709551615
  cout << "Case : 9000000000000000000 + 18446744073709551615" << endl;
  b = (uint64_t)(9000000000000000000);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7CE66C50E2840000), (int)__LINE__, _result);
  c = (uint64_t)(18446744073709551615);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x7CE66C50E283FFFF), (int)__LINE__, _result);

  // -1 + -1000000000000000
  cout << "Case : -1 + -1000000000000000" << endl;
  b = -1;
  c = (int64_t)(-1000000000000000);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B398000), (int)__LINE__, _result);
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B397FFF), (int)__LINE__, _result);

  // (2^190-1) + (2^190+1) + (2^190-1) + (2^190+1) + (2^190-1)
  cout << "Case : (2^190-1) + (2^190+1) + (2^190-1) + (2^190+1) + (2^190-1)" << endl;
  b.from_string("1569275433846670190958947355801916604025588861116008628223");
  check_value(b, (uint64_t)(0), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.from_string("1569275433846670190958947355801916604025588861116008628225");
  check_value(c, (uint64_t)(0), (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a = b + c + b + c + b;
  check_value(a, (uint64_t)(1), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 2......2 + 1......1
  cout << "Case : 2......2 + 1......1" << endl;
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a = b + c;
  check_value(a, (uint64_t)(0x49B1FF823AA8F306), (uint64_t)(0x18A504E7B15134EA), (uint64_t)(0x38DD7E7A25463555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  // Case : 3......3 + 1......1
  cout << "Case : 3......3 + 1......1" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a = b + c;
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // Case : 3......3 + 2......2
  cout << "Case : 3......3 + 2......2" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b + c;
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // Case : 4......4 + 2......2
  cout << "Case : 4......4 + 2......2" << endl;
  b.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b + c;
  check_value(a, (uint64_t)(0x9363FF047551E60C), (uint64_t)(0x314A09CF62A269D4), (uint64_t)(0x71BAFCF44A8C6AAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  // Case : 2......2 + -1......1
  cout << "Case : 2......2 + -1......1" << endl;
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a = b + c;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 3......3 + -1......1
  cout << "Case : 3......3 + -1......1" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a = b + c;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 3......3 + -2......2
  cout << "Case : 3......3 + -2......2" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b + c;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 4......4 + -2......2
  cout << "Case : 4......4 + -2......2" << endl;
  b.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b + c;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : -1......1 + 2......2
  cout << "Case : -1......1 + 2......2" << endl;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b + c;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -1......1 + 3......3
  cout << "Case : -1......1 + 3......3" << endl;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a = b + c;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : -2......2 + 3......3
  cout << "Case : -2......2 + 3......3" << endl;
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a = b + c;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -2......2 + 4......4
  cout << "Case : -2......2 + 4......4" << endl;
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  a = b + c;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 876543218765432187654321876543218765432187654321876543218765432187654321 + 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 + 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  b.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  c.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  a = b + c;
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 123456781234567812345678123456781234567812345678123456781234567812345678 + 876543218765432187654321876543218765432187654321876543218765432187654321
  cout << "Case : 123456781234567812345678123456781234567812345678123456781234567812345678 + 876543218765432187654321876543218765432187654321876543218765432187654321" << endl;
  b.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  c.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  a = b + c;
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 9838263505978427528 + 8608480567731124088
  cout << "Case : 9838263505978427528 + 8608480567731124088" << endl;
  b.from_string("9838263505978427528");
  c.from_string("8608480567731124088");
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 181483929024500513847133123963609712776 + 158798437896437949616241483468158498680
  cout << "Case : 181483929024500513847133123963609712776 + 158798437896437949616241483468158498680" << endl;
  b.from_string("181483929024500513847133123963609712776");
  c.from_string("158798437896437949616241483468158498680");
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 3347787592206229740712421025710755421921256237047485073544 + 2929314143180451023123368397496910994181099207416549439352
  cout << "Case : 3347787592206229740712421025710755421921256237047485073544 + 2929314143180451023123368397496910994181099207416549439352" << endl;
  b.from_string("3347787592206229740712421025710755421921256237047485073544");
  c.from_string("2929314143180451023123368397496910994181099207416549439352");
  a = b + c;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 + 54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 + 54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  b.from_string("61755780926568637559237858671300217521743991821674967487710711470887002474632");
  c.from_string("54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -9838263505978427528 + -8608480567731124088
  cout << "Case : -9838263505978427528 + -8608480567731124088" << endl;
  b.from_string("-9838263505978427528");
  c.from_string("-8608480567731124088");
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -181483929024500513847133123963609712776 + -158798437896437949616241483468158498680
  cout << "Case : -181483929024500513847133123963609712776 + -158798437896437949616241483468158498680" << endl;
  b.from_string("-181483929024500513847133123963609712776");
  c.from_string("-158798437896437949616241483468158498680");
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -3347787592206229740712421025710755421921256237047485073544 + -2929314143180451023123368397496910994181099207416549439352
  cout << "Case : -3347787592206229740712421025710755421921256237047485073544 + -2929314143180451023123368397496910994181099207416549439352" << endl;
  b.from_string("-3347787592206229740712421025710755421921256237047485073544");
  c.from_string("-2929314143180451023123368397496910994181099207416549439352");
  a = b + c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 + -54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 + -54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  b.from_string("-61755780926568637559237858671300217521743991821674967487710711470887002474632");
  c.from_string("-54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a = b + c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 3347787592206229740712421025710755421921256237047485073544 + 57896044618658097708437704912137724185922571307109526597807535766909079746424
  cout << "Case : 3347787592206229740712421025710755421921256237047485073544 + 57896044618658097708437704912137724185922571307109526597807535766909079746424" << endl;
  b.from_string("3347787592206229740712421025710755421921256237047485073544");
  c.from_string("57896044618658097708437704912137724185922571307109526597807535766909079746424");
  a = b + c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -3347787592206229740712421025710755421921256237047485073544 + -57896044618658097708437704912137724185922571307109526597807535766909079746424
  cout << "Case : -3347787592206229740712421025710755421921256237047485073544 + -57896044618658097708437704912137724185922571307109526597807535766909079746424" << endl;
  b.from_string("-3347787592206229740712421025710755421921256237047485073544");
  c.from_string("-57896044618658097708437704912137724185922571307109526597807535766909079746424");
  a = b + c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\naddition_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void addition_assignment_operator_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[addition_assignment_operator(+=)_test]]==================================" << endl << endl;

  // Case : 1 += 1
  cout << "Case : 1 += 1" << endl;
  a = 1;
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : 1 += 0
  cout << "Case : 1 += 0" << endl;
  a = 1;
  b = 0;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : 1 += -1
  cout << "Case : 1 += -1" << endl;
  a = 1;
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -1 += 1
  cout << "Case : -1 += 1" << endl;
  a = -1;
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -1 += 0
  cout << "Case : -1 += 0" << endl;
  a = -1;
  b = 0;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -1 += -1
  cout << "Case : -1 += -1" << endl;
  a = -1;
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : 0 += 1
  cout << "Case : 0 += 1" << endl;
  a = 0;
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : 0 += 0
  cout << "Case : 0 += 0" << endl;
  a = 0;
  b = 0;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 0 += -1
  cout << "Case : 0 += -1" << endl;
  a = 0;
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 1 += 2
  cout << "Case : 1 += 2" << endl;
  a = 1;
  b = 2;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  // Case : 1 += -2
  cout << "Case : 1 += -2" << endl;
  a = 1;
  b = -2;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -1 += 2
  cout << "Case : -1 += 2" << endl;
  a = -1;
  b = 2;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -1 += -2
  cout << "Case : -1 += -2" << endl;
  a = -1;
  b = -2;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  // Case : (2^63) += (2^63)
  cout << "Case : (2^63) += (2^63)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775808");
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^127) += (2^127)
  cout << "Case : (2^127) += (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^191) += (2^191)
  cout << "Case : (2^191) += (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  a += b;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) += (2^253)
  cout << "Case : (2^254) += (2^253)" << endl;
  a.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b.from_string("14474011154664524427946373126085988481658748083205070504932198000989141204992");
  a += b;
  check_value(a, (uint64_t)(0x6000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) += (2^254)
  cout << "Case : (2^254) += (2^254)" << endl;
  a.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a += b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^64-1) += 1
  cout << "Case : (2^64-1) += 1" << endl;
  a.from_string("18446744073709551615");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^64-1) += -1
  cout << "Case : (2^64-1) += -1" << endl;
  a.from_string("18446744073709551615");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : (2^128-1) += 1
  cout << "Case : (2^128-1) += 1" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^128-1) += -1
  cout << "Case : (2^128-1) += -1" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : (2^192-1) += 1
  cout << "Case : (2^192-1) += 1" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512895");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^192-1) += -1
  cout << "Case : (2^192-1) += -1" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512895");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : (2^64) += 1
  cout << "Case : (2^64) += 1" << endl;
  a.from_string("18446744073709551616");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^64) += -1
  cout << "Case : (2^64) += -1" << endl;
  a.from_string("18446744073709551616");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : (2^128) += 1
  cout << "Case : (2^128) += 1" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^128) += -1
  cout << "Case : (2^128) += -1" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : (2^192) += 1
  cout << "Case : (2^192) += 1" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^192) += -1
  cout << "Case : (2^192) += -1" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -(2^64-1) += 1
  cout << "Case : -(2^64-1) += 1" << endl;
  a.from_string("-18446744073709551615");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(2), (int)__LINE__, _result);

  // Case : -(2^64-1) += -1
  cout << "Case : -(2^64-1) += -1" << endl;
  a.from_string("-18446744073709551615");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -(2^128-1) += 1
  cout << "Case : -(2^128-1) += 1" << endl;
  a.from_string("-340282366920938463463374607431768211455");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : -(2^128-1) += -1
  cout << "Case : -(2^128-1) += -1" << endl;
  a.from_string("-340282366920938463463374607431768211455");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -(2^192-1) += 1
  cout << "Case : -(2^192-1) += 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512895");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // Case : -(2^192-1) += -1
  cout << "Case : -(2^192-1) += -1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512895");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -(2^64) += 1
  cout << "Case : -(2^64) += 1" << endl;
  a.from_string("-18446744073709551616");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -(2^64) += -1
  cout << "Case : -(2^64) += -1" << endl;
  a.from_string("-18446744073709551616");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -(2^128) += 1
  cout << "Case : -(2^128) += 1" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -(2^128) += -1
  cout << "Case : -(2^128) += -1" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : -(2^192) += 1
  cout << "Case : -(2^192) += 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -(2^192) += -1
  cout << "Case : -(2^192) += -1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : max += 1
  cout << "Case : max += 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : max += -1
  cout << "Case : max += -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : min += 1
  cout << "Case : min += 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : min += -1
  cout << "Case : min += -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 1 + max
  cout << "Case : 1 + max" << endl;
  a = 1;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a += b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -1 + max
  cout << "Case : -1 + max" << endl;
  a = -1;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a += b;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // Case : 1 + min
  cout << "Case :1 + min" << endl;
  a = 1;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a += b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : -1 + min
  cout << "Case : -1 + min" << endl;
  a = -1;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a += b;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : min += max
  cout << "Case : min += max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : max += min
  cout << "Case : max += min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 9000000000000000000 += 8000000000000000000
  cout << "Case : 9000000000000000000 += 8000000000000000000" << endl;
  a = (uint64_t)(9000000000000000000);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7CE66C50E2840000), (int)__LINE__, _result);
  b = (uint64_t)(8000000000000000000);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x6F05B59D3B200000), (int)__LINE__, _result);
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)0xEBEC21EE1DA40000, (int)__LINE__, _result);

  // Case : 9000000000000000000 += 18446744073709551615
  cout << "Case : 9000000000000000000 += 18446744073709551615" << endl;
  a = (uint64_t)(9000000000000000000);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7CE66C50E2840000), (int)__LINE__, _result);
  b = (uint64_t)(18446744073709551615);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x7CE66C50E283FFFF), (int)__LINE__, _result);

  // -1 += -1000000000000000
  cout << "Case : -1 += -1000000000000000" << endl;
  a = -1;
  b = (int64_t)(-1000000000000000);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B398000), (int)__LINE__, _result);
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B397FFF), (int)__LINE__, _result);

  cout << "Case : 0 += 1; 1 += (0 += 1)" << endl;
  a = 0;
  b = 1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  b += a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF += -1; -1 += (0xFFFFFFFFFFFFFFFF += -1)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  b += a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : -1 += -1; -1 += (-1 += -1)" << endl;
  a = -1;
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  b += a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : -1000 += -1; -1 += (-1000 += -1)" << endl;
  a = -1000;
  b = -1;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFC17, (int)__LINE__, _result);
  b += a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFC16, (int)__LINE__, _result);

  cout << "Case : 0 += 1000; 1000 += (0 += 1000)" << endl;
  a = 0;
  b = 1000;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1000), (int)__LINE__, _result);
  b += a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2000), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF += 1000; 1000 += (0xFFFFFFFFFFFFFFFF += 1000)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = 1000;
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(999), (int)__LINE__, _result);
  b += a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1999), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF += -1000; -1000 += (0xFFFFFFFFFFFFFFFF += -1000)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = -1000;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFC17), (int)__LINE__, _result);
  b += a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFF82F), (int)__LINE__, _result);

  cout << "Case : -1 += -1000; -1000 += (-1 += -1000)" << endl;
  a = -1;
  b = -1000;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFC17, (int)__LINE__, _result);
  b += a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFF82F, (int)__LINE__, _result);

  cout << "Case : -1000 += -1000; -1000 += (-1000 += -1000)" << endl;
  a = -1000;
  b = -1000;
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFF830, (int)__LINE__, _result);
  b += a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFF448, (int)__LINE__, _result);

  // Case : 2......2 + 1......1
  cout << "Case : 2......2 + 1......1" << endl;
  a.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a += b;
  check_value(a, (uint64_t)(0x49B1FF823AA8F306), (uint64_t)(0x18A504E7B15134EA), (uint64_t)(0x38DD7E7A25463555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  // Case : 3......3 + 1......1
  cout << "Case : 3......3 + 1......1" << endl;
  a.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a += b;
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // Case : 3......3 + 2......2
  cout << "Case : 3......3 + 2......2" << endl;
  a.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a += b;
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // Case : 4......4 + 2......2
  cout << "Case : 4......4 + 2......2" << endl;
  a.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a += b;
  check_value(a, (uint64_t)(0x9363FF047551E60C), (uint64_t)(0x314A09CF62A269D4), (uint64_t)(0x71BAFCF44A8C6AAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  // Case : 2......2 + -1......1
  cout << "Case : 2......2 + -1......1" << endl;
  a.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a += b;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 3......3 + -1......1
  cout << "Case : 3......3 + -1......1" << endl;
  a.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a += b;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 3......3 + -2......2
  cout << "Case : 3......3 + -2......2" << endl;
  a.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a += b;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 4......4 + -2......2
  cout << "Case : 4......4 + -2......2" << endl;
  a.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a += b;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : -1......1 + 2......2
  cout << "Case : -1......1 + 2......2" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a += b;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -1......1 + 3......3
  cout << "Case : -1......1 + 3......3" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a += b;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : -2......2 + 3......3
  cout << "Case : -2......2 + 3......3" << endl;
  a.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a += b;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -2......2 + 4......4
  cout << "Case : -2......2 + 4......4" << endl;
  a.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  b.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  a += b;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 876543218765432187654321876543218765432187654321876543218765432187654321 + 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 + 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  a.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  b.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  a += b;
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 123456781234567812345678123456781234567812345678123456781234567812345678 + 876543218765432187654321876543218765432187654321876543218765432187654321
  cout << "Case : 123456781234567812345678123456781234567812345678123456781234567812345678 + 876543218765432187654321876543218765432187654321876543218765432187654321" << endl;
  a.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  b.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  a += b;
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 9838263505978427528 + 8608480567731124088
  cout << "Case : 9838263505978427528 + 8608480567731124088" << endl;
  a.from_string("9838263505978427528");
  b.from_string("8608480567731124088");
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 181483929024500513847133123963609712776 + 158798437896437949616241483468158498680
  cout << "Case : 181483929024500513847133123963609712776 + 158798437896437949616241483468158498680" << endl;
  a.from_string("181483929024500513847133123963609712776");
  b.from_string("158798437896437949616241483468158498680");
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 3347787592206229740712421025710755421921256237047485073544 + 2929314143180451023123368397496910994181099207416549439352
  cout << "Case : 3347787592206229740712421025710755421921256237047485073544 + 2929314143180451023123368397496910994181099207416549439352" << endl;
  a.from_string("3347787592206229740712421025710755421921256237047485073544");
  b.from_string("2929314143180451023123368397496910994181099207416549439352");
  a += b;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 + 54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 + 54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  a.from_string("61755780926568637559237858671300217521743991821674967487710711470887002474632");
  b.from_string("54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -9838263505978427528 + -8608480567731124088
  cout << "Case : -9838263505978427528 + -8608480567731124088" << endl;
  a.from_string("-9838263505978427528");
  b.from_string("-8608480567731124088");
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -181483929024500513847133123963609712776 + -158798437896437949616241483468158498680
  cout << "Case : -181483929024500513847133123963609712776 + -158798437896437949616241483468158498680" << endl;
  a.from_string("-181483929024500513847133123963609712776");
  b.from_string("-158798437896437949616241483468158498680");
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -3347787592206229740712421025710755421921256237047485073544 + -2929314143180451023123368397496910994181099207416549439352
  cout << "Case : -3347787592206229740712421025710755421921256237047485073544 + -2929314143180451023123368397496910994181099207416549439352" << endl;
  a.from_string("-3347787592206229740712421025710755421921256237047485073544");
  b.from_string("-2929314143180451023123368397496910994181099207416549439352");
  a += b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 + -54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 + -54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  a.from_string("-61755780926568637559237858671300217521743991821674967487710711470887002474632");
  b.from_string("-54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a += b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 3347787592206229740712421025710755421921256237047485073544 + 57896044618658097708437704912137724185922571307109526597807535766909079746424
  cout << "Case : 3347787592206229740712421025710755421921256237047485073544 + 57896044618658097708437704912137724185922571307109526597807535766909079746424" << endl;
  a.from_string("3347787592206229740712421025710755421921256237047485073544");
  b.from_string("57896044618658097708437704912137724185922571307109526597807535766909079746424");
  a += b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -3347787592206229740712421025710755421921256237047485073544 + -57896044618658097708437704912137724185922571307109526597807535766909079746424
  cout << "Case : -3347787592206229740712421025710755421921256237047485073544 + -57896044618658097708437704912137724185922571307109526597807535766909079746424" << endl;
  a.from_string("-3347787592206229740712421025710755421921256237047485073544");
  b.from_string("-57896044618658097708437704912137724185922571307109526597807535766909079746424");
  a += b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\naddition_assign_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void subtraction_test()
{
  BigInt a, b, c;
  bool _result = true;
  cout << "\n==[[subtraction_sub()_test]]==================================" << endl << endl;

  // 1 - 1
  cout << "Case : 1 - 1" << endl;
  b = 1;
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 - 0
  cout << "Case : 1 - 0" << endl;
  b = 1;
  c = 0;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - -1
  cout << "Case : 1 - -1" << endl;
  b = 1;
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -1 - 1
  cout << "Case : -1 - 1" << endl;
  b = -1;
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -1 - 0
  cout << "Case : -1 - 0" << endl;
  b = -1;
  c = 0;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -1 - -1
  cout << "Case : -1 - -1" << endl;
  b = -1;
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 - 1
  cout << "Case : 0 - 1" << endl;
  b = 0;
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 0 - 0
  cout << "Case : 0 - 0" << endl;
  b = 0;
  c = 0;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 - -1
  cout << "Case : 0 - -1" << endl;
  b = 0;
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - 2
  cout << "Case : 1 - 2" << endl;
  b = 1;
  c = 2;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 1 - -2
  cout << "Case : 1 - -2" << endl;
  b = 1;
  c = -2;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  // -1 - 2
  cout << "Case : -1 - 2" << endl;
  b = -1;
  c = 2;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  // -1 - -2
  cout << "Case : -1 - -2" << endl;
  b = -1;
  c = -2;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^64) - (2^63)
  cout << "Case : (2^64) - (2^63)" << endl;
  b.from_string("18446744073709551616");
  c.from_string("9223372036854775808");
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  // Case : (2^128) - (2^127)
  cout << "Case : (2^128) - (2^127)" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c.from_string("170141183460469231731687303715884105728");
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^192) - (2^191)
  cout << "Case : (2^192) - (2^191)" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c.from_string("3138550867693340381917894711603833208051177722232017256448");
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) - (2^253)
  cout << "Case : (2^254) - (2^253)" << endl;
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  c.from_string("14474011154664524427946373126085988481658748083205070504932198000989141204992");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x2000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^255) - (2^254)
  cout << "Case : (2^255) - (2^254)" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^63) - (2^64)
  cout << "Case : (2^63) - (2^64)" << endl;
  b.from_string("9223372036854775808");
  c.from_string("18446744073709551616");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  // Case : (2^127) - (2^128)
  cout << "Case : (2^127) - (2^128)" << endl;
  b.from_string("170141183460469231731687303715884105728");
  c.from_string("340282366920938463463374607431768211456");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^191) - (2^192)
  cout << "Case : (2^191) - (2^192)" << endl;
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  c.from_string("6277101735386680763835789423207666416102355444464034512896");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^253) - (2^254)
  cout << "Case : (2^253) - (2^254)" << endl;
  b.from_string("14474011154664524427946373126085988481658748083205070504932198000989141204992");
  c.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xE000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) - (2^255)
  cout << "Case : (2^254) - (2^255)" << endl;
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xC000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 - (2^64)
  cout << "Case : 1 - (2^64)" << endl;
  b = 1;
  c.from_string("18446744073709551616");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - (2^128)
  cout << "Case : 1 - (2^128)" << endl;
  b = 1;
  c.from_string("340282366920938463463374607431768211456");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - (2^192)
  cout << "Case : 1 - (2^192)" << endl;
  b = 1;
  c.from_string("6277101735386680763835789423207666416102355444464034512896");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // (2^64-1) - 1
  cout << "Case : (2^64-1) - 1" << endl;
  b.from_string("18446744073709551615");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // (2^64-1) - -1
  cout << "Case : (2^64-1) - -1" << endl;
  b.from_string("18446744073709551615");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // (2^128-1) - 1
  cout << "Case : (2^128-1) - 1" << endl;
  b.from_string("340282366920938463463374607431768211455");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // (2^128-1) - -1
  cout << "Case : (2^128-1) - -1" << endl;
  b.from_string("340282366920938463463374607431768211455");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // (2^192-1) - 1
  cout << "Case : (2^192-1) - 1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512895");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // (2^192-1) - -1
  cout << "Case : (2^192-1) - -1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512895");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // (2^64) - 1
  cout << "Case : (2^64) - 1" << endl;
  b.from_string("18446744073709551616");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^64) - -1
  cout << "Case : (2^64) - -1" << endl;
  b.from_string("18446744073709551616");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);

  // (2^128) - 1
  cout << "Case : (2^128) - 1" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^128) - -1
  cout << "Case : (2^128) - -1" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // (2^192) - 1
  cout << "Case : (2^192) - 1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^192) - -1
  cout << "Case : (2^192) - -1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -(2^64-1) - 1
  cout << "Case : -(2^64-1) - 1" << endl;
  b.from_string("-18446744073709551615");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // -(2^64-1) - -1
  cout << "Case : -(2^64-1) - -1" << endl;
  b.from_string("-18446744073709551615");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(2), (int)__LINE__, _result);

  // -(2^128-1) - 1
  cout << "Case : -(2^128-1) - 1" << endl;
  b.from_string("-340282366920938463463374607431768211455");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // C-(2^128-1) - -1
  cout << "Case : -(2^128-1) - -1" << endl;
  b.from_string("-340282366920938463463374607431768211455");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -(2^192-1) - 1
  cout << "Case : -(2^192-1) - 1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512895");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -(2^192-1) - -1
  cout << "Case : -(2^192-1) - -1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512895");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -(2^64) - 1
  cout << "Case : -(2^64) - 1" << endl;
  b.from_string("-18446744073709551616");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -(2^64) - -1
  cout << "Case : -(2^64) - -1" << endl;
  b.from_string("-18446744073709551616");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  // -(2^128) - 1
  cout << "Case : -(2^128) - 1" << endl;
  b.from_string("-340282366920938463463374607431768211456");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  //  -(2^128) - -1
  cout << "Case : -(2^128) - -1" << endl;
  b.from_string("-340282366920938463463374607431768211456");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -(2^192) - 1
  cout << "Case : -(2^192) - 1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512896");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -(2^192) - -1
  cout << "Case : -(2^192) - -1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512896");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // max - 1
  cout << "Case : max - 1" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // max - -1
  cout << "Case : max - -1" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // min - 1
  cout << "Case : min - 1" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // min - -1
  cout << "Case : min - -1" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - max
  cout << "Case : 1 - max" << endl;
  b = 1;
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -1 - max
  cout << "Case : -1 - max" << endl;
  b = -1;
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 - min
  cout << "Case : 1 - min" << endl;
  b = 1;
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -1 - min
  cout << "Case : -1 - min" << endl;
  b = -1;
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // min - max
  cout << "Case : min - max" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // max - min
  cout << "Case : max - min" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 9000000000000000000 - 8000000000000000000
  cout << "Case : 9000000000000000000 - 8000000000000000000" << endl;
  b = (uint64_t)(9000000000000000000);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7CE66C50E2840000), (int)__LINE__, _result);
  c = (uint64_t)(8000000000000000000);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x6F05B59D3B200000), (int)__LINE__, _result);
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xDE0B6B3A7640000), (int)__LINE__, _result);

  // -1 - 1000000000000000
  cout << "Case : -1 - 1000000000000000" << endl;
  b = -1;
  c = (uint64_t)(1000000000000000);
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B397FFF), (int)__LINE__, _result);

  // -1 - -1000000000000000
  cout << "Case : -1 - -1000000000000000" << endl;
  b = -1;
  c = (int64_t)(-1000000000000000);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B398000), (int)__LINE__, _result);
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00038D7EA4C67FFF), (int)__LINE__, _result);

  // 1000 - 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 - (1000 - 0xFFFFFFFFFFFFFFFF << 64)
  cout << "Case : 1000 - 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 - (1000 - 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  b = 1000;
  c = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  c = c << 64;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(1000), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);

  // 9000000000000000000 - 18446744073709551615
  cout << "Case : 9000000000000000000 - 18446744073709551615" << endl;
  b = (uint64_t)(9000000000000000000);
  c = (uint64_t)(18446744073709551615);
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x7CE66C50E2840001), (int)__LINE__, _result);

  cout << "Case : 2^192 -= (2^191+1)" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c.from_string("3138550867693340381917894711603833208051177722232017256449");
  check_value(c, (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^191+1) -= 2^192" << endl;
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  c.from_string("6277101735386680763835789423207666416102355444464034512896");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 2^128 -= (2^127+1)" << endl;
  b.from_string("340282366920938463463374607431768211456");
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c.from_string("170141183460469231731687303715884105729");
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(1), (int)__LINE__, _result);
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^127+1) -= 2^128" << endl;
  b.from_string("170141183460469231731687303715884105729");
  c.from_string("340282366920938463463374607431768211456");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 2^64 -= (2^63+1)" << endl;
  b.from_string("18446744073709551616");
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  c.from_string("9223372036854775809");
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^63+1) -= 2^64" << endl;
  b.from_string("9223372036854775809");
  c.from_string("18446744073709551616");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);

  cout << "Case : -1 -= -1; -1 -= (-1 -= -1)" << endl;
  b = -1;
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 -= 0; 0 -= (-1 -= 0)" << endl;
  b = -1;
  c = 0;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 -= 100; 100 -= (-1 -= 100)" << endl;
  b = -1;
  c = 100;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFF9B, (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(201), (int)__LINE__, _result);

  cout << "Case : -1 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (-1 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  b = -1;
  c = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  c = c << 64;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -10000 -= 1; 1 -= (-10000 -= 1)" << endl;
  b = -10000;
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD8EF), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(10002), (int)__LINE__, _result);

  cout << "Case : -10000 -= -1; -1 -= (-10000 -= -1)" << endl;
  b = -10000;
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD8F1), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(9998), (int)__LINE__, _result);

  cout << "Case : -10000 -= 0; 0 -= (-10000 -= 0)" << endl;
  b = -10000;
  c = 0;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD8F0), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(10000), (int)__LINE__, _result);

  cout << "Case : -10000 -= 100; 100 -= (-10000 -= 100)" << endl;
  b = -10000;
  c = 100;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD88C), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(10200), (int)__LINE__, _result);

  cout << "Case : -10000 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (-10000 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  b = -10000;
  c = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  c = c << 64;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFD8F0), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0x0000000000002710), (int)__LINE__, _result);

  cout << "Case : 0 -= 1; 1 -= (0 -= 1)" << endl;
  b = 0;
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 0 -= -1; -1 -= (0 -= -1)" << endl;
  b = 0;
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0 -= 0; 0 -= (0 -= 0)" << endl;
  b = 0;
  c = 0;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0 -= 100; 100 -= (0 -= 100)" << endl;
  b = 0;
  c = 100;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFF9C), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(200), (int)__LINE__, _result);

  cout << "Case : 0 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (0 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  b = 0;
  c = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  c = c << 64;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 -= 1; 1 -= (1 -= 1)" << endl;
  b = 1;
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1 -= -1; -1 -= (1 -= -1)" << endl;
  b = 1;
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : 1 -= 0; 0 -= (1 -= 0)" << endl;
  b = 1;
  c = 0;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1 -= 100; 100 -= (1 -= 100)" << endl;
  b = 1;
  c = 100;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFF9D), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(199), (int)__LINE__, _result);

  cout << "Case : 1 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (1 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  b = 1;
  c = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  c = c << 64;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1000 -= 1; 1 -= (1000 -= 1)" << endl;
  b = 1000;
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(999), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC1A), (int)__LINE__, _result);

  cout << "Case : 1000 -= -1; -1 -= (1000 -= -1)" << endl;
  b = 1000;
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1001), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC16), (int)__LINE__, _result);

  cout << "Case : 1000 -= 0; 0 -= (1000 -= 0)" << endl;
  b = 1000;
  c = 0;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1000), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);

  cout << "Case : 1000 -= 100; 100 -= (1000 -= 100)" << endl;
  b = 1000;
  c = 100;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(900), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFCE0), (int)__LINE__, _result);

  cout << "Case : 1000 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (1000 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  b = 1000;
  c = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  c = c << 64;
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(1000), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 1; 1 -= (0xFFFFFFFFFFFFFFFF << 64 -= 1)" << endl;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  c = 1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= -1; -1 -= (0xFFFFFFFFFFFFFFFF << 64 -= -1)" << endl;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  c = -1;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 0; 0 -= (0xFFFFFFFFFFFFFFFF << 64 -= 0)" << endl;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  c = 0;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 100; 100 -= (0xFFFFFFFFFFFFFFFF << 64 -= 100)" << endl;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  c = 100;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFF9C), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(0x00000000000000C8), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 0xFFFFFFFFFFFFFFFF << 63; 0xFFFFFFFFFFFFFFFF << 63 -= (0xFFFFFFFFFFFFFFFF << 64 -= 0xFFFFFFFFFFFFFFFF << 63)" << endl;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  c = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  c = c << 63;
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 2......2 - 1......1
  cout << "Case : 2......2 - 1......1" << endl;
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 3......3 - 1......1
  cout << "Case : 3......3 - 1......1" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 3......3 - 2......2
  cout << "Case : 3......3 - 2......2" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 4......4 - 2......2
  cout << "Case : 4......4 - 2......2" << endl;
  b.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 2......2 - -1......1
  cout << "Case : 2......2 - -1......1" << endl;
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x49B1FF823AA8F306), (uint64_t)(0x18A504E7B15134EA), (uint64_t)(0x38DD7E7A25463555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  // Case : 3......3 - -1......1
  cout << "Case : 3......3 - -1......1" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // Case : 3......3 - -2......2
  cout << "Case : 3......3 - -2......2" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // Case : 4......4 - -2......2
  cout << "Case : 4......4 - -2......2" << endl;
  b.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x9363FF047551E60C), (uint64_t)(0x314A09CF62A269D4), (uint64_t)(0x71BAFCF44A8C6AAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  // Case : -1......1 - -2......2
  cout << "Case : -1......1 - -2......2" << endl;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -1......1 - -3......3
  cout << "Case : -1......1 - -3......3" << endl;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : -2......2 - -3......3
  cout << "Case : -2......2 - -3......3" << endl;
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -2......2 - -4......4
  cout << "Case : -2......2 - -4......4" << endl;
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("-44444444444444444444444444444444444444444444444444444444444444444444444444444");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 876543218765432187654321876543218765432187654321876543218765432187654321 - -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 - -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  b.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  c.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 123456781234567812345678123456781234567812345678123456781234567812345678 - -876543218765432187654321876543218765432187654321876543218765432187654321
  cout << "Case : 123456781234567812345678123456781234567812345678123456781234567812345678 - -876543218765432187654321876543218765432187654321876543218765432187654321" << endl;
  b.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  c.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  a.sub(b, c);
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 9838263505978427528 - -8608480567731124088
  cout << "Case : 9838263505978427528 - -8608480567731124088" << endl;
  b.from_string("9838263505978427528");
  c.from_string("-8608480567731124088");
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 181483929024500513847133123963609712776 - -158798437896437949616241483468158498680
  cout << "Case : 181483929024500513847133123963609712776 - -158798437896437949616241483468158498680" << endl;
  b.from_string("181483929024500513847133123963609712776");
  c.from_string("-158798437896437949616241483468158498680");
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 3347787592206229740712421025710755421921256237047485073544 - -2929314143180451023123368397496910994181099207416549439352
  cout << "Case : 3347787592206229740712421025710755421921256237047485073544 - -2929314143180451023123368397496910994181099207416549439352" << endl;
  b.from_string("3347787592206229740712421025710755421921256237047485073544");
  c.from_string("-2929314143180451023123368397496910994181099207416549439352");
  a.sub(b, c);
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 - -54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 - -54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  b.from_string("61755780926568637559237858671300217521743991821674967487710711470887002474632");
  c.from_string("-54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -9838263505978427528 - 8608480567731124088
  cout << "Case : -9838263505978427528 - 8608480567731124088" << endl;
  b.from_string("-9838263505978427528");
  c.from_string("8608480567731124088");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -181483929024500513847133123963609712776 - 158798437896437949616241483468158498680
  cout << "Case : -181483929024500513847133123963609712776 - 158798437896437949616241483468158498680" << endl;
  b.from_string("-181483929024500513847133123963609712776");
  c.from_string("158798437896437949616241483468158498680");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -3347787592206229740712421025710755421921256237047485073544 - 2929314143180451023123368397496910994181099207416549439352
  cout << "Case : -3347787592206229740712421025710755421921256237047485073544 - 2929314143180451023123368397496910994181099207416549439352" << endl;
  b.from_string("-3347787592206229740712421025710755421921256237047485073544");
  c.from_string("2929314143180451023123368397496910994181099207416549439352");
  a.sub(b, c);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 - 54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 - 54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  b.from_string("-61755780926568637559237858671300217521743991821674967487710711470887002474632");
  c.from_string("54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a.sub(b, c);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nsubtraction_sub()_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void subtraction_operator_test()
{
  BigInt a, b, c;
  bool _result = true;
  cout << "\n==[[subtraction_operator(-)_test]]==================================" << endl << endl;

  // 1 - 1
  cout << "Case : 1 - 1" << endl;
  b = 1;
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 - 0
  cout << "Case : 1 - 0" << endl;
  b = 1;
  c = 0;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - -1
  cout << "Case : 1 - -1" << endl;
  b = 1;
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -1 - 1
  cout << "Case : -1 - 1" << endl;
  b = -1;
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -1 - 0
  cout << "Case : -1 - 0" << endl;
  b = -1;
  c = 0;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -1 - -1
  cout << "Case : -1 - -1" << endl;
  b = -1;
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 - 1
  cout << "Case : 0 - 1" << endl;
  b = 0;
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 0 - 0
  cout << "Case : 0 - 0" << endl;
  b = 0;
  c = 0;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 - -1
  cout << "Case : 0 - -1" << endl;
  b = 0;
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - 2
  cout << "Case : 1 - 2" << endl;
  b = 1;
  c = 2;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 1 - -2
  cout << "Case : 1 - -2" << endl;
  b = 1;
  c = -2;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  // -1 - 2
  cout << "Case : -1 - 2" << endl;
  b = -1;
  c = 2;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  // -1 - -2
  cout << "Case : -1 - -2" << endl;
  b = -1;
  c = -2;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^64) - (2^63)
  cout << "Case : (2^64) - (2^63)" << endl;
  b.from_string("18446744073709551616");
  c.from_string("9223372036854775808");
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  // Case : (2^128) - (2^127)
  cout << "Case : (2^128) - (2^127)" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c.from_string("170141183460469231731687303715884105728");
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^192) - (2^191)
  cout << "Case : (2^192) - (2^191)" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c.from_string("3138550867693340381917894711603833208051177722232017256448");
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) - (2^253)
  cout << "Case : (2^254) - (2^253)" << endl;
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  c.from_string("14474011154664524427946373126085988481658748083205070504932198000989141204992");
  a = b - c;
  check_value(a, (uint64_t)(0x2000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^255) - (2^254)
  cout << "Case : (2^255) - (2^254)" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a = b - c;
  check_value(a, (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^63) - (2^64)
  cout << "Case : (2^63) - (2^64)" << endl;
  b.from_string("9223372036854775808");
  c.from_string("18446744073709551616");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  // Case : (2^127) - (2^128)
  cout << "Case : (2^127) - (2^128)" << endl;
  b.from_string("170141183460469231731687303715884105728");
  c.from_string("340282366920938463463374607431768211456");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^191) - (2^192)
  cout << "Case : (2^191) - (2^192)" << endl;
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  c.from_string("6277101735386680763835789423207666416102355444464034512896");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^253) - (2^254)
  cout << "Case : (2^253) - (2^254)" << endl;
  b.from_string("14474011154664524427946373126085988481658748083205070504932198000989141204992");
  c.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a = b - c;
  check_value(a, (uint64_t)(0xE000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) - (2^255)
  cout << "Case : (2^254) - (2^255)" << endl;
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a = b - c;
  check_value(a, (uint64_t)(0xC000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 - (2^64)
  cout << "Case : 1 - (2^64)" << endl;
  b = 1;
  c.from_string("18446744073709551616");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - (2^128)
  cout << "Case : 1 - (2^128)" << endl;
  b = 1;
  c.from_string("340282366920938463463374607431768211456");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - (2^192)
  cout << "Case : 1 - (2^192)" << endl;
  b = 1;
  c.from_string("6277101735386680763835789423207666416102355444464034512896");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // (2^64-1) - 1
  cout << "Case : (2^64-1) - 1" << endl;
  b.from_string("18446744073709551615");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // (2^64-1) - -1
  cout << "Case : (2^64-1) - -1" << endl;
  b.from_string("18446744073709551615");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // (2^128-1) - 1
  cout << "Case : (2^128-1) - 1" << endl;
  b.from_string("340282366920938463463374607431768211455");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // (2^128-1) - -1
  cout << "Case : (2^128-1) - -1" << endl;
  b.from_string("340282366920938463463374607431768211455");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // (2^192-1) - 1
  cout << "Case : (2^192-1) - 1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512895");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // (2^192-1) - -1
  cout << "Case : (2^192-1) - -1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512895");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // (2^64) - 1
  cout << "Case : (2^64) - 1" << endl;
  b.from_string("18446744073709551616");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^64) - -1
  cout << "Case : (2^64) - -1" << endl;
  b.from_string("18446744073709551616");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);

  // (2^128) - 1
  cout << "Case : (2^128) - 1" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^128) - -1
  cout << "Case : (2^128) - -1" << endl;
  b.from_string("340282366920938463463374607431768211456");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // (2^192) - 1
  cout << "Case : (2^192) - 1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^192) - -1
  cout << "Case : (2^192) - -1" << endl;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -(2^64-1) - 1
  cout << "Case : -(2^64-1) - 1" << endl;
  b.from_string("-18446744073709551615");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // -(2^64-1) - -1
  cout << "Case : -(2^64-1) - -1" << endl;
  b.from_string("-18446744073709551615");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(2), (int)__LINE__, _result);

  // -(2^128-1) - 1
  cout << "Case : -(2^128-1) - 1" << endl;
  b.from_string("-340282366920938463463374607431768211455");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // C-(2^128-1) - -1
  cout << "Case : -(2^128-1) - -1" << endl;
  b.from_string("-340282366920938463463374607431768211455");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -(2^192-1) - 1
  cout << "Case : -(2^192-1) - 1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512895");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -(2^192-1) - -1
  cout << "Case : -(2^192-1) - -1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512895");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -(2^64) - 1
  cout << "Case : -(2^64) - 1" << endl;
  b.from_string("-18446744073709551616");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -(2^64) - -1
  cout << "Case : -(2^64) - -1" << endl;
  b.from_string("-18446744073709551616");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  // -(2^128) - 1
  cout << "Case : -(2^128) - 1" << endl;
  b.from_string("-340282366920938463463374607431768211456");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  //  -(2^128) - -1
  cout << "Case : -(2^128) - -1" << endl;
  b.from_string("-340282366920938463463374607431768211456");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -(2^192) - 1
  cout << "Case : -(2^192) - 1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512896");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -(2^192) - -1
  cout << "Case : -(2^192) - -1" << endl;
  b.from_string("-6277101735386680763835789423207666416102355444464034512896");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // max - 1
  cout << "Case : max - 1" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // max - -1
  cout << "Case : max - -1" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // min - 1
  cout << "Case : min - 1" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c = 1;
  a = b - c;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // min - -1
  cout << "Case : min - -1" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c = -1;
  a = b - c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - max
  cout << "Case : 1 - max" << endl;
  b = 1;
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a = b - c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -1 - max
  cout << "Case : -1 - max" << endl;
  b = -1;
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a = b - c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 - min
  cout << "Case : 1 - min" << endl;
  b = 1;
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a = b - c;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -1 - min
  cout << "Case : -1 - min" << endl;
  b = -1;
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a = b - c;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // min - max
  cout << "Case : min - max" << endl;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  c.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // max - min
  cout << "Case : max - min" << endl;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 9000000000000000000 - 8000000000000000000
  cout << "Case : 9000000000000000000 - 8000000000000000000" << endl;
  b = (uint64_t)(9000000000000000000);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7CE66C50E2840000), (int)__LINE__, _result);
  c = (uint64_t)8000000000000000000;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x6F05B59D3B200000), (int)__LINE__, _result);
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xDE0B6B3A7640000), (int)__LINE__, _result);

  // -1 - 1000000000000000
  cout << "Case : -1 - 1000000000000000" << endl;
  b = -1;
  c = (uint64_t)1000000000000000;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B397FFF), (int)__LINE__, _result);

  // -1 - -1000000000000000
  cout << "Case : -1 - -1000000000000000" << endl;
  b = -1;
  c = (int64_t)(-1000000000000000);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B398000), (int)__LINE__, _result);
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00038D7EA4C67FFF), (int)__LINE__, _result);

  // 1000 - 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 - (1000 - 0xFFFFFFFFFFFFFFFF << 64)
  cout << "Case : 1000 - 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 - (1000 - 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  b = 1000;
  c = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  c = c << 64;
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(1000), (int)__LINE__, _result);
  b.sub(c, a);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);

  // 9000000000000000000 - 18446744073709551615
  cout << "Case : 9000000000000000000 - 18446744073709551615" << endl;
  b = (uint64_t)(9000000000000000000);
  c = (uint64_t)(18446744073709551615);
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x7CE66C50E2840001), (int)__LINE__, _result);

  // (2^193) - (2^190+1) - (2^190+1) - (2^190+1) - (2^190+1)
  cout << "Case : (2^193) - (2^190+1) - (2^190+1) - (2^190+1) - (2^190+1)" << endl;
  b.from_string("12554203470773361527671578846415332832204710888928069025792");
  check_value(b, (uint64_t)(2), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c.from_string("1569275433846670190958947355801916604025588861116008628225");
  check_value(c, (uint64_t)(0), (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a = b - c - c - c - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFC), (int)__LINE__, _result);

  cout << "Case : 2^192 -= (2^191+1)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  a = a - b;
  check_value(b, (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(a, (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^191+1) -= 2^192" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 2^128 -= (2^127+1)" << endl;
  a.from_string("340282366920938463463374607431768211456");
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b.from_string("170141183460469231731687303715884105729");
  a = a - b;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(1), (int)__LINE__, _result);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^127+1) -= 2^128" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b.from_string("170141183460469231731687303715884105729");
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 2^64 -= (2^63+1)" << endl;
  a.from_string("18446744073709551616");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  b.from_string("9223372036854775809");
  a = a - b;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^63+1) -= 2^64" << endl;
  a.from_string("18446744073709551616");
  b.from_string("9223372036854775809");
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);

  cout << "Case : -1 -= -1; -1 -= (-1 -= -1)" << endl;
  a = -1;
  b = -1;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 -= 0; 0 -= (-1 -= 0)" << endl;
  a = -1;
  b = 0;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 -= 100; 100 -= (-1 -= 100)" << endl;
  a = -1;
  b = 100;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFF9B, (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(201), (int)__LINE__, _result);

  cout << "Case : -1 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (-1 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = -1;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -10000 -= 1; 1 -= (-10000 -= 1)" << endl;
  a = -10000;
  b = 1;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD8EF), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(10002), (int)__LINE__, _result);

  cout << "Case : -10000 -= -1; -1 -= (-10000 -= -1)" << endl;
  a = -10000;
  b = -1;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD8F1), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(9998), (int)__LINE__, _result);

  cout << "Case : -10000 -= 0; 0 -= (-10000 -= 0)" << endl;
  a = -10000;
  b = 0;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD8F0), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(10000), (int)__LINE__, _result);

  cout << "Case : -10000 -= 100; 100 -= (-10000 -= 100)" << endl;
  a = -10000;
  b = 100;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD88C), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(10200), (int)__LINE__, _result);

  cout << "Case : -10000 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (-10000 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = -10000;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFD8F0), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0x0000000000002710), (int)__LINE__, _result);

  cout << "Case : 0 -= 1; 1 -= (0 -= 1)" << endl;
  a = 0;
  b = 1;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 0 -= -1; -1 -= (0 -= -1)" << endl;
  a = 0;
  b = -1;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0 -= 0; 0 -= (0 -= 0)" << endl;
  a = 0;
  b = 0;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0 -= 100; 100 -= (0 -= 100)" << endl;
  a = 0;
  b = 100;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFF9C), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(200), (int)__LINE__, _result);

  cout << "Case : 0 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (0 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = 0;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 -= 1; 1 -= (1 -= 1)" << endl;
  a = 1;
  b = 1;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1 -= -1; -1 -= (1 -= -1)" << endl;
  a = 1;
  b = -1;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : 1 -= 0; 0 -= (1 -= 0)" << endl;
  a = 1;
  b = 0;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1 -= 100; 100 -= (1 -= 100)" << endl;
  a = 1;
  b = 100;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFF9D), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(199), (int)__LINE__, _result);

  cout << "Case : 1 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (1 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = 1;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1000 -= 1; 1 -= (1000 -= 1)" << endl;
  a = 1000;
  b = 1;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(999), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC1A), (int)__LINE__, _result);

  cout << "Case : 1000 -= -1; -1 -= (1000 -= -1)" << endl;
  a = 1000;
  b = -1;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1001), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC16), (int)__LINE__, _result);

  cout << "Case : 1000 -= 0; 0 -= (1000 -= 0)" << endl;
  a = 1000;
  b = 0;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1000), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);

  cout << "Case : 1000 -= 100; 100 -= (1000 -= 100)" << endl;
  a = 1000;
  b = 100;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(900), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFCE0), (int)__LINE__, _result);

  cout << "Case : 1000 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (1000 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = 1000;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a = a - b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(1000), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 1; 1 -= (0xFFFFFFFFFFFFFFFF << 64 -= 1)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  b = 1;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= -1; -1 -= (0xFFFFFFFFFFFFFFFF << 64 -= -1)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  b = -1;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 0; 0 -= (0xFFFFFFFFFFFFFFFF << 64 -= 0)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  //a = a * 1000000;
  b = 0;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 100; 100 -= (0xFFFFFFFFFFFFFFFF << 64 -= 100)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  //a = a * 1000000;
  b = 100;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFF9C), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(0x00000000000000C8), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 0xFFFFFFFFFFFFFFFF << 63; 0xFFFFFFFFFFFFFFFF << 63 -= (0xFFFFFFFFFFFFFFFF << 64 -= 0xFFFFFFFFFFFFFFFF << 63)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 63;
  a = a - b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);
  b = b - a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 2......2 - 1......1
  cout << "Case : 2......2 - 1......1" << endl;
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a = b - c;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 3......3 - 1......1
  cout << "Case : 3......3 - 1......1" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a = b - c;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 3......3 - 2......2
  cout << "Case : 3......3 - 2......2" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b - c;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 4......4 - 2......2
  cout << "Case : 4......4 - 2......2" << endl;
  b.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  c.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b - c;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 2......2 - -1......1
  cout << "Case : 2......2 - -1......1" << endl;
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a = b - c;
  check_value(a, (uint64_t)(0x49B1FF823AA8F306), (uint64_t)(0x18A504E7B15134EA), (uint64_t)(0x38DD7E7A25463555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  // Case : 3......3 - -1......1
  cout << "Case : 3......3 - -1......1" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a = b - c;
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // Case : 3......3 - -2......2
  cout << "Case : 3......3 - -2......2" << endl;
  b.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b - c;
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // Case : 4......4 - -2......2
  cout << "Case : 4......4 - -2......2" << endl;
  b.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b - c;
  check_value(a, (uint64_t)(0x9363FF047551E60C), (uint64_t)(0x314A09CF62A269D4), (uint64_t)(0x71BAFCF44A8C6AAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  // Case : -1......1 - -2......2
  cout << "Case : -1......1 - -2......2" << endl;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a = b - c;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -1......1 - -3......3
  cout << "Case : -1......1 - -3......3" << endl;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a = b - c;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : -2......2 - -3......3
  cout << "Case : -2......2 - -3......3" << endl;
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a = b - c;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -2......2 - -4......4
  cout << "Case : -2......2 - -4......4" << endl;
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  c.from_string("-44444444444444444444444444444444444444444444444444444444444444444444444444444");
  a = b - c;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 876543218765432187654321876543218765432187654321876543218765432187654321 - -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 - -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  b.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  c.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  a = b - c;
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 123456781234567812345678123456781234567812345678123456781234567812345678 - -876543218765432187654321876543218765432187654321876543218765432187654321
  cout << "Case : 123456781234567812345678123456781234567812345678123456781234567812345678 - -876543218765432187654321876543218765432187654321876543218765432187654321" << endl;
  b.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  c.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  a = b - c;
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 9838263505978427528 - -8608480567731124088
  cout << "Case : 9838263505978427528 - -8608480567731124088" << endl;
  b.from_string("9838263505978427528");
  c.from_string("-8608480567731124088");
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 181483929024500513847133123963609712776 - -158798437896437949616241483468158498680
  cout << "Case : 181483929024500513847133123963609712776 - -158798437896437949616241483468158498680" << endl;
  b.from_string("181483929024500513847133123963609712776");
  c.from_string("-158798437896437949616241483468158498680");
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 3347787592206229740712421025710755421921256237047485073544 - -2929314143180451023123368397496910994181099207416549439352
  cout << "Case : 3347787592206229740712421025710755421921256237047485073544 - -2929314143180451023123368397496910994181099207416549439352" << endl;
  b.from_string("3347787592206229740712421025710755421921256237047485073544");
  c.from_string("-2929314143180451023123368397496910994181099207416549439352");
  a = b - c;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 - -54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 - -54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  b.from_string("61755780926568637559237858671300217521743991821674967487710711470887002474632");
  c.from_string("-54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -9838263505978427528 - 8608480567731124088
  cout << "Case : -9838263505978427528 - 8608480567731124088" << endl;
  b.from_string("-9838263505978427528");
  c.from_string("8608480567731124088");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -181483929024500513847133123963609712776 - 158798437896437949616241483468158498680
  cout << "Case : -181483929024500513847133123963609712776 - 158798437896437949616241483468158498680" << endl;
  b.from_string("-181483929024500513847133123963609712776");
  c.from_string("158798437896437949616241483468158498680");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -3347787592206229740712421025710755421921256237047485073544 - 2929314143180451023123368397496910994181099207416549439352
  cout << "Case : -3347787592206229740712421025710755421921256237047485073544 - 2929314143180451023123368397496910994181099207416549439352" << endl;
  b.from_string("-3347787592206229740712421025710755421921256237047485073544");
  c.from_string("2929314143180451023123368397496910994181099207416549439352");
  a = b - c;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 - 54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 - 54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  b.from_string("-61755780926568637559237858671300217521743991821674967487710711470887002474632");
  c.from_string("54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a = b - c;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nsubtraction_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void subtraction_assignment_operator_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[subtract_assign_operator(-=)_test]]==================================" << endl << endl;

  // 1 -= 1
  cout << "Case : 1 -= 1" << endl;
  a = 1;
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 -= 0
  cout << "Case : 1 -= 0" << endl;
  a = 1;
  b = 0;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 -= -1
  cout << "Case : 1 -= -1" << endl;
  a = 1;
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -1 -= 1
  cout << "Case : -1 -= 1" << endl;
  a = -1;
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -1 -= 0
  cout << "Case : -1 -= 0" << endl;
  a = -1;
  b = 0;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -1 -= -1
  cout << "Case : -1 -= -1" << endl;
  a = -1;
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 -= 1
  cout << "Case : 0 -= 1" << endl;
  a = 0;
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 0 -= 0
  cout << "Case : 0 -= 0" << endl;
  a = 0;
  b = 0;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 -= -1
  cout << "Case : 0 -= -1" << endl;
  a = 0;
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 -= 2
  cout << "Case : 1 -= 2" << endl;
  a = 1;
  b = 2;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 1 -= -2
  cout << "Case : 1 -= -2" << endl;
  a = 1;
  b = -2;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  // -1 -= 2
  cout << "Case : -1 -= 2" << endl;
  a = -1;
  b = 2;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  // -1 -= -2
  cout << "Case : -1 -= -2" << endl;
  a = -1;
  b = -2;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // Case : (2^64) -= (2^63)
  cout << "Case : (2^64) -= (2^63)" << endl;
  a.from_string("18446744073709551616");
  b.from_string("9223372036854775808");
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  // Case : (2^128) -= (2^127)
  cout << "Case : (2^128) -= (2^127)" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b.from_string("170141183460469231731687303715884105728");
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^192) -= (2^191)
  cout << "Case : (2^192) -= (2^191)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) -= (2^253)
  cout << "Case : (2^254) -= (2^253)" << endl;
  a.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b.from_string("14474011154664524427946373126085988481658748083205070504932198000989141204992");
  a -= b;
  check_value(a, (uint64_t)(0x2000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^255) -= (2^254)
  cout << "Case : (2^255) -= (2^254)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a -= b;
  check_value(a, (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^63) -= (2^64)
  cout << "Case : (2^63) -= (2^64)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("18446744073709551616");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  // Case : (2^127) -= (2^128)
  cout << "Case : (2^127) -= (2^128)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("340282366920938463463374607431768211456");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^191) -= (2^192)
  cout << "Case : (2^191) -= (2^192)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^253) -= (2^254)
  cout << "Case : (2^253) -= (2^254)" << endl;
  a.from_string("14474011154664524427946373126085988481658748083205070504932198000989141204992");
  b.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a -= b;
  check_value(a, (uint64_t)(0xE000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : (2^254) -= (2^255)
  cout << "Case : (2^254) -= (2^255)" << endl;
  a.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a -= b;
  check_value(a, (uint64_t)(0xC000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 -= (2^64)
  cout << "Case : 1 -= (2^64)" << endl;
  a = 1;
  b.from_string("18446744073709551616");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  // 1 -= (2^128)
  cout << "Case : 1 -= (2^128)" << endl;
  a = 1;
  b.from_string("340282366920938463463374607431768211456");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 -= (2^192)
  cout << "Case : 1 -= (2^192)" << endl;
  a = 1;
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // min -= max
  cout << "Case : min -= max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // max -= min
  cout << "Case : max -= min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^64-1) -= 1
  cout << "Case : (2^64-1) -= 1" << endl;
  a.from_string("18446744073709551615");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // (2^64-1) -= -1
  cout << "Case : (2^64-1) -= -1" << endl;
  a.from_string("18446744073709551615");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // (2^128-1) -= 1
  cout << "Case : (2^128-1) -= 1" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // (2^128-1) -= -1
  cout << "Case : (2^128-1) -= -1" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // (2^192-1) -= 1
  cout << "Case : (2^192-1) -= 1" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512895");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // (2^192-1) -= -1
  cout << "Case : (2^192-1) -= -1" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512895");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // (2^64) -= 1
  cout << "Case : (2^64) -= 1" << endl;
  a.from_string("18446744073709551616");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^64) -= -1
  cout << "Case : (2^64) -= -1" << endl;
  a.from_string("18446744073709551616");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);

  // (2^128) -= 1
  cout << "Case : (2^128) -= 1" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^128) -= -1
  cout << "Case : (2^128) -= -1" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // (2^192) -= 1
  cout << "Case : (2^192) -= 1" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // (2^192) -= -1
  cout << "Case : (2^192) -= -1" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -(2^64-1) -= 1
  cout << "Case : -(2^64-1) -= 1" << endl;
  a.from_string("-18446744073709551615");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // -(2^64-1) -= -1
  cout << "Case : -(2^64-1) -= -1" << endl;
  a.from_string("-18446744073709551615");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(2), (int)__LINE__, _result);

  // -(2^128-1) -= 1
  cout << "Case : -(2^128-1) -= 1" << endl;
  a.from_string("-340282366920938463463374607431768211455");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -(2^128-1) -= -1
  cout << "Case : -(2^128-1) -= -1" << endl;
  a.from_string("-340282366920938463463374607431768211455");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -(2^192-1) -= 1
  cout << "Case : -(2^192-1) -= 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512895");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -(2^192-1) -= -1
  cout << "Case : -(2^192-1) -= -1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512895");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -(2^64) -= 1
  cout << "Case : -(2^64) -= 1" << endl;
  a.from_string("-18446744073709551616");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -(2^64) -= -1
  cout << "Case : -(2^64) -= -1" << endl;
  a.from_string("-18446744073709551616");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  // -(2^128) -= 1
  cout << "Case : -(2^128) -= 1" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  //  -(2^128) -= -1
  cout << "Case : -(2^128) -= -1" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -(2^192) -= 1
  cout << "Case : -(2^192) -= 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -(2^192) -= -1
  cout << "Case : -(2^192) -= -1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // max -= 1
  cout << "Case : max -= 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // max -= -1
  cout << "Case : max -= -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // min -= 1
  cout << "Case : min -= 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // min -= -1
  cout << "Case : min -= -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 - max
  cout << "Case : 1 - max" << endl;
  a = 1;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a -= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -1 - max
  cout << "Case : -1 - max" << endl;
  a = -1;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a -= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 - min
  cout << "Case : 1 - min" << endl;
  a = 1;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a -= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -1 - min
  cout << "Case : -1 - min" << endl;
  a = -1;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a -= b;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 9000000000000000000 -= 8000000000000000000
  cout << "Case : 9000000000000000000 -= 8000000000000000000" << endl;
  a = (uint64_t)(9000000000000000000);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7CE66C50E2840000), (int)__LINE__, _result);
  b = (uint64_t)8000000000000000000;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x6F05B59D3B200000), (int)__LINE__, _result);
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xDE0B6B3A7640000), (int)__LINE__, _result);

  // -1 -= 1000000000000000
  cout << "Case : -1 -= 1000000000000000" << endl;
  a = -1;
  b = (uint64_t)1000000000000000;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B397FFF), (int)__LINE__, _result);

  // -1 -= -1000000000000000
  cout << "Case : -1 -= -1000000000000000" << endl;
  a = -1;
  b = (int64_t)(-1000000000000000);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFC72815B398000), (int)__LINE__, _result);
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00038D7EA4C67FFF), (int)__LINE__, _result);

  // 1000 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (1000 -= 0xFFFFFFFFFFFFFFFF << 64)
  cout << "Case : 1000 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (1000 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = 1000;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(1000), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);

  // 9000000000000000000 -= 18446744073709551615
  cout << "Case : 9000000000000000000 -= 18446744073709551615" << endl;
  a = (uint64_t)(9000000000000000000);
  b = (uint64_t)(18446744073709551615);
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x7CE66C50E2840001), (int)__LINE__, _result);

  cout << "Case : 2^192 -= (2^191+1)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  a -= b;
  check_value(b, (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(a, (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^191+1) -= 2^192" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 2^128 -= (2^127+1)" << endl;
  a.from_string("340282366920938463463374607431768211456");
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b.from_string("170141183460469231731687303715884105729");
  a -= b;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(1), (int)__LINE__, _result);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^127+1) -= 2^128" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b.from_string("170141183460469231731687303715884105729");
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 2^64 -= (2^63+1)" << endl;
  a.from_string("18446744073709551616");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  b.from_string("9223372036854775809");
  a -= b;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^63+1) -= 2^64" << endl;
  a.from_string("18446744073709551616");
  b.from_string("9223372036854775809");
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000001), (int)__LINE__, _result);

  cout << "Case : -1 -= -1; -1 -= (-1 -= -1)" << endl;
  a = -1;
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 -= 0; 0 -= (-1 -= 0)" << endl;
  a = -1;
  b = 0;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 -= 100; 100 -= (-1 -= 100)" << endl;
  a = -1;
  b = 100;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFF9B, (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(201), (int)__LINE__, _result);

  cout << "Case : -1 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (-1 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = -1;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -10000 -= 1; 1 -= (-10000 -= 1)" << endl;
  a = -10000;
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD8EF), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(10002), (int)__LINE__, _result);

  cout << "Case : -10000 -= -1; -1 -= (-10000 -= -1)" << endl;
  a = -10000;
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD8F1), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(9998), (int)__LINE__, _result);

  cout << "Case : -10000 -= 0; 0 -= (-10000 -= 0)" << endl;
  a = -10000;
  b = 0;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD8F0), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(10000), (int)__LINE__, _result);

  cout << "Case : -10000 -= 100; 100 -= (-10000 -= 100)" << endl;
  a = -10000;
  b = 100;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFD88C), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(10200), (int)__LINE__, _result);

  cout << "Case : -10000 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (-10000 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = -10000;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFD8F0), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0x0000000000002710), (int)__LINE__, _result);

  cout << "Case : 0 -= 1; 1 -= (0 -= 1)" << endl;
  a = 0;
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 0 -= -1; -1 -= (0 -= -1)" << endl;
  a = 0;
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0 -= 0; 0 -= (0 -= 0)" << endl;
  a = 0;
  b = 0;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0 -= 100; 100 -= (0 -= 100)" << endl;
  a = 0;
  b = 100;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFF9C), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(200), (int)__LINE__, _result);

  cout << "Case : 0 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (0 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = 0;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 -= 1; 1 -= (1 -= 1)" << endl;
  a = 1;
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1 -= -1; -1 -= (1 -= -1)" << endl;
  a = 1;
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : 1 -= 0; 0 -= (1 -= 0)" << endl;
  a = 1;
  b = 0;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1 -= 100; 100 -= (1 -= 100)" << endl;
  a = 1;
  b = 100;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFF9D), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(199), (int)__LINE__, _result);

  cout << "Case : 1 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (1 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = 1;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1000 -= 1; 1 -= (1000 -= 1)" << endl;
  a = 1000;
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(999), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC1A), (int)__LINE__, _result);

  cout << "Case : 1000 -= -1; -1 -= (1000 -= -1)" << endl;
  a = 1000;
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1001), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC16), (int)__LINE__, _result);

  cout << "Case : 1000 -= 0; 0 -= (1000 -= 0)" << endl;
  a = 1000;
  b = 0;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1000), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);

  cout << "Case : 1000 -= 100; 100 -= (1000 -= 100)" << endl;
  a = 1000;
  b = 100;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(900), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFCE0), (int)__LINE__, _result);

  cout << "Case : 1000 -= 0xFFFFFFFFFFFFFFFF << 64; 0xFFFFFFFFFFFFFFFF << 64 -= (1000 -= 0xFFFFFFFFFFFFFFFF << 64)" << endl;
  a = 1000;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 64;
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(1000), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (uint64_t)(0xFFFFFFFFFFFFFC18), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 1; 1 -= (0xFFFFFFFFFFFFFFFF << 64 -= 1)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  b = 1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= -1; -1 -= (0xFFFFFFFFFFFFFFFF << 64 -= -1)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  b = -1;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 0; 0 -= (0xFFFFFFFFFFFFFFFF << 64 -= 0)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  //a = a * 1000000;
  b = 0;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 100; 100 -= (0xFFFFFFFFFFFFFFFF << 64 -= 100)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  //a = a * 1000000;
  b = 100;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFF9C), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (uint64_t)(0x00000000000000C8), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF << 64 -= 0xFFFFFFFFFFFFFFFF << 63; 0xFFFFFFFFFFFFFFFF << 63 -= (0xFFFFFFFFFFFFFFFF << 64 -= 0xFFFFFFFFFFFFFFFF << 63)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a << 64;
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = b << 63;
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);
  b -= a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 2......2 - 1......1
  cout << "Case : 2......2 - 1......1" << endl;
  a.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a -= b;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 3......3 - 1......1
  cout << "Case : 3......3 - 1......1" << endl;
  a.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a -= b;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 3......3 - 2......2
  cout << "Case : 3......3 - 2......2" << endl;
  a.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a -= b;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : 4......4 - 2......2
  cout << "Case : 4......4 - 2......2" << endl;
  a.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  b.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a -= b;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 2......2 - -1......1
  cout << "Case : 2......2 - -1......1" << endl;
  a.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a -= b;
  check_value(a, (uint64_t)(0x49B1FF823AA8F306), (uint64_t)(0x18A504E7B15134EA), (uint64_t)(0x38DD7E7A25463555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  // Case : 3......3 - -1......1
  cout << "Case : 3......3 - -1......1" << endl;
  a.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a -= b;
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // Case : 3......3 - -2......2
  cout << "Case : 3......3 - -2......2" << endl;
  a.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a -= b;
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // Case : 4......4 - -2......2
  cout << "Case : 4......4 - -2......2" << endl;
  a.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a -= b;
  check_value(a, (uint64_t)(0x9363FF047551E60C), (uint64_t)(0x314A09CF62A269D4), (uint64_t)(0x71BAFCF44A8C6AAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  // Case : -1......1 - -2......2
  cout << "Case : -1......1 - -2......2" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  a -= b;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -1......1 - -3......3
  cout << "Case : -1......1 - -3......3" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a -= b;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : -2......2 - -3......3
  cout << "Case : -2......2 - -3......3" << endl;
  a.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  b.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  a -= b;
  check_value(a, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // Case : -2......2 - -4......4
  cout << "Case : -2......2 - -4......4" << endl;
  a.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  b.from_string("-44444444444444444444444444444444444444444444444444444444444444444444444444444");
  a -= b;
  check_value(a, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // Case : 876543218765432187654321876543218765432187654321876543218765432187654321 - -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 - -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  a.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  b.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  a -= b;
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 123456781234567812345678123456781234567812345678123456781234567812345678 - -876543218765432187654321876543218765432187654321876543218765432187654321
  cout << "Case : 123456781234567812345678123456781234567812345678123456781234567812345678 - -876543218765432187654321876543218765432187654321876543218765432187654321" << endl;
  a.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  b.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  a -= b;
  check_value(a, (uint64_t)(0x90E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x31CDCF66F634E0FF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // Case : 9838263505978427528 - -8608480567731124088
  cout << "Case : 9838263505978427528 - -8608480567731124088" << endl;
  a.from_string("9838263505978427528");
  b.from_string("-8608480567731124088");
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 181483929024500513847133123963609712776 - -158798437896437949616241483468158498680
  cout << "Case : 181483929024500513847133123963609712776 - -158798437896437949616241483468158498680" << endl;
  a.from_string("181483929024500513847133123963609712776");
  b.from_string("-158798437896437949616241483468158498680");
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 3347787592206229740712421025710755421921256237047485073544 - -2929314143180451023123368397496910994181099207416549439352
  cout << "Case : 3347787592206229740712421025710755421921256237047485073544 - -2929314143180451023123368397496910994181099207416549439352" << endl;
  a.from_string("3347787592206229740712421025710755421921256237047485073544");
  b.from_string("-2929314143180451023123368397496910994181099207416549439352");
  a -= b;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 - -54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : 61755780926568637559237858671300217521743991821674967487710711470887002474632 - -54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  a.from_string("61755780926568637559237858671300217521743991821674967487710711470887002474632");
  b.from_string("-54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -9838263505978427528 - 8608480567731124088
  cout << "Case : -9838263505978427528 - 8608480567731124088" << endl;
  a.from_string("-9838263505978427528");
  b.from_string("8608480567731124088");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -181483929024500513847133123963609712776 - 158798437896437949616241483468158498680
  cout << "Case : -181483929024500513847133123963609712776 - 158798437896437949616241483468158498680" << endl;
  a.from_string("-181483929024500513847133123963609712776");
  b.from_string("158798437896437949616241483468158498680");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -3347787592206229740712421025710755421921256237047485073544 - 2929314143180451023123368397496910994181099207416549439352
  cout << "Case : -3347787592206229740712421025710755421921256237047485073544 - 2929314143180451023123368397496910994181099207416549439352" << endl;
  a.from_string("-3347787592206229740712421025710755421921256237047485073544");
  b.from_string("2929314143180451023123368397496910994181099207416549439352");
  a -= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 - 54036308310747557864333126337387690331525992843965596551746872537026127165304
  cout << "Case : -61755780926568637559237858671300217521743991821674967487710711470887002474632 - 54036308310747557864333126337387690331525992843965596551746872537026127165304" << endl;
  a.from_string("-61755780926568637559237858671300217521743991821674967487710711470887002474632");
  b.from_string("54036308310747557864333126337387690331525992843965596551746872537026127165304");
  a -= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nsubtract_assign_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}



void multiplication_test()
{
  BigInt a, b, c;
  bool _result = true;

  cout << "\n==[[multiplication_mul()_test]]==================================" << endl << endl;

  // 0 * 0
  cout << "Case : 0 * 0 = 0" << endl;
  a = 0;
  b = 0;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 * 1
  cout << "Case : 0 * 1 = 0" << endl;
  a = 0;
  b = 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 * 0
  cout << "Case : 1 * 0 = 0" << endl;
  a = 1;
  b = 0;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 * -1
  cout << "Case : 0 * -1 = 0" << endl;
  a = 0;
  b = -1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -1 * 0
  cout << "Case : -1 * 0 = 0" << endl;
  a = -1;
  b = 0;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -1 * -1
  cout << "Case : -1 * -1 = 1" << endl;
  a = -1;
  b = -1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 * 1
  cout << "Case : 1 * 1 = 1" << endl;
  a = 1;
  b = 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 * -1
  cout << "Case : 1 * -1 = -1" << endl;
  a = 1;
  b = -1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -1 * 1
  cout << "Case : -1 * 1 = -1" << endl;
  a = -1;
  b = 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max * 1
  cout << "Case : max * 1 = max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max * -1
  cout << "Case : -1 * max = min+1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 0 * max
  cout << "Case : 0 * max = 0" << endl;
  a = 0;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max * 1
  cout << "Case : min * 1 = min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max * -1
  cout << "Case : min * -1 = min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 * -max
  cout << "Case : 0 * min = 0" << endl;
  a = 0;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max * max
  cout << "Case : min * max = min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // max * -max
  cout << "Case : max * min = min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 2 * -1
  cout << "Case : 2 * -1 = -2" << endl;
  a = 2;
  b = -1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 * 1
  cout << "Case : -2 * 1 = -2" << endl;
  a = -2;
  b = 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 * -1
  cout << "Case : -2 * -1 = 2" << endl;
  a = -2;
  b = -1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // 2 * 1
  cout << "Case : 2 * 1 = 2" << endl;
  a = 2;
  b = 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // 2^192 * 2^192
  cout << "Case : 2^192 * 2^192 = 0 (overflow)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 10^40 * 10^40
  cout << "Case : 10000000000000000000000000000000000000000 * 10000000000000000000000000000000000000000" << endl;
  a.from_string("10000000000000000000000000000000000000000");
  b.from_string("10000000000000000000000000000000000000000");
  check_value(a, (uint64_t)(0), (uint64_t)(0x1D), (uint64_t)(0x6329F1C35CA4BFAB), (uint64_t)(0xB9F5610000000000), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0x1D), (uint64_t)(0x6329F1C35CA4BFAB), (uint64_t)(0xB9F5610000000000), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x9DEA3E1F6BDFEF70), (uint64_t)(0xCDD17B25EFA418CA), (uint64_t)(0x63A22764CEC10000), (uint64_t)(0x0000000000000000), (int)__LINE__, _result);

  // 2^127 * 2^127
  cout << "Case : 2^127 * 2^127 = 2^254" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 3^25 * 5^25 * 1000000000000000000000000000001
  cout << "Case : 3^25 * 5^25 * 1000000000000000000000000000001 = 252511682940423488616943359375252511682940423488616943359375" << endl;
  a.from_string("847288609443000000000000000000847288609443");
  b.from_string("298023223876953125");
  check_value(a, (uint64_t)(0), (uint64_t)(0x9B9), (uint64_t)(0xF51A724A8458BDC5), (uint64_t)(0x45AD6B6C06562AA3), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x422CA8B0A00A425), (int)__LINE__, _result);
  c.mul(a,b);
  // 252511682940423488616943359375252511682940423488616943359375
  check_value(c, (uint64_t)(0x28), (uint64_t)(0x3A38FB0C95516300), (uint64_t)(0x726C62C54F7D551C), (uint64_t)(0x0734DCD77BC4958F), (int)__LINE__, _result);

  // 1010... * 7
  cout << "Case : 1010....01 * 7 = 707...07" << endl;
  a.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  b = 7;
  // 00392B70E125BF92  A2FBD87383A3EE51  6378234AD7C607EB  50295FAD40A57EB5
  check_value(a, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  c.mul(a,b);
  // 0190301628083D02  74E2EB28997B8439  B848F70BE66A376F  31219DBCC48676F3
  check_value(c, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)(0x31219DBCC48676F3), (int)__LINE__, _result);

  // 1010... * 13
  cout << "Case : 1010....01 * 13 = 1313...13" << endl;
  a = 13;
  b.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  c.mul(a,b);
  // 02E734BB6EEABA72  46C9FDDDAF531A22  0D19CACCF50E66F3  1219DBCC48676F31
  check_value(c, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)(0x1219DBCC48676F31), (int)__LINE__, _result);

  // 1010... * 17
  cout << "Case : 1010....01 * 17 = 1717...17" << endl;
  a.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  b = 17;
  check_value(a, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(17), (int)__LINE__, _result);
  c.mul(a,b);
  // 03CBE27EF381B8BC  D2B95FABBDE2D367  9AFA57F8542686A0  52BF5A814AFD6A05
  check_value(c, (uint64_t)(0x03CBE27EF381B8BC), (uint64_t)(0xD2B95FABBDE2D367), (uint64_t)(0x9AFA57F8542686A0), (uint64_t)(0x52BF5A814AFD6A05), (int)__LINE__, _result);

  // 1010... * 19
  cout << "Case : 1010....01 * 19 = 1919...19" << endl;
  a = 19;
  b.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  c.mul(a,b);
  // 043E3960B5CD37E2  18B11092C52AB00A  61EA9E8E03B29676  F31219DBCC48676F
  check_value(c, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC48676F), (int)__LINE__, _result);

  // 10000000000000000000 * 10000000000000000000 * 10000000000000000000 * 10000000000000000000
  cout << "Case : 10000000000000000000 * 10000000000000000000" << endl;
  cout << "Case : 10000000000000000000 * 10000000000000000000 * 10000000000000000000" << endl;
  cout << "Case : 10000000000000000000 * 10000000000000000000 * 10000000000000000000 * 10000000000000000000" << endl;
  a = (uint64_t)(10000000000000000000);
  b = (uint64_t)(10000000000000000000);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8AC7230489E80000), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x4B3B4CA85A86C47A), (uint64_t)(0x098A224000000000), (int)__LINE__, _result);
  a.mul(c,b);
  check_value(a, (uint64_t)(0), (uint64_t)(0x28C87CB5C89A2571), (uint64_t)(0xEBFDCB54864ADA83), (uint64_t)(0x4A00000000000000), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x161BCCA7119915B5), (uint64_t)(0x0764B4ABE8652979), (uint64_t)(0x7775A5F171951000), (uint64_t)(0x0000000000000000), (int)__LINE__, _result);

  // 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777
  cout << "Case : 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777" << endl;
  a = 1;
  b.from_string("77777777777777");
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  a.mul(c,b);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x138BEE9E), (uint64_t)(0x259789EB8D7269E1), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0x566), (uint64_t)(0xB288EABF5CAD1D48), (uint64_t)(0xA2DA4991554E1851), (int)__LINE__, _result);
  a.mul(c,b);
  check_value(a, (uint64_t)(0), (uint64_t)(0x17E11E877BBC0A0), (uint64_t)(0xEDCFF74BCB80F371), (uint64_t)(0x64F670DA522E57C1), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0x69930BE9EC), (uint64_t)(0x2ED0FBECB1799892), (uint64_t)(0xAD356BD9AECB80FE), (uint64_t)(0x9F35F03F72AE9831), (int)__LINE__, _result);

  // 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333
  cout << "Case : 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333" << endl;
  a = 1;
  b.from_string("3333333333333333");
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  a.mul(c,b);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8C3DEFB1ED), (uint64_t)(0xB97D191158F18E39), (int)__LINE__, _result);
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0x67CCC55), (uint64_t)(0x8544DF1368D21BBE), (uint64_t)(0x8D94533287AD25ED), (int)__LINE__, _result);
  a.mul(c,b);
  check_value(a, (uint64_t)(0x4CD3), (uint64_t)(0xCD26B73BE0C3F7C0), (uint64_t)(0x4FAB319FFE4C8789), (uint64_t)(0x626CFB46465548B1), (int)__LINE__, _result);

  // 1......1 * 4
  cout << "Case : 1......1 * 4" << endl;
  a.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = 4;
  c.mul(a,b);
  check_value(c, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // 1......1 * 5
  cout << "Case : 1......1 * 5" << endl;
  a.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = 5;
  c.mul(a,b);
  check_value(c, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // -1......1 * -4
  cout << "Case : -1......1 * -4" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = -4;
  c.mul(a,b);
  check_value(c, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // -1......1 * -5
  cout << "Case : -1......1 * -5" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = -5;
  c.mul(a,b);
  check_value(c, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // 4 * 1......1
  cout << "Case : 4 * 1......1" << endl;
  a = 4;
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // 5 * 1......1
  cout << "Case : 5 * 1......1" << endl;
  a = 5;
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // -4 * -1......1
  cout << "Case : -4 * -1......1" << endl;
  a = -4;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // -5 * -1......1
  cout << "Case : -5 * -1......1" << endl;
  a = -5;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // 123456789123456789123456789123456789 * 987654321987654321987654321987654321
  cout << "Case : 123456789123456789123456789123456789 * 987654321987654321987654321987654321" << endl;
  a.from_string("123456789123456789123456789123456789");
  b.from_string("987654321987654321987654321987654321");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x11AABB8FBC21), (uint64_t)(0x9EF2126052906DAF), (uint64_t)(0x968614A541EDB2A8), (uint64_t)(0x55AA9D7BFEAD3785), (int)__LINE__, _result);

  // -123456789123456789123456789123456789 * -987654321987654321987654321987654321
  cout << "Case : -123456789123456789123456789123456789 * -987654321987654321987654321987654321" << endl;
  a.from_string("-123456789123456789123456789123456789");
  b.from_string("-987654321987654321987654321987654321");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x11AABB8FBC21), (uint64_t)(0x9EF2126052906DAF), (uint64_t)(0x968614A541EDB2A8), (uint64_t)(0x55AA9D7BFEAD3785), (int)__LINE__, _result);

  // -123456789123456789123456789123456789 * 987654321987654321987654321987654321
  cout << "Case : -123456789123456789123456789123456789 * 987654321987654321987654321987654321" << endl;
  a.from_string("-123456789123456789123456789123456789");
  b.from_string("987654321987654321987654321987654321");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFEE55447043DE), (uint64_t)(0x610DED9FAD6F9250), (uint64_t)(0x6979EB5ABE124D57), (uint64_t)(0xAA5562840152C87B), (int)__LINE__, _result);

  // 123456789123456789123456789123456789 * -987654321987654321987654321987654321
  cout << "Case : 123456789123456789123456789123456789 * -987654321987654321987654321987654321" << endl;
  a.from_string("123456789123456789123456789123456789");
  b.from_string("-987654321987654321987654321987654321");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFEE55447043DE), (uint64_t)(0x610DED9FAD6F9250), (uint64_t)(0x6979EB5ABE124D57), (uint64_t)(0xAA5562840152C87B), (int)__LINE__, _result);

  // 35742549198872617291353508656626642567 * 35742549198872617291353508656626642567
  cout << "Case : 35742549198872617291353508656626642567 * 35742549198872617291353508656626642567" << endl;
  a.from_string("35742549198872617291353508656626642567");
  b.from_string("35742549198872617291353508656626642567");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x02D30E66C7BED085), (uint64_t)(0x5601483EC300C9A4), (uint64_t)(0x907EDC343AB58797), (uint64_t)(0xB2E1CE3A8DB1CB31), (int)__LINE__, _result);

  // 106484651641840845105310984084035105060 * 89080563064446506664086404606621606262
  cout << "Case : 106484651641840845105310984084035105060 * 89080563064446506664086404606621606262" << endl;
  a.from_string("106484651641840845105310984084035105060");
  b.from_string("89080563064446506664086404606621606262");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x14F8B91FDE53ACCA), (uint64_t)(0x3F9CF391B8EFD753), (uint64_t)(0x366F079F449E5113), (uint64_t)(0x794C02CDB3FACA98), (int)__LINE__, _result);

  // 18904105168415152101680984531121209848546804322305 * 789748987489478499498
  cout << "Case : 18904105168415152101680984531121209848546804322305 * 789748987489478499498" << endl;
  a.from_string("18904105168415152101680984531121209848546804322305");
  b.from_string("789748987489478499498");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x229C40F124C), (uint64_t)(0xD05528D81D7017E6), (uint64_t)(0x04BD64530E9E40D7), (uint64_t)(0x6C9451B2CD0AFCAA), (int)__LINE__, _result);

  // 1505184098465606860 * 8799841184894135648664151164987984514684897418584164894156
  cout << "Case : 1505184098465606860 * 8799841184894135648664151164987984514684897418584164894156" << endl;
  a.from_string("1505184098465606860");
  b.from_string("8799841184894135648664151164987984514684897418584164894156");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x1D489EB77ECCCABE), (uint64_t)(0xDD31DF0E661E2F52), (uint64_t)(0x28CD9E061F9751FB), (uint64_t)(0xA5669E0EFF8AAE90), (int)__LINE__, _result);

  // 999999999999999999999999999999999999 * 999999999999999999999999999999999999
  cout << "Case : 999999999999999999999999999999999999 * 999999999999999999999999999999999999" << endl;
  a.from_string("999999999999999999999999999999999999");
  b.from_string("999999999999999999999999999999999999");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x000090E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x304C9FC9FEA2D2D4), (uint64_t)(0x9968C1E000000001), (int)__LINE__, _result);

  // 4810988494053020848210550522300588553 * 842020005600052120502303203523568201
  cout << "Case : 4810988494053020848210550522300588553 * 842020005600052120502303203523568201" << endl;
  a.from_string("4810988494053020848210550522300588553");
  b.from_string("842020005600052120502303203523568201");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x00024AF2087948A6), (uint64_t)(0x5FF31B77E66D3D7B), (uint64_t)(0x8D742E454A77EF87), (uint64_t)(0x6793F8E6362CA691), (int)__LINE__, _result);

  // 57896044618658097711785492504343953926634992332820282019728792003956564819967 * 57896044618658097711785492504343953926634992332820282019728792003956564819967
  cout << "Case : 57896044618658097711785492504343953926634992332820282019728792003956564819967 * 57896044618658097711785492504343953926634992332820282019728792003956564819967" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 340282366920938463463374607431768211455 * 340282366920938463463374607431768211455
  cout << "Case : 340282366920938463463374607431768211455 * 340282366920938463463374607431768211455" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b.from_string("340282366920938463463374607431768211455");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1844674409088942079 * 10
  cout << "Case : 1844674409088942079 * 10" << endl;
  a.from_string("1844674409088942079");
  b.from_string("10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 34028236723785111335441126115973791743 * 10
  cout << "Case : 34028236723785111335441126115973791743 * 10" << endl;
  a.from_string("34028236723785111335441126115973791743");
  b.from_string("10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 627710174123268731009685979405087222568815270992982048767 * 10
  cout << "Case : 627710174123268731009685979405087222568815270992982048767 * 10" << endl;
  a.from_string("627710174123268731009685979405087222568815270992982048767");
  b.from_string("10");
  c.mul(a,b);
  check_value(c, (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10
  cout << "Case : 11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10" << endl;
  a.from_string("11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 1844674409088942079 * -10
  cout << "Case : 1844674409088942079 * -10" << endl;
  a.from_string("1844674409088942079");
  b.from_string("-10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // 34028236723785111335441126115973791743 * -10
  cout << "Case : 34028236723785111335441126115973791743 * -10" << endl;
  a.from_string("34028236723785111335441126115973791743");
  b.from_string("-10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // 627710174123268731009685979405087222568815270992982048767 * -10
  cout << "Case : 627710174123268731009685979405087222568815270992982048767 * -10" << endl;
  a.from_string("627710174123268731009685979405087222568815270992982048767");
  b.from_string("-10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // 11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10
  cout << "Case : 11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10" << endl;
  a.from_string("11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("-10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -1844674409088942079 * 10
  cout << "Case : -1844674409088942079 * 10" << endl;
  a.from_string("-1844674409088942079");
  b.from_string("10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -34028236723785111335441126115973791743 * 10
  cout << "Case : -34028236723785111335441126115973791743 * 10" << endl;
  a.from_string("-34028236723785111335441126115973791743");
  b.from_string("10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -627710174123268731009685979405087222568815270992982048767 * 10
  cout << "Case : -627710174123268731009685979405087222568815270992982048767 * 10" << endl;
  a.from_string("-627710174123268731009685979405087222568815270992982048767");
  b.from_string("10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10
  cout << "Case : -11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10" << endl;
  a.from_string("-11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -1844674409088942079 * -10
  cout << "Case : -1844674409088942079 * -10" << endl;
  a.from_string("-1844674409088942079");
  b.from_string("-10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // -34028236723785111335441126115973791743 * -10
  cout << "Case : -34028236723785111335441126115973791743 * -10" << endl;
  a.from_string("-34028236723785111335441126115973791743");
  b.from_string("-10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // -627710174123268731009685979405087222568815270992982048767 * -10
  cout << "Case : -627710174123268731009685979405087222568815270992982048767 * -10" << endl;
  a.from_string("-627710174123268731009685979405087222568815270992982048767");
  b.from_string("-10");
  c.mul(a,b);
  check_value(c, (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // -11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10
  cout << "Case : -11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10" << endl;
  a.from_string("-11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("-10");
  c.mul(a,b);
  check_value(c, (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nmultiplication_mul()_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void multiplication_operator_test()
{
  BigInt a, b, c;
  bool _result = true;

  cout << "\n==[[multiplication_mul()_test]]==================================" << endl << endl;

  // 0 * 0
  cout << "Case : 0 * 0 = 0" << endl;
  a = 0;
  b = 0;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 * 1
  cout << "Case : 0 * 1 = 0" << endl;
  a = 0;
  b = 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 * 0
  cout << "Case : 1 * 0 = 0" << endl;
  a = 1;
  b = 0;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 * -1
  cout << "Case : 0 * -1 = 0" << endl;
  a = 0;
  b = -1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -1 * 0
  cout << "Case : -1 * 0 = 0" << endl;
  a = -1;
  b = 0;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -1 * -1
  cout << "Case : -1 * -1 = 1" << endl;
  a = -1;
  b = -1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 * 1
  cout << "Case : 1 * 1 = 1" << endl;
  a = 1;
  b = 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 * -1
  cout << "Case : 1 * -1 = -1" << endl;
  a = 1;
  b = -1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -1 * 1
  cout << "Case : -1 * 1 = -1" << endl;
  a = -1;
  b = 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max * 1
  cout << "Case : max * 1 = max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max * -1
  cout << "Case : -1 * max = min+1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 0 * max
  cout << "Case : 0 * max = 0" << endl;
  a = 0;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max * 1
  cout << "Case : min * 1 = min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max * -1
  cout << "Case : min * -1 = min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 * -max
  cout << "Case : 0 * min = 0" << endl;
  a = 0;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max * max
  cout << "Case : min * max = min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // max * -max
  cout << "Case : max * min = min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 2 * -1
  cout << "Case : 2 * -1 = -2" << endl;
  a = 2;
  b = -1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 * 1
  cout << "Case : -2 * 1 = -2" << endl;
  a = -2;
  b = 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 * -1
  cout << "Case : -2 * -1 = 2" << endl;
  a = -2;
  b = -1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // 2 * 1
  cout << "Case : 2 * 1 = 2" << endl;
  a = 2;
  b = 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // 2^192 * 2^192
  cout << "Case : 2^192 * 2^192 = 0 (overflow)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 10^40 * 10^40
  cout << "Case : 10000000000000000000000000000000000000000 * 10000000000000000000000000000000000000000" << endl;
  a.from_string("10000000000000000000000000000000000000000");
  b.from_string("10000000000000000000000000000000000000000");
  check_value(a, (uint64_t)(0), (uint64_t)(0x1D), (uint64_t)(0x6329F1C35CA4BFAB), (uint64_t)(0xB9F5610000000000), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0x1D), (uint64_t)(0x6329F1C35CA4BFAB), (uint64_t)(0xB9F5610000000000), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0x9DEA3E1F6BDFEF70), (uint64_t)(0xCDD17B25EFA418CA), (uint64_t)(0x63A22764CEC10000), (uint64_t)(0x0000000000000000), (int)__LINE__, _result);

  // 2^127 * 2^127
  cout << "Case : 2^127 * 2^127 = 2^254" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 3^25 * 5^25 * 1000000000000000000000000000001
  cout << "Case : 3^25 * 5^25 * 1000000000000000000000000000001 = 252511682940423488616943359375252511682940423488616943359375" << endl;
  a.from_string("847288609443000000000000000000847288609443");
  b.from_string("298023223876953125");
  check_value(a, (uint64_t)(0), (uint64_t)(0x9B9), (uint64_t)(0xF51A724A8458BDC5), (uint64_t)(0x45AD6B6C06562AA3), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x422CA8B0A00A425), (int)__LINE__, _result);
  c = a * b;
  // 252511682940423488616943359375252511682940423488616943359375
  check_value(c, (uint64_t)(0x28), (uint64_t)(0x3A38FB0C95516300), (uint64_t)(0x726C62C54F7D551C), (uint64_t)(0x0734DCD77BC4958F), (int)__LINE__, _result);

  // 1010... * 7
  cout << "Case : 1010....01 * 7 = 707...07" << endl;
  a.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  b = 7;
  // 00392B70E125BF92  A2FBD87383A3EE51  6378234AD7C607EB  50295FAD40A57EB5
  check_value(a, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  c = a * b;
  // 0190301628083D02  74E2EB28997B8439  B848F70BE66A376F  31219DBCC48676F3
  check_value(c, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)(0x31219DBCC48676F3), (int)__LINE__, _result);

  // 1010... * 13
  cout << "Case : 1010....01 * 13 = 1313...13" << endl;
  a = 13;
  b.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  c = a * b;
  // 02E734BB6EEABA72  46C9FDDDAF531A22  0D19CACCF50E66F3  1219DBCC48676F31
  check_value(c, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)(0x1219DBCC48676F31), (int)__LINE__, _result);

  // 1010... * 17
  cout << "Case : 1010....01 * 17 = 1717...17" << endl;
  a.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  b = 17;
  check_value(a, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(17), (int)__LINE__, _result);
  c = a * b;
  // 03CBE27EF381B8BC  D2B95FABBDE2D367  9AFA57F8542686A0  52BF5A814AFD6A05
  check_value(c, (uint64_t)(0x03CBE27EF381B8BC), (uint64_t)(0xD2B95FABBDE2D367), (uint64_t)(0x9AFA57F8542686A0), (uint64_t)(0x52BF5A814AFD6A05), (int)__LINE__, _result);

  // 1010... * 19
  cout << "Case : 1010....01 * 19 = 1919...19" << endl;
  a = 19;
  b.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  c = a * b;
  // 043E3960B5CD37E2  18B11092C52AB00A  61EA9E8E03B29676  F31219DBCC48676F
  check_value(c, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC48676F), (int)__LINE__, _result);

  // (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25)
  cout << "Case : (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25) * (2^25)" << endl;
  a.from_string("33554432");
  c = a * a * a * a * a * a * a * a * a * a ;
  check_value(c, (uint64_t)(0x0400000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 10000000000000000000 * 10000000000000000000 * 10000000000000000000 * 10000000000000000000
  cout << "Case : 10000000000000000000 * 10000000000000000000" << endl;
  cout << "Case : 10000000000000000000 * 10000000000000000000 * 10000000000000000000" << endl;
  cout << "Case : 10000000000000000000 * 10000000000000000000 * 10000000000000000000 * 10000000000000000000" << endl;
  a = (uint64_t)(10000000000000000000);
  b = (uint64_t)(10000000000000000000);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8AC7230489E80000), (int)__LINE__, _result);
  a = a * b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x4B3B4CA85A86C47A), (uint64_t)(0x098A224000000000), (int)__LINE__, _result);
  a = a * b;
  check_value(a, (uint64_t)(0), (uint64_t)(0x28C87CB5C89A2571), (uint64_t)(0xEBFDCB54864ADA83), (uint64_t)(0x4A00000000000000), (int)__LINE__, _result);
  a = a * b;
  check_value(a, (uint64_t)(0x161BCCA7119915B5), (uint64_t)(0x0764B4ABE8652979), (uint64_t)(0x7775A5F171951000), (uint64_t)(0x0000000000000000), (int)__LINE__, _result);

  // 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777
  cout << "Case : 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777" << endl;
  a = 1;
  b.from_string("77777777777777");
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  a = c * b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x138BEE9E), (uint64_t)(0x259789EB8D7269E1), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0x566), (uint64_t)(0xB288EABF5CAD1D48), (uint64_t)(0xA2DA4991554E1851), (int)__LINE__, _result);
  a = c * b;
  check_value(a, (uint64_t)(0), (uint64_t)(0x17E11E877BBC0A0), (uint64_t)(0xEDCFF74BCB80F371), (uint64_t)(0x64F670DA522E57C1), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0x69930BE9EC), (uint64_t)(0x2ED0FBECB1799892), (uint64_t)(0xAD356BD9AECB80FE), (uint64_t)(0x9F35F03F72AE9831), (int)__LINE__, _result);

  // 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333
  cout << "Case : 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333" << endl;
  a = 1;
  b.from_string("3333333333333333");
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  a = c * b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8C3DEFB1ED), (uint64_t)(0xB97D191158F18E39), (int)__LINE__, _result);
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0x67CCC55), (uint64_t)(0x8544DF1368D21BBE), (uint64_t)(0x8D94533287AD25ED), (int)__LINE__, _result);
  a = c * b;
  check_value(a, (uint64_t)(0x4CD3), (uint64_t)(0xCD26B73BE0C3F7C0), (uint64_t)(0x4FAB319FFE4C8789), (uint64_t)(0x626CFB46465548B1), (int)__LINE__, _result);

  // 1......1 * 4
  cout << "Case : 1......1 * 4" << endl;
  a.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = 4;
  c = a * b;
  check_value(c, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // 1......1 * 5
  cout << "Case : 1......1 * 5" << endl;
  a.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = 5;
  c = a * b;
  check_value(c, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // -1......1 * -4
  cout << "Case : -1......1 * -4" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = -4;
  c = a * b;
  check_value(c, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // -1......1 * -5
  cout << "Case : -1......1 * -5" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = -5;
  c = a * b;
  check_value(c, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // 4 * 1......1
  cout << "Case : 4 * 1......1" << endl;
  a = 4;
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c = a * b;
  check_value(c, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // 5 * 1......1
  cout << "Case : 5 * 1......1" << endl;
  a = 5;
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c = a * b;
  check_value(c, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // -4 * -1......1
  cout << "Case : -4 * -1......1" << endl;
  a = -4;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c = a * b;
  check_value(c, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // -5 * -1......1
  cout << "Case : -5 * -1......1" << endl;
  a = -5;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  c = a * b;
  check_value(c, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // 123456789123456789123456789123456789 * 987654321987654321987654321987654321
  cout << "Case : 123456789123456789123456789123456789 * 987654321987654321987654321987654321" << endl;
  a.from_string("123456789123456789123456789123456789");
  b.from_string("987654321987654321987654321987654321");
  c = a * b;
  check_value(c, (uint64_t)(0x11AABB8FBC21), (uint64_t)(0x9EF2126052906DAF), (uint64_t)(0x968614A541EDB2A8), (uint64_t)(0x55AA9D7BFEAD3785), (int)__LINE__, _result);

  // -123456789123456789123456789123456789 * -987654321987654321987654321987654321
  cout << "Case : -123456789123456789123456789123456789 * -987654321987654321987654321987654321" << endl;
  a.from_string("-123456789123456789123456789123456789");
  b.from_string("-987654321987654321987654321987654321");
  c = a * b;
  check_value(c, (uint64_t)(0x11AABB8FBC21), (uint64_t)(0x9EF2126052906DAF), (uint64_t)(0x968614A541EDB2A8), (uint64_t)(0x55AA9D7BFEAD3785), (int)__LINE__, _result);

  // -123456789123456789123456789123456789 * 987654321987654321987654321987654321
  cout << "Case : -123456789123456789123456789123456789 * 987654321987654321987654321987654321" << endl;
  a.from_string("-123456789123456789123456789123456789");
  b.from_string("987654321987654321987654321987654321");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFEE55447043DE), (uint64_t)(0x610DED9FAD6F9250), (uint64_t)(0x6979EB5ABE124D57), (uint64_t)(0xAA5562840152C87B), (int)__LINE__, _result);

  // 123456789123456789123456789123456789 * -987654321987654321987654321987654321
  cout << "Case : 123456789123456789123456789123456789 * -987654321987654321987654321987654321" << endl;
  a.from_string("123456789123456789123456789123456789");
  b.from_string("-987654321987654321987654321987654321");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFEE55447043DE), (uint64_t)(0x610DED9FAD6F9250), (uint64_t)(0x6979EB5ABE124D57), (uint64_t)(0xAA5562840152C87B), (int)__LINE__, _result);

  // 35742549198872617291353508656626642567 * 35742549198872617291353508656626642567
  cout << "Case : 35742549198872617291353508656626642567 * 35742549198872617291353508656626642567" << endl;
  a.from_string("35742549198872617291353508656626642567");
  b.from_string("35742549198872617291353508656626642567");
  c = a * b;
  check_value(c, (uint64_t)(0x02D30E66C7BED085), (uint64_t)(0x5601483EC300C9A4), (uint64_t)(0x907EDC343AB58797), (uint64_t)(0xB2E1CE3A8DB1CB31), (int)__LINE__, _result);

  // 106484651641840845105310984084035105060 * 89080563064446506664086404606621606262
  cout << "Case : 106484651641840845105310984084035105060 * 89080563064446506664086404606621606262" << endl;
  a.from_string("106484651641840845105310984084035105060");
  b.from_string("89080563064446506664086404606621606262");
  c = a * b;
  check_value(c, (uint64_t)(0x14F8B91FDE53ACCA), (uint64_t)(0x3F9CF391B8EFD753), (uint64_t)(0x366F079F449E5113), (uint64_t)(0x794C02CDB3FACA98), (int)__LINE__, _result);

  // 18904105168415152101680984531121209848546804322305 * 789748987489478499498
  cout << "Case : 18904105168415152101680984531121209848546804322305 * 789748987489478499498" << endl;
  a.from_string("18904105168415152101680984531121209848546804322305");
  b.from_string("789748987489478499498");
  c = a * b;
  check_value(c, (uint64_t)(0x229C40F124C), (uint64_t)(0xD05528D81D7017E6), (uint64_t)(0x04BD64530E9E40D7), (uint64_t)(0x6C9451B2CD0AFCAA), (int)__LINE__, _result);

  // 1505184098465606860 * 8799841184894135648664151164987984514684897418584164894156
  cout << "Case : 1505184098465606860 * 8799841184894135648664151164987984514684897418584164894156" << endl;
  a.from_string("1505184098465606860");
  b.from_string("8799841184894135648664151164987984514684897418584164894156");
  c = a * b;
  check_value(c, (uint64_t)(0x1D489EB77ECCCABE), (uint64_t)(0xDD31DF0E661E2F52), (uint64_t)(0x28CD9E061F9751FB), (uint64_t)(0xA5669E0EFF8AAE90), (int)__LINE__, _result);

  // 999999999999999999999999999999999999 * 999999999999999999999999999999999999
  cout << "Case : 999999999999999999999999999999999999 * 999999999999999999999999999999999999" << endl;
  a.from_string("999999999999999999999999999999999999");
  b.from_string("999999999999999999999999999999999999");
  c = a * b;
  check_value(c, (uint64_t)(0x000090E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x304C9FC9FEA2D2D4), (uint64_t)(0x9968C1E000000001), (int)__LINE__, _result);

  // 4810988494053020848210550522300588553 * 842020005600052120502303203523568201
  cout << "Case : 4810988494053020848210550522300588553 * 842020005600052120502303203523568201" << endl;
  a.from_string("4810988494053020848210550522300588553");
  b.from_string("842020005600052120502303203523568201");
  c = a * b;
  check_value(c, (uint64_t)(0x00024AF2087948A6), (uint64_t)(0x5FF31B77E66D3D7B), (uint64_t)(0x8D742E454A77EF87), (uint64_t)(0x6793F8E6362CA691), (int)__LINE__, _result);

  // 57896044618658097711785492504343953926634992332820282019728792003956564819967 * 57896044618658097711785492504343953926634992332820282019728792003956564819967
  cout << "Case : 57896044618658097711785492504343953926634992332820282019728792003956564819967 * 57896044618658097711785492504343953926634992332820282019728792003956564819967" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 340282366920938463463374607431768211455 * 340282366920938463463374607431768211455
  cout << "Case : 340282366920938463463374607431768211455 * 340282366920938463463374607431768211455" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b.from_string("340282366920938463463374607431768211455");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1844674409088942079 * 10
  cout << "Case : 1844674409088942079 * 10" << endl;
  a.from_string("1844674409088942079");
  b.from_string("10");
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 34028236723785111335441126115973791743 * 10
  cout << "Case : 34028236723785111335441126115973791743 * 10" << endl;
  a.from_string("34028236723785111335441126115973791743");
  b.from_string("10");
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 627710174123268731009685979405087222568815270992982048767 * 10
  cout << "Case : 627710174123268731009685979405087222568815270992982048767 * 10" << endl;
  a.from_string("627710174123268731009685979405087222568815270992982048767");
  b.from_string("10");
  c = a * b;
  check_value(c, (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10
  cout << "Case : 11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10" << endl;
  a.from_string("11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("10");
  c = a * b;
  check_value(c, (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 1844674409088942079 * -10
  cout << "Case : 1844674409088942079 * -10" << endl;
  a.from_string("1844674409088942079");
  b.from_string("-10");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // 34028236723785111335441126115973791743 * -10
  cout << "Case : 34028236723785111335441126115973791743 * -10" << endl;
  a.from_string("34028236723785111335441126115973791743");
  b.from_string("-10");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // 627710174123268731009685979405087222568815270992982048767 * -10
  cout << "Case : 627710174123268731009685979405087222568815270992982048767 * -10" << endl;
  a.from_string("627710174123268731009685979405087222568815270992982048767");
  b.from_string("-10");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // 11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10
  cout << "Case : 11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10" << endl;
  a.from_string("11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("-10");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -1844674409088942079 * 10
  cout << "Case : -1844674409088942079 * 10" << endl;
  a.from_string("-1844674409088942079");
  b.from_string("10");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -34028236723785111335441126115973791743 * 10
  cout << "Case : -34028236723785111335441126115973791743 * 10" << endl;
  a.from_string("-34028236723785111335441126115973791743");
  b.from_string("10");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -627710174123268731009685979405087222568815270992982048767 * 10
  cout << "Case : -627710174123268731009685979405087222568815270992982048767 * 10" << endl;
  a.from_string("-627710174123268731009685979405087222568815270992982048767");
  b.from_string("10");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10
  cout << "Case : -11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10" << endl;
  a.from_string("-11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("10");
  c = a * b;
  check_value(c, (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -1844674409088942079 * -10
  cout << "Case : -1844674409088942079 * -10" << endl;
  a.from_string("-1844674409088942079");
  b.from_string("-10");
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // -34028236723785111335441126115973791743 * -10
  cout << "Case : -34028236723785111335441126115973791743 * -10" << endl;
  a.from_string("-34028236723785111335441126115973791743");
  b.from_string("-10");
  c = a * b;
  check_value(c, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // -627710174123268731009685979405087222568815270992982048767 * -10
  cout << "Case : -627710174123268731009685979405087222568815270992982048767 * -10" << endl;
  a.from_string("-627710174123268731009685979405087222568815270992982048767");
  b.from_string("-10");
  c = a * b;
  check_value(c, (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // -11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10
  cout << "Case : -11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10" << endl;
  a.from_string("-11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("-10");
  c = a * b;
  check_value(c, (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nmultiplication_mul()_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void multiplication_assignment_operator_test()
{
  BigInt a, b;
  bool _result = true;

  cout << "\n==[[multiplication_assignment_operator(*=)_test]]==================================" << endl << endl;

  // 0 * 0
  cout << "Case : 0 * 0 = 0" << endl;
  a = 0;
  b = 0;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 * 1
  cout << "Case : 0 * 1 = 0" << endl;
  a = 0;
  b = 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1 * 0
  cout << "Case : 1 * 0 = 0" << endl;
  a = 1;
  b = 0;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 * -1
  cout << "Case : 0 * -1 = 0" << endl;
  a = 0;
  b = -1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -1 * 0
  cout << "Case : -1 * 0 = 0" << endl;
  a = -1;
  b = 0;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -1 * -1
  cout << "Case : -1 * -1 = 1" << endl;
  a = -1;
  b = -1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 * 1
  cout << "Case : 1 * 1 = 1" << endl;
  a = 1;
  b = 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1 * -1
  cout << "Case : 1 * -1 = -1" << endl;
  a = 1;
  b = -1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -1 * 1
  cout << "Case : -1 * 1 = -1" << endl;
  a = -1;
  b = 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max * 1
  cout << "Case : max * 1 = max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max * -1
  cout << "Case : -1 * max = min+1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 0 * max
  cout << "Case : 0 * max = 0" << endl;
  a = 0;
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max * 1
  cout << "Case : min * 1 = min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max * -1
  cout << "Case : min * -1 = min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 0 * -max
  cout << "Case : 0 * min = 0" << endl;
  a = 0;
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max * max
  cout << "Case : min * max = min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // max * -max
  cout << "Case : max * min = min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 2 * -1
  cout << "Case : 2 * -1 = -2" << endl;
  a = 2;
  b = -1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 * 1
  cout << "Case : -2 * 1 = -2" << endl;
  a = -2;
  b = 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 * -1
  cout << "Case : -2 * -1 = 2" << endl;
  a = -2;
  b = -1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // 2 * 1
  cout << "Case : 2 * 1 = 2" << endl;
  a = 2;
  b = 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // 2^192 * 2^192
  cout << "Case : 2^192 * 2^192 = 0 (overflow)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 10^40 * 10^40
  cout << "Case : 10000000000000000000000000000000000000000 * 10000000000000000000000000000000000000000" << endl;
  a.from_string("10000000000000000000000000000000000000000");
  b.from_string("10000000000000000000000000000000000000000");
  check_value(a, (uint64_t)(0), (uint64_t)(0x1D), (uint64_t)(0x6329F1C35CA4BFAB), (uint64_t)(0xB9F5610000000000), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0x1D), (uint64_t)(0x6329F1C35CA4BFAB), (uint64_t)(0xB9F5610000000000), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x9DEA3E1F6BDFEF70), (uint64_t)(0xCDD17B25EFA418CA), (uint64_t)(0x63A22764CEC10000), (uint64_t)(0x0000000000000000), (int)__LINE__, _result);

  // 2^127 * 2^127
  cout << "Case : 2^127 * 2^127 = 2^254" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 3^25 * 5^25 * 1000000000000000000000000000001
  cout << "Case : 3^25 * 5^25 * 1000000000000000000000000000001 = 252511682940423488616943359375252511682940423488616943359375" << endl;
  a.from_string("847288609443000000000000000000847288609443");
  b.from_string("298023223876953125");
  check_value(a, (uint64_t)(0), (uint64_t)(0x9B9), (uint64_t)(0xF51A724A8458BDC5), (uint64_t)(0x45AD6B6C06562AA3), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x422CA8B0A00A425), (int)__LINE__, _result);
  a *= b;
  // 252511682940423488616943359375252511682940423488616943359375
  check_value(a, (uint64_t)(0x28), (uint64_t)(0x3A38FB0C95516300), (uint64_t)(0x726C62C54F7D551C), (uint64_t)(0x0734DCD77BC4958F), (int)__LINE__, _result);

  // 1010... * 7
  cout << "Case : 1010....01 * 7 = 707...07" << endl;
  a.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  b = 7;
  // 00392B70E125BF92  A2FBD87383A3EE51  6378234AD7C607EB  50295FAD40A57EB5
  check_value(a, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  a *= b;
  // 0190301628083D02  74E2EB28997B8439  B848F70BE66A376F  31219DBCC48676F3
  check_value(a, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)(0x31219DBCC48676F3), (int)__LINE__, _result);

  // 1010... * 13
  cout << "Case : 1010....01 * 13 = 1313...13" << endl;
  a = 13;
  b.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  a *= b;
  // 02E734BB6EEABA72  46C9FDDDAF531A22  0D19CACCF50E66F3  1219DBCC48676F31
  check_value(a, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)(0x1219DBCC48676F31), (int)__LINE__, _result);

  // 1010... * 17
  cout << "Case : 1010....01 * 17 = 1717...17" << endl;
  a.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  b = 17;
  check_value(a, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(17), (int)__LINE__, _result);
  a *= b;
  // 03CBE27EF381B8BC  D2B95FABBDE2D367  9AFA57F8542686A0  52BF5A814AFD6A05
  check_value(a, (uint64_t)(0x03CBE27EF381B8BC), (uint64_t)(0xD2B95FABBDE2D367), (uint64_t)(0x9AFA57F8542686A0), (uint64_t)(0x52BF5A814AFD6A05), (int)__LINE__, _result);

  // 1010... * 19
  cout << "Case : 1010....01 * 19 = 1919...19" << endl;
  a = 19;
  b.from_string("101010101010101010101010101010101010101010101010101010101010101010101010101");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  a *= b;
  // 043E3960B5CD37E2  18B11092C52AB00A  61EA9E8E03B29676  F31219DBCC48676F
  check_value(a, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC48676F), (int)__LINE__, _result);

  // 10000000000000000000 * 10000000000000000000 * 10000000000000000000 * 10000000000000000000
  cout << "Case : 10000000000000000000 * 10000000000000000000" << endl;
  cout << "Case : 10000000000000000000 * 10000000000000000000 * 10000000000000000000" << endl;
  cout << "Case : 10000000000000000000 * 10000000000000000000 * 10000000000000000000 * 10000000000000000000" << endl;
  BigInt a7((uint64_t)10000000000000000000);
  BigInt b7((uint64_t)10000000000000000000);
  check_value(a7, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8AC7230489E80000), (int)__LINE__, _result);
  b7 *= a7;
  check_value(b7, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x4B3B4CA85A86C47A), (uint64_t)(0x098A224000000000), (int)__LINE__, _result);
  b7 *= a7;
  check_value(b7, (uint64_t)(0), (uint64_t)(0x28C87CB5C89A2571), (uint64_t)(0xEBFDCB54864ADA83), (uint64_t)(0x4A00000000000000), (int)__LINE__, _result);
  b7 *= a7;
  check_value(b7, (uint64_t)(0x161BCCA7119915B5), (uint64_t)(0x0764B4ABE8652979), (uint64_t)(0x7775A5F171951000), (uint64_t)(0x0000000000000000), (int)__LINE__, _result);

  // 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777
  cout << "Case : 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777 * 77777777777777" << endl;
  a = 1;
  b.from_string("77777777777777");
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x138BEE9E), (uint64_t)(0x259789EB8D7269E1), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0x566), (uint64_t)(0xB288EABF5CAD1D48), (uint64_t)(0xA2DA4991554E1851), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0x17E11E877BBC0A0), (uint64_t)(0xEDCFF74BCB80F371), (uint64_t)(0x64F670DA522E57C1), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x69930BE9EC), (uint64_t)(0x2ED0FBECB1799892), (uint64_t)(0xAD356BD9AECB80FE), (uint64_t)(0x9F35F03F72AE9831), (int)__LINE__, _result);

  // 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333
  cout << "Case : 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333 * 3333333333333333" << endl;
  a = 1;
  b.from_string("3333333333333333");
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8C3DEFB1ED), (uint64_t)(0xB97D191158F18E39), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0x67CCC55), (uint64_t)(0x8544DF1368D21BBE), (uint64_t)(0x8D94533287AD25ED), (int)__LINE__, _result);
  a *= b;
  check_value(a, (uint64_t)(0x4CD3), (uint64_t)(0xCD26B73BE0C3F7C0), (uint64_t)(0x4FAB319FFE4C8789), (uint64_t)(0x626CFB46465548B1), (int)__LINE__, _result);

  // 1......1 * 4
  cout << "Case : 1......1 * 4" << endl;
  a.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = 4;
  a *= b;
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // 1......1 * 5
  cout << "Case : 1......1 * 5" << endl;
  a.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = 5;
  a *= b;
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // -1......1 * -4
  cout << "Case : -1......1 * -4" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = -4;
  a *= b;
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // -1......1 * -5
  cout << "Case : -1......1 * -5" << endl;
  a.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  b = -5;
  a *= b;
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // 4 * 1......1
  cout << "Case : 4 * 1......1" << endl;
  a = 4;
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a *= b;
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // 5 * 1......1
  cout << "Case : 5 * 1......1" << endl;
  a = 5;
  b.from_string("11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a *= b;
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // -4 * -1......1
  cout << "Case : -4 * -1......1" << endl;
  a = -4;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a *= b;
  check_value(a, (uint64_t)(0x6242AA02F8E14408), (uint64_t)(0x20DC068A41C19BE2), (uint64_t)(0xF67CA8A2DC5D9C71), (uint64_t)(0xC71C71C71C71C71C), (int)__LINE__, _result);

  // -5 * -1......1
  cout << "Case : -5 * -1......1" << endl;
  a = -5;
  b.from_string("-11111111111111111111111111111111111111111111111111111111111111111111111111111");
  a *= b;
  check_value(a, (uint64_t)(0x7AD35483B719950A), (uint64_t)(0x2913082CD23202DB), (uint64_t)(0xB41BD2CB9375038E), (uint64_t)(0x38E38E38E38E38E3), (int)__LINE__, _result);

  // 123456789123456789123456789123456789 * 987654321987654321987654321987654321
  cout << "Case : 123456789123456789123456789123456789 * 987654321987654321987654321987654321" << endl;
  a.from_string("123456789123456789123456789123456789");
  b.from_string("987654321987654321987654321987654321");
  a *= b;
  check_value(a, (uint64_t)(0x11AABB8FBC21), (uint64_t)(0x9EF2126052906DAF), (uint64_t)(0x968614A541EDB2A8), (uint64_t)(0x55AA9D7BFEAD3785), (int)__LINE__, _result);

  // -123456789123456789123456789123456789 * -987654321987654321987654321987654321
  cout << "Case : -123456789123456789123456789123456789 * -987654321987654321987654321987654321" << endl;
  a.from_string("-123456789123456789123456789123456789");
  b.from_string("-987654321987654321987654321987654321");
  a *= b;
  check_value(a, (uint64_t)(0x11AABB8FBC21), (uint64_t)(0x9EF2126052906DAF), (uint64_t)(0x968614A541EDB2A8), (uint64_t)(0x55AA9D7BFEAD3785), (int)__LINE__, _result);

  // -123456789123456789123456789123456789 * 987654321987654321987654321987654321
  cout << "Case : -123456789123456789123456789123456789 * 987654321987654321987654321987654321" << endl;
  a.from_string("-123456789123456789123456789123456789");
  b.from_string("987654321987654321987654321987654321");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFEE55447043DE), (uint64_t)(0x610DED9FAD6F9250), (uint64_t)(0x6979EB5ABE124D57), (uint64_t)(0xAA5562840152C87B), (int)__LINE__, _result);

  // 123456789123456789123456789123456789 * -987654321987654321987654321987654321
  cout << "Case : 123456789123456789123456789123456789 * -987654321987654321987654321987654321" << endl;
  a.from_string("123456789123456789123456789123456789");
  b.from_string("-987654321987654321987654321987654321");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFEE55447043DE), (uint64_t)(0x610DED9FAD6F9250), (uint64_t)(0x6979EB5ABE124D57), (uint64_t)(0xAA5562840152C87B), (int)__LINE__, _result);

  // 35742549198872617291353508656626642567 * 35742549198872617291353508656626642567
  cout << "Case : 35742549198872617291353508656626642567 * 35742549198872617291353508656626642567" << endl;
  a.from_string("35742549198872617291353508656626642567");
  b.from_string("35742549198872617291353508656626642567");
  a *= b;
  check_value(a, (uint64_t)(0x02D30E66C7BED085), (uint64_t)(0x5601483EC300C9A4), (uint64_t)(0x907EDC343AB58797), (uint64_t)(0xB2E1CE3A8DB1CB31), (int)__LINE__, _result);

  // 106484651641840845105310984084035105060 * 89080563064446506664086404606621606262
  cout << "Case : 106484651641840845105310984084035105060 * 89080563064446506664086404606621606262" << endl;
  a.from_string("106484651641840845105310984084035105060");
  b.from_string("89080563064446506664086404606621606262");
  a *= b;
  check_value(a, (uint64_t)(0x14F8B91FDE53ACCA), (uint64_t)(0x3F9CF391B8EFD753), (uint64_t)(0x366F079F449E5113), (uint64_t)(0x794C02CDB3FACA98), (int)__LINE__, _result);

  // 18904105168415152101680984531121209848546804322305 * 789748987489478499498
  cout << "Case : 18904105168415152101680984531121209848546804322305 * 789748987489478499498" << endl;
  a.from_string("18904105168415152101680984531121209848546804322305");
  b.from_string("789748987489478499498");
  a *= b;
  check_value(a, (uint64_t)(0x229C40F124C), (uint64_t)(0xD05528D81D7017E6), (uint64_t)(0x04BD64530E9E40D7), (uint64_t)(0x6C9451B2CD0AFCAA), (int)__LINE__, _result);

  // 1505184098465606860 * 8799841184894135648664151164987984514684897418584164894156
  cout << "Case : 1505184098465606860 * 8799841184894135648664151164987984514684897418584164894156" << endl;
  a.from_string("1505184098465606860");
  b.from_string("8799841184894135648664151164987984514684897418584164894156");
  a *= b;
  check_value(a, (uint64_t)(0x1D489EB77ECCCABE), (uint64_t)(0xDD31DF0E661E2F52), (uint64_t)(0x28CD9E061F9751FB), (uint64_t)(0xA5669E0EFF8AAE90), (int)__LINE__, _result);

  // 999999999999999999999999999999999999 * 999999999999999999999999999999999999
  cout << "Case : 999999999999999999999999999999999999 * 999999999999999999999999999999999999" << endl;
  a.from_string("999999999999999999999999999999999999");
  b.from_string("999999999999999999999999999999999999");
  a *= b;
  check_value(a, (uint64_t)(0x000090E40FBEEA1D), (uint64_t)(0x3A4ABC8955E946FE), (uint64_t)(0x304C9FC9FEA2D2D4), (uint64_t)(0x9968C1E000000001), (int)__LINE__, _result);

  // 4810988494053020848210550522300588553 * 842020005600052120502303203523568201
  cout << "Case : 4810988494053020848210550522300588553 * 842020005600052120502303203523568201" << endl;
  a.from_string("4810988494053020848210550522300588553");
  b.from_string("842020005600052120502303203523568201");
  a *= b;
  check_value(a, (uint64_t)(0x00024AF2087948A6), (uint64_t)(0x5FF31B77E66D3D7B), (uint64_t)(0x8D742E454A77EF87), (uint64_t)(0x6793F8E6362CA691), (int)__LINE__, _result);

  // 57896044618658097711785492504343953926634992332820282019728792003956564819967 * 57896044618658097711785492504343953926634992332820282019728792003956564819967
  cout << "Case : 57896044618658097711785492504343953926634992332820282019728792003956564819967 * 57896044618658097711785492504343953926634992332820282019728792003956564819967" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 340282366920938463463374607431768211455 * 340282366920938463463374607431768211455
  cout << "Case : 340282366920938463463374607431768211455 * 340282366920938463463374607431768211455" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b.from_string("340282366920938463463374607431768211455");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 1844674409088942079 * 10
  cout << "Case : 1844674409088942079 * 10" << endl;
  a.from_string("1844674409088942079");
  b.from_string("10");
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 34028236723785111335441126115973791743 * 10
  cout << "Case : 34028236723785111335441126115973791743 * 10" << endl;
  a.from_string("34028236723785111335441126115973791743");
  b.from_string("10");
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 627710174123268731009685979405087222568815270992982048767 * 10
  cout << "Case : 627710174123268731009685979405087222568815270992982048767 * 10" << endl;
  a.from_string("627710174123268731009685979405087222568815270992982048767");
  b.from_string("10");
  a *= b;
  check_value(a, (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10
  cout << "Case : 11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10" << endl;
  a.from_string("11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("10");
  a *= b;
  check_value(a, (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // 1844674409088942079 * -10
  cout << "Case : 1844674409088942079 * -10" << endl;
  a.from_string("1844674409088942079");
  b.from_string("-10");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // 34028236723785111335441126115973791743 * -10
  cout << "Case : 34028236723785111335441126115973791743 * -10" << endl;
  a.from_string("34028236723785111335441126115973791743");
  b.from_string("-10");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // 627710174123268731009685979405087222568815270992982048767 * -10
  cout << "Case : 627710174123268731009685979405087222568815270992982048767 * -10" << endl;
  a.from_string("627710174123268731009685979405087222568815270992982048767");
  b.from_string("-10");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // 11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10
  cout << "Case : 11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10" << endl;
  a.from_string("11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("-10");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -1844674409088942079 * 10
  cout << "Case : -1844674409088942079 * 10" << endl;
  a.from_string("-1844674409088942079");
  b.from_string("10");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -34028236723785111335441126115973791743 * 10
  cout << "Case : -34028236723785111335441126115973791743 * 10" << endl;
  a.from_string("-34028236723785111335441126115973791743");
  b.from_string("10");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -627710174123268731009685979405087222568815270992982048767 * 10
  cout << "Case : -627710174123268731009685979405087222568815270992982048767 * 10" << endl;
  a.from_string("-627710174123268731009685979405087222568815270992982048767");
  b.from_string("10");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10
  cout << "Case : -11579208934515598203567962857472184787308747292216334979428447219761704599551 * 10" << endl;
  a.from_string("-11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("10");
  a *= b;
  check_value(a, (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC00000008), (uint64_t)(0xFFFFFFFC0000000A), (int)__LINE__, _result);

  // -1844674409088942079 * -10
  cout << "Case : -1844674409088942079 * -10" << endl;
  a.from_string("-1844674409088942079");
  b.from_string("-10");
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // -34028236723785111335441126115973791743 * -10
  cout << "Case : -34028236723785111335441126115973791743 * -10" << endl;
  a.from_string("-34028236723785111335441126115973791743");
  b.from_string("-10");
  a *= b;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // -627710174123268731009685979405087222568815270992982048767 * -10
  cout << "Case : -627710174123268731009685979405087222568815270992982048767 * -10" << endl;
  a.from_string("-627710174123268731009685979405087222568815270992982048767");
  b.from_string("-10");
  a *= b;
  check_value(a, (uint64_t)(1), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  // -11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10
  cout << "Case : -11579208934515598203567962857472184787308747292216334979428447219761704599551 * -10" << endl;
  a.from_string("-11579208934515598203567962857472184787308747292216334979428447219761704599551");
  b.from_string("-10");
  a *= b;
  check_value(a, (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF7), (uint64_t)(0x3FFFFFFF6), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nmultiplication_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void div_mod_test()
{
  bool _result = true;
  BigInt i;
  BigInt j;
  BigInt q;
  BigInt r;

  cout << "\n==[[div_mod_test]]==================================" << endl << endl;

  i = 1024;
  j = 32;
  cout << "Case : 1024 / 32 =  32 ... 0" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1024), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  i = 1025;
  j = 32;
  cout << "Case : 1025 / 32 =  32 ... 1" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1025), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  i = 1023;
  j = 32;
  cout << "Case : 1023 / 32 =  31 ... 31" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1023), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(31), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(31), (int)__LINE__, _result);

  // -5 / -2 =  2 ... -1
  cout << "Case : -5 / -2 =  2 ... -1" << endl;
  i = -5;
  j = -2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  //  5 / -2 = -2 ...  1
  cout << "Case : 5 / -2 = -2 ...  1" << endl;
  i = 5;
  j = -2;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)5, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -5 /  2 = -2 ... -1
  cout << "Case : -5 /  2 = -2 ... -1" << endl;
  i = -5;
  j = 2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -2 / -5 =  0 ... -2
  cout << "Case : -2 / -5 =  0 ... -2" << endl;
  i = -2;
  j = -5;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  //  2 / -5 =  0 ...  2
  cout << "Case : 2 / -5 =  0 ...  2" << endl;
  i = 2;
  j = -5;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -2 /  5 =  0 ... -2
  cout << "Case : -2 /  5 =  0 ... -2" << endl;
  i = -2;
  j = 5;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)5, (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 / -2 =  1 ...  0
  cout << "Case : -2 / -2 =  1 ...  0" << endl;
  i = -2;
  j = -2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  //  2 / -2 = -1 ...  0
  cout << "Case : 2 / -2 = -1 ...  0" << endl;
  i = 2;
  j = -2;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -2 /  2 = -1 ...  0
  cout << "Case : -2 /  2 = -1 ...  0" << endl;
  i = -2;
  j = 2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // max / 3
  cout << "Case : max / 3" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = 3;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x2AAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -max / 3
  cout << "Case : min / 3" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = 3;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xD555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555556), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // max / -3
  cout << "Case : max / -3" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = -3;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xD555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555556), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -max / -3
  cout << "Case : min / -3" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = -3;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x2AAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // max / 7
  cout << "Case : max / 7" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = 7;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x1249249249249249), (uint64_t)(0x2492492492492492), (uint64_t)(0x4924924924924924), (uint64_t)(0x9249249249249249), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max / 7
  cout << "Case : min / 7" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = 7;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xEDB6DB6DB6DB6DB6), (uint64_t)(0xDB6DB6DB6DB6DB6D), (uint64_t)(0xB6DB6DB6DB6DB6DB), (uint64_t)(0x6DB6DB6DB6DB6DB7), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max / -max = 0 ... max
  cout << "Case : max / -max = 0 ... max" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -max / max = -1 ... -1
  cout << "Case : -max / max = -1 ... -1" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max / max = 1 ... 0
  cout << "Case : max / max = 1 ... 0" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max / -max = 1 ... 0
  cout << "Case : -max / -max = 1 ... 0" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // max / 2^127 = 2^128-1 ... 2^127-1
  cout << "Case : max / 2^127 = 2^128-1 ... 2^127-1" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("170141183460469231731687303715884105728");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -max / 2^127 = -2^128 ... 0
  cout << "Case : min / 2^127 = -2^128 ... 0" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("170141183460469231731687303715884105728");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 7070... / 7
  cout << "Case : 7070...07 / 7 = 1010...01 ... 0" << endl;
  i.from_string("707070707070707070707070707070707070707070707070707070707070707070707070707");
  j = 7;
  check_value(i, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)(0x31219DBCC48676F3), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 7070...4 / 7
  cout << "Case : 7070...11 / 7 = 1010...01 ... 4" << endl;
  i.from_string("707070707070707070707070707070707070707070707070707070707070707070707070711");
  j = 7;
  check_value(i, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)0x31219DBCC48676F7, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(4), (int)__LINE__, _result);

  // 1313... / 13
  cout << "Case : 1313...13 / 13 = 1010...01 ... 0" << endl;
  i.from_string("1313131313131313131313131313131313131313131313131313131313131313131313131313");
  j = 13;
  check_value(i, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)(0x1219DBCC48676F31), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1313...8 / 13
  cout << "Case : 1313...21 / 13 = 1010...01 ... 8" << endl;
  i.from_string("1313131313131313131313131313131313131313131313131313131313131313131313131321");
  j = 13;
  check_value(i, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)0x1219DBCC48676F39, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(8), (int)__LINE__, _result);

  // 1919... / 19
  cout << "Case : 1919...19 / 19 = 1010...01 ... 0" << endl;
  i.from_string("1919191919191919191919191919191919191919191919191919191919191919191919191919");
  j = 19;
  check_value(i, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC48676F), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1919...18 / 19
  cout << "Case : 1919...37 / 19 = 1010...01 ... 18" << endl;
  i.from_string("1919191919191919191919191919191919191919191919191919191919191919191919191937");
  j = 19;
  check_value(i, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC486781), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(18), (int)__LINE__, _result);

  // max / 100000000000000
  cout << "Case : max / 100000000000000" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("100000000000000");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x5AF3107A4000), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x16849), (uint64_t)(0xB86A12B9B01EA709), (uint64_t)(0x09833DE71928DB21), (uint64_t)(0x38E9F98E67D007F0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3956564819967), (int)__LINE__, _result);

  // (max / 100000000000000) / 100000000000000
  cout << "Case : (max / 100000000000000) / 100000000000000" << endl;
  i.from_string("578960446186580977117854925043439539266349923328202820197287920");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0x16849), (uint64_t)(0xB86A12B9B01EA709), (uint64_t)(0x09833DE71928DB21), (uint64_t)(0x38E9F98E67D007F0), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0x3F61ED7CA), (uint64_t)(0x0C0328362F2A75B8), (uint64_t)(0x62214FF1DB72D802), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2820197287920), (int)__LINE__, _result);

  // ((max / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : ((max / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("5789604461865809771178549250434395392663499233282");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0x3F61ED7CA), (uint64_t)(0x0C0328362F2A75B8), (uint64_t)(0x62214FF1DB72D802), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB267ED1940F1C), (uint64_t)(0x61C55F038B237591), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(92663499233282), (int)__LINE__, _result);

  // (((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : (((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("57896044618658097711785492504343953");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB267ED1940F1C), (uint64_t)(0x61C55F038B237591), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1F), (uint64_t)(0x62B0B257C0D1A5DD), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(85492504343953), (int)__LINE__, _result);

  // ((((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : ((((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("578960446186580977117");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1F), (uint64_t)(0x62B0B257C0D1A5DD), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(5789604), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(46186580977117), (int)__LINE__, _result);

  // max / 77777777777777
  cout << "Case : max / 77777777777777" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("77777777777777");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x1CF3A), (uint64_t)(0x363F3CAAB12A7E7D), (uint64_t)(0x1BBB227F8F04E940), (uint64_t)(0x0D14071A4ADE219A), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(31119352451845), (int)__LINE__, _result);

  // (max / 77777777777777) / 77777777777777
  cout << "Case : (max / 77777777777777) / 77777777777777" << endl;
  i.from_string("744377716525611557214407302599994408844047329937492066441240986");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0x1CF3A), (uint64_t)(0x363F3CAAB12A7E7D), (uint64_t)(0x1BBB227F8F04E940), (uint64_t)(0x0D14071A4ADE219A), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0x68C673AEA), (uint64_t)(0xBB2F4ECDD3D6E044), (uint64_t)(0x66641DD153516E4C), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(71096126874126), (int)__LINE__, _result);

  // ((max / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : ((max / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("9570570641043672869891647184442912744466738671180");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0x68C673AEA), (uint64_t)(0xBB2F4ECDD3D6E044), (uint64_t)(0x66641DD153516E4C), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x17B2D7CC5B85A7), (uint64_t)(0xE407E181B4E33171), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(25042959957867), (int)__LINE__, _result);

  // (((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : (((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("123050193956277024543403597998797169");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x17B2D7CC5B85A7), (uint64_t)(0xE407E181B4E33171), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x55), (uint64_t)(0xC3AFAA23F2CA87E9), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(20938559125400), (int)__LINE__, _result);

  // ((((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : ((((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("1582073922295006136297");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x55), (uint64_t)(0xC3AFAA23F2CA87E9), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(20340950), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(33406133068147), (int)__LINE__, _result);

  // max / 3333333333333333
  cout << "Case : max / 3333333333333333" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("3333333333333333");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xACF), (uint64_t)(0x02F8F133A6DE29FD), (uint64_t)(0xB1E6DB4C6B12D53D), (uint64_t)(0xBEABA6B1F820779E), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(162358756430473), (int)__LINE__, _result);

  // (max / 3333333333333333) / 3333333333333333
  cout << "Case : (max / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("17368813385597431050416986311046291219689128804475206574831518");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0xACF), (uint64_t)(0x02F8F133A6DE29FD), (uint64_t)(0xB1E6DB4C6B12D53D), (uint64_t)(0xBEABA6B1F820779E), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0xE9A742), (uint64_t)(0x82EDE0D4790197BE), (uint64_t)(0x864457E83EABBB9D), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(98868193659773), (int)__LINE__, _result);

  // ((max / 3333333333333333) / 3333333333333333) / 3333333333333333
  cout << "Case : ((max / 3333333333333333) / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("5210644015679229836189497461236870984856484765");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0), (uint64_t)(0xE9A742), (uint64_t)(0x82EDE0D4790197BE), (uint64_t)(0x864457E83EABBB9D), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BAF31CD3), (uint64_t)(0xB8600EEFC9E89CCB), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3240043579721014), (int)__LINE__, _result);

  // (((max / 3333333333333333) / 3333333333333333) / 3333333333333333) / 3333333333333333
  cout << "Case : (((max / 3333333333333333) / 3333333333333333) / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("1563193204703769107176169708747");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BAF31CD3), (uint64_t)(0xB8600EEFC9E89CCB), (int)__LINE__, _result);
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1AA83C8B45A3A), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2596828823512457), (int)__LINE__, _result);

  // 5......5 / 3......3
  cout << "Case : 5......5 / 3......3" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // 5......5 / 2......2
  cout << "Case : 5......5 / 2......2" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / 3......3
  cout << "Case : 4......4 / 3......3" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / 2......2
  cout << "Case : 4......4 / 2......2" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 5......5 / -3......3
  cout << "Case : 5......5 / -3......3" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // 5......5 / -2......2
  cout << "Case : 5......5 / -2......2" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / -3......3
  cout << "Case : 4......4 / -3......3" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / -2......2
  cout << "Case : 4......4 / -2......2" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1C9EDE81B7E), (uint64_t)(0x430DBE4679DDC581), (uint64_t)(0x64D68830A2802734), (uint64_t)(0xD29394146250858F), (int)__LINE__, _result);

  // -876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : -876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFE361217E481), (uint64_t)(0xBCF241B986223A7E), (uint64_t)(0x9B2977CF5D7FD8CB), (uint64_t)(0x2D6C6BEB9DAF7A71), (int)__LINE__, _result);

  // 876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFF9), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1C9EDE81B7E), (uint64_t)(0x430DBE4679DDC581), (uint64_t)(0x64D68830A2802734), (uint64_t)(0xD29394146250858F), (int)__LINE__, _result);

  // -876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : -876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFF9), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFE361217E481), (uint64_t)(0xBCF241B986223A7E), (uint64_t)(0x9B2977CF5D7FD8CB), (uint64_t)(0x2D6C6BEB9DAF7A71), (int)__LINE__, _result);

  // 45646484978879789878784164168798787987879874498498555555555555555555 / 516561516484814184881456154661544444444444444444444444777
  cout << "Case : 45646484978879789878784164168798787987879874498498555555555555555555 / " << endl;
  cout << "       516561516484814184881456154661544444444444444444444444777" << endl;
  i.from_string("45646484978879789878784164168798787987879874498498555555555555555555");
  j.from_string("516561516484814184881456154661544444444444444444444444777");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000001493067338), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0x64A9794005D7C6F), (uint64_t)(0x4DAB91911C1994C5), (uint64_t)(0x0CA7AFF0584936EB), (int)__LINE__, _result);

  // 9999999999999999944444444444222222222288888888888777777777711111111115555555 / 4444444444111111111122222222266666333333333
  cout << "Case : 9999999999999999944444444444222222222288888888888777777777711111111115555555 / " << endl;
  cout << "       4444444444111111111122222222266666333333333" << endl;
  i.from_string("9999999999999999944444444444222222222288888888888777777777711111111115555555");
  j.from_string("4444444444111111111122222222266666333333333");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00006EEEFE1A6247), (uint64_t)(0x3437F6BB0B5FEF99), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0x0000000000002086), (uint64_t)(0x02C73B074640CFAC), (uint64_t)(0x1E76BBF99EDE2616), (int)__LINE__, _result);

  // 6666666666688888888888888444444444411111111199999977777777777722222222233333 / 8888888555555555444444111111222222222
  cout << "Case : 6666666666688888888888888444444444411111111199999977777777777722222222233333 / " << endl;
  cout << "       8888888555555555444444111111222222222" << endl;
  i.from_string("6666666666688888888888888444444444411111111199999977777777777722222222233333");
  j.from_string("8888888555555555444444111111222222222");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0x0000000000000002), (uint64_t)(0x343CC051ABCE50E4), (uint64_t)(0x9C426A6074892191), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x056DA4E841A585DB), (uint64_t)(0x4DDD85AAA2998387), (int)__LINE__, _result);

  // 7897897894564564561231231324897664841313516848487456151561848755133115158 / 784523322266655412987456632114568
  cout << "Case : 7897897894564564561231231324897664841313516848487456151561848755133115158 / " << endl;
  cout << "       784523322266655412987456632114568" << endl;
  i.from_string("7897897894564564561231231324897664841313516848487456151561848755133115158");
  j.from_string("784523322266655412987456632114568");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0x000000000000001D), (uint64_t)(0x95AA9E7F5391428C), (uint64_t)(0x87731D29AF89DA2F), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x000012C92342A4B7), (uint64_t)(0x90CC4C0CF587DF1E), (int)__LINE__, _result);

  // 7897897894564564561231231324897664841313516848487456151561848755133115158 / 78452332226665541298745663211445245436435435354545378568
  cout << "Case : 7897897894564564561231231324897664841313516848487456151561848755133115158 / " << endl;
  cout << "       78452332226665541298745663211445245436435435354545378568" << endl;
  i.from_string("7897897894564564561231231324897664841313516848487456151561848755133115158");
  j.from_string("78452332226665541298745663211445245436435435354545378568");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0165A80273D669B5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0x0037B35DA18103ED), (uint64_t)(0x13DA38F2043F8CF8), (uint64_t)(0xB39EF424835F846E), (int)__LINE__, _result);

  // 9999999999999999999999999999999999999999999999999999999999999999999999 / 555555555555555555555555555555555555555555555555555555
  cout << "Case : 9999999999999999999999999999999999999999999999999999999999999999999999 / " << endl;
  cout << "       555555555555555555555555555555555555555555555555555555" << endl;
  i.from_string("9999999999999999999999999999999999999999999999999999999999999999999999");
  j.from_string("555555555555555555555555555555555555555555555555555555");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x003FF2E795F50000), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x002386F26FC0FFFF), (int)__LINE__, _result);

  // 1111111111899999454444444444444444444444444444444444442222222299999999999 / 3333333333333
  cout << "Case : 1111111111899999454444444444444444444444444444444444442222222299999999999 / " << endl;
  cout << "       3333333333333" << endl;
  i.from_string("1111111111899999454444444444444444444444444444444444442222222299999999999");
  j.from_string("3333333333333");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x0000000000000035), (uint64_t)(0x1A6262A9D2EF2C1C), (uint64_t)(0x000643655C08141C), (uint64_t)(0x468EDC79735B08D8), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x000000247AB4F047), (int)__LINE__, _result);

  // 878787878446451687978513004456014086489485498740864006980406984780441321 / 33016854646849846046894516546894
  cout << "Case : 878787878446451687978513004456014086489485498740864006980406984780441321 / " << endl;
  cout << "       33016854646849846046894516546894" << endl;
  i.from_string("878787878446451687978513004456014086489485498740864006980406984780441321");
  j.from_string("33016854646849846046894516546894");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0x4E), (uint64_t)(0x37E8E8F3649AF1B2), (uint64_t)(0x1DE9E28B1BEF8397), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000018BEC7A0EB0), (uint64_t)(0x1AA686371459C3E7), (int)__LINE__, _result);

  // 878787878446451687978513004456014086489485498740864006980406984780441321 / 330168546
  cout << "Case : 878787878446451687978513004456014086489485498740864006980406984780441321 / " << endl;
  cout << "       330168546" << endl;
  i.from_string("878787878446451687978513004456014086489485498740864006980406984780441321");
  j.from_string("330168546");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0x67856), (uint64_t)(0xC8B6766034CAD242), (uint64_t)(0x7DC8ABDF4CEDE0CE), (uint64_t)(0x29A60456CDE5F44F), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB6D312B), (int)__LINE__, _result);

  // 12320101323121212032012012013015615615150151510650156510610513056001561 / 78978784874878484874889784
  cout << "Case : 12320101323121212032012012013015615615150151510650156510610513056001561 / " << endl;
  cout << "       78978784874878484874889784" << endl;
  i.from_string("12320101323121212032012012013015615615150151510650156510610513056001561");
  j.from_string("78978784874878484874889784");
  q.div_mod(i, j, r);
  check_value(q, (uint64_t)(0), (uint64_t)(0x6FEB4), (uint64_t)(0xE051AF2B1BC117DC), (uint64_t)(0x1A2F19046E9E8DF6), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BDFB), (uint64_t)(0xCF97C5669A3CC449), (int)__LINE__, _result);

  if (g_test_exception_div)
  {
    i.from_string("1919191919191919191919191919191919191919191919191919191919191919191919191937");
    j = 0;
    check_value(i, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC486781), (int)__LINE__, _result);
    q.div_mod(i, j, r);
    check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
    check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(18), (int)__LINE__, _result);
  }

  if (_result)
  {
    cout << "\ndiv_mod_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void division_modulo_operator_test()
{
  bool _result = true;
  BigInt i;
  BigInt j;
  BigInt q;
  BigInt r;

  cout << "\n==[[div_mod_operator_test]]==================================" << endl << endl;

  i = 1024;
  j = 32;
  cout << "Case : 1024 / 32 =  32 ... 0" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1024), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  i = 1025;
  j = 32;
  cout << "Case : 1025 / 32 =  32 ... 1" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1025), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  i = 1023;
  j = 32;
  cout << "Case : 1023 / 32 =  31 ... 31" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1023), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(31), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(31), (int)__LINE__, _result);

  // -5 / -2 =  2 ... -1
  cout << "Case : -5 / -2 =  2 ... -1" << endl;
  i = -5;
  j = -2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  //  5 / -2 = -2 ...  1
  cout << "Case : 5 / -2 = -2 ...  1" << endl;
  i = 5;
  j = -2;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)5, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -5 /  2 = -2 ... -1
  cout << "Case : -5 /  2 = -2 ... -1" << endl;
  i = -5;
  j = 2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -2 / -5 =  0 ... -2
  cout << "Case : -2 / -5 =  0 ... -2" << endl;
  i = -2;
  j = -5;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  //  2 / -5 =  0 ...  2
  cout << "Case : 2 / -5 =  0 ...  2" << endl;
  i = 2;
  j = -5;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -2 /  5 =  0 ... -2
  cout << "Case : -2 /  5 =  0 ... -2" << endl;
  i = -2;
  j = 5;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)5, (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 / -2 =  1 ...  0
  cout << "Case : -2 / -2 =  1 ...  0" << endl;
  i = -2;
  j = -2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  //  2 / -2 = -1 ...  0
  cout << "Case : 2 / -2 = -1 ...  0" << endl;
  i = 2;
  j = -2;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -2 /  2 = -1 ...  0
  cout << "Case : -2 /  2 = -1 ...  0" << endl;
  i = -2;
  j = 2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // max / 3
  cout << "Case : max / 3" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = 3;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x2AAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -max / 3
  cout << "Case : min / 3" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = 3;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xD555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555556), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // max / -3
  cout << "Case : max / -3" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = -3;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xD555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555556), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -max / -3
  cout << "Case : min / -3" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = -3;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x2AAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // max / 7
  cout << "Case : max / 7" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = 7;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x1249249249249249), (uint64_t)(0x2492492492492492), (uint64_t)(0x4924924924924924), (uint64_t)(0x9249249249249249), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max / 7
  cout << "Case : min / 7" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = 7;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xEDB6DB6DB6DB6DB6), (uint64_t)(0xDB6DB6DB6DB6DB6D), (uint64_t)(0xB6DB6DB6DB6DB6DB), (uint64_t)(0x6DB6DB6DB6DB6DB7), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max / -max = 0 ... max
  cout << "Case : max / -max = 0 ... max" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -max / max = -1 ... -1
  cout << "Case : -max / max = -1 ... -1" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max / max = 1 ... 0
  cout << "Case : max / max = 1 ... 0" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max / -max = 1 ... 0
  cout << "Case : -max / -max = 1 ... 0" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // max / 2^127 = 2^128-1 ... 2^127-1
  cout << "Case : max / 2^127 = 2^128-1 ... 2^127-1" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("170141183460469231731687303715884105728");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -max / 2^127 = -2^128 ... 0
  cout << "Case : min / 2^127 = -2^128 ... 0" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("170141183460469231731687303715884105728");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 7070... / 7
  cout << "Case : 7070...07 / 7 = 1010...01 ... 0" << endl;
  i.from_string("707070707070707070707070707070707070707070707070707070707070707070707070707");
  j = 7;
  check_value(i, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)(0x31219DBCC48676F3), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 7070...4 / 7
  cout << "Case : 7070...11 / 7 = 1010...01 ... 4" << endl;
  i.from_string("707070707070707070707070707070707070707070707070707070707070707070707070711");
  j = 7;
  check_value(i, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)0x31219DBCC48676F7, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(4), (int)__LINE__, _result);

  // 1313... / 13
  cout << "Case : 1313...13 / 13 = 1010...01 ... 0" << endl;
  i.from_string("1313131313131313131313131313131313131313131313131313131313131313131313131313");
  j = 13;
  check_value(i, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)(0x1219DBCC48676F31), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1313...8 / 13
  cout << "Case : 1313...21 / 13 = 1010...01 ... 8" << endl;
  i.from_string("1313131313131313131313131313131313131313131313131313131313131313131313131321");
  j = 13;
  check_value(i, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)0x1219DBCC48676F39, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(8), (int)__LINE__, _result);

  // 1919... / 19
  cout << "Case : 1919...19 / 19 = 1010...01 ... 0" << endl;
  i.from_string("1919191919191919191919191919191919191919191919191919191919191919191919191919");
  j = 19;
  check_value(i, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC48676F), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1919...18 / 19
  cout << "Case : 1919...37 / 19 = 1010...01 ... 18" << endl;
  i.from_string("1919191919191919191919191919191919191919191919191919191919191919191919191937");
  j = 19;
  check_value(i, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC486781), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(18), (int)__LINE__, _result);

  // max / 100000000000000
  cout << "Case : max / 100000000000000" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("100000000000000");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x5AF3107A4000), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x16849), (uint64_t)(0xB86A12B9B01EA709), (uint64_t)(0x09833DE71928DB21), (uint64_t)(0x38E9F98E67D007F0), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3956564819967), (int)__LINE__, _result);

  // (max / 100000000000000) / 100000000000000
  cout << "Case : (max / 100000000000000) / 100000000000000" << endl;
  i.from_string("578960446186580977117854925043439539266349923328202820197287920");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0x16849), (uint64_t)(0xB86A12B9B01EA709), (uint64_t)(0x09833DE71928DB21), (uint64_t)(0x38E9F98E67D007F0), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0x3F61ED7CA), (uint64_t)(0x0C0328362F2A75B8), (uint64_t)(0x62214FF1DB72D802), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2820197287920), (int)__LINE__, _result);

  // ((max / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : ((max / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("5789604461865809771178549250434395392663499233282");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0x3F61ED7CA), (uint64_t)(0x0C0328362F2A75B8), (uint64_t)(0x62214FF1DB72D802), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB267ED1940F1C), (uint64_t)(0x61C55F038B237591), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(92663499233282), (int)__LINE__, _result);

  // (((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : (((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("57896044618658097711785492504343953");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB267ED1940F1C), (uint64_t)(0x61C55F038B237591), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1F), (uint64_t)(0x62B0B257C0D1A5DD), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(85492504343953), (int)__LINE__, _result);

  // ((((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : ((((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("578960446186580977117");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1F), (uint64_t)(0x62B0B257C0D1A5DD), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(5789604), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(46186580977117), (int)__LINE__, _result);

  // max / 77777777777777
  cout << "Case : max / 77777777777777" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("77777777777777");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x1CF3A), (uint64_t)(0x363F3CAAB12A7E7D), (uint64_t)(0x1BBB227F8F04E940), (uint64_t)(0x0D14071A4ADE219A), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(31119352451845), (int)__LINE__, _result);

  // (max / 77777777777777) / 77777777777777
  cout << "Case : (max / 77777777777777) / 77777777777777" << endl;
  i.from_string("744377716525611557214407302599994408844047329937492066441240986");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0x1CF3A), (uint64_t)(0x363F3CAAB12A7E7D), (uint64_t)(0x1BBB227F8F04E940), (uint64_t)(0x0D14071A4ADE219A), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0x68C673AEA), (uint64_t)(0xBB2F4ECDD3D6E044), (uint64_t)(0x66641DD153516E4C), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(71096126874126), (int)__LINE__, _result);

  // ((max / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : ((max / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("9570570641043672869891647184442912744466738671180");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0x68C673AEA), (uint64_t)(0xBB2F4ECDD3D6E044), (uint64_t)(0x66641DD153516E4C), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x17B2D7CC5B85A7), (uint64_t)(0xE407E181B4E33171), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(25042959957867), (int)__LINE__, _result);

  // (((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : (((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("123050193956277024543403597998797169");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x17B2D7CC5B85A7), (uint64_t)(0xE407E181B4E33171), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x55), (uint64_t)(0xC3AFAA23F2CA87E9), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(20938559125400), (int)__LINE__, _result);

  // ((((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : ((((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("1582073922295006136297");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x55), (uint64_t)(0xC3AFAA23F2CA87E9), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(20340950), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(33406133068147), (int)__LINE__, _result);

  // max / 3333333333333333
  cout << "Case : max / 3333333333333333" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("3333333333333333");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xACF), (uint64_t)(0x02F8F133A6DE29FD), (uint64_t)(0xB1E6DB4C6B12D53D), (uint64_t)(0xBEABA6B1F820779E), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(162358756430473), (int)__LINE__, _result);

  // (max / 3333333333333333) / 3333333333333333
  cout << "Case : (max / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("17368813385597431050416986311046291219689128804475206574831518");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0xACF), (uint64_t)(0x02F8F133A6DE29FD), (uint64_t)(0xB1E6DB4C6B12D53D), (uint64_t)(0xBEABA6B1F820779E), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0xE9A742), (uint64_t)(0x82EDE0D4790197BE), (uint64_t)(0x864457E83EABBB9D), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(98868193659773), (int)__LINE__, _result);

  // ((max / 3333333333333333) / 3333333333333333) / 3333333333333333
  cout << "Case : ((max / 3333333333333333) / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("5210644015679229836189497461236870984856484765");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0), (uint64_t)(0xE9A742), (uint64_t)(0x82EDE0D4790197BE), (uint64_t)(0x864457E83EABBB9D), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BAF31CD3), (uint64_t)(0xB8600EEFC9E89CCB), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3240043579721014), (int)__LINE__, _result);

  // (((max / 3333333333333333) / 3333333333333333) / 3333333333333333) / 3333333333333333
  cout << "Case : (((max / 3333333333333333) / 3333333333333333) / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("1563193204703769107176169708747");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BAF31CD3), (uint64_t)(0xB8600EEFC9E89CCB), (int)__LINE__, _result);
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1AA83C8B45A3A), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2596828823512457), (int)__LINE__, _result);

  // 5......5 / 3......3
  cout << "Case : 5......5 / 3......3" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // 5......5 / 2......2
  cout << "Case : 5......5 / 2......2" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / 3......3
  cout << "Case : 4......4 / 3......3" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / 2......2
  cout << "Case : 4......4 / 2......2" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 5......5 / -3......3
  cout << "Case : 5......5 / -3......3" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // 5......5 / -2......2
  cout << "Case : 5......5 / -2......2" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / -3......3
  cout << "Case : 4......4 / -3......3" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / -2......2
  cout << "Case : 4......4 / -2......2" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1C9EDE81B7E), (uint64_t)(0x430DBE4679DDC581), (uint64_t)(0x64D68830A2802734), (uint64_t)(0xD29394146250858F), (int)__LINE__, _result);

  // -876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : -876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFE361217E481), (uint64_t)(0xBCF241B986223A7E), (uint64_t)(0x9B2977CF5D7FD8CB), (uint64_t)(0x2D6C6BEB9DAF7A71), (int)__LINE__, _result);

  // 876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFF9), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0x1C9EDE81B7E), (uint64_t)(0x430DBE4679DDC581), (uint64_t)(0x64D68830A2802734), (uint64_t)(0xD29394146250858F), (int)__LINE__, _result);

  // -876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : -876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFF9), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0xFFFFFE361217E481), (uint64_t)(0xBCF241B986223A7E), (uint64_t)(0x9B2977CF5D7FD8CB), (uint64_t)(0x2D6C6BEB9DAF7A71), (int)__LINE__, _result);

  // 45646484978879789878784164168798787987879874498498555555555555555555 / 516561516484814184881456154661544444444444444444444444777
  cout << "Case : 45646484978879789878784164168798787987879874498498555555555555555555 / " << endl;
  cout << "       516561516484814184881456154661544444444444444444444444777" << endl;
  i.from_string("45646484978879789878784164168798787987879874498498555555555555555555");
  j.from_string("516561516484814184881456154661544444444444444444444444777");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000001493067338), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0x64A9794005D7C6F), (uint64_t)(0x4DAB91911C1994C5), (uint64_t)(0x0CA7AFF0584936EB), (int)__LINE__, _result);

  // 9999999999999999944444444444222222222288888888888777777777711111111115555555 / 4444444444111111111122222222266666333333333
  cout << "Case : 9999999999999999944444444444222222222288888888888777777777711111111115555555 / " << endl;
  cout << "       4444444444111111111122222222266666333333333" << endl;
  i.from_string("9999999999999999944444444444222222222288888888888777777777711111111115555555");
  j.from_string("4444444444111111111122222222266666333333333");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00006EEEFE1A6247), (uint64_t)(0x3437F6BB0B5FEF99), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0x0000000000002086), (uint64_t)(0x02C73B074640CFAC), (uint64_t)(0x1E76BBF99EDE2616), (int)__LINE__, _result);

  // 6666666666688888888888888444444444411111111199999977777777777722222222233333 / 8888888555555555444444111111222222222
  cout << "Case : 6666666666688888888888888444444444411111111199999977777777777722222222233333 / " << endl;
  cout << "       8888888555555555444444111111222222222" << endl;
  i.from_string("6666666666688888888888888444444444411111111199999977777777777722222222233333");
  j.from_string("8888888555555555444444111111222222222");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0x0000000000000002), (uint64_t)(0x343CC051ABCE50E4), (uint64_t)(0x9C426A6074892191), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x056DA4E841A585DB), (uint64_t)(0x4DDD85AAA2998387), (int)__LINE__, _result);

  // 7897897894564564561231231324897664841313516848487456151561848755133115158 / 784523322266655412987456632114568
  cout << "Case : 7897897894564564561231231324897664841313516848487456151561848755133115158 / " << endl;
  cout << "       784523322266655412987456632114568" << endl;
  i.from_string("7897897894564564561231231324897664841313516848487456151561848755133115158");
  j.from_string("784523322266655412987456632114568");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0x000000000000001D), (uint64_t)(0x95AA9E7F5391428C), (uint64_t)(0x87731D29AF89DA2F), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x000012C92342A4B7), (uint64_t)(0x90CC4C0CF587DF1E), (int)__LINE__, _result);

  // 7897897894564564561231231324897664841313516848487456151561848755133115158 / 78452332226665541298745663211445245436435435354545378568
  cout << "Case : 7897897894564564561231231324897664841313516848487456151561848755133115158 / " << endl;
  cout << "       78452332226665541298745663211445245436435435354545378568" << endl;
  i.from_string("7897897894564564561231231324897664841313516848487456151561848755133115158");
  j.from_string("78452332226665541298745663211445245436435435354545378568");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0165A80273D669B5), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0x0037B35DA18103ED), (uint64_t)(0x13DA38F2043F8CF8), (uint64_t)(0xB39EF424835F846E), (int)__LINE__, _result);

  // 9999999999999999999999999999999999999999999999999999999999999999999999 / 555555555555555555555555555555555555555555555555555555
  cout << "Case : 9999999999999999999999999999999999999999999999999999999999999999999999 / " << endl;
  cout << "       555555555555555555555555555555555555555555555555555555" << endl;
  i.from_string("9999999999999999999999999999999999999999999999999999999999999999999999");
  j.from_string("555555555555555555555555555555555555555555555555555555");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x003FF2E795F50000), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x002386F26FC0FFFF), (int)__LINE__, _result);

  // 1111111111899999454444444444444444444444444444444444442222222299999999999 / 3333333333333
  cout << "Case : 1111111111899999454444444444444444444444444444444444442222222299999999999 / " << endl;
  cout << "       3333333333333" << endl;
  i.from_string("1111111111899999454444444444444444444444444444444444442222222299999999999");
  j.from_string("3333333333333");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x0000000000000035), (uint64_t)(0x1A6262A9D2EF2C1C), (uint64_t)(0x000643655C08141C), (uint64_t)(0x468EDC79735B08D8), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x000000247AB4F047), (int)__LINE__, _result);

  // 878787878446451687978513004456014086489485498740864006980406984780441321 / 33016854646849846046894516546894
  cout << "Case : 878787878446451687978513004456014086489485498740864006980406984780441321 / " << endl;
  cout << "       33016854646849846046894516546894" << endl;
  i.from_string("878787878446451687978513004456014086489485498740864006980406984780441321");
  j.from_string("33016854646849846046894516546894");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0x4E), (uint64_t)(0x37E8E8F3649AF1B2), (uint64_t)(0x1DE9E28B1BEF8397), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000018BEC7A0EB0), (uint64_t)(0x1AA686371459C3E7), (int)__LINE__, _result);

  // 878787878446451687978513004456014086489485498740864006980406984780441321 / 330168546
  cout << "Case : 878787878446451687978513004456014086489485498740864006980406984780441321 / " << endl;
  cout << "       330168546" << endl;
  i.from_string("878787878446451687978513004456014086489485498740864006980406984780441321");
  j.from_string("330168546");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0x67856), (uint64_t)(0xC8B6766034CAD242), (uint64_t)(0x7DC8ABDF4CEDE0CE), (uint64_t)(0x29A60456CDE5F44F), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB6D312B), (int)__LINE__, _result);

  // 12320101323121212032012012013015615615150151510650156510610513056001561 / 78978784874878484874889784
  cout << "Case : 12320101323121212032012012013015615615150151510650156510610513056001561 / " << endl;
  cout << "       78978784874878484874889784" << endl;
  i.from_string("12320101323121212032012012013015615615150151510650156510610513056001561");
  j.from_string("78978784874878484874889784");
  q = i/j;
  r = i%j;
  check_value(q, (uint64_t)(0), (uint64_t)(0x6FEB4), (uint64_t)(0xE051AF2B1BC117DC), (uint64_t)(0x1A2F19046E9E8DF6), (int)__LINE__, _result);
  check_value(r, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BDFB), (uint64_t)(0xCF97C5669A3CC449), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\ndiv_mod_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void division_assignment_operator_test()
{
  bool _result = true;
  BigInt i;
  BigInt j;

  cout << "\n==[[division_assignment_operator(/=)_test]]==================================" << endl << endl;

  i = 1024;
  j = 32;
  cout << "Case : 1024 / 32 =  32 ... 0" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1024), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);

  i = 1025;
  j = 32;
  cout << "Case : 1025 / 32 =  32 ... 1" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1025), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);

  i = 1023;
  j = 32;
  cout << "Case : 1023 / 32 =  31 ... 31" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1023), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(31), (int)__LINE__, _result);

  // -5 / -2 =  2 ... -1
  cout << "Case : -5 / -2 =  2 ... -1" << endl;
  i = -5;
  j = -2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  //  5 / -2 = -2 ...  1
  cout << "Case : 5 / -2 = -2 ...  1" << endl;
  i = 5;
  j = -2;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)5, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -5 /  2 = -2 ... -1
  cout << "Case : -5 /  2 = -2 ... -1" << endl;
  i = -5;
  j = 2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 / -5 =  0 ... -2
  cout << "Case : -2 / -5 =  0 ... -2" << endl;
  i = -2;
  j = -5;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  //  2 / -5 =  0 ...  2
  cout << "Case : 2 / -5 =  0 ...  2" << endl;
  i = 2;
  j = -5;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -2 /  5 =  0 ... -2
  cout << "Case : -2 /  5 =  0 ... -2" << endl;
  i = -2;
  j = 5;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)5, (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -2 / -2 =  1 ...  0
  cout << "Case : -2 / -2 =  1 ...  0" << endl;
  i = -2;
  j = -2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  //  2 / -2 = -1 ...  0
  cout << "Case : 2 / -2 = -1 ...  0" << endl;
  i = 2;
  j = -2;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -2 /  2 = -1 ...  0
  cout << "Case : -2 /  2 = -1 ...  0" << endl;
  i = -2;
  j = 2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max / 3
  cout << "Case : max / 3" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = 3;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x2AAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  // -max / 3
  cout << "Case : min / 3" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = 3;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xD555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555556), (int)__LINE__, _result);

  // max / -3
  cout << "Case : max / -3" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = -3;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xD555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555556), (int)__LINE__, _result);

  // -max / -3
  cout << "Case : min / -3" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = -3;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x2AAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  // max / 7
  cout << "Case : max / 7" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = 7;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x1249249249249249), (uint64_t)(0x2492492492492492), (uint64_t)(0x4924924924924924), (uint64_t)(0x9249249249249249), (int)__LINE__, _result);

  // -max / 7
  cout << "Case : min / 7" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = 7;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xEDB6DB6DB6DB6DB6), (uint64_t)(0xDB6DB6DB6DB6DB6D), (uint64_t)(0xB6DB6DB6DB6DB6DB), (uint64_t)(0x6DB6DB6DB6DB6DB7), (int)__LINE__, _result);

  // max / -max = 0 ... max
  cout << "Case : max / -max = 0 ... max" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max / max = -1 ... -1
  cout << "Case : -max / max = -1 ... -1" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max / max = 1 ... 0
  cout << "Case : max / max = 1 ... 0" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -max / -max = 1 ... 0
  cout << "Case : -max / -max = 1 ... 0" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // max / 2^127 = 2^128-1 ... 2^127-1
  cout << "Case : max / 2^127 = 2^128-1 ... 2^127-1" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("170141183460469231731687303715884105728");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -max / 2^127 = -2^128 ... 0
  cout << "Case : min / 2^127 = -2^128 ... 0" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("170141183460469231731687303715884105728");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 7070... / 7
  cout << "Case : 7070...07 / 7 = 1010...01 ... 0" << endl;
  i.from_string("707070707070707070707070707070707070707070707070707070707070707070707070707");
  j = 7;
  check_value(i, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)(0x31219DBCC48676F3), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);

  // 7070...4 / 7
  cout << "Case : 7070...11 / 7 = 1010...01 ... 4" << endl;
  i.from_string("707070707070707070707070707070707070707070707070707070707070707070707070711");
  j = 7;
  check_value(i, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)0x31219DBCC48676F7, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);

  // 1313... / 13
  cout << "Case : 1313...13 / 13 = 1010...01 ... 0" << endl;
  i.from_string("1313131313131313131313131313131313131313131313131313131313131313131313131313");
  j = 13;
  check_value(i, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)(0x1219DBCC48676F31), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);

  // 1313...8 / 13
  cout << "Case : 1313...21 / 13 = 1010...01 ... 8" << endl;
  i.from_string("1313131313131313131313131313131313131313131313131313131313131313131313131321");
  j = 13;
  check_value(i, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)0x1219DBCC48676F39, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);

  // 1919... / 19
  cout << "Case : 1919...19 / 19 = 1010...01 ... 0" << endl;
  i.from_string("1919191919191919191919191919191919191919191919191919191919191919191919191919");
  j = 19;
  check_value(i, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC48676F), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);

  // 1919...18 / 19
  cout << "Case : 1919...37 / 19 = 1010...01 ... 18" << endl;
  i.from_string("1919191919191919191919191919191919191919191919191919191919191919191919191937");
  j = 19;
  check_value(i, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC486781), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x00392B70E125BF92), (uint64_t)(0xA2FBD87383A3EE51), (uint64_t)(0x6378234AD7C607EB), (uint64_t)(0x50295FAD40A57EB5), (int)__LINE__, _result);

  // max / 100000000000000
  cout << "Case : max / 100000000000000" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("100000000000000");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x5AF3107A4000), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x16849), (uint64_t)(0xB86A12B9B01EA709), (uint64_t)(0x09833DE71928DB21), (uint64_t)(0x38E9F98E67D007F0), (int)__LINE__, _result);

  // (max / 100000000000000) / 100000000000000
  cout << "Case : (max / 100000000000000) / 100000000000000" << endl;
  i.from_string("578960446186580977117854925043439539266349923328202820197287920");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0x16849), (uint64_t)(0xB86A12B9B01EA709), (uint64_t)(0x09833DE71928DB21), (uint64_t)(0x38E9F98E67D007F0), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0x3F61ED7CA), (uint64_t)(0x0C0328362F2A75B8), (uint64_t)(0x62214FF1DB72D802), (int)__LINE__, _result);

  // ((max / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : ((max / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("5789604461865809771178549250434395392663499233282");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0x3F61ED7CA), (uint64_t)(0x0C0328362F2A75B8), (uint64_t)(0x62214FF1DB72D802), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB267ED1940F1C), (uint64_t)(0x61C55F038B237591), (int)__LINE__, _result);

  // (((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : (((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("57896044618658097711785492504343953");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB267ED1940F1C), (uint64_t)(0x61C55F038B237591), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1F), (uint64_t)(0x62B0B257C0D1A5DD), (int)__LINE__, _result);

  // ((((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : ((((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("578960446186580977117");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1F), (uint64_t)(0x62B0B257C0D1A5DD), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(5789604), (int)__LINE__, _result);

  // max / 77777777777777
  cout << "Case : max / 77777777777777" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("77777777777777");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0x1CF3A), (uint64_t)(0x363F3CAAB12A7E7D), (uint64_t)(0x1BBB227F8F04E940), (uint64_t)(0x0D14071A4ADE219A), (int)__LINE__, _result);

  // (max / 77777777777777) / 77777777777777
  cout << "Case : (max / 77777777777777) / 77777777777777" << endl;
  i.from_string("744377716525611557214407302599994408844047329937492066441240986");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0x1CF3A), (uint64_t)(0x363F3CAAB12A7E7D), (uint64_t)(0x1BBB227F8F04E940), (uint64_t)(0x0D14071A4ADE219A), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0x68C673AEA), (uint64_t)(0xBB2F4ECDD3D6E044), (uint64_t)(0x66641DD153516E4C), (int)__LINE__, _result);

  // ((max / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : ((max / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("9570570641043672869891647184442912744466738671180");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0x68C673AEA), (uint64_t)(0xBB2F4ECDD3D6E044), (uint64_t)(0x66641DD153516E4C), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x17B2D7CC5B85A7), (uint64_t)(0xE407E181B4E33171), (int)__LINE__, _result);

  // (((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : (((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("123050193956277024543403597998797169");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x17B2D7CC5B85A7), (uint64_t)(0xE407E181B4E33171), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x55), (uint64_t)(0xC3AFAA23F2CA87E9), (int)__LINE__, _result);

  // ((((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : ((((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("1582073922295006136297");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x55), (uint64_t)(0xC3AFAA23F2CA87E9), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(20340950), (int)__LINE__, _result);

  // max / 3333333333333333
  cout << "Case : max / 3333333333333333" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("3333333333333333");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0xACF), (uint64_t)(0x02F8F133A6DE29FD), (uint64_t)(0xB1E6DB4C6B12D53D), (uint64_t)(0xBEABA6B1F820779E), (int)__LINE__, _result);

  // (max / 3333333333333333) / 3333333333333333
  cout << "Case : (max / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("17368813385597431050416986311046291219689128804475206574831518");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0xACF), (uint64_t)(0x02F8F133A6DE29FD), (uint64_t)(0xB1E6DB4C6B12D53D), (uint64_t)(0xBEABA6B1F820779E), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0xE9A742), (uint64_t)(0x82EDE0D4790197BE), (uint64_t)(0x864457E83EABBB9D), (int)__LINE__, _result);

  // ((max / 3333333333333333) / 3333333333333333) / 3333333333333333
  cout << "Case : ((max / 3333333333333333) / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("5210644015679229836189497461236870984856484765");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0), (uint64_t)(0xE9A742), (uint64_t)(0x82EDE0D4790197BE), (uint64_t)(0x864457E83EABBB9D), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BAF31CD3), (uint64_t)(0xB8600EEFC9E89CCB), (int)__LINE__, _result);

  // (((max / 3333333333333333) / 3333333333333333) / 3333333333333333) / 3333333333333333
  cout << "Case : (((max / 3333333333333333) / 3333333333333333) / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("1563193204703769107176169708747");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BAF31CD3), (uint64_t)(0xB8600EEFC9E89CCB), (int)__LINE__, _result);
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1AA83C8B45A3A), (int)__LINE__, _result);

  // 5......5 / 3......3
  cout << "Case : 5......5 / 3......3" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 5......5 / 2......2
  cout << "Case : 5......5 / 2......2" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // 4......4 / 3......3
  cout << "Case : 4......4 / 3......3" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // 4......4 / 2......2
  cout << "Case : 4......4 / 2......2" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // 5......5 / -3......3
  cout << "Case : 5......5 / -3......3" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 5......5 / -2......2
  cout << "Case : 5......5 / -2......2" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // 4......4 / -3......3
  cout << "Case : 4......4 / -3......3" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // 4......4 / -2......2
  cout << "Case : 4......4 / -2......2" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // 876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);

  // -876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : -876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);

  // 876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  i /= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFF9), (int)__LINE__, _result);

  // -876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : -876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  i /= j;;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFF9), (int)__LINE__, _result);

  // 45646484978879789878784164168798787987879874498498555555555555555555 / 516561516484814184881456154661544444444444444444444444777
  cout << "Case : 45646484978879789878784164168798787987879874498498555555555555555555 / " << endl;
  cout << "       516561516484814184881456154661544444444444444444444444777" << endl;
  i.from_string("45646484978879789878784164168798787987879874498498555555555555555555");
  j.from_string("516561516484814184881456154661544444444444444444444444777");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000001493067338), (int)__LINE__, _result);

  // 9999999999999999944444444444222222222288888888888777777777711111111115555555 / 4444444444111111111122222222266666333333333
  cout << "Case : 9999999999999999944444444444222222222288888888888777777777711111111115555555 / " << endl;
  cout << "       4444444444111111111122222222266666333333333" << endl;
  i.from_string("9999999999999999944444444444222222222288888888888777777777711111111115555555");
  j.from_string("4444444444111111111122222222266666333333333");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00006EEEFE1A6247), (uint64_t)(0x3437F6BB0B5FEF99), (int)__LINE__, _result);

  // 6666666666688888888888888444444444411111111199999977777777777722222222233333 / 8888888555555555444444111111222222222
  cout << "Case : 6666666666688888888888888444444444411111111199999977777777777722222222233333 / " << endl;
  cout << "       8888888555555555444444111111222222222" << endl;
  i.from_string("6666666666688888888888888444444444411111111199999977777777777722222222233333");
  j.from_string("8888888555555555444444111111222222222");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0x0000000000000002), (uint64_t)(0x343CC051ABCE50E4), (uint64_t)(0x9C426A6074892191), (int)__LINE__, _result);

  // 7897897894564564561231231324897664841313516848487456151561848755133115158 / 784523322266655412987456632114568
  cout << "Case : 7897897894564564561231231324897664841313516848487456151561848755133115158 / " << endl;
  cout << "       784523322266655412987456632114568" << endl;
  i.from_string("7897897894564564561231231324897664841313516848487456151561848755133115158");
  j.from_string("784523322266655412987456632114568");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0x000000000000001D), (uint64_t)(0x95AA9E7F5391428C), (uint64_t)(0x87731D29AF89DA2F), (int)__LINE__, _result);

  // 7897897894564564561231231324897664841313516848487456151561848755133115158 / 78452332226665541298745663211445245436435435354545378568
  cout << "Case : 7897897894564564561231231324897664841313516848487456151561848755133115158 / " << endl;
  cout << "       78452332226665541298745663211445245436435435354545378568" << endl;
  i.from_string("7897897894564564561231231324897664841313516848487456151561848755133115158");
  j.from_string("78452332226665541298745663211445245436435435354545378568");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0165A80273D669B5), (int)__LINE__, _result);

  // 9999999999999999999999999999999999999999999999999999999999999999999999 / 555555555555555555555555555555555555555555555555555555
  cout << "Case : 9999999999999999999999999999999999999999999999999999999999999999999999 / " << endl;
  cout << "       555555555555555555555555555555555555555555555555555555" << endl;
  i.from_string("9999999999999999999999999999999999999999999999999999999999999999999999");
  j.from_string("555555555555555555555555555555555555555555555555555555");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x003FF2E795F50000), (int)__LINE__, _result);

  // 1111111111899999454444444444444444444444444444444444442222222299999999999 / 3333333333333
  cout << "Case : 1111111111899999454444444444444444444444444444444444442222222299999999999 / " << endl;
  cout << "       3333333333333" << endl;
  i.from_string("1111111111899999454444444444444444444444444444444444442222222299999999999");
  j.from_string("3333333333333");
  i /= j;
  check_value(i, (uint64_t)(0x0000000000000035), (uint64_t)(0x1A6262A9D2EF2C1C), (uint64_t)(0x000643655C08141C), (uint64_t)(0x468EDC79735B08D8), (int)__LINE__, _result);

  // 878787878446451687978513004456014086489485498740864006980406984780441321 / 33016854646849846046894516546894
  cout << "Case : 878787878446451687978513004456014086489485498740864006980406984780441321 / " << endl;
  cout << "       33016854646849846046894516546894" << endl;
  i.from_string("878787878446451687978513004456014086489485498740864006980406984780441321");
  j.from_string("33016854646849846046894516546894");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0x4E), (uint64_t)(0x37E8E8F3649AF1B2), (uint64_t)(0x1DE9E28B1BEF8397), (int)__LINE__, _result);

  // 878787878446451687978513004456014086489485498740864006980406984780441321 / 330168546
  cout << "Case : 878787878446451687978513004456014086489485498740864006980406984780441321 / " << endl;
  cout << "       330168546" << endl;
  i.from_string("878787878446451687978513004456014086489485498740864006980406984780441321");
  j.from_string("330168546");
  i /= j;
  check_value(i, (uint64_t)(0x67856), (uint64_t)(0xC8B6766034CAD242), (uint64_t)(0x7DC8ABDF4CEDE0CE), (uint64_t)(0x29A60456CDE5F44F), (int)__LINE__, _result);

  // 12320101323121212032012012013015615615150151510650156510610513056001561 / 78978784874878484874889784
  cout << "Case : 12320101323121212032012012013015615615150151510650156510610513056001561 / " << endl;
  cout << "       78978784874878484874889784" << endl;
  i.from_string("12320101323121212032012012013015615615150151510650156510610513056001561");
  j.from_string("78978784874878484874889784");
  i /= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0x6FEB4), (uint64_t)(0xE051AF2B1BC117DC), (uint64_t)(0x1A2F19046E9E8DF6), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\ndivision_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void modulo_assignment_operator_test()
{
  bool _result = true;
  BigInt i;
  BigInt j;

  cout << "\n==[[modulo_assignment_operator(%=)_test]]==================================" << endl << endl;

  i = 1024;
  j = 32;
  cout << "Case : 1024 / 32 =  32 ... 0" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1024), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  i = 1025;
  j = 32;
  cout << "Case : 1025 / 32 =  32 ... 1" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1025), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  i = 1023;
  j = 32;
  cout << "Case : 1023 / 32 =  31 ... 31" << endl;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1023), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(32), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(31), (int)__LINE__, _result);

  // -5 / -2 =  2 ... -1
  cout << "Case : -5 / -2 =  2 ... -1" << endl;
  i = -5;
  j = -2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  //  5 / -2 = -2 ...  1
  cout << "Case : 5 / -2 = -2 ...  1" << endl;
  i = 5;
  j = -2;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)5, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -5 /  2 = -2 ... -1
  cout << "Case : -5 /  2 = -2 ... -1" << endl;
  i = -5;
  j = 2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -2 / -5 =  0 ... -2
  cout << "Case : -2 / -5 =  0 ... -2" << endl;
  i = -2;
  j = -5;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  //  2 / -5 =  0 ...  2
  cout << "Case : 2 / -5 =  0 ...  2" << endl;
  i = 2;
  j = -5;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFB), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  // -2 /  5 =  0 ... -2
  cout << "Case : -2 /  5 =  0 ... -2" << endl;
  i = -2;
  j = 5;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)5, (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // -2 / -2 =  1 ...  0
  cout << "Case : -2 / -2 =  1 ...  0" << endl;
  i = -2;
  j = -2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  //  2 / -2 = -1 ...  0
  cout << "Case : 2 / -2 = -1 ...  0" << endl;
  i = 2;
  j = -2;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -2 /  2 = -1 ...  0
  cout << "Case : -2 /  2 = -1 ...  0" << endl;
  i = -2;
  j = 2;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // max / 3
  cout << "Case : max / 3" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = 3;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -max / 3
  cout << "Case : min / 3" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = 3;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // max / -3
  cout << "Case : max / -3" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = -3;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  // -max / -3
  cout << "Case : min / -3" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = -3;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  // max / 7
  cout << "Case : max / 7" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j = 7;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max / 7
  cout << "Case : min / 7" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j = 7;
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max / -max = 0 ... max
  cout << "Case : max / -max = 0 ... max" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -max / max = -1 ... -1
  cout << "Case : -max / max = -1 ... -1" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // max / max = 1 ... 0
  cout << "Case : max / max = 1 ... 0" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // -max / -max = 1 ... 0
  cout << "Case : -max / -max = 1 ... 0" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // max / 2^127 = 2^128-1 ... 2^127-1
  cout << "Case : max / 2^127 = 2^128-1 ... 2^127-1" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("170141183460469231731687303715884105728");
  check_value(i, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  // -max / 2^127 = -2^128 ... 0
  cout << "Case : min / 2^127 = -2^128 ... 0" << endl;
  i.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  j.from_string("170141183460469231731687303715884105728");
  check_value(i, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 7070... / 7
  cout << "Case : 7070...07 / 7 = 1010...01 ... 0" << endl;
  i.from_string("707070707070707070707070707070707070707070707070707070707070707070707070707");
  j = 7;
  check_value(i, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)(0x31219DBCC48676F3), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 7070...4 / 7
  cout << "Case : 7070...11 / 7 = 1010...01 ... 4" << endl;
  i.from_string("707070707070707070707070707070707070707070707070707070707070707070707070711");
  j = 7;
  check_value(i, (uint64_t)(0x0190301628083D02), (uint64_t)(0x74E2EB28997B8439), (uint64_t)(0xB848F70BE66A376F), (uint64_t)0x31219DBCC48676F7, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(7), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(4), (int)__LINE__, _result);

  // 1313... / 13
  cout << "Case : 1313...13 / 13 = 1010...01 ... 0" << endl;
  i.from_string("1313131313131313131313131313131313131313131313131313131313131313131313131313");
  j = 13;
  check_value(i, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)(0x1219DBCC48676F31), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1313...8 / 13
  cout << "Case : 1313...21 / 13 = 1010...01 ... 8" << endl;
  i.from_string("1313131313131313131313131313131313131313131313131313131313131313131313131321");
  j = 13;
  check_value(i, (uint64_t)(0x02E734BB6EEABA72), (uint64_t)(0x46C9FDDDAF531A22), (uint64_t)(0x0D19CACCF50E66F3), (uint64_t)0x1219DBCC48676F39, (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(13), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(8), (int)__LINE__, _result);

  // 1919... / 19
  cout << "Case : 1919...19 / 19 = 1010...01 ... 0" << endl;
  i.from_string("1919191919191919191919191919191919191919191919191919191919191919191919191919");
  j = 19;
  check_value(i, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC48676F), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 1919...18 / 19
  cout << "Case : 1919...37 / 19 = 1010...01 ... 18" << endl;
  i.from_string("1919191919191919191919191919191919191919191919191919191919191919191919191937");
  j = 19;
  check_value(i, (uint64_t)(0x043E3960B5CD37E2), (uint64_t)(0x18B11092C52AB00A), (uint64_t)(0x61EA9E8E03B29676), (uint64_t)(0xF31219DBCC486781), (int)__LINE__, _result);
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(19), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(18), (int)__LINE__, _result);

  // max / 100000000000000
  cout << "Case : max / 100000000000000" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("100000000000000");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x5AF3107A4000), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3956564819967), (int)__LINE__, _result);

  // (max / 100000000000000) / 100000000000000
  cout << "Case : (max / 100000000000000) / 100000000000000" << endl;
  i.from_string("578960446186580977117854925043439539266349923328202820197287920");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0x16849), (uint64_t)(0xB86A12B9B01EA709), (uint64_t)(0x09833DE71928DB21), (uint64_t)(0x38E9F98E67D007F0), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2820197287920), (int)__LINE__, _result);

  // ((max / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : ((max / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("5789604461865809771178549250434395392663499233282");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0x3F61ED7CA), (uint64_t)(0x0C0328362F2A75B8), (uint64_t)(0x62214FF1DB72D802), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(92663499233282), (int)__LINE__, _result);

  // (((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : (((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("57896044618658097711785492504343953");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB267ED1940F1C), (uint64_t)(0x61C55F038B237591), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(85492504343953), (int)__LINE__, _result);

  // ((((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000
  cout << "Case : ((((max / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000) / 100000000000000" << endl;
  i.from_string("578960446186580977117");
  j.from_string("100000000000000");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1F), (uint64_t)(0x62B0B257C0D1A5DD), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(46186580977117), (int)__LINE__, _result);

  // max / 77777777777777
  cout << "Case : max / 77777777777777" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("77777777777777");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x46BD0CD0DC71), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(31119352451845), (int)__LINE__, _result);

  // (max / 77777777777777) / 77777777777777
  cout << "Case : (max / 77777777777777) / 77777777777777" << endl;
  i.from_string("744377716525611557214407302599994408844047329937492066441240986");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0x1CF3A), (uint64_t)(0x363F3CAAB12A7E7D), (uint64_t)(0x1BBB227F8F04E940), (uint64_t)(0x0D14071A4ADE219A), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(71096126874126), (int)__LINE__, _result);

  // ((max / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : ((max / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("9570570641043672869891647184442912744466738671180");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0x68C673AEA), (uint64_t)(0xBB2F4ECDD3D6E044), (uint64_t)(0x66641DD153516E4C), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(25042959957867), (int)__LINE__, _result);

  // (((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : (((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("123050193956277024543403597998797169");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x17B2D7CC5B85A7), (uint64_t)(0xE407E181B4E33171), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(20938559125400), (int)__LINE__, _result);

  // ((((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777
  cout << "Case : ((((max / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777) / 77777777777777" << endl;
  i.from_string("1582073922295006136297");
  j.from_string("77777777777777");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x55), (uint64_t)(0xC3AFAA23F2CA87E9), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(33406133068147), (int)__LINE__, _result);

  // max / 3333333333333333
  cout << "Case : max / 3333333333333333" << endl;
  i.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  j.from_string("3333333333333333");
  check_value(j, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xBD7A625405555), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(162358756430473), (int)__LINE__, _result);

  // (max / 3333333333333333) / 3333333333333333
  cout << "Case : (max / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("17368813385597431050416986311046291219689128804475206574831518");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0xACF), (uint64_t)(0x02F8F133A6DE29FD), (uint64_t)(0xB1E6DB4C6B12D53D), (uint64_t)(0xBEABA6B1F820779E), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(98868193659773), (int)__LINE__, _result);

  // ((max / 3333333333333333) / 3333333333333333) / 3333333333333333
  cout << "Case : ((max / 3333333333333333) / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("5210644015679229836189497461236870984856484765");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0), (uint64_t)(0xE9A742), (uint64_t)(0x82EDE0D4790197BE), (uint64_t)(0x864457E83EABBB9D), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3240043579721014), (int)__LINE__, _result);

  // (((max / 3333333333333333) / 3333333333333333) / 3333333333333333) / 3333333333333333
  cout << "Case : (((max / 3333333333333333) / 3333333333333333) / 3333333333333333) / 3333333333333333" << endl;
  i.from_string("1563193204703769107176169708747");
  j.from_string("3333333333333333");
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BAF31CD3), (uint64_t)(0xB8600EEFC9E89CCB), (int)__LINE__, _result);
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2596828823512457), (int)__LINE__, _result);

  // 5......5 / 3......3
  cout << "Case : 5......5 / 3......3" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  i %= j;
  check_value(i, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // 5......5 / 2......2
  cout << "Case : 5......5 / 2......2" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  i %= j;
  check_value(i, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / 3......3
  cout << "Case : 4......4 / 3......3" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("33333333333333333333333333333333333333333333333333333333333333333333333333333");
  i %= j;
  check_value(i, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / 2......2
  cout << "Case : 4......4 / 2......2" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("22222222222222222222222222222222222222222222222222222222222222222222222222222");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 5......5 / -3......3
  cout << "Case : 5......5 / -3......3" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  i %= j;
  check_value(i, (uint64_t)(0x312155017C70A204), (uint64_t)(0x106E034520E0CDF1), (uint64_t)(0x7B3E54516E2ECE38), (uint64_t)(0xE38E38E38E38E38E), (int)__LINE__, _result);

  // 5......5 / -2......2
  cout << "Case : 5......5 / -2......2" << endl;
  i.from_string("55555555555555555555555555555555555555555555555555555555555555555555555555555");
  j.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  i %= j;
  check_value(i, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / -3......3
  cout << "Case : 4......4 / -3......3" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("-33333333333333333333333333333333333333333333333333333333333333333333333333333");
  i %= j;
  check_value(i, (uint64_t)(0x1890AA80BE385102), (uint64_t)(0x083701A2907066F8), (uint64_t)(0xBD9F2A28B717671C), (uint64_t)(0x71C71C71C71C71C7), (int)__LINE__, _result);

  // 4......4 / -2......2
  cout << "Case : 4......4 / -2......2" << endl;
  i.from_string("44444444444444444444444444444444444444444444444444444444444444444444444444444");
  j.from_string("-22222222222222222222222222222222222222222222222222222222222222222222222222222");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  // 876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  i %= j;
  check_value(i, (uint64_t)(0x1C9EDE81B7E), (uint64_t)(0x430DBE4679DDC581), (uint64_t)(0x64D68830A2802734), (uint64_t)(0xD29394146250858F), (int)__LINE__, _result);

  // -876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : -876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFE361217E481), (uint64_t)(0xBCF241B986223A7E), (uint64_t)(0x9B2977CF5D7FD8CB), (uint64_t)(0x2D6C6BEB9DAF7A71), (int)__LINE__, _result);

  // 876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : 876543218765432187654321876543218765432187654321876543218765432187654321 / -123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("-123456781234567812345678123456781234567812345678123456781234567812345678");
  i %= j;
  check_value(i, (uint64_t)(0x1C9EDE81B7E), (uint64_t)(0x430DBE4679DDC581), (uint64_t)(0x64D68830A2802734), (uint64_t)(0xD29394146250858F), (int)__LINE__, _result);

  // -876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678
  cout << "Case : -876543218765432187654321876543218765432187654321876543218765432187654321 / 123456781234567812345678123456781234567812345678123456781234567812345678" << endl;
  i.from_string("-876543218765432187654321876543218765432187654321876543218765432187654321");
  j.from_string("123456781234567812345678123456781234567812345678123456781234567812345678");
  i %= j;
  check_value(i, (uint64_t)(0xFFFFFE361217E481), (uint64_t)(0xBCF241B986223A7E), (uint64_t)(0x9B2977CF5D7FD8CB), (uint64_t)(0x2D6C6BEB9DAF7A71), (int)__LINE__, _result);

  // 45646484978879789878784164168798787987879874498498555555555555555555 / 516561516484814184881456154661544444444444444444444444777
  cout << "Case : 45646484978879789878784164168798787987879874498498555555555555555555 / " << endl;
  cout << "       516561516484814184881456154661544444444444444444444444777" << endl;
  i.from_string("45646484978879789878784164168798787987879874498498555555555555555555");
  j.from_string("516561516484814184881456154661544444444444444444444444777");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0x64A9794005D7C6F), (uint64_t)(0x4DAB91911C1994C5), (uint64_t)(0x0CA7AFF0584936EB), (int)__LINE__, _result);

  // 9999999999999999944444444444222222222288888888888777777777711111111115555555 / 4444444444111111111122222222266666333333333
  cout << "Case : 9999999999999999944444444444222222222288888888888777777777711111111115555555 / " << endl;
  cout << "       4444444444111111111122222222266666333333333" << endl;
  i.from_string("9999999999999999944444444444222222222288888888888777777777711111111115555555");
  j.from_string("4444444444111111111122222222266666333333333");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0x0000000000002086), (uint64_t)(0x02C73B074640CFAC), (uint64_t)(0x1E76BBF99EDE2616), (int)__LINE__, _result);

  // 6666666666688888888888888444444444411111111199999977777777777722222222233333 / 8888888555555555444444111111222222222
  cout << "Case : 6666666666688888888888888444444444411111111199999977777777777722222222233333 / " << endl;
  cout << "       8888888555555555444444111111222222222" << endl;
  i.from_string("6666666666688888888888888444444444411111111199999977777777777722222222233333");
  j.from_string("8888888555555555444444111111222222222");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x056DA4E841A585DB), (uint64_t)(0x4DDD85AAA2998387), (int)__LINE__, _result);

  // 7897897894564564561231231324897664841313516848487456151561848755133115158 / 784523322266655412987456632114568
  cout << "Case : 7897897894564564561231231324897664841313516848487456151561848755133115158 / " << endl;
  cout << "       784523322266655412987456632114568" << endl;
  i.from_string("7897897894564564561231231324897664841313516848487456151561848755133115158");
  j.from_string("784523322266655412987456632114568");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x000012C92342A4B7), (uint64_t)(0x90CC4C0CF587DF1E), (int)__LINE__, _result);

  // 7897897894564564561231231324897664841313516848487456151561848755133115158 / 78452332226665541298745663211445245436435435354545378568
  cout << "Case : 7897897894564564561231231324897664841313516848487456151561848755133115158 / " << endl;
  cout << "       78452332226665541298745663211445245436435435354545378568" << endl;
  i.from_string("7897897894564564561231231324897664841313516848487456151561848755133115158");
  j.from_string("78452332226665541298745663211445245436435435354545378568");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0x0037B35DA18103ED), (uint64_t)(0x13DA38F2043F8CF8), (uint64_t)(0xB39EF424835F846E), (int)__LINE__, _result);

  // 9999999999999999999999999999999999999999999999999999999999999999999999 / 555555555555555555555555555555555555555555555555555555
  cout << "Case : 9999999999999999999999999999999999999999999999999999999999999999999999 / " << endl;
  cout << "       555555555555555555555555555555555555555555555555555555" << endl;
  i.from_string("9999999999999999999999999999999999999999999999999999999999999999999999");
  j.from_string("555555555555555555555555555555555555555555555555555555");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x002386F26FC0FFFF), (int)__LINE__, _result);

  // 1111111111899999454444444444444444444444444444444444442222222299999999999 / 3333333333333
  cout << "Case : 1111111111899999454444444444444444444444444444444444442222222299999999999 / " << endl;
  cout << "       3333333333333" << endl;
  i.from_string("1111111111899999454444444444444444444444444444444444442222222299999999999");
  j.from_string("3333333333333");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x000000247AB4F047), (int)__LINE__, _result);

  // 878787878446451687978513004456014086489485498740864006980406984780441321 / 33016854646849846046894516546894
  cout << "Case : 878787878446451687978513004456014086489485498740864006980406984780441321 / " << endl;
  cout << "       33016854646849846046894516546894" << endl;
  i.from_string("878787878446451687978513004456014086489485498740864006980406984780441321");
  j.from_string("33016854646849846046894516546894");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000018BEC7A0EB0), (uint64_t)(0x1AA686371459C3E7), (int)__LINE__, _result);

  // 878787878446451687978513004456014086489485498740864006980406984780441321 / 330168546
  cout << "Case : 878787878446451687978513004456014086489485498740864006980406984780441321 / " << endl;
  cout << "       330168546" << endl;
  i.from_string("878787878446451687978513004456014086489485498740864006980406984780441321");
  j.from_string("330168546");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xB6D312B), (int)__LINE__, _result);

  // 12320101323121212032012012013015615615150151510650156510610513056001561 / 78978784874878484874889784
  cout << "Case : 12320101323121212032012012013015615615150151510650156510610513056001561 / " << endl;
  cout << "       78978784874878484874889784" << endl;
  i.from_string("12320101323121212032012012013015615615150151510650156510610513056001561");
  j.from_string("78978784874878484874889784");
  i %= j;
  check_value(i, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x13BDFB), (uint64_t)(0xCF97C5669A3CC449), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nmodulo_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}



void shl_test()
{
  BigInt a;
  bool _result = true;
  cout << "\n==[[shl()_test]]==================================" << endl << endl;

  cout << "Case : 1 << 1; (1 << 1) << 1" << endl;
  a = 1;
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(4), (int)__LINE__, _result);

  cout << "Case : 2 << 1; (2 << 1) << 1" << endl;
  a = 2;
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(4), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(8), (int)__LINE__, _result);

  cout << "Case : -1 << 1; (-1 << 1) << 1" << endl;
  a = -1;
  a.shl();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFC), (int)__LINE__, _result);

  cout << "Case : -2 << 1; (-2 << 1) << 1" << endl;
  a = -2;
  a.shl();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFC), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFF8), (int)__LINE__, _result);

  cout << "Case : 1000000 << 1; (1000000 << 1) << 1" << endl;
  a = 1000000;
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2000000), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(4000000), (int)__LINE__, _result);

  cout << "Case : -1000000 << 1; (-1000000 << 1) << 1" << endl;
  a = -1000000;
  a.shl();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFE17B80), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFC2F700), (int)__LINE__, _result);

  cout << "Case : (2^63) << 1; ((2^63) << 1) << 1" << endl;
  a.from_string("9223372036854775808");
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^127) << 1; ((2^127) << 1) << 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(2), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^191) << 1; ((2^191) << 1) << 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  a.shl();
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(2), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^254) << 1; ((2^254) << 1) << 1" << endl;
  a.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  a.shl();
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFF00000000 << 1; (0xFFFFFFFF00000000 << 1) << 1" << endl;
  a.from_string("18446744069414584320");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFE00000000), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFC00000000), (int)__LINE__, _result);

  cout << "Case : (0 0 0xFFFFFFFFFFFFFFFF 0) << 1; ((0 0 0xFFFFFFFFFFFFFFFF 0) << 1) << 1" << endl;
  a.from_string("340282366920938463444927863358058659840");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0 0xFFFFFFFFFFFFFFFF 0 0) << 1; ((0 0xFFFFFFFFFFFFFFFF 0 0) << 1) << 1" << endl;
  a.from_string("6277101735386680763495507056286727952638980837032266301440");
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0xFFFFFFFFFFFFFFFF 0 0 0) << 1; ((0xFFFFFFFFFFFFFFFF 0 0 0) << 1) << 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x8765432187654321 << 1; (0x8765432187654321 << 1) << 1" << endl;
  a = (uint64_t)(0x8765432187654321);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x0ECA86430ECA8642), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (uint64_t)(0x1D950C861D950C84), (int)__LINE__, _result);

  cout << "Case : 0x555555...55 << 1 << 1 << 1 ... (change sign)" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a.shl();
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a.shl();
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a.shl();
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a.shl();
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a.shl();
  check_value((bool)(a > 0), false, (int)__LINE__, _result);

  cout << "Case : 1229782938247303441" << endl;
  a.from_string("1229782938247303441");
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x2222222222222222), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x4444444444444444), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8888888888888888), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x1111111111111110), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (uint64_t)(0x2222222222222220), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(4), (uint64_t)(0x4444444444444440), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(8), (uint64_t)(0x8888888888888880), (int)__LINE__, _result);

  cout << "Case : 22685491128062564229661857557203910656" << endl;
  a.from_string("22685491128062564229661857557203910656");
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x2222222222222222), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x4444444444444444), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8888888888888888), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0x1111111111111110), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(2), (uint64_t)(0x2222222222222220), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(4), (uint64_t)(0x4444444444444440), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(8), (uint64_t)(0x8888888888888880), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 418473449025778717566367137085781863509265389135484420096" << endl;
  a.from_string("418473449025778717566367137085781863509265389135484420096");
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0x2222222222222222), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0x4444444444444444), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0), (uint64_t)(0x8888888888888888), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(1), (uint64_t)(0x1111111111111110), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(2), (uint64_t)(0x2222222222222220), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(4), (uint64_t)(0x4444444444444440), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(8), (uint64_t)(0x8888888888888880), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 7719472615821079694486258884886748472628946349495526508223681904229939675136" << endl;
  a.from_string("7719472615821079694486258884886748472628946349495526508223681904229939675136");
  a.shl();
  check_value(a, (uint64_t)(0x2222222222222222), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0x4444444444444444), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0x8888888888888888), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0x1111111111111110), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0x2222222222222220), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0x4444444444444440), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shl();
  check_value(a, (uint64_t)(0x8888888888888880), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nshl()_test PASS" << endl;
  }

  cout << "========================================================" << endl;


  return;
}

void bitwise_left_shift_int32_test()
{
  BigInt a, b;
  int32_t offset = 0;

  bool _result = true;
  cout << "\n==[[bitwise_left_shift_int32(<<)_test]]==================================" << endl << endl;

  cout << "Case : 0 << 0" << endl;
  a = 0;
  offset = 0;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 << 1" << endl;
  a = 0;
  offset = 1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 << -1" << endl;
  a = 0;
  offset = -1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 1 << 255" << endl;
  a = 1;
  offset = 255;
  b = a << offset;
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -1 << 255" << endl;
  a = -1;
  offset = 255;
  b = a << offset;
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 1 << 1000" << endl;
  a = 1;
  offset = 1000;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -1 << 1000" << endl;
  a = -1;
  offset = 1000;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0x555555...55 << 1 << 1 << 1 ... (change sign)" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  offset = 1;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);

  cout << "Case : 2^127 << 0" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 0;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << 5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 5;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(16), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << -1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << -5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -5;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 0" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 0;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 1;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 5;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFFF0, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << -1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << -5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -5;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : max << 5 (overflow)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  offset = 5;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFFE0, (int)__LINE__, _result);

  cout << "Case : min << 5 (overflow)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 5;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 32" << endl;
  a = 1;
  offset = 32;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000100000000), (int)__LINE__, _result);

  cout << "Case : 1 << 64" << endl;
  a = 1;
  offset = 64;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 96" << endl;
  a = 1;
  offset = 96;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000100000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 128" << endl;
  a = 1;
  offset = 128;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 160" << endl;
  a = 1;
  offset = 160;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x0000000100000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 192" << endl;
  a = 1;
  offset = 192;
  b = a << offset;
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 224" << endl;
  a = 1;
  offset = 224;
  b = a << offset;
  check_value(b, (uint64_t)(0x0000000100000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 256" << endl;
  a = 1;
  offset = 256;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 32" << endl;
  a = -1;
  offset = 32;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);

  cout << "Case : -1 << 64" << endl;
  a = -1;
  offset = 64;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 96" << endl;
  a = -1;
  offset = 96;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 128" << endl;
  a = -1;
  offset = 128;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 160" << endl;
  a = -1;
  offset = 160;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 192" << endl;
  a = -1;
  offset = 192;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 224" << endl;
  a = -1;
  offset = 224;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 256" << endl;
  a = -1;
  offset = 256;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 32" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 32;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 64" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 64;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 96" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 96;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 128" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 128;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 160" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 160;
  b = a << offset;
  check_value(b, (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 192" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 192;
  b = a << offset;
  check_value(b, (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 224" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 224;
  b = a << offset;
  check_value(b, (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 256" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 256;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << -10" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = -10;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFF00000000 << 1; (0xFFFFFFFF00000000 << 1) << 1" << endl;
  a.from_string("18446744069414584320");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFE00000000), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFC00000000), (int)__LINE__, _result);

  cout << "Case : (0 0 0xFFFFFFFFFFFFFFFF 0) << 1; ((0 0 0xFFFFFFFFFFFFFFFF 0) << 1) << 1" << endl;
  a.from_string("340282366920938463444927863358058659840");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0 0xFFFFFFFFFFFFFFFF 0 0) << 1; ((0 0xFFFFFFFFFFFFFFFF 0 0) << 1) << 1" << endl;
  a.from_string("6277101735386680763495507056286727952638980837032266301440");
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0xFFFFFFFFFFFFFFFF 0 0 0) << 1; ((0xFFFFFFFFFFFFFFFF 0 0 0) << 1) << 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_left_shift_int32_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_left_shift_bigint_test()
{
  BigInt a, b;
  BigInt offset = 0;

  bool _result = true;
  cout << "\n==[[bitwise_left_shift_bigint(<<)_test]]==================================" << endl << endl;

  cout << "Case : 0 << 0" << endl;
  a = 0;
  offset = 0;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 << 1" << endl;
  a = 0;
  offset = 1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 << -1" << endl;
  a = 0;
  offset = -1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 1 << 255" << endl;
  a = 1;
  offset = 255;
  b = a << offset;
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -1 << 255" << endl;
  a = -1;
  offset = 255;
  b = a << offset;
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 1 << 1000" << endl;
  a = 1;
  offset = 1000;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -1 << 1000" << endl;
  a = -1;
  offset = 1000;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0x555555...55 << 1 << 1 << 1 ... (change sign)" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  offset = 1;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);


  cout << "Case : 2^127 << 0" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 0;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << 5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 5;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)16, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << -1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << -5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -5;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 0" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 0;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 1;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 5;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFFF0, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << -1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -1;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << -5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -5;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 2^127 << max" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 2^127 << min" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : max << 5 (overflow)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  offset = 5;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFFE0, (int)__LINE__, _result);

  cout << "Case : min << 5 (overflow)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 5;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 32" << endl;
  a = 1;
  offset = 32;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000100000000), (int)__LINE__, _result);

  cout << "Case : 1 << 64" << endl;
  a = 1;
  offset = 64;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 96" << endl;
  a = 1;
  offset = 96;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000100000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 128" << endl;
  a = 1;
  offset = 128;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 160" << endl;
  a = 1;
  offset = 160;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x0000000100000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 192" << endl;
  a = 1;
  offset = 192;
  b = a << offset;
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 224" << endl;
  a = 1;
  offset = 224;
  b = a << offset;
  check_value(b, (uint64_t)(0x0000000100000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 256" << endl;
  a = 1;
  offset = 256;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 32" << endl;
  a = -1;
  offset = 32;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);

  cout << "Case : -1 << 64" << endl;
  a = -1;
  offset = 64;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 96" << endl;
  a = -1;
  offset = 96;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 128" << endl;
  a = -1;
  offset = 128;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 160" << endl;
  a = -1;
  offset = 160;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 192" << endl;
  a = -1;
  offset = 192;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 224" << endl;
  a = -1;
  offset = 224;
  b = a << offset;
  check_value(b, (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 256" << endl;
  a = -1;
  offset = 256;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 32" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 32;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 64" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 64;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 96" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 96;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 128" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 128;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 160" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 160;
  b = a << offset;
  check_value(b, (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 192" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 192;
  b = a << offset;
  check_value(b, (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 224" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 224;
  b = a << offset;
  check_value(b, (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 256" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 256;
  b = a << offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFF00000000 << 1; (0xFFFFFFFF00000000 << 1) << 1" << endl;
  a.from_string("18446744069414584320");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFE00000000), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFC00000000), (int)__LINE__, _result);

  cout << "Case : (0 0 0xFFFFFFFFFFFFFFFF 0) << 1; ((0 0 0xFFFFFFFFFFFFFFFF 0) << 1) << 1" << endl;
  a.from_string("340282366920938463444927863358058659840");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0 0xFFFFFFFFFFFFFFFF 0 0) << 1; ((0 0xFFFFFFFFFFFFFFFF 0 0) << 1) << 1" << endl;
  a.from_string("6277101735386680763495507056286727952638980837032266301440");
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0xFFFFFFFFFFFFFFFF 0 0 0) << 1; ((0xFFFFFFFFFFFFFFFF 0 0 0) << 1) << 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a = a << offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_left_shift_bigint_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_left_shift_int32_assignment_operator_test()
{
  BigInt a, b;
  int32_t offset = 0;

  bool _result = true;
  cout << "\n==[[bitwise_left_shift_int32_assignment_operator(<<=)_test]]==================================" << endl << endl;

  cout << "Case : 0 << 0" << endl;
  a = 0;
  offset = 0;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 << 1" << endl;
  a = 0;
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 << -1" << endl;
  a = 0;
  offset = -1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 1 << 255" << endl;
  a = 1;
  offset = 255;
  a <<= offset;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -1 << 255" << endl;
  a = -1;
  offset = 255;
  a <<= offset;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 1 << 1000" << endl;
  a = 1;
  offset = 1000;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -1 << 1000" << endl;
  a = -1;
  offset = 1000;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0x555555...55 << 1 << 1 << 1 ... (change sign)" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  offset = 1;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);

  cout << "Case : 2^127 << 0" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 0;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << 5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 5;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(16), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << -1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << -5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -5;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 0" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 0;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 5;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFFF0, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << -1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << -5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -5;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : max << 5 (overflow)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  offset = 5;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFFE0, (int)__LINE__, _result);

  cout << "Case : min << 5 (overflow)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 5;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 32" << endl;
  a = 1;
  offset = 32;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000100000000), (int)__LINE__, _result);

  cout << "Case : 1 << 64" << endl;
  a = 1;
  offset = 64;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 96" << endl;
  a = 1;
  offset = 96;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000100000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 128" << endl;
  a = 1;
  offset = 128;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 160" << endl;
  a = 1;
  offset = 160;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x0000000100000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 192" << endl;
  a = 1;
  offset = 192;
  a <<= offset;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 224" << endl;
  a = 1;
  offset = 224;
  a <<= offset;
  check_value(a, (uint64_t)(0x0000000100000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 256" << endl;
  a = 1;
  offset = 256;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 32" << endl;
  a = -1;
  offset = 32;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);

  cout << "Case : -1 << 64" << endl;
  a = -1;
  offset = 64;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 96" << endl;
  a = -1;
  offset = 96;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 128" << endl;
  a = -1;
  offset = 128;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 160" << endl;
  a = -1;
  offset = 160;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 192" << endl;
  a = -1;
  offset = 192;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 224" << endl;
  a = -1;
  offset = 224;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 256" << endl;
  a = -1;
  offset = 256;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 32" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 32;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 64" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 64;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 96" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 96;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 128" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 128;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 160" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 160;
  a <<= offset;
  check_value(a, (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 192" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 192;
  a <<= offset;
  check_value(a, (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 224" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 224;
  a <<= offset;
  check_value(a, (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 256" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 256;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFF00000000 << 1; (0xFFFFFFFF00000000 << 1) << 1" << endl;
  a.from_string("18446744069414584320");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFE00000000), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFC00000000), (int)__LINE__, _result);

  cout << "Case : (0 0 0xFFFFFFFFFFFFFFFF 0) << 1; ((0 0 0xFFFFFFFFFFFFFFFF 0) << 1) << 1" << endl;
  a.from_string("340282366920938463444927863358058659840");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0 0xFFFFFFFFFFFFFFFF 0 0) << 1; ((0 0xFFFFFFFFFFFFFFFF 0 0) << 1) << 1" << endl;
  a.from_string("6277101735386680763495507056286727952638980837032266301440");
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0xFFFFFFFFFFFFFFFF 0 0 0) << 1; ((0xFFFFFFFFFFFFFFFF 0 0 0) << 1) << 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_left_shift_int32_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_left_shift_bigint_assignment_operator_test()
{
  BigInt a, b;
  BigInt offset = 0;

  bool _result = true;
  cout << "\n==[[bitwise_left_shift_bigint_assignment_operator(<<=)_test]]==================================" << endl << endl;

  cout << "Case : 0 << 0" << endl;
  a = 0;
  offset = 0;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 << 1" << endl;
  a = 0;
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 << -1" << endl;
  a = 0;
  offset = -1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 1 << 255" << endl;
  a = 1;
  offset = 255;
  a <<= offset;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -1 << 255" << endl;
  a = -1;
  offset = 255;
  a <<= offset;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 1 << 1000" << endl;
  a = 1;
  offset = 1000;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -1 << 1000" << endl;
  a = -1;
  offset = 1000;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0x555555...55 << 1 << 1 << 1 ... (change sign)" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  offset = 1;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), true, (int)__LINE__, _result);
  a = a << offset;
  check_value((bool)(a > 0), false, (int)__LINE__, _result);


  cout << "Case : 2^127 << 0" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 0;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << 5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 5;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)16, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << -1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 << -5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -5;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 0" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 0;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << 5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 5;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFFF0, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << -1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 << -5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -5;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 2^127 << max" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 2^127 << min" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : max << 5 (overflow)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  offset = 5;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFFFFFFFFE0, (int)__LINE__, _result);

  cout << "Case : min << 5 (overflow)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 5;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 32" << endl;
  a = 1;
  offset = 32;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000100000000), (int)__LINE__, _result);

  cout << "Case : 1 << 64" << endl;
  a = 1;
  offset = 64;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 96" << endl;
  a = 1;
  offset = 96;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000100000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 128" << endl;
  a = 1;
  offset = 128;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 160" << endl;
  a = 1;
  offset = 160;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x0000000100000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 192" << endl;
  a = 1;
  offset = 192;
  a <<= offset;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 224" << endl;
  a = 1;
  offset = 224;
  a <<= offset;
  check_value(a, (uint64_t)(0x0000000100000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 << 256" << endl;
  a = 1;
  offset = 256;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 32" << endl;
  a = -1;
  offset = 32;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);

  cout << "Case : -1 << 64" << endl;
  a = -1;
  offset = 64;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 96" << endl;
  a = -1;
  offset = 96;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 128" << endl;
  a = -1;
  offset = 128;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 160" << endl;
  a = -1;
  offset = 160;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 192" << endl;
  a = -1;
  offset = 192;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 224" << endl;
  a = -1;
  offset = 224;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 << 256" << endl;
  a = -1;
  offset = 256;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 32" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 32;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 64" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 64;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 96" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 96;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 128" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 128;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 160" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 160;
  a <<= offset;
  check_value(a, (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 192" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 192;
  a <<= offset;
  check_value(a, (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 224" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 224;
  a <<= offset;
  check_value(a, (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 << 256" << endl;
  a = (uint64_t)(0x1234567812345678);
  offset = 256;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFF00000000 << 1; (0xFFFFFFFF00000000 << 1) << 1" << endl;
  a.from_string("18446744069414584320");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFE00000000), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFC00000000), (int)__LINE__, _result);

  cout << "Case : (0 0 0xFFFFFFFFFFFFFFFF 0) << 1; ((0 0 0xFFFFFFFFFFFFFFFF 0) << 1) << 1" << endl;
  a.from_string("340282366920938463444927863358058659840");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0 0xFFFFFFFFFFFFFFFF 0 0) << 1; ((0 0xFFFFFFFFFFFFFFFF 0 0) << 1) << 1" << endl;
  a.from_string("6277101735386680763495507056286727952638980837032266301440");
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(3), (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0xFFFFFFFFFFFFFFFF 0 0 0) << 1; ((0xFFFFFFFFFFFFFFFF 0 0 0) << 1) << 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  offset = 1;
  a <<= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFC), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_left_shift_bigint_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void shr_test()
{

  BigInt a;
  bool _result = true;
  cout << "\n==[[shr()_test]]==================================" << endl << endl;

  cout << "Case : 1 >> 1; (1 >> 1) >> 1" << endl;
  a = 1;
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 2 >> 1; (2 >> 1) >> 1" << endl;
  a = 2;
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 >> 1; (-1 >> 1) >> 1" << endl;
  a = -1;
  a.shr();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -2 >> 1; (-2 >> 1) >> 1" << endl;
  a = -2;
  a.shr();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1000000 >> 1; (1000000 >> 1) >> 1" << endl;
  a = 1000000;
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7A120), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3D090), (int)__LINE__, _result);

  cout << "Case : -1000000 >> 1; (-1000000 >> 1) >> 1" << endl;
  a = -1000000;
  a.shr();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFF85EE0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFC2F70), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFF00000000 >> 1; (0xFFFFFFFF00000000 >> 1) >> 1" << endl;
  a.from_string("18446744069414584320");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFF80000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3FFFFFFFC0000000), (int)__LINE__, _result);

  cout << "Case : (0 0 0xFFFFFFFFFFFFFFFF 0) >> 1; ((0 0 0xFFFFFFFFFFFFFFFF 0) >> 1) >> 1" << endl;
  a.from_string("340282366920938463444927863358058659840");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (int)__LINE__, _result);

  cout << "Case : (0 0xFFFFFFFFFFFFFFFF 0 0) >> 1; ((0 0xFFFFFFFFFFFFFFFF 0 0) >> 1) >> 1" << endl;
  a.from_string("6277101735386680763495507056286727952638980837032266301440");
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0xFFFFFFFFFFFFFFFF 0 0 0) >> 1; ((0xFFFFFFFFFFFFFFFF 0 0 0) >> 1) >> 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^63) >> 1; ((2^63) >> 1) >> 1" << endl;
  a.from_string("9223372036854775808");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x4000000000000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x2000000000000000), (int)__LINE__, _result);

  cout << "Case : (2^127) >> 1; ((2^127) >> 1) >> 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x4000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x2000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^191) >> 1; ((2^191) >> 1) >> 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  check_value(a, (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x2000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^254) >> 1; ((2^254) >> 1) >> 1" << endl;
  a.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  check_value(a, (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0x2000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0x1000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1229782938247303441" << endl;
  a.from_string("1229782938247303441");
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0888888888888888), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0444444444444444), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0222222222222222), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0111111111111111), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0088888888888888), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0044444444444444), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0022222222222222), (int)__LINE__, _result);

  cout << "Case : 22685491128062564229661857557203910656" << endl;
  a.from_string("22685491128062564229661857557203910656");
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0888888888888888), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0444444444444444), (uint64_t)(0x4000000000000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0222222222222222), (uint64_t)(0x2000000000000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0111111111111111), (uint64_t)(0x1000000000000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0088888888888888), (uint64_t)(0x8800000000000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0044444444444444), (uint64_t)(0x4400000000000000), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0022222222222222), (uint64_t)(0x2200000000000000), (int)__LINE__, _result);

  cout << "Case : 418473449025778717566367137085781863509265389135484420096" << endl;
  a.from_string("418473449025778717566367137085781863509265389135484420096");
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x0888888888888888), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x0444444444444444), (uint64_t)(0x4000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x0222222222222222), (uint64_t)(0x2000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x0111111111111111), (uint64_t)(0x1000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x0088888888888888), (uint64_t)(0x8800000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x0044444444444444), (uint64_t)(0x4400000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0), (uint64_t)(0x0022222222222222), (uint64_t)(0x2200000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 7719472615821079694486258884886748472628946349495526508223681904229939675136" << endl;
  a.from_string("7719472615821079694486258884886748472628946349495526508223681904229939675136");
  a.shr();
  check_value(a, (uint64_t)(0x0888888888888888), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0x0444444444444444), (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0x0222222222222222), (uint64_t)(0x2000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0x0111111111111111), (uint64_t)(0x1000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0x0088888888888888), (uint64_t)(0x8800000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0x0044444444444444), (uint64_t)(0x4400000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a.shr();
  check_value(a, (uint64_t)(0x0022222222222222), (uint64_t)(0x2200000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nshr()_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_right_shift_int32_test()
{
  BigInt a, b;
  int32_t offset = 0;

  bool _result = true;
  cout << "\n==[[bitwise_right_shift_int32(>>)_test]]==================================" << endl << endl;

  cout << "Case : 0 >> 0" << endl;
  a = 0;
  offset = 0;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 >> 1" << endl;
  a = 0;
  offset = 1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 >> -1" << endl;
  a = 0;
  offset = -1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 0" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 0;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)0x4000000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 5;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)0x0400000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> -1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> -5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -5;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 0" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 0;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 1;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xC000000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 5;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFC00000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> -1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> -5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -5;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : max >> 5" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  offset = 5;
  b = a >> offset;
  check_value(b, (uint64_t)0x03FFFFFFFFFFFFFF, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : min >> 5" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 5;
  b = a >> offset;
  check_value(b, (uint64_t)0xFC00000000000000, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 32" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 32;
  b = a >> offset;
  check_value(b, (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 64" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 64;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 96" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 96;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 128" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 128;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 160" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 160;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 192" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 192;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  cout << "Case : min >> 224" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 224;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (int)__LINE__, _result);

  cout << "Case : min >> 256" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 256;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 32" << endl;
  a = -1;
  offset = 32;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 64" << endl;
  a = -1;
  offset = 64;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 96" << endl;
  a = -1;
  offset = 96;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 128" << endl;
  a = -1;
  offset = 128;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 160" << endl;
  a = -1;
  offset = 160;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 192" << endl;
  a = -1;
  offset = 192;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 224" << endl;
  a = -1;
  offset = 224;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 256" << endl;
  a = -1;
  offset = 256;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 1000" << endl;
  a = -1;
  offset = 1000;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 32" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 32;
  b = a >> offset;
  check_value(b, (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 64" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 64;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 96" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 96;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 128" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 128;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 160" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 160;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 192" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 192;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 224" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 224;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 256" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 256;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFF00000000 >> 1; (0xFFFFFFFF00000000 >> 1) >> 1" << endl;
  a.from_string("18446744069414584320");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFF80000000), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3FFFFFFFC0000000), (int)__LINE__, _result);

  cout << "Case : (0 0 0xFFFFFFFFFFFFFFFF 0) >> 1; ((0 0 0xFFFFFFFFFFFFFFFF 0) >> 1) >> 1" << endl;
  a.from_string("340282366920938463444927863358058659840");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (int)__LINE__, _result);

  cout << "Case : (0 0xFFFFFFFFFFFFFFFF 0 0) >> 1; ((0 0xFFFFFFFFFFFFFFFF 0 0) >> 1) >> 1" << endl;
  a.from_string("6277101735386680763495507056286727952638980837032266301440");
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0xFFFFFFFFFFFFFFFF 0 0 0) >> 1; ((0xFFFFFFFFFFFFFFFF 0 0 0) >> 1) >> 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 57896044618658097705508390768957273162799202909612615603626436559492530307072 >> 30" << endl;
  a.from_string("57896044618658097705508390768957273162799202909612615603626436559492530307072");
  offset = 30;
  b = a >> offset;
  check_value(b, (uint64_t)(0x1FFFFFFFF), (uint64_t)(0xFFFFFFFC00000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 57896044618658097705508390768957273162799202909612615603626436559492530307072 >> 60" << endl;
  a.from_string("57896044618658097705508390768957273162799202909612615603626436559492530307072");
  offset = 60;
  b = a >> offset;
  check_value(b, (uint64_t)(7), (uint64_t)(0xFFFFFFFFFFFFFFF0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 57896044618658097705508390768957273162799202909612615603626436559492530307072 >> 90" << endl;
  a.from_string("57896044618658097705508390768957273162799202909612615603626436559492530307072");
  offset = 90;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x1FFFFFFFFF), (uint64_t)(0xFFFFFFC000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 57896044618658097705508390768957273162799202909612615603626436559492530307072 >> 120" << endl;
  a.from_string("57896044618658097705508390768957273162799202909612615603626436559492530307072");
  offset = 120;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x7F), (uint64_t)(0xFFFFFFFFFFFFFF00), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_right_shift_int32_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_right_shift_bigint_test()
{
  BigInt a, b;
  BigInt offset = 0;

  bool _result = true;
  cout << "\n==[[bitwise_right_shift_bigint(>>)_test]]==================================" << endl << endl;

  cout << "Case : 0 >> 0" << endl;
  a = 0;
  offset = 0;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 >> 1" << endl;
  a = 0;
  offset = 1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 >> -1" << endl;
  a = 0;
  offset = -1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 0" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 0;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)0x4000000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 5;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)0x0400000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> -1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> -5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -5;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 0" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 0;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 1;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xC000000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 5;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFC00000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> -1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -1;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> -5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -5;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 2^127 >> max" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 2^127 >> min" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -2^127 >> min" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 5 >> min" << endl;
  a = 5;
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -5 >> min" << endl;
  a = -5;
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : max >> 5" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  offset = 5;
  b = a >> offset;
  check_value(b, (uint64_t)0x03FFFFFFFFFFFFFF, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : min >> 5" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 5;
  b = a >> offset;
  check_value(b, (uint64_t)0xFC00000000000000, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 32" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 32;
  b = a >> offset;
  check_value(b, (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 64" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 64;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 96" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 96;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 128" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 128;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 160" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 160;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 192" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 192;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  cout << "Case : min >> 224" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 224;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (int)__LINE__, _result);

  cout << "Case : min >> 256" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 256;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 32" << endl;
  a = -1;
  offset = 32;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 64" << endl;
  a = -1;
  offset = 64;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 96" << endl;
  a = -1;
  offset = 96;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 128" << endl;
  a = -1;
  offset = 128;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 160" << endl;
  a = -1;
  offset = 160;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 192" << endl;
  a = -1;
  offset = 192;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 224" << endl;
  a = -1;
  offset = 224;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 256" << endl;
  a = -1;
  offset = 256;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 1000" << endl;
  a = -1;
  offset = 1000;
  b = a >> offset;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 32" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 32;
  b = a >> offset;
  check_value(b, (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 64" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 64;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 96" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 96;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 128" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 128;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 160" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 160;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 192" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 192;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 224" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 224;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 256" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 256;
  b = a >> offset;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFF00000000 >> 1; (0xFFFFFFFF00000000 >> 1) >> 1" << endl;
  a.from_string("18446744069414584320");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFF80000000), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3FFFFFFFC0000000), (int)__LINE__, _result);

  cout << "Case : (0 0 0xFFFFFFFFFFFFFFFF 0) >> 1; ((0 0 0xFFFFFFFFFFFFFFFF 0) >> 1) >> 1" << endl;
  a.from_string("340282366920938463444927863358058659840");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (int)__LINE__, _result);

  cout << "Case : (0 0xFFFFFFFFFFFFFFFF 0 0) >> 1; ((0 0xFFFFFFFFFFFFFFFF 0 0) >> 1) >> 1" << endl;
  a.from_string("6277101735386680763495507056286727952638980837032266301440");
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0xFFFFFFFFFFFFFFFF 0 0 0) >> 1; ((0xFFFFFFFFFFFFFFFF 0 0 0) >> 1) >> 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a = a >> 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  if (_result)
  {
    cout << "\nbitwise_right_shift_bigint_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_right_shift_int32_assignment_operator_test()
{
  BigInt a, b;
  int32_t offset = 0;

  bool _result = true;
  cout << "\n==[[bitwise_right_shift_int32_assignment_operator(>>=)_test]]==================================" << endl << endl;

  cout << "Case : 0 >> 0" << endl;
  a = 0;
  offset = 0;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 >> 1" << endl;
  a = 0;
  offset = 1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 >> -1" << endl;
  a = 0;
  offset = -1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 0" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 0;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)0x4000000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 5;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)0x0400000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> -1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> -5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -5;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 0" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 0;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 1;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xC000000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 5;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFC00000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> -1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> -5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -5;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : max >> 5" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  offset = 5;
  a >>= offset;
  check_value(a, (uint64_t)0x03FFFFFFFFFFFFFF, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : min >> 5" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 5;
  a >>= offset;
  check_value(a, (uint64_t)0xFC00000000000000, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 32" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 32;
  a >>= offset;
  check_value(a, (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 64" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 64;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 96" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 96;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 128" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 128;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 160" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 160;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 192" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 192;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  cout << "Case : min >> 224" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 224;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (int)__LINE__, _result);

  cout << "Case : min >> 256" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 256;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 32" << endl;
  a = -1;
  offset = 32;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 64" << endl;
  a = -1;
  offset = 64;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 96" << endl;
  a = -1;
  offset = 96;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 128" << endl;
  a = -1;
  offset = 128;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 160" << endl;
  a = -1;
  offset = 160;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 192" << endl;
  a = -1;
  offset = 192;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 224" << endl;
  a = -1;
  offset = 224;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 256" << endl;
  a = -1;
  offset = 256;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 1000" << endl;
  a = -1;
  offset = 1000;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 32" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 32;
  a >>= offset;
  check_value(a, (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 64" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 64;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 96" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 96;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 128" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 128;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 160" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 160;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 192" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 192;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 224" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 224;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 256" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 256;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFF00000000 >> 1; (0xFFFFFFFF00000000 >> 1) >> 1" << endl;
  a.from_string("18446744069414584320");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);
  a >>= 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFF80000000), (int)__LINE__, _result);
  a >>= 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3FFFFFFFC0000000), (int)__LINE__, _result);

  cout << "Case : (0 0 0xFFFFFFFFFFFFFFFF 0) >> 1; ((0 0 0xFFFFFFFFFFFFFFFF 0) >> 1) >> 1" << endl;
  a.from_string("340282366920938463444927863358058659840");
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  a >>= 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);
  a >>= 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (int)__LINE__, _result);

  cout << "Case : (0 0xFFFFFFFFFFFFFFFF 0 0) >> 1; ((0 0xFFFFFFFFFFFFFFFF 0 0) >> 1) >> 1" << endl;
  a.from_string("6277101735386680763495507056286727952638980837032266301440");
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a >>= 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);
  a >>= 1;
  check_value(a, (uint64_t)(0), (uint64_t)(0x3FFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (0xFFFFFFFFFFFFFFFF 0 0 0) >> 1; ((0xFFFFFFFFFFFFFFFF 0 0 0) >> 1) >> 1" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a >>= 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  a >>= 1;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xC000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_right_shift_int32_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_right_shift_bigint_assignment_operator_test()
{
  BigInt a, b;
  BigInt offset = 0;

  bool _result = true;
  cout << "\n==[[bitwise_right_shift_bigint_assignment_operator(>>=)_test]]==================================" << endl << endl;

  cout << "Case : 0 >> 0" << endl;
  a = 0;
  offset = 0;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 >> 1" << endl;
  a = 0;
  offset = 1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 0 >> -1" << endl;
  a = 0;
  offset = -1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 0" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 0;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)0x4000000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> 5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = 5;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)0x0400000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> -1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 2^127 >> -5" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset = -5;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 0" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 0;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 1;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xC000000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> 5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = 5;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFC00000000000000, (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> -1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -1;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : -2^127 >> -5" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset = -5;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 2^127 >> max" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 2^127 >> min" << endl;
  a.from_string("170141183460469231731687303715884105728");
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -2^127 >> min" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 5 >> min" << endl;
  a = 5;
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -5 >> min" << endl;
  a = -5;
  offset.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : max >> 5" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  offset = 5;
  a >>= offset;
  check_value(a, (uint64_t)0x03FFFFFFFFFFFFFF, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : min >> 5" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 5;
  a >>= offset;
  check_value(a, (uint64_t)0xFC00000000000000, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 32" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 32;
  a >>= offset;
  check_value(a, (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 64" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 64;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 96" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 96;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 128" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 128;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 160" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 160;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : min >> 192" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 192;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  cout << "Case : min >> 224" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 224;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)0xFFFFFFFF80000000, (int)__LINE__, _result);

  cout << "Case : min >> 256" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  offset = 256;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 32" << endl;
  a = -1;
  offset = 32;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 64" << endl;
  a = -1;
  offset = 64;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 96" << endl;
  a = -1;
  offset = 96;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 128" << endl;
  a = -1;
  offset = 128;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 160" << endl;
  a = -1;
  offset = 160;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 192" << endl;
  a = -1;
  offset = 192;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 224" << endl;
  a = -1;
  offset = 224;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 256" << endl;
  a = -1;
  offset = 256;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 >> 1000" << endl;
  a = -1;
  offset = 1000;
  a >>= offset;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 32" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 32;
  a >>= offset;
  check_value(a, (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 64" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 64;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 96" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 96;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 128" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 128;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 160" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 160;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (uint64_t)(0x1234567800000000), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 192" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 192;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1234567812345678), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 224" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 224;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x0000000012345678), (int)__LINE__, _result);

  cout << "Case : 0x1234567812345678 >> 256" << endl;
  a = (uint64_t)(0x1234567812345678);
  a = a << 192;
  offset = 256;
  a >>= offset;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  if (_result)
  {
    cout << "\nbitwise_right_shift_bigint_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}



void compare_equalto_test()
{
  BigInt a, b, c;
  bool rtv = true;
  bool _result = true;

  // compare_equalto()_test
  cout << "\n==[[equal_to_operator(==)_test]]==================================" << endl << endl;

  cout << "Case : 1 == 1" << endl;
  a = 1;
  b = 1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : 1 == 0" << endl;
  a = 1;
  b = 0;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 1 == -1" << endl;
  a = 1;
  b = -1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 0 == 1" << endl;
  a = 0;
  b = 1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 0 == 0" << endl;
  a = 0;
  b = 0;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : 0 == -1" << endl;
  a = 0;
  b = -1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -1 == 1" << endl;
  a = -1;
  b = 1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -1 == 0" << endl;
  a = -1;
  b = 0;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -1 == -1" << endl;
  a = -1;
  b = -1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : (2^64) == 1" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a + 1;
  b = 1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 1 == 2" << endl;
  a = 1;
  b = a + 1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFE == 0xFFFFFFFFFFFFFFFF" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF == 0xFFFFFFFFFFFFFFFE" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -1 == -2" << endl;
  a = -1;
  b = -2;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -2 == -1" << endl;
  a = -2;
  b = -1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^63) == (2^63)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775808");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : (2^63) == (2^63) + 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775809");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^63) == (2^63) - 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775807");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^127) == (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : (2^127) == (2^127) + 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105729");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^127) == (2^127) - 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105727");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^191) == (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : (2^191) == (2^191) + 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^191) == (2^191) - 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256447");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^63) == -(2^63)" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775808");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : -(2^63) == -(2^63) + 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775807");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^63) == -(2^63) - 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775809");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : --(2^127) == --(2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105728");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : -(2^127) == -(2^127) + 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105727");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^127) == -(2^127) - 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105729");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^191) == -(2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256448");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : -(2^191) == -(2^191) + 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256447");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^191) == -(2^191) - 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256449");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max == 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max == 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 0;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max == -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max == (2^64)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("18446744073709551616");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max == (2^128)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("340282366920938463463374607431768211456");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max == (2^192)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max == min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max == max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : min == 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : min == 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : min == -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : min == (2^64)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("18446744073709551616");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : min == (2^128)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("340282366920938463463374607431768211456");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : min == (2^192)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : min == min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : min == max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  rtv = c.compare_equalto(a,b);
  check_value(rtv, false, __LINE__, _result);

  if (_result)
  {
    cout << "\nequal_to_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void equal_to_operator_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[equal_to_operator(==)_test]]==================================" << endl << endl;

  cout << "Case : 1 == 1" << endl;
  a = 1;
  b = 1;
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : 1 == 0" << endl;
  a = 1;
  b = 0;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : 1 == -1" << endl;
  a = 1;
  b = -1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : 0 == 1" << endl;
  a = 0;
  b = 1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : 0 == 0" << endl;
  a = 0;
  b = 0;
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : 0 == -1" << endl;
  a = 0;
  b = -1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -1 == 1" << endl;
  a = -1;
  b = 1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -1 == 0" << endl;
  a = -1;
  b = 0;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -1 == -1" << endl;
  a = -1;
  b = -1;
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : (2^64) == 1" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a + 1;
  b = 1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : 1 == 2" << endl;
  a = 1;
  b = a + 1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFE == 0xFFFFFFFFFFFFFFFF" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF == 0xFFFFFFFFFFFFFFFE" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -1 == -2" << endl;
  a = -1;
  b = -2;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -2 == -1" << endl;
  a = -2;
  b = -1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : (2^63) == (2^63)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775808");
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : (2^63) == (2^63) + 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775809");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : (2^63) == (2^63) - 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775807");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : (2^127) == (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : (2^127) == (2^127) + 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105729");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : (2^127) == (2^127) - 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105727");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : (2^191) == (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : (2^191) == (2^191) + 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : (2^191) == (2^191) - 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -(2^63) == -(2^63)" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775808");
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : -(2^63) == -(2^63) + 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775807");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -(2^63) == -(2^63) - 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775809");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : --(2^127) == --(2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105728");
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : -(2^127) == -(2^127) + 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105727");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -(2^127) == -(2^127) - 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105729");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -(2^191) == -(2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : -(2^191) == -(2^191) + 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : -(2^191) == -(2^191) - 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : max == 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : max == 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 0;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : max == -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : max == (2^64)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("18446744073709551616");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : max == (2^128)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : max == (2^192)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : max == min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : max == max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : min == 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : min == 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : min == -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : min == (2^64)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("18446744073709551616");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : min == (2^128)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : min == (2^192)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a == b), false, __LINE__, _result);

  cout << "Case : min == min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a == b), true, __LINE__, _result);

  cout << "Case : min == max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a == b), false, __LINE__, _result);

  if (_result)
  {
    cout << "\nequal_to_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void compare_lessthan_test()
{
  BigInt a, b, c;
  bool rtv = true;
  bool _result = true;
  cout << "\n==[[compare_lessthan_test]]==================================" << endl << endl;

  cout << "Case : 1 < 1" << endl;
  a = 1;
  b = 1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 1 < 0" << endl;
  a = 1;
  b = 0;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 1 < -1" << endl;
  a = 1;
  b = -1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 0 < 1" << endl;
  a = 0;
  b = 1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : 0 < 0" << endl;
  a = 0;
  b = 0;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 0 < -1" << endl;
  a = 0;
  b = -1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -1 < 1" << endl;
  a = -1;
  b = 1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : -1 < 0" << endl;
  a = -1;
  b = 0;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : -1 < -1" << endl;
  a = -1;
  b = -1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^64) < 1" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a + 1;
  b = 1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : 1 < 2" << endl;
  a = 1;
  b = a + 1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFE < 0xFFFFFFFFFFFFFFFF" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF < 0xFFFFFFFFFFFFFFFE" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -1 < -2" << endl;
  a = -1;
  b = -2;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -2 < -1" << endl;
  a = -2;
  b = -1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : (2^63) < (2^63)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775808");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^63) < (2^63) + 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775809");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : (2^63) < (2^63) - 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775807");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^127) < (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^127) < (2^127) + 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105729");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : (2^127) < (2^127) - 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105727");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^191) < (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : (2^191) < (2^191) + 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : (2^191) < (2^191) - 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256447");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^63) < -(2^63)" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775808");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^63) < -(2^63) + 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775807");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : -(2^63) < -(2^63) - 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775809");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^127) < -(2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105728");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^127) < -(2^127) + 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105727");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : -(2^127) < -(2^127) - 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105729");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^191) < -(2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256448");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : -(2^191) < -(2^191) + 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256447");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : -(2^191) < -(2^191) - 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256449");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);


  cout << "Case : max < 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max < 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 0;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max < -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max < (2^64)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("18446744073709551616");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max < (2^128)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("340282366920938463463374607431768211456");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max < (2^192)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max < min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : max < max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : min < 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : min < 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : min < -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : min < (2^64)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("18446744073709551616");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : min < (2^128)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("340282366920938463463374607431768211456");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : min < (2^192)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  cout << "Case : min < min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, false, __LINE__, _result);

  cout << "Case : min < max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  rtv = c.compare_lessthan(a,b);
  check_value(rtv, true, __LINE__, _result);

  if (_result)
  {
    cout << "\ncompare_lessthan_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void less_than_operator_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[less_than_operator(<)_test]]==================================" << endl << endl;

  cout << "Case : 1 < 1" << endl;
  a = 1;
  b = 1;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : 1 < 0" << endl;
  a = 1;
  b = 0;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : 1 < -1" << endl;
  a = 1;
  b = -1;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : 0 < 1" << endl;
  a = 0;
  b = 1;
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : 0 < 0" << endl;
  a = 0;
  b = 0;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : 0 < -1" << endl;
  a = 0;
  b = -1;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : -1 < 1" << endl;
  a = -1;
  b = 1;
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : -1 < 0" << endl;
  a = -1;
  b = 0;
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : -1 < -1" << endl;
  a = -1;
  b = -1;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : (2^64) < 1" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a + 1;
  b = 1;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : 1 < 2" << endl;
  a = 1;
  b = a + 1;
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFE < 0xFFFFFFFFFFFFFFFF" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF < 0xFFFFFFFFFFFFFFFE" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : -1 < -2" << endl;
  a = -1;
  b = -2;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : -2 < -1" << endl;
  a = -2;
  b = -1;
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : (2^63) < (2^63)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775808");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : (2^63) < (2^63) + 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775809");
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : (2^63) < (2^63) - 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775807");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : (2^127) < (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : (2^127) < (2^127) + 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105729");
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : (2^127) < (2^127) - 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105727");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : (2^191) < (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : (2^191) < (2^191) + 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : (2^191) < (2^191) - 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : -(2^63) < -(2^63)" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775808");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : -(2^63) < -(2^63) + 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775807");
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : -(2^63) < -(2^63) - 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775809");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : -(2^127) < -(2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105728");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : -(2^127) < -(2^127) + 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105727");
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : -(2^127) < -(2^127) - 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105729");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : -(2^191) < -(2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : -(2^191) < -(2^191) + 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : -(2^191) < -(2^191) - 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : max < 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : max < 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 0;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : max < -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : max < (2^64)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("18446744073709551616");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : max < (2^128)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : max < (2^192)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : max < min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : max < max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : min < 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : min < 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : min < -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : min < (2^64)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("18446744073709551616");
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : min < (2^128)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : min < (2^192)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a < b), true, __LINE__, _result);

  cout << "Case : min < min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a < b), false, __LINE__, _result);

  cout << "Case : min < max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a < b), true, __LINE__, _result);

  if (_result)
  {
    cout << "\nless_than_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void less_than_or_equal_to_operator_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[less_than_or_equal_to_operator(<=)_test]]==================================" << endl << endl;

  cout << "Case : 1 <= 1" << endl;
  a = 1;
  b = 1;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : 1 <= 0" << endl;
  a = 1;
  b = 0;
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : 1 <= -1" << endl;
  a = 1;
  b = -1;
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : 0 <= 1" << endl;
  a = 0;
  b = 1;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : 0 <= 0" << endl;
  a = 0;
  b = 0;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : 0 <= -1" << endl;
  a = 0;
  b = -1;
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : -1 <= 1" << endl;
  a = -1;
  b = 1;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : -1 <= 0" << endl;
  a = -1;
  b = 0;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : -1 <= -1" << endl;
  a = -1;
  b = -1;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : (2^64) <= 1" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a + 1;
  b = 1;
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : 1 <= 2" << endl;
  a = 1;
  b = a + 1;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFE <= 0xFFFFFFFFFFFFFFFF" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF <= 0xFFFFFFFFFFFFFFFE" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : -1 <= -2" << endl;
  a = -1;
  b = -2;
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : -2 <= -1" << endl;
  a = -2;
  b = -1;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : (2^63) <= (2^63)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775808");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : (2^63) <= (2^63) + 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775809");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : (2^63) <= (2^63) - 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775807");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : (2^127) <= (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : (2^127) <= (2^127) + 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105729");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : (2^127) <= (2^127) - 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105727");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : (2^191) <= (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : (2^191) <= (2^191) + 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : (2^191) <= (2^191) - 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : -(2^63) <= -(2^63)" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775808");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : -(2^63) <= -(2^63) + 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775807");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : -(2^63) <= -(2^63) - 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775809");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : -(2^127) <= -(2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105728");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : -(2^127) <= -(2^127) + 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105727");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : -(2^127) <= -(2^127) - 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105729");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : -(2^191) <= -(2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : -(2^191) <= -(2^191) + 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : -(2^191) <= -(2^191) - 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : max <= 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : max <= 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 0;
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : max <= -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : max <= (2^64)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("18446744073709551616");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : max <= (2^128)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : max <= (2^192)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : max <= min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a <= b), false, __LINE__, _result);

  cout << "Case : max <= max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : min <= 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : min <= 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : min <= -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : min <= (2^64)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("18446744073709551616");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : min <= (2^128)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : min <= (2^192)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : min <= min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a <= b), true, __LINE__, _result);

  cout << "Case : min <= max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a <= b), true, __LINE__, _result);

  if (_result)
  {
    cout << "\nless_than_or_equal_to_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void greater_than_operator_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[greater_than_operator(>)_test]]==================================" << endl << endl;

  cout << "Case : 1 > 1" << endl;
  a = 1;
  b = 1;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : 1 > 0" << endl;
  a = 1;
  b = 0;
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : 1 > -1" << endl;
  a = 1;
  b = -1;
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : 0 > 1" << endl;
  a = 0;
  b = 1;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : 0 > 0" << endl;
  a = 0;
  b = 0;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : 0 > -1" << endl;
  a = 0;
  b = -1;
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : -1 > 1" << endl;
  a = -1;
  b = 1;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : -1 > 0" << endl;
  a = -1;
  b = 0;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : -1 > -1" << endl;
  a = -1;
  b = -1;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : (2^64) > 1" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a + 1;
  b = 1;
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : 1 > 2" << endl;
  a = 1;
  b = a + 1;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFE > 0xFFFFFFFFFFFFFFFF" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF > 0xFFFFFFFFFFFFFFFE" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : -1 > -2" << endl;
  a = -1;
  b = -2;
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : -2 > -1" << endl;
  a = -2;
  b = -1;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : (2^63) > (2^63)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775808");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : (2^63) > (2^63) + 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775809");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : (2^63) > (2^63) - 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775807");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : (2^127) > (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : (2^127) > (2^127) + 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105729");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : (2^127) > (2^127) - 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105727");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : (2^191) > (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : (2^191) > (2^191) + 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : (2^191) > (2^191) - 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : -(2^63) > -(2^63)" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775808");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : -(2^63) > -(2^63) + 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775807");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : -(2^63) > -(2^63) - 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775809");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : -(2^127) > -(2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105728");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : -(2^127) > -(2^127) + 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105727");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : -(2^127) > -(2^127) - 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105729");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : -(2^191) > -(2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : -(2^191) > -(2^191) + 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : -(2^191) > -(2^191) - 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : max > 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : max > 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 0;
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : max > -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : max > (2^64)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("18446744073709551616");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : max > (2^128)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : max > (2^192)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : max > min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a > b), true, __LINE__, _result);

  cout << "Case : max > max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : min > 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : min > 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : min > -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : min > (2^64)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("18446744073709551616");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : min > (2^128)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : min > (2^192)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : min > min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a > b), false, __LINE__, _result);

  cout << "Case : min > max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a > b), false, __LINE__, _result);

  if (_result)
  {
    cout << "\ngreater_than_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void greater_than_or_equal_to_operator_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[greater_than_or_equal_to_operator(>=)_test]]==================================" << endl << endl;

  cout << "Case : 1 >= 1" << endl;
  a = 1;
  b = 1;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : 1 >= 0" << endl;
  a = 1;
  b = 0;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : 1 >= -1" << endl;
  a = 1;
  b = -1;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : 0 >= 1" << endl;
  a = 0;
  b = 1;
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : 0 >= 0" << endl;
  a = 0;
  b = 0;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : 0 >= -1" << endl;
  a = 0;
  b = -1;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : -1 >= 1" << endl;
  a = -1;
  b = 1;
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : -1 >= 0" << endl;
  a = -1;
  b = 0;
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : -1 >= -1" << endl;
  a = -1;
  b = -1;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : (2^64) >= 1" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a + 1;
  b = 1;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : 1 >= 2" << endl;
  a = 1;
  b = a + 1;
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFE >= 0xFFFFFFFFFFFFFFFF" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF >= 0xFFFFFFFFFFFFFFFE" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : -1 >= -2" << endl;
  a = -1;
  b = -2;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : -2 >= -1" << endl;
  a = -2;
  b = -1;
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : (2^63) >= (2^63)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775808");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : (2^63) >= (2^63) + 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775809");
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : (2^63) >= (2^63) - 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775807");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : (2^127) >= (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : (2^127) >= (2^127) + 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105729");
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : (2^127) >= (2^127) - 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105727");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : (2^191) >= (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : (2^191) >= (2^191) + 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : (2^191) >= (2^191) - 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : -(2^63) >= -(2^63)" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775808");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : -(2^63) >= -(2^63) + 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775807");
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : -(2^63) >= -(2^63) - 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775809");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : -(2^127) >= -(2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105728");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : -(2^127) >= -(2^127) + 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105727");
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : -(2^127) >= -(2^127) - 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105729");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : -(2^191) >= -(2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : -(2^191) >= -(2^191) + 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : -(2^191) >= -(2^191) - 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : max >= 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : max >= 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 0;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : max >= -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : max >= (2^64)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("18446744073709551616");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : max >= (2^128)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : max >= (2^192)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : max >= min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : max >= max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : min >= 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : min >= 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : min >= -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : min >= (2^64)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("18446744073709551616");
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : min >= (2^128)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : min >= (2^192)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a >= b), false, __LINE__, _result);

  cout << "Case : min >= min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a >= b), true, __LINE__, _result);

  cout << "Case : min >= max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a >= b), false, __LINE__, _result);

  if (_result)
  {
    cout << "\ngreater_than_or_equal_to_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void not_equal_to_operator_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[not_equal_to_operator(!=)_test]]==================================" << endl << endl;

  cout << "Case : 1 != 1" << endl;
  a = 1;
  b = 1;
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : 1 != 0" << endl;
  a = 1;
  b = 0;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : 1 != -1" << endl;
  a = 1;
  b = -1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : 0 != 1" << endl;
  a = 0;
  b = 1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : 0 != 0" << endl;
  a = 0;
  b = 0;
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : 0 != -1" << endl;
  a = 0;
  b = -1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -1 != 1" << endl;
  a = -1;
  b = 1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -1 != 0" << endl;
  a = -1;
  b = 0;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -1 != -1" << endl;
  a = -1;
  b = -1;
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : (2^64) != 1" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  a = a + 1;
  b = 1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : 1 != 2" << endl;
  a = 1;
  b = a + 1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFE != 0xFFFFFFFFFFFFFFFF" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF != 0xFFFFFFFFFFFFFFFE" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = (uint64_t)(0xFFFFFFFFFFFFFFFE);
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -1 != -2" << endl;
  a = -1;
  b = -2;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -2 != -1" << endl;
  a = -2;
  b = -1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : (2^63) != (2^63)" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775808");
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : (2^63) != (2^63) + 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775809");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : (2^63) != (2^63) - 1" << endl;
  a.from_string("9223372036854775808");
  b.from_string("9223372036854775807");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : (2^127) != (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105728");
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : (2^127) != (2^127) + 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105729");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : (2^127) != (2^127) - 1" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b.from_string("170141183460469231731687303715884105727");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : (2^191) != (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : (2^191) != (2^191) + 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : (2^191) != (2^191) - 1" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b.from_string("3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -(2^63) != -(2^63)" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775808");
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : -(2^63) != -(2^63) + 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775807");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -(2^63) != -(2^63) - 1" << endl;
  a.from_string("-9223372036854775808");
  b.from_string("-9223372036854775809");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -(2^127) != -(2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105728");
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : -(2^127) != -(2^127) + 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105727");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -(2^127) != -(2^127) - 1" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b.from_string("-170141183460469231731687303715884105729");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -(2^191) != -(2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256448");
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : -(2^191) != -(2^191) + 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256447");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : -(2^191) != -(2^191) - 1" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b.from_string("-3138550867693340381917894711603833208051177722232017256449");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : max != 1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : max != 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 0;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : max != -1" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : max != (2^64)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("18446744073709551616");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : max != (2^128)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : max != (2^192)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : max != min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : max != max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : min != 1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : min != 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : min != -1" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -1;
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : min != (2^64)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("18446744073709551616");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : min != (2^128)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("340282366920938463463374607431768211456");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : min != (2^192)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(a != b), true, __LINE__, _result);

  cout << "Case : min != min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a != b), false, __LINE__, _result);

  cout << "Case : min != max" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(a != b), true, __LINE__, _result);

  if (_result)
  {
    cout << "\nnot_equal_to_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}


void logical_negation_test()
{
  BigInt a;
  bool _result = true;
  cout << "\n==[[logical_negation_test(!)]]==================================" << endl << endl;

  cout << "Case : !1" << endl;
  a = 1;
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !-1" << endl;
  a = -1;
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !0" << endl;
  a = 0;
  check_value((bool)(!a), true, __LINE__, _result);

  cout << "Case : !(2^32)" << endl;
  a.from_string("4294967296");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^32 - 1)" << endl;
  a.from_string("4294967295");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^64)" << endl;
  a.from_string("18446744073709551616");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^64 - 1)" << endl;
  a.from_string("18446744073709551615");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^96)" << endl;
  a.from_string("79228162514264337593543950336");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^96 - 1)" << endl;
  a.from_string("79228162514264337593543950335");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^128)" << endl;
  a.from_string("340282366920938463463374607431768211456");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^128 - 1)" << endl;
  a.from_string("340282366920938463463374607431768211455");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^160)" << endl;
  a.from_string("1461501637330902918203684832716283019655932542976");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^160 - 1)" << endl;
  a.from_string("1461501637330902918203684832716283019655932542975");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^192)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^192 - 1)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512895");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^224)" << endl;
  a.from_string("26959946667150639794667015087019630673637144422540572481103610249216");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^224 - 1)" << endl;
  a.from_string("26959946667150639794667015087019630673637144422540572481103610249215");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(2^256)" << endl;
  a.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639936");
  check_value((bool)(!a), true, __LINE__, _result);

  cout << "Case : !(2^256 - 1)" << endl;
  a.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639935");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^32)" << endl;
  a.from_string("-4294967296");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^32 - 1)" << endl;
  a.from_string("-4294967297");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^64)" << endl;
  a.from_string("-18446744073709551616");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^64 - 1)" << endl;
  a.from_string("-18446744073709551617");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^96)" << endl;
  a.from_string("-79228162514264337593543950336");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^96 - 1)" << endl;
  a.from_string("-79228162514264337593543950337");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^128)" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^128 - 1)" << endl;
  a.from_string("-340282366920938463463374607431768211457");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^160)" << endl;
  a.from_string("-1461501637330902918203684832716283019655932542976");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^160 - 1)" << endl;
  a.from_string("-1461501637330902918203684832716283019655932542977");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^192)" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^192 - 1)" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512897");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^224)" << endl;
  a.from_string("-26959946667150639794667015087019630673637144422540572481103610249216");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^224 - 1)" << endl;
  a.from_string("-26959946667150639794667015087019630673637144422540572481103610249217");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !(-2^256)" << endl;
  a.from_string("-115792089237316195423570985008687907853269984665640564039457584007913129639936");
  check_value((bool)(!a), true, __LINE__, _result);

  cout << "Case : !(-2^256 - 1)" << endl;
  a.from_string("-115792089237316195423570985008687907853269984665640564039457584007913129639937");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  check_value((bool)(!a), false, __LINE__, _result);

  cout << "Case : !min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(!a), false, __LINE__, _result);


  if (_result)
  {
    cout << "\nlogical_negation_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void logical_AND_test()
{
  BigInt a, b;

  bool _result = true;
  cout << "\n==[[logical_AND(&&)_test_test]]==================================" << endl << endl;

  cout << "Case : 1 && 1" << endl;
  a = 1;
  b = 1;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 1 && -1" << endl;
  a = 1;
  b = -1;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 1 && 0" << endl;
  a = 1;
  b = 0;
  check_value((bool)(a && b), false, __LINE__, _result);

  cout << "Case : -1 && 1" << endl;
  a = -1;
  b = 1;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : -1 && -1" << endl;
  a = -1;
  b = -1;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : -1 && 0" << endl;
  a = -1;
  b = 0;
  check_value((bool)(a && b), false, __LINE__, _result);
  cout << "Case : 0 && 1" << endl;
  a = 0;
  b = 1;
  check_value((bool)(a && b), false, __LINE__, _result);

  cout << "Case : 0 && -1" << endl;
  a = 0;
  b = -1;
  check_value((bool)(a && b), false, __LINE__, _result);

  cout << "Case : 0 && 0" << endl;
  a = 0;
  b = 0;
  check_value((bool)(a && b), false, __LINE__, _result);

  cout << "Case : 1 & 2" << endl;
  a = 1;
  b = 2;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : -1 && 2" << endl;
  a = -1;
  b = 2;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 1 && -2" << endl;
  a = 1;
  b = -2;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : -1 && -2" << endl;
  a = -1;
  b = -2;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 0xAAA... && 0" << endl;
  // 101010101010...10
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = 0;
  check_value((bool)(a && b), false, __LINE__, _result);

  cout << "Case : 0xF0F0... && 0" << endl;
  // 1111000011110000...11110000
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = 0;
  check_value((bool)(a && b), false, __LINE__, _result);

  cout << "Case : 0x555... && 0" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = 0;
  check_value((bool)(a && b), false, __LINE__, _result);

  cout << "Case : 0x0F0F... && 0" << endl;
  // 0000111100001111...00001111
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = 0;
  check_value((bool)(a && b), false, __LINE__, _result);

  cout << "Case : 0xAAA... && -1" << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = -1;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 0xF0F0... && -1" << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = -1;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 0x555... && -1" << endl;
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = -1;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 0x0F0F... && -1" << endl;
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = -1;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 0xAAA... && 0x555..." << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 0xF0F0... && 0x0F0F..." << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : 123456 && 234567" << endl;
  a = 123456;
  b = 234567;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : max && min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : max && 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value((bool)(a && b), true, __LINE__, _result);

  cout << "Case : min && 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  check_value((bool)(a && b), false, __LINE__, _result);


  if (_result)
  {
    cout << "\nlogical_AND_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void logical_OR_test()
{
  BigInt a, b;

  bool _result = true;
  cout << "\n==[[logical_OR(||)_test_test]]==================================" << endl << endl;

  cout << "Case : 1 || 1" << endl;
  a = 1;
  b = 1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 1 || -1" << endl;
  a = 1;
  b = -1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 1 || 0" << endl;
  a = 1;
  b = 0;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : -1 || 1" << endl;
  a = -1;
  b = 1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : -1 || -1" << endl;
  a = -1;
  b = -1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : -1 || 0" << endl;
  a = -1;
  b = 0;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0 || 1" << endl;
  a = 0;
  b = 1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0 || -1" << endl;
  a = 0;
  b = -1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0 || 0" << endl;
  a = 0;
  b = 0;
  check_value((bool)(a || b), false, __LINE__, _result);

  cout << "Case : 1 || 2" << endl;
  a = 1;
  b = 2;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : -1 || 2" << endl;
  a = -1;
  b = 2;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 1 || -2" << endl;
  a = 1;
  b = -2;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : -1 || -2" << endl;
  a = -1;
  b = -2;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0xAAA... || 0" << endl;
  // 101010101010...10
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = 0;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0xF0F0... || 0" << endl;
  // 1111000011110000...11110000
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = 0;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0x555... || 0" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = 0;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0x0F0F... || 0" << endl;
  // 0000111100001111...00001111
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = 0;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0xAAA... || -1" << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = -1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0xF0F0... || -1" << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = -1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0x555... || -1" << endl;
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = -1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0x0F0F... || -1" << endl;
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = -1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0xAAA... || 0x555..." << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 0xF0F0... || 0x0F0F..." << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : 123456 || 234567" << endl;
  a = 123456;
  b = 234567;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : max || min" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : max || 0" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = -1;
  check_value((bool)(a || b), true, __LINE__, _result);

  cout << "Case : min || 0" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 0;
  check_value((bool)(a || b), true, __LINE__, _result);


  if (_result)
  {
    cout << "\nlogical_OR_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}


void bitwise_NOT_test()
{
  BigInt a, b;

  bool _result = true;
  cout << "\n==[[bitwise_NOT_test(~)_test]]==================================" << endl << endl;

  cout << "Case : ~0" << endl;
  a = 0;
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ~1" << endl;
  a = 1;
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : ~-1" << endl;
  a = -1;
  b = ~a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ~2" << endl;
  a = 2;
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : ~-2" << endl;
  a = -2;
  b = ~a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ~(2^32-1)" << endl;
  a.from_string("4294967295");
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (int)__LINE__, _result);

  cout << "Case : ~(-2^32)" << endl;
  a.from_string("-4294967296");
  b = ~a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00000000FFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ~(2^64-1)" << endl;
  a.from_string("18446744073709551615");
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ~(-2^64)" << endl;
  a.from_string("-18446744073709551616");
  b = ~a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ~(2^96-1)" << endl;
  a.from_string("79228162514264337593543950335");
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ~(-2^96)" << endl;
  a.from_string("-79228162514264337593543950336");
  b = ~a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x00000000FFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ~(2^128-1)" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ~(-2^128)" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  b = ~a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ~(2^160-1)" << endl;
  a.from_string("1461501637330902918203684832716283019655932542975");
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ~(-2^160)" << endl;
  a.from_string("-1461501637330902918203684832716283019655932542976");
  b = ~a;
  check_value(b, (uint64_t)(0), (uint64_t)(0x00000000FFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ~(2^192-1)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512895");
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ~(-2^192)" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  b = ~a;
  check_value(b, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ~(2^224-1)" << endl;
  a.from_string("26959946667150639794667015087019630673637144422540572481103610249215");
  b = ~a;
  check_value(b, (uint64_t)(0xFFFFFFFF00000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ~(-2^224)" << endl;
  a.from_string("-26959946667150639794667015087019630673637144422540572481103610249216");
  b = ~a;
  check_value(b, (uint64_t)(0x00000000FFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ~max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = ~a;
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ~min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = ~a;
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : ~0xAAA... " << endl;
  // 101010101010...10
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = ~a;
  check_value(b, (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  cout << "Case : ~0xF0F0... " << endl;
  // 1111000011110000...11110000
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = ~a;
  check_value(b, (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (int)__LINE__, _result);

  cout << "Case : ~0x555... " << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = ~a;
  check_value(b, (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  cout << "Case : ~0x0F0F... " << endl;
  // 0000111100001111...00001111
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = ~a;
  check_value(b, (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (int)__LINE__, _result);


  if (_result)
  {
    cout << "\nbitwise_NOT_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_AND_test()
{
  BigInt a, b, c;

  bool _result = true;
  cout << "\n==[[bitwise_AND_test(&)_test]]==================================" << endl << endl;

  cout << "Case : 1 & 0" << endl;
  a = 1;
  b = 0;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 & 0" << endl;
  a = -1;
  b = 0;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0 & 0" << endl;
  a = 0;
  b = 0;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 & 1" << endl;
  a = 1;
  b = 1;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 & 1" << endl;
  a = -1;
  b = 1;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 0 & 1" << endl;
  a = 0;
  b = 1;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 & -1" << endl;
  a = 1;
  b = -1;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 & -1" << endl;
  a = -1;
  b = -1;
  c = a & b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 & -1" << endl;
  a = 0;
  b = -1;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 & 2" << endl;
  a = 1;
  b = 2;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 & 2" << endl;
  a = -1;
  b = 2;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 1 & -2" << endl;
  a = 1;
  b = -2;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 & -2" << endl;
  a = -1;
  b = -2;
  c = a & b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0xAAA... & 0" << endl;
  // 101010101010...10
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = 0;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... & 0" << endl;
  // 1111000011110000...11110000
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = 0;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x555... & 0" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = 0;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... & 0" << endl;
  // 0000111100001111...00001111
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = 0;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xAAA... & -1" << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = -1;
  c = a & b;
  check_value(c, (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... & -1" << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = -1;
  c = a & b;
  check_value(c, (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (int)__LINE__, _result);

  cout << "Case : 0x555... & -1" << endl;
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = -1;
  c = a & b;
  check_value(c, (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... & -1" << endl;
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = -1;
  c = a & b;
  check_value(c, (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (int)__LINE__, _result);

  cout << "Case : 0xAAA... & 0x555..." << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... & 0x0F0F..." << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);


  cout << "Case : 123456 & 234567" << endl;
  a = 123456;
  b = 234567;
  c = a & b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x18040), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_AND_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_OR_test()
{
  BigInt a, b, c;

  bool _result = true;
  cout << "\n==[[bitwise_OR_test(|)_test]]==================================" << endl << endl;

  // bitwise_OR(|)_test

  cout << "Case : 1 | 0" << endl;
  a = 1;
  b = 0;
  c = a | b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 | 0" << endl;
  a = -1;
  b = 0;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 | 0" << endl;
  a = 0;
  b = 0;
  c = a | b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 | 1" << endl;
  a = 1;
  b = 1;
  c = a | b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 | 1" << endl;
  a = -1;
  b = 1;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 | 1" << endl;
  a = 0;
  b = 1;
  c = a | b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1 | -1" << endl;
  a = 1;
  b = -1;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 | -1" << endl;
  a = -1;
  b = -1;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 | -1" << endl;
  a = 0;
  b = -1;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1 | 2" << endl;
  a = 1;
  b = 2;
  c = a | b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  cout << "Case : -1 | 2" << endl;
  a = -1;
  b = 2;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1 | -2" << endl;
  a = 1;
  b = -2;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 | -2" << endl;
  a = -1;
  b = -2;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xAAA... | 0" << endl;
  // 101010101010...10
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = 0;
  c = a | b;
  check_value(c, (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... | 0" << endl;
  // 1111000011110000...11110000
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = 0;
  c = a | b;
  check_value(c, (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (int)__LINE__, _result);

  cout << "Case : 0x555... | 0" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = 0;
  c = a | b;
  check_value(c, (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... | 0" << endl;
  // 0000111100001111...00001111
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = 0;
  c = a | b;
  check_value(c, (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (int)__LINE__, _result);

  cout << "Case : 0xAAA... | -1" << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = -1;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... | -1" << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = -1;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0x555... | -1" << endl;
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = -1;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... | -1" << endl;
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = -1;
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xAAA... | 0x555..." << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... | 0x0F0F..." << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  c = a | b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 123456 | 234567" << endl;
  a = 123456;
  b = 234567;
  c = a | b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(259655), (int)__LINE__, _result);


  if (_result)
  {
    cout << "\nbitwise_OR_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_XOR_test()
{
  BigInt a, b, c;

  bool _result = true;
  cout << "\n==[[bitwise_XOR_test(^)_test]]==================================" << endl << endl;


  cout << "Case : 1 ^ 0" << endl;
  a = 1;
  b = 0;
  c = a ^ b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 ^ 0" << endl;
  a = -1;
  b = 0;
  c = a ^ b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 ^ 0" << endl;
  a = 0;
  b = 0;
  c = a ^ b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 ^ 1" << endl;
  a = 1;
  b = 1;
  c = a ^ b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 ^ 1" << endl;
  a = -1;
  b = 1;
  c = a ^ b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0 ^ 1" << endl;
  a = 0;
  b = 1;
  c = a ^ b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1 ^ -1" << endl;
  a = 1;
  b = -1;
  c = a ^ b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : -1 ^ -1" << endl;
  a = -1;
  b = -1;
  c = a ^ b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0 ^ -1" << endl;
  a = 0;
  b = -1;
  c = a ^ b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1 ^ 2" << endl;
  a = 1;
  b = 2;
  c = a ^ b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  cout << "Case : -1 ^ 2" << endl;
  a = -1;
  b = 2;
  c = a ^ b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : 1 ^ -2" << endl;
  a = 1;
  b = -2;
  c = a ^ b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 ^ -2" << endl;
  a = -1;
  b = -2;
  c = a ^ b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 0xAAA... ^ 0" << endl;
  // 101010101010...10
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = 0;
  c = a ^ b;
  check_value(c, (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... ^ 0" << endl;
  // 1111000011110000...11110000
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = 0;
  c = a ^ b;
  check_value(c, (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (int)__LINE__, _result);

  cout << "Case : 0x555... ^ 0" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = 0;
  c = a ^ b;
  check_value(c, (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... ^ 0" << endl;
  // 0000111100001111...00001111
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = 0;
  c = a ^ b;
  check_value(c, (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (int)__LINE__, _result);

  cout << "Case : 0xAAA... ^ -1" << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = -1;
  c = a ^ b;
  check_value(c, (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... ^ -1" << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = -1;
  c = a ^ b;
  check_value(c, (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (int)__LINE__, _result);

  cout << "Case : 0x555... ^ -1" << endl;
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = -1;
  c = a ^ b;
  check_value(c, (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... ^ -1" << endl;
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = -1;
  c = a ^ b;
  check_value(c, (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (int)__LINE__, _result);

  cout << "Case : 0xAAA... ^ 0x555..." << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  c = a ^ b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... ^ 0x0F0F..." << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  c = a ^ b;
  check_value(c, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 123456 ^ 234567" << endl;
  a = 123456;
  b = 234567;
  c = a ^ b;
  check_value(c, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(161287), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_XOR_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_AND_assignment_operator_test()
{
  BigInt a, b;

  bool _result = true;
  cout << "\n==[[bitwise_AND_assignment_operator(&=)_test]]==================================" << endl << endl;

  cout << "Case : 1 & 0" << endl;
  a = 1;
  b = 0;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 & 0" << endl;
  a = -1;
  b = 0;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0 & 0" << endl;
  a = 0;
  b = 0;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 & 1" << endl;
  a = 1;
  b = 1;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 & 1" << endl;
  a = -1;
  b = 1;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 0 & 1" << endl;
  a = 0;
  b = 1;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 & -1" << endl;
  a = 1;
  b = -1;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 & -1" << endl;
  a = -1;
  b = -1;
  a &= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 & -1" << endl;
  a = 0;
  b = -1;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 & 2" << endl;
  a = 1;
  b = 2;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 & 2" << endl;
  a = -1;
  b = 2;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 1 & -2" << endl;
  a = 1;
  b = -2;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 & -2" << endl;
  a = -1;
  b = -2;
  a &= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0xAAA... & 0" << endl;
  // 101010101010...10
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = 0;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... & 0" << endl;
  // 1111000011110000...11110000
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = 0;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x555... & 0" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = 0;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... & 0" << endl;
  // 0000111100001111...00001111
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = 0;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xAAA... & -1" << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = -1;
  a &= b;
  check_value(a, (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... & -1" << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = -1;
  a &= b;
  check_value(a, (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (int)__LINE__, _result);

  cout << "Case : 0x555... & -1" << endl;
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = -1;
  a &= b;
  check_value(a, (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... & -1" << endl;
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = -1;
  a &= b;
  check_value(a, (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (int)__LINE__, _result);

  cout << "Case : 0xAAA... & 0x555..." << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... & 0x0F0F..." << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 123456 & 234567" << endl;
  a = 123456;
  b = 234567;
  a &= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x18040), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_AND_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_OR_assignment_operator_test()
{
  BigInt a, b, c;

  bool _result = true;
  cout << "\n==[[bitwise_OR_assignment_operator(|=)_test]]==================================" << endl << endl;

  // bitwise_OR(|)_test

  cout << "Case : 1 | 0" << endl;
  a = 1;
  b = 0;
  a |= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 | 0" << endl;
  a = -1;
  b = 0;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 | 0" << endl;
  a = 0;
  b = 0;
  a |= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 | 1" << endl;
  a = 1;
  b = 1;
  a |= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 | 1" << endl;
  a = -1;
  b = 1;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 | 1" << endl;
  a = 0;
  b = 1;
  a |= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1 | -1" << endl;
  a = 1;
  b = -1;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 | -1" << endl;
  a = -1;
  b = -1;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 | -1" << endl;
  a = 0;
  b = -1;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1 | 2" << endl;
  a = 1;
  b = 2;
  a |= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  cout << "Case : -1 | 2" << endl;
  a = -1;
  b = 2;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1 | -2" << endl;
  a = 1;
  b = -2;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 | -2" << endl;
  a = -1;
  b = -2;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xAAA... | 0" << endl;
  // 101010101010...10
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = 0;
  a |= b;
  check_value(a, (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... | 0" << endl;
  // 1111000011110000...11110000
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = 0;
  a |= b;
  check_value(a, (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (int)__LINE__, _result);

  cout << "Case : 0x555... | 0" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = 0;
  a |= b;
  check_value(a, (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... | 0" << endl;
  // 0000111100001111...00001111
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = 0;
  a |= b;
  check_value(a, (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (int)__LINE__, _result);

  cout << "Case : 0xAAA... | -1" << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = -1;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... | -1" << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = -1;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0x555... | -1" << endl;
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = -1;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... | -1" << endl;
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = -1;
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xAAA... | 0x555..." << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... | 0x0F0F..." << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  a |= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 123456 | 234567" << endl;
  a = 123456;
  b = 234567;
  a |= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(259655), (int)__LINE__, _result);


  if (_result)
  {
    cout << "\nbitwise_OR_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void bitwise_XOR_assignment_operator_test()
{
  BigInt a, b, c;

  bool _result = true;
  cout << "\n==[[bitwise_XOR_assignment_operator(^=)_test]]==================================" << endl << endl;


  cout << "Case : 1 ^ 0" << endl;
  a = 1;
  b = 0;
  a ^= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1 ^ 0" << endl;
  a = -1;
  b = 0;
  a ^= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0 ^ 0" << endl;
  a = 0;
  b = 0;
  a ^= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1 ^ 1" << endl;
  a = 1;
  b = 1;
  a ^= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -1 ^ 1" << endl;
  a = -1;
  b = 1;
  a ^= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0 ^ 1" << endl;
  a = 0;
  b = 1;
  a ^= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1 ^ -1" << endl;
  a = 1;
  b = -1;
  a ^= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : -1 ^ -1" << endl;
  a = -1;
  b = -1;
  a ^= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0 ^ -1" << endl;
  a = 0;
  b = -1;
  a ^= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 1 ^ 2" << endl;
  a = 1;
  b = 2;
  a ^= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  cout << "Case : -1 ^ 2" << endl;
  a = -1;
  b = 2;
  a ^= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : 1 ^ -2" << endl;
  a = 1;
  b = -2;
  a ^= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1 ^ -2" << endl;
  a = -1;
  b = -2;
  a ^= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 0xAAA... ^ 0" << endl;
  // 101010101010...10
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = 0;
  a ^= b;
  check_value(a, (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... ^ 0" << endl;
  // 1111000011110000...11110000
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = 0;
  a ^= b;
  check_value(a, (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (int)__LINE__, _result);

  cout << "Case : 0x555... ^ 0" << endl;
  // 010101010101...01
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = 0;
  a ^= b;
  check_value(a, (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... ^ 0" << endl;
  // 0000111100001111...00001111
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = 0;
  a ^= b;
  check_value(a, (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (int)__LINE__, _result);

  cout << "Case : 0xAAA... ^ -1" << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b = -1;
  a ^= b;
  check_value(a, (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (uint64_t)(0x5555555555555555), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... ^ -1" << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b = -1;
  a ^= b;
  check_value(a, (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (uint64_t)(0x0F0F0F0F0F0F0F0F), (int)__LINE__, _result);

  cout << "Case : 0x555... ^ -1" << endl;
  a.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  b = -1;
  a ^= b;
  check_value(a, (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (uint64_t)(0xAAAAAAAAAAAAAAAA), (int)__LINE__, _result);

  cout << "Case : 0x0F0F... ^ -1" << endl;
  a.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  b = -1;
  a ^= b;
  check_value(a, (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (uint64_t)(0xF0F0F0F0F0F0F0F0), (int)__LINE__, _result);

  cout << "Case : 0xAAA... ^ 0x555..." << endl;
  a.from_string("-38597363079105398474523661669562635951089994888546854679819194669304376546646");
  b.from_string("38597363079105398474523661669562635951089994888546854679819194669304376546645");
  a ^= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0xF0F0... ^ 0x0F0F..." << endl;
  a.from_string("-6811299366900952671974763824040465167839410862684739061144563765171360567056");
  b.from_string("6811299366900952671974763824040465167839410862684739061144563765171360567055");
  a ^= b;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);


  cout << "Case : 123456 ^ 234567" << endl;
  a = 123456;
  b = 234567;
  a ^= b;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(161287), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nbitwise_XOR_assignment_operator_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}


void increment_prefix_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[increment_prefix(++)_test]]==================================" << endl << endl;

  cout << "Case : ++1" << endl;
  a = 1;
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : ++1" << endl;
  a = 1;
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : ++++1" << endl;
  a = 1;
  b = 0;
  b = ++++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);

  cout << "Case : (++1)++" << endl;
  a = 1;
  b = 1;
  b = (++a)++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : ++0" << endl;
  a = 0;
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ++++0" << endl;
  a = 0;
  b = 1;
  b = ++++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : (++0)++" << endl;
  a = 0;
  b = 1;
  b = (++a)++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ++(-1)" << endl;
  a = -1;
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++++(-1)" << endl;
  a = -1;
  b = 1;
  b = ++++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : (++(-1))++" << endl;
  a = -1;
  b = 1;
  b = (++a)++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++18446744073709551617" << endl;
  a.from_string("18446744073709551617");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : ++36893488147419103230" << endl;
  a.from_string("36893488147419103230");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ++(2^64)" << endl;
  a.from_string("18446744073709551616");
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ++(2^128)" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ++(2^192)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ++(-(2^64))" << endl;
  a.from_string("-18446744073709551616");
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ++(-(2^128))" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ++(-(2^192))" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ++max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : ++(2^64-1)" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++(2^128-1)" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++(2^192-1)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512895");
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++(2^256-1)" << endl;
  a.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639935");
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++(-(2^64)-1)" << endl;
  a.from_string("-18446744073709551617");
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++(-(2^128)-1)" << endl;
  a.from_string("-340282366920938463463374607431768211457");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++(-(2^192)-1)" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512897");
  b = 1;
  b = ++a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ++(-(2^256)-1)" << endl;
  a.from_string("-115792089237316195423570985008687907853269984665640564039457584007913129639937");
  b = 0;
  b = ++a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nincrement_prefix PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void increment_postfix_test()
{
  BigInt a, b;

  bool _result = true;
  cout << "\n==[[increment_postfix(++)_test]]==================================" << endl << endl;

  cout << "Case : 1++" << endl;
  a = 1;
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1++" << endl;
  a = 1;
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : (++1)++" << endl;
  a = 1;
  b = 1;
  b = (++a)++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(3), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);

  cout << "Case : 0++" << endl;
  a = 0;
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (++0)++" << endl;
  a = 0;
  b = 1;
  b = (++a)++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -1++" << endl;
  a = -1;
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (++(-1))++" << endl;
  a = -1;
  b = 1;
  b = (++a)++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 18446744073709551617++" << endl;
  a.from_string("18446744073709551617");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(2), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 36893488147419103230++" << endl;
  a.from_string("36893488147419103230");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : (2^64)++" << endl;
  a.from_string("18446744073709551616");
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^128)++" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^192)++" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(2^64)++" << endl;
  a.from_string("-18446744073709551616");
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(2^128)++" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(2^192)++" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : max++" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : min++" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^64-1)++" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^128-1)++" << endl;
  a.from_string("340282366920938463463374607431768211455");
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^192-1)++" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512895");
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (2^256-1)++" << endl;
  a.from_string("115792089237316195423570985008687907853269984665640564039457584007913129639935");
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (-(2^64)-1)++" << endl;
  a.from_string("-18446744073709551617");
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (-(2^128)-1)++" << endl;
  a.from_string("-340282366920938463463374607431768211457");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (-(2^192)-1)++" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512897");
  b = 1;
  b = a++;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (-(2^256)-1)++" << endl;
  a.from_string("-115792089237316195423570985008687907853269984665640564039457584007913129639937");
  b = 0;
  b = a++;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nincrement_postfix_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void decrement_prefix_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[decrement_prefix(--)_test]]==================================" << endl << endl;

  cout << "Case : --1" << endl;
  a = 1;
  b = 0;
  b = --a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : --1" << endl;
  a = 1;
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : ----1" << endl;
  a = 1;
  b = 0;
  b = ----a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (--1)--" << endl;
  a = 1;
  b = 1;
  b = (--a)--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : --0" << endl;
  a = 0;
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : ----0" << endl;
  a = 0;
  b = 1;
  b = ----a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : (--0)--" << endl;
  a = 0;
  b = 1;
  b = (--a)--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : --(-1)" << endl;
  a = -1;
  b = 0;
  b = --a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : ----(-1)" << endl;
  a = -1;
  b = 1;
  b = ----a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : (--(-1))--" << endl;
  a = -1;
  b = 1;
  b = (--a)--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : --0xFFFFFFFFFFFFFFFF" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = 0;
  b = --a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : --18446744073709551617" << endl;
  a.from_string("18446744073709551617");
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : --36893488147419103230" << endl;
  a.from_string("36893488147419103230");
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);

  cout << "Case : --(2^64)" << endl;
  a.from_string("18446744073709551616");
  b = 0;
  b = --a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : --(2^128)" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : --(2^192)" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : --(-(2^64))" << endl;
  a.from_string("-18446744073709551616");
  b = 0;
  b = --a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : --(-(2^128))" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : --(-(2^192))" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : --max" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : --min" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  b = --a;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\ndecrement_prefix_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}

void decrement_postfix_test()
{
  BigInt a, b;

  bool _result = true;
  cout << "\n==[[decrement_postfix(--)_test]]==================================" << endl << endl;

  cout << "Case : 1--" << endl;
  a = 1;
  b = 0;
  b = a--;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1--" << endl;
  a = 1;
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : (--1)--" << endl;
  a = 1;
  b = 1;
  b = (--a)--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0--" << endl;
  a = 0;
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (--0)--" << endl;
  a = 0;
  b = 1;
  b = (--a)--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -1--" << endl;
  a = -1;
  b = 0;
  b = a--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (--(-1))--" << endl;
  a = -1;
  b = 1;
  b = (--a)--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : 0xFFFFFFFFFFFFFFFF--" << endl;
  a = (uint64_t)(0xFFFFFFFFFFFFFFFF);
  b = 0;
  b = a--;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 18446744073709551617--" << endl;
  a.from_string("18446744073709551617");
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 36893488147419103230--" << endl;
  a.from_string("36893488147419103230");
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFD), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);

  cout << "Case : (2^64)--" << endl;
  a.from_string("18446744073709551616");
  b = 0;
  b = a--;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^128)--" << endl;
  a.from_string("340282366920938463463374607431768211456");
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0), (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : (2^192)--" << endl;
  a.from_string("6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(1), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(2^64)--" << endl;
  a.from_string("-18446744073709551616");
  b = 0;
  b = a--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(2^128)--" << endl;
  a.from_string("-340282366920938463463374607431768211456");
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(2^192)--" << endl;
  a.from_string("-6277101735386680763835789423207666416102355444464034512896");
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFE), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : max--" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFE), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : min--" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = 1;
  b = a--;
  check_value(a, (uint64_t)(0x7FFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\ndecrement_postfix_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}


void unary_plus_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[unary_plus_test]]==================================" << endl << endl;

  cout << "Case : +(1)" << endl;
  a = 1;
  b = +a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : +(-1)" << endl;
  a = -1;
  b = +a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : +(1000000000000)" << endl;
  a = (uint64_t)(1000000000000);
  b = +a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0xE8D4A51000), (int)__LINE__, _result);

  cout << "Case : +(-1000000000000)" << endl;
  a = (int64_t)(-1000000000000);
  b = +a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFF172B5AF000), (int)__LINE__, _result);

  cout << "Case : +(2^63)" << endl;
  a.from_string("9223372036854775808");
  b = +a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  cout << "Case : +(2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b = +a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : +(2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b = +a;
  check_value(b, (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : +(2^254)" << endl;
  a.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b = +a;
  check_value(b, (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : +(-2^63)" << endl;
  a.from_string("-9223372036854775808");
  b = +a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  cout << "Case : +(-2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b = +a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : +(-2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b = +a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : +(-2^254)" << endl;
  a.from_string("-28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b = +a;
  check_value(b, (uint64_t)(0xC000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : +(min)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = +a;
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nunary_plus_test PASS" << endl;
  }

  cout << "========================================================" << endl;

  return;
}

void unary_minus_test()
{
  BigInt a, b;
  bool _result = true;
  cout << "\n==[[unary_minus_test]]==================================" << endl << endl;

  cout << "Case : -(1)" << endl;
  a = 1;
  b = -a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -(-1)" << endl;
  a = -1;
  b = -a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -(1152921504606846976)" << endl;
  a = (uint64_t)(1152921504606846976);
  check_value(a, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1000000000000000), (int)__LINE__, _result);
  b = -a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xF000000000000000), (int)__LINE__, _result);

  cout << "Case : -(-1152921504606846976)" << endl;
  a = (int64_t)(-1152921504606846976);
  check_value(a, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xF000000000000000), (int)__LINE__, _result);
  b = -a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x1000000000000000), (int)__LINE__, _result);

  cout << "Case : -(2^63)" << endl;
  a.from_string("9223372036854775808");
  b = -a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  cout << "Case : -(2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b = -a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b = -a;
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(2^254)" << endl;
  a.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b = -a;
  check_value(b, (uint64_t)(0xC000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(-2^63)" << endl;
  a.from_string("-9223372036854775808");
  b = -a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (int)__LINE__, _result);

  cout << "Case : -(-2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b = -a;
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(-2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b = -a;
  check_value(b, (uint64_t)(0), (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(-2^254)" << endl;
  a.from_string("-28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b = -a;
  check_value(b, (uint64_t)(0x4000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : -(min)  (overflow)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = -a;
  check_value(b, (uint64_t)(0x8000000000000000), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  if (_result)
  {
    cout << "\nunary_minus_test PASS" << endl;
  }

  cout << "========================================================" << endl;
  return;
}


void istream_ostream_operator_test()
{
  BigInt a;
  cout << "\n//====================================//" << endl;
  cout << "----------------------------------------(" << __LINE__ << ")" << endl;

  while (a != 123456)
  {
    cout << "Input a(a = 123456 -> end the test): ";
    cin >> a;
    cout << "a is : " << a << endl;
    a.debug();
  }

  cout << "//====================================//\n" << endl;

  return;
}

void sign_test()
{
  BigInt a,b;
  bool _result = true;
  cout << "\n==[[sign_test]]==================================" << endl << endl;

  cout << "Case : -(1)" << endl;
  a = -1;
  b = a.sign();
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -(1)" << endl;
  a = -(-(-1));
  b = a.sign();
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : 0" << endl;
  a = 0;
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0" << endl;
  a.from_string("+0");
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 0" << endl;
  a.from_string("-0");
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (int)__LINE__, _result);

  cout << "Case : 1" << endl;
  a = 1;
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : 1" << endl;
  a = -(-1);
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : (2^63)" << endl;
  a.from_string("9223372036854775808");
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : (2^127)" << endl;
  a.from_string("170141183460469231731687303715884105728");
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : (2^191)" << endl;
  a.from_string("3138550867693340381917894711603833208051177722232017256448");
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : (2^254)" << endl;
  a.from_string("28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : (max)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819967");
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "Case : -(2^63)" << endl;
  a.from_string("-9223372036854775808");
  b = a.sign();
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -(2^127)" << endl;
  a.from_string("-170141183460469231731687303715884105728");
  b = a.sign();
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -(2^191)" << endl;
  a.from_string("-3138550867693340381917894711603833208051177722232017256448");
  b = a.sign();
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -(2^254)" << endl;
  a.from_string("-28948022309329048855892746252171976963317496166410141009864396001978282409984");
  b = a.sign();
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -(min)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = a.sign();
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : (max)  (overflow)" << endl;
  a.from_string("57896044618658097711785492504343953926634992332820282019728792003956564819968");
  b = a.sign();
  check_value(b, (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (uint64_t)(0xFFFFFFFFFFFFFFFF), (int)__LINE__, _result);

  cout << "Case : -(min)  (overflow)" << endl;
  a.from_string("-57896044618658097711785492504343953926634992332820282019728792003956564819969");
  b = a.sign();
  check_value(b, (uint64_t)(0), (uint64_t)(0), (uint64_t)(0), (uint64_t)(1), (int)__LINE__, _result);

  cout << "//====================================//\n" << endl;

  return;
}

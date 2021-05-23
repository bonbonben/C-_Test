#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

#include "../inc/Big_Integer.h"

// constructor
BigInt::BigInt(void)
{
  memset(&this->elm[0], 0, BIGINT_SIZE);

  return;
}

// destructor
BigInt::~BigInt(void)
{

  return;
}

// debug mode for printing out debug information
void BigInt::Debug1(std::string str)
{
  printf("%s: ", str.c_str());
  for (ssize_t i = ELEMENT_NUMBER - 1; i >= 0; --i)
  {
    printf("%016llX ", this->elm[i]);
  }
  printf("\n");

  std::string str2 = "";
  for (size_t i = 0; i < 64; ++i)
  {
    if ((this->elm[1] << i) & (uint64_t)0x8000000000000000)
    {
      str2 += '1';
    }
    else
    {
      str2 += '0';
    }
  }

  str2 += " ";

  for (size_t i = 0; i < 64; ++i)
  {
    if ((this->elm[0] << i) & (uint64_t)0x8000000000000000)
    {
      str2 += '1';
    }
    else
    {
      str2 += '0';
    }
  }

  printf("[%s]\n", str2.c_str());

  return;
}

// std::string to BigInt
void BigInt::from_string(const std::string& str_int)
{
  this->elm[1] = 0x0;
  this->elm[0] = 0x0;

  bool negative_sign_flag = false;

  for (size_t i = 0; i < str_int.length(); ++i)
  {
    if (isdigit(str_int[i]))
    {
      uint32_t A = (uint32_t)((this->elm[1] & 0xFFFFFFFF00000000) >> 32);
      uint32_t B = (uint32_t)(this->elm[1] & 0x00000000FFFFFFFF);
      uint32_t C = (uint32_t)((this->elm[0] & 0xFFFFFFFF00000000) >> 32);
      uint32_t D = (uint32_t)(this->elm[0] & 0x00000000FFFFFFFF);
      uint32_t H = (uint32_t)(0x000000000000000A);

      uint64_t YZ = (uint64_t)D * (uint64_t)H;
      uint64_t XY = (uint64_t)C * (uint64_t)H;
      uint64_t WX = (uint64_t)B * (uint64_t)H;
      uint64_t VW = (uint64_t)A * (uint64_t)H;

      this->elm[1] = ((VW & 0x00000000FFFFFFFF) << 32) + WX + ((XY & 0xFFFFFFFF00000000) >> 32);
      this->elm[0] = ((XY & 0x00000000FFFFFFFF) << 32) + YZ;

      //48 = '0'
      if ((this->elm[0] + (uint64_t)(str_int[i] - 48)) < this->elm[0])
      {
        this->elm[1] += (uint64_t)1;
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
      else
      {
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
    }
    else if (str_int[0] == '-')
    {
      negative_sign_flag = true;
    }
    else if (str_int[0] == '+')
    {
      negative_sign_flag = false;
    }
    else
    {
      std::cerr << "BigInt::from_string() error [" << str_int.c_str() << "]" << std::endl;
      abort();
    }
  }

  if (negative_sign_flag)
  {
    this->elm[1] = ~this->elm[1];
    this->elm[0] = ~this->elm[0];
    if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      this->elm[1] += 1;
      this->elm[0] = 0;
    }
    else
    {
      this->elm[0] += 1;
    }
  }

  return;
}

// bitwise XOR assignment operator ^= overloading for BigInt
void BigInt::operator ^=(const BigInt& bigint)
{
  this->elm[1] = this->elm[1] ^ bigint.elm[1];
  this->elm[0] = this->elm[0] ^ bigint.elm[0];

  return;
}

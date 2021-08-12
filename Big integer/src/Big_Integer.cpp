#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>

#include "../inc/Big_Integer.h"

#define SIZE_OF_8_BYTES 8

const BigInt bigint_negative_1(-1);
const BigInt bigint_0(0);
const BigInt bigint_1(1);
const BigInt bigint_256_min("-57896044618658097711785492504343953926634992332820282019728792003956564819968");

// constructor
BigInt::BigInt(void)
{
  memset(&this->elm[0], 0, BIGINT_SIZE);

  return;
}

// constructor: initialized by BigInt
BigInt::BigInt(const BigInt& bigint)
{
  memcpy(&this->elm[0], &bigint.elm[0], BIGINT_SIZE);

  return;
}

// constructor: initialized by int32_t
BigInt::BigInt(int32_t int32)
{
  memset(&this->elm[0], 0, BIGINT_SIZE);

  if (int32 < 0)
  {
    int64_t temp_element = (int64_t)int32;
    memcpy(&this->elm[0], &temp_element, SIZE_OF_8_BYTES);
    this->elm[1] = 0xFFFFFFFFFFFFFFFF;
    this->elm[2] = 0xFFFFFFFFFFFFFFFF;
    this->elm[3] = 0xFFFFFFFFFFFFFFFF;
  }
  else
  {
    this->elm[0] = (uint64_t)int32;
    //this->elm[1] = 0;
    //this->elm[2] = 0;
    //this->elm[3] = 0;
  }

  return;
}

// constructor: initialized by int64_t
BigInt::BigInt(int64_t int64)
{
  memset(&this->elm[0], 0, BIGINT_SIZE);

  if (int64 < 0)
  {
    memcpy(&this->elm[0], &int64, SIZE_OF_8_BYTES);
    this->elm[1] = 0xFFFFFFFFFFFFFFFF;
    this->elm[2] = 0xFFFFFFFFFFFFFFFF;
    this->elm[3] = 0xFFFFFFFFFFFFFFFF;
  }
  else
  {
    this->elm[0] = (uint64_t)int64;
    //this->elm[1] = 0;
    //this->elm[2] = 0;
    //this->elm[3] = 0;
  }

  return;
}

// constructor: initialized by uint64_t
BigInt::BigInt(uint64_t uint64)
{
  memset(&this->elm[0], 0, BIGINT_SIZE);
  this->elm[0] = uint64;

  return;
}

// constructor: initialized by std::string
BigInt::BigInt(const std::string& str_int)
{
  memset(&this->elm[0], 0, BIGINT_SIZE);

  bool negative_sign = false;

  for (size_t i = 0; i < str_int.length(); ++i)
  {
    if (isdigit(str_int[i]))
    {
      uint32_t A = (uint32_t)((this->elm[3] & 0xFFFFFFFF00000000) >> 32);
      uint32_t B = (uint32_t)(this->elm[3] & 0x00000000FFFFFFFF);
      uint32_t C = (uint32_t)((this->elm[2] & 0xFFFFFFFF00000000) >> 32);
      uint32_t D = (uint32_t)(this->elm[2] & 0x00000000FFFFFFFF);
      uint32_t E = (uint32_t)((this->elm[1] & 0xFFFFFFFF00000000) >> 32);
      uint32_t F = (uint32_t)(this->elm[1] & 0x00000000FFFFFFFF);
      uint32_t G = (uint32_t)((this->elm[0] & 0xFFFFFFFF00000000) >> 32);
      uint32_t H = (uint32_t)(this->elm[0] & 0x00000000FFFFFFFF);
      uint32_t P = (uint32_t)(0x000000000000000A);

      uint64_t YZ = (uint64_t)H * (uint64_t)P;
      uint64_t XY = (uint64_t)G * (uint64_t)P;
      uint64_t WX = (uint64_t)F * (uint64_t)P;
      uint64_t VW = (uint64_t)E * (uint64_t)P;
      uint64_t UV = (uint64_t)D * (uint64_t)P;
      uint64_t TU = (uint64_t)C * (uint64_t)P;
      uint64_t ST = (uint64_t)B * (uint64_t)P;
      uint64_t RS = (uint64_t)A * (uint64_t)P;

      //this->elm[0] = ((XY & 0x00000000FFFFFFFF) << 32) + YZ;
      //this->elm[1] = ((VW & 0x00000000FFFFFFFF) << 32) + WX + ((XY & 0xFFFFFFFF00000000) >> 32);
      //this->elm[2] = ((TU & 0x00000000FFFFFFFF) << 32) + UV + ((VW & 0xFFFFFFFF00000000) >> 32);
      //this->elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);
      // consider overflow except this->elm[3], ex: this->elm[0] = 0xFFFFFFFA00000000 + 0x9FFFFFFF6 (overflow)
      this->elm[0] = ((XY & 0x00000000FFFFFFFF) << 32);
      this->elm[1] = ((VW & 0x00000000FFFFFFFF) << 32);
      this->elm[2] = ((TU & 0x00000000FFFFFFFF) << 32);
      this->elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);

      if ((this->elm[0] + YZ) < YZ)
      {
        this->elm[0] += YZ;
        this->elm[1] += 1;
      }
      else
      {
        this->elm[0] += YZ;
      }

      if ((this->elm[1] + WX) < WX)
      {
        this->elm[1] += WX;
        this->elm[2] += 1;
      }
      else
      {
        this->elm[1] += WX;
      }
      if ((this->elm[1] + ((XY & 0xFFFFFFFF00000000) >> 32)) < ((XY & 0xFFFFFFFF00000000) >> 32))
      {
        this->elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
        this->elm[2] += 1;
      }
      else
      {
        this->elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
      }

      if ((this->elm[2] + UV) < UV)
      {
        this->elm[2] += UV;
        this->elm[3] += 1;
      }
      else
      {
        this->elm[2] += UV;
      }
      if ((this->elm[2] + ((VW & 0xFFFFFFFF00000000) >> 32)) < ((VW & 0xFFFFFFFF00000000) >> 32))
      {
        this->elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
        this->elm[3] += 1;
      }
      else
      {
        this->elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
      }

      //48 = '0'
      if (((this->elm[0] + (uint64_t)(str_int[i] - 48)) < this->elm[0]) &&
          (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
          (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
      {
        this->elm[3] += (uint64_t)1;
        this->elm[2] = 0;
        this->elm[1] = 0;
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
      else if (((this->elm[0] + (uint64_t)(str_int[i] - 48)) < this->elm[0]) &&
                (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
      {
        this->elm[2] += (uint64_t)1;
        this->elm[1] = 0;
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
      else if ((this->elm[0] + (uint64_t)(str_int[i] - 48)) < this->elm[0])
      {
        this->elm[1] += (uint64_t)1;
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
      else
      {
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
    }
    else if ((i == 0) && (str_int[i] == '-'))
    {
      negative_sign = true;
    }
    else if ((i == 0) && (str_int[i] == '+'))
    {
      //negative_sign = false;
    }
    else
    {
      std::cerr << "BigInt::from_string() error [" << str_int.c_str() << "]" << std::endl;
      abort();
    }
  }

  if (negative_sign)
  {
    this->elm[3] = ~this->elm[3];
    this->elm[2] = ~this->elm[2];
    this->elm[1] = ~this->elm[1];
    this->elm[0] = ~this->elm[0];
    if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[3] += 1;
      this->elm[2] = 0;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
             (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[2] += 1;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
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

// destructor
BigInt::~BigInt(void)
{
  return;
}

// clear BigInt object(set the value to 0)
void BigInt::clear(void)
{
  memset(&this->elm[0], 0, BIGINT_SIZE);

  return;
}

// basic assignment operator = overloading for BigInt
void BigInt::operator =(const BigInt& bigint)
{
  memcpy(&this->elm[0], &bigint.elm[0], BIGINT_SIZE);

  return;
}

// unary plus(positive sign) operator + overloading for BigInt
BigInt BigInt::operator +(void) const
{
  return (*this);
}

// unary minus(negative sign) operator - overloading for BigInt
BigInt BigInt::operator -(void) const
{
  BigInt bigint(*this);

  bigint.elm[3] = ~bigint.elm[3];
  bigint.elm[2] = ~bigint.elm[2];
  bigint.elm[1] = ~bigint.elm[1];
  bigint.elm[0] = ~bigint.elm[0];
  if ((bigint.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
      (bigint.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
      (bigint.elm[2] == 0xFFFFFFFFFFFFFFFF))
  {
    bigint.elm[3] += 1;
    bigint.elm[2] = 0;
    bigint.elm[1] = 0;
    bigint.elm[0] = 0;
  }
  else if ((bigint.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
           (bigint.elm[1] == 0xFFFFFFFFFFFFFFFF))
  {
    bigint.elm[2] += 1;
    bigint.elm[1] = 0;
    bigint.elm[0] = 0;
  }
  else if (bigint.elm[0] == 0xFFFFFFFFFFFFFFFF)
  {
    bigint.elm[1] += 1;
    bigint.elm[0] = 0;
  }
  else
  {
    bigint.elm[0] += 1;
  }

  return bigint;
}

// addition operator + overloading for BigInt
BigInt BigInt::operator +(const BigInt& addend) const
{
  //BigInt sum(0);
  BigInt sum;

  sum.elm[3] = this->elm[3] + addend.elm[3];
  sum.elm[2] = this->elm[2] + addend.elm[2];
  sum.elm[1] = this->elm[1] + addend.elm[1];
  sum.elm[0] = this->elm[0] + addend.elm[0];
  if (sum.elm[0] < this->elm[0])
  {
    sum.elm[1] += (uint64_t)1;
  }

  if ((sum.elm[1] < this->elm[1]) ||
      ((sum.elm[1] == this->elm[1]) &&
       (addend.elm[1] != 0)))
  {
    sum.elm[2] += (uint64_t)1;
  }

  if ((sum.elm[2] < this->elm[2]) ||
      ((sum.elm[2] == this->elm[2]) &&
       (addend.elm[2] != 0)))
  {
    sum.elm[3] += (uint64_t)1;
  }

  return sum;
}

// subtraction operator - overloading for BigInt
BigInt BigInt::operator -(const BigInt& subtrahend) const
{
  //BigInt difference(0);
  BigInt difference;
  BigInt _subtrahend(subtrahend);

  _subtrahend.elm[3] = ~_subtrahend.elm[3];
  _subtrahend.elm[2] = ~_subtrahend.elm[2];
  _subtrahend.elm[1] = ~_subtrahend.elm[1];
  _subtrahend.elm[0] = ~_subtrahend.elm[0];
  if ((_subtrahend.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
      (_subtrahend.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
      (_subtrahend.elm[2] == 0xFFFFFFFFFFFFFFFF))
  {
    _subtrahend.elm[3] += 1;
    _subtrahend.elm[2] = 0;
    _subtrahend.elm[1] = 0;
    _subtrahend.elm[0] = 0;
  }
  else if ((_subtrahend.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
            (_subtrahend.elm[1] == 0xFFFFFFFFFFFFFFFF))
  {
    _subtrahend.elm[2] += 1;
    _subtrahend.elm[1] = 0;
    _subtrahend.elm[0] = 0;
  }
  else if (_subtrahend.elm[0] == 0xFFFFFFFFFFFFFFFF)
  {
    _subtrahend.elm[1] += 1;
    _subtrahend.elm[0] = 0;
  }
  else
  {
    _subtrahend.elm[0] += 1;
  }

  difference.elm[3] = this->elm[3] + _subtrahend.elm[3];
  difference.elm[2] = this->elm[2] + _subtrahend.elm[2];
  difference.elm[1] = this->elm[1] + _subtrahend.elm[1];
  difference.elm[0] = this->elm[0] + _subtrahend.elm[0];
  if (difference.elm[0] < this->elm[0])
  {
    difference.elm[1] += (uint64_t)1;
  }

  if ((difference.elm[1] < this->elm[1]) ||
      ((difference.elm[1] == this->elm[1]) &&
       (_subtrahend.elm[1] != 0)))
  {
    difference.elm[2] += (uint64_t)1;
  }

  if ((difference.elm[2] < this->elm[2]) ||
      ((difference.elm[2] == this->elm[2]) &&
       (_subtrahend.elm[2] != 0)))
  {
    difference.elm[3] += (uint64_t)1;
  }

  return difference;
}

// multiplication operator * overloading for BigInt
BigInt BigInt::operator *(const BigInt& multiplier) const
{
  BigInt product;
  BigInt _multiplicand(*this);
  BigInt _multiplier(multiplier);

  bool negative_sign = false;

  if (_multiplicand.elm[3] & (uint64_t)0x8000000000000000)
  {
    negative_sign = !negative_sign;
    _multiplicand.elm[3] = ~_multiplicand.elm[3];
    _multiplicand.elm[2] = ~_multiplicand.elm[2];
    _multiplicand.elm[1] = ~_multiplicand.elm[1];
    _multiplicand.elm[0] = ~_multiplicand.elm[0];
    if ((_multiplicand.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (_multiplicand.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (_multiplicand.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      _multiplicand.elm[3] += 1;
      _multiplicand.elm[2] = 0;
      _multiplicand.elm[1] = 0;
      _multiplicand.elm[0] = 0;
    }
    else if ((_multiplicand.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (_multiplicand.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      _multiplicand.elm[2] += 1;
      _multiplicand.elm[1] = 0;
      _multiplicand.elm[0] = 0;
    }
    else if (_multiplicand.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      _multiplicand.elm[1] += 1;
      _multiplicand.elm[0] = 0;
    }
    else
    {
      _multiplicand.elm[0] += 1;
    }
  }

  if (_multiplier.elm[3] & (uint64_t)0x8000000000000000)
  {
    negative_sign = !negative_sign;
    _multiplier.elm[3] = ~_multiplier.elm[3];
    _multiplier.elm[2] = ~_multiplier.elm[2];
    _multiplier.elm[1] = ~_multiplier.elm[1];
    _multiplier.elm[0] = ~_multiplier.elm[0];
    if ((_multiplier.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (_multiplier.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (_multiplier.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      _multiplier.elm[3] += 1;
      _multiplier.elm[2] = 0;
      _multiplier.elm[1] = 0;
      _multiplier.elm[0] = 0;
    }
    else if ((_multiplier.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (_multiplier.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      _multiplier.elm[2] += 1;
      _multiplier.elm[1] = 0;
      _multiplier.elm[0] = 0;
    }
    else if (_multiplier.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      _multiplier.elm[1] += 1;
      _multiplier.elm[0] = 0;
    }
    else
    {
      _multiplier.elm[0] += 1;
    }
  }

  // _multiplicand = (AB)(CD)(EF)(GH)
  // _multiplier = (IJ)(KL)(MN)(OP)
  // YZ = H*P
  // XY = G*P + H*O
  // WX = F*P + G*O + H*N
  // VW = E*P + F*O + G*N + H*M
  // UV = D*P + E*O + F*N + G*M + H*L
  // TU = C*P + D*O + E*N + F*M + G*L + H*K
  // ST = B*P + C*O + D*N + E*M + F*L + G*K + H*J
  // RS = A*P + B*O + C*N + D*M + E*L + F*K + G*J + H*I

  uint32_t A = (uint32_t)((_multiplicand.elm[3] & 0xFFFFFFFF00000000) >> 32);
  uint32_t B = (uint32_t)(_multiplicand.elm[3] & 0x00000000FFFFFFFF);
  uint32_t C = (uint32_t)((_multiplicand.elm[2] & 0xFFFFFFFF00000000) >> 32);
  uint32_t D = (uint32_t)(_multiplicand.elm[2] & 0x00000000FFFFFFFF);
  uint32_t E = (uint32_t)((_multiplicand.elm[1] & 0xFFFFFFFF00000000) >> 32);
  uint32_t F = (uint32_t)(_multiplicand.elm[1] & 0x00000000FFFFFFFF);
  uint32_t G = (uint32_t)((_multiplicand.elm[0] & 0xFFFFFFFF00000000) >> 32);
  uint32_t H = (uint32_t)(_multiplicand.elm[0] & 0x00000000FFFFFFFF);

  uint32_t I = (uint32_t)((_multiplier.elm[3] & 0xFFFFFFFF00000000) >> 32);
  uint32_t J = (uint32_t)(_multiplier.elm[3] & 0x00000000FFFFFFFF);
  uint32_t K = (uint32_t)((_multiplier.elm[2] & 0xFFFFFFFF00000000) >> 32);
  uint32_t L = (uint32_t)(_multiplier.elm[2] & 0x00000000FFFFFFFF);
  uint32_t M = (uint32_t)((_multiplier.elm[1] & 0xFFFFFFFF00000000) >> 32);
  uint32_t N = (uint32_t)(_multiplier.elm[1] & 0x00000000FFFFFFFF);
  uint32_t O = (uint32_t)((_multiplier.elm[0] & 0xFFFFFFFF00000000) >> 32);
  uint32_t P = (uint32_t)(_multiplier.elm[0] & 0x00000000FFFFFFFF);

  uint64_t YZ = 0;
  uint64_t XY = 0;
  uint64_t WX = 0;
  uint64_t VW = 0;
  uint64_t UV = 0;
  uint64_t TU = 0;
  uint64_t ST = 0;
  uint64_t RS = 0;

  // 4294967296 = 0x100000000
  // consider overflow except RS and YZ (YZ never overflow)
  YZ = (uint64_t)H * (uint64_t)P;

  XY = ((uint64_t)G * (uint64_t)P) + ((uint64_t)H * (uint64_t)O);
  if (XY < ((uint64_t)G * (uint64_t)P))
  {
    WX += (uint64_t)4294967296;
  }

  WX += ((uint64_t)F * (uint64_t)P);
  if (WX < ((uint64_t)F * (uint64_t)P))
  {
    VW += (uint64_t)4294967296;
  }
  WX += ((uint64_t)G * (uint64_t)O);
  if (WX < ((uint64_t)G * (uint64_t)O))
  {
    VW += (uint64_t)4294967296;
  }
  WX += ((uint64_t)H * (uint64_t)N);
  if (WX < ((uint64_t)H * (uint64_t)N))
  {
    VW += (uint64_t)4294967296;
  }

  VW += ((uint64_t)E * (uint64_t)P);
  if (VW < ((uint64_t)E * (uint64_t)P))
  {
    UV += (uint64_t)4294967296;
  }
  VW += ((uint64_t)F * (uint64_t)O);
  if (VW < ((uint64_t)F * (uint64_t)O))
  {
    UV += (uint64_t)4294967296;
  }
  VW += ((uint64_t)G * (uint64_t)N);
  if (VW < ((uint64_t)G * (uint64_t)N))
  {
    UV += (uint64_t)4294967296;
  }
  VW += ((uint64_t)H * (uint64_t)M);
  if (VW < ((uint64_t)H * (uint64_t)M))
  {
    UV += (uint64_t)4294967296;
  }

  UV += ((uint64_t)D * (uint64_t)P);
  if (UV < ((uint64_t)D * (uint64_t)P))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)E * (uint64_t)O);
  if (UV < ((uint64_t)E * (uint64_t)O))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)F * (uint64_t)N);
  if (UV < ((uint64_t)F * (uint64_t)N))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)G * (uint64_t)M);
  if (UV < ((uint64_t)G * (uint64_t)M))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)H * (uint64_t)L);
  if (UV < ((uint64_t)H * (uint64_t)L))
  {
    TU += (uint64_t)4294967296;
  }

  TU += ((uint64_t)C * (uint64_t)P);
  if (TU < ((uint64_t)C * (uint64_t)P))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)D * (uint64_t)O);
  if (TU < ((uint64_t)D * (uint64_t)O))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)E * (uint64_t)N);
  if (TU < ((uint64_t)E * (uint64_t)N))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)F * (uint64_t)M);
  if (TU < ((uint64_t)F * (uint64_t)M))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)G * (uint64_t)L);
  if (TU < ((uint64_t)G * (uint64_t)L))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)H * (uint64_t)K);
  if (TU < ((uint64_t)H * (uint64_t)K))
  {
    ST += (uint64_t)4294967296;
  }

  ST += ((uint64_t)B * (uint64_t)P);
  if (ST < ((uint64_t)B * (uint64_t)P))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)C * (uint64_t)O);
  if (ST < ((uint64_t)C * (uint64_t)O))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)D * (uint64_t)N);
  if (ST < ((uint64_t)D * (uint64_t)N))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)E * (uint64_t)M);
  if (ST < ((uint64_t)E * (uint64_t)M))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)F * (uint64_t)L);
  if (ST < ((uint64_t)F * (uint64_t)L))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)G * (uint64_t)K);
  if (ST < ((uint64_t)G * (uint64_t)K))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)H * (uint64_t)J);
  if (ST < ((uint64_t)H * (uint64_t)J))
  {
    RS += (uint64_t)4294967296;
  }

  RS += ((uint64_t)A * (uint64_t)P) +
        ((uint64_t)B * (uint64_t)O) +
        ((uint64_t)C * (uint64_t)N) +
        ((uint64_t)D * (uint64_t)M) +
        ((uint64_t)E * (uint64_t)L) +
        ((uint64_t)F * (uint64_t)K) +
        ((uint64_t)G * (uint64_t)J) +
        ((uint64_t)H * (uint64_t)I);

  //product.elm[0] = ((XY & 0x00000000FFFFFFFF) << 32) + YZ;
  //product.elm[1] = ((VW & 0x00000000FFFFFFFF) << 32) + WX + ((XY & 0xFFFFFFFF00000000) >> 32);
  //product.elm[2] = ((TU & 0x00000000FFFFFFFF) << 32) + UV + ((VW & 0xFFFFFFFF00000000) >> 32);
  //product.elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);
  // consider overflow except product.elm[3], ex: product.elm[0] = 0xFFFFFFFA00000000 + 0x9FFFFFFF6 (overflow)
  product.elm[0] = ((XY & 0x00000000FFFFFFFF) << 32);
  product.elm[1] = ((VW & 0x00000000FFFFFFFF) << 32);
  product.elm[2] = ((TU & 0x00000000FFFFFFFF) << 32);
  product.elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);

  if ((product.elm[0] + YZ) < YZ)
  {
    product.elm[0] += YZ;
    product.elm[1] += 1;
  }
  else
  {
    product.elm[0] += YZ;
  }

  if ((product.elm[1] + WX) < WX)
  {
    product.elm[1] += WX;
    product.elm[2] += 1;
  }
  else
  {
    product.elm[1] += WX;
  }
  if ((product.elm[1] + ((XY & 0xFFFFFFFF00000000) >> 32)) < ((XY & 0xFFFFFFFF00000000) >> 32))
  {
    product.elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
    product.elm[2] += 1;
  }
  else
  {
    product.elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
  }

  if ((product.elm[2] + UV) < UV)
  {
    product.elm[2] += UV;
    product.elm[3] += 1;
  }
  else
  {
    product.elm[2] += UV;
  }
  if ((product.elm[2] + ((VW & 0xFFFFFFFF00000000) >> 32)) < ((VW & 0xFFFFFFFF00000000) >> 32))
  {
    product.elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
    product.elm[3] += 1;
  }
  else
  {
    product.elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
  }

  if (negative_sign)
  {
    product.elm[3] = ~product.elm[3];
    product.elm[2] = ~product.elm[2];
    product.elm[1] = ~product.elm[1];
    product.elm[0] = ~product.elm[0];
    if ((product.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (product.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (product.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      product.elm[3] += 1;
      product.elm[2] = 0;
      product.elm[1] = 0;
      product.elm[0] = 0;
    }
    else if ((product.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (product.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      product.elm[2] += 1;
      product.elm[1] = 0;
      product.elm[0] = 0;
    }
    else if (product.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      product.elm[1] += 1;
      product.elm[0] = 0;
    }
    else
    {
      product.elm[0] += 1;
    }
  }

  return product;
}

// division operator / overloading for BigInt
BigInt BigInt::operator /(const BigInt& divisor) const
{
  BigInt quotient;
  BigInt remainder;
  quotient.div_mod((*this), divisor, remainder);

  return quotient;
}

// modulo operator % overloading for BigInt
BigInt BigInt::operator %(const BigInt& divisor) const
{
  BigInt quotient;
  BigInt remainder;
  quotient.div_mod((*this), divisor, remainder);

  return remainder;
}

// increment(prefix) ++ overloading for BigInt
BigInt& BigInt::operator ++()
{
  if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
      (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
      (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
  {
    this->elm[3] += (uint64_t)1;
    this->elm[2] = 0;
    this->elm[1] = 0;
    this->elm[0] = 0;
  }
  else if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
           (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
  {
    this->elm[2] += (uint64_t)1;
    this->elm[1] = 0;
    this->elm[0] = 0;
  }
  else if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
  {
    this->elm[1] += (uint64_t)1;
    this->elm[0] = 0;
  }
  else
  {
    this->elm[0] += 1;
  }

  return (*this);
}

// increment(postfix) ++ overloading for BigInt
const BigInt BigInt::operator ++(int)
{
  BigInt temp_bigint(*this);

  if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
      (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
      (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
  {
    this->elm[3] += (uint64_t)1;
    this->elm[2] = 0;
    this->elm[1] = 0;
    this->elm[0] = 0;
  }
  else if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
           (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
  {
    this->elm[2] += (uint64_t)1;
    this->elm[1] = 0;
    this->elm[0] = 0;
  }
  else if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
  {
    this->elm[1] += (uint64_t)1;
    this->elm[0] = 0;
  }
  else
  {
    this->elm[0] += 1;
  }

  return temp_bigint;
}

// decrement(prefix) -- overloading for BigInt
BigInt& BigInt::operator --()
{
  if ((this->elm[0] == 0x0) && (this->elm[1] == 0x0) && (this->elm[2] == 0x0))
  {
    this->elm[3] -= (uint64_t)1;
    this->elm[2] = 0xFFFFFFFFFFFFFFFF;
    this->elm[1] = 0xFFFFFFFFFFFFFFFF;
    this->elm[0] = 0xFFFFFFFFFFFFFFFF;
  }
  else if ((this->elm[0] == 0x0) && (this->elm[1] == 0x0))
  {
    this->elm[2] -= (uint64_t)1;
    this->elm[1] = 0xFFFFFFFFFFFFFFFF;
    this->elm[0] = 0xFFFFFFFFFFFFFFFF;
  }
  else if (this->elm[0] == 0x0)
  {
    this->elm[1] -= (uint64_t)1;
    this->elm[0] = 0xFFFFFFFFFFFFFFFF;
  }
  else
  {
    this->elm[0] -= (uint64_t)1;
  }

  return (*this);
}

// decrement(postfix) -- overloading for BigInt
const BigInt BigInt::operator --(int)
{
  BigInt temp_bigint = (*this);

  if ((this->elm[0] == 0x0) && (this->elm[1] == 0x0) && (this->elm[2] == 0x0))
  {
    this->elm[3] -= (uint64_t)1;
    this->elm[2] = 0xFFFFFFFFFFFFFFFF;
    this->elm[1] = 0xFFFFFFFFFFFFFFFF;
    this->elm[0] = 0xFFFFFFFFFFFFFFFF;
  }
  else if ((this->elm[0] == 0x0) && (this->elm[1] == 0x0))
  {
    this->elm[2] -= (uint64_t)1;
    this->elm[1] = 0xFFFFFFFFFFFFFFFF;
    this->elm[0] = 0xFFFFFFFFFFFFFFFF;
  }
  else if (this->elm[0] == 0x0)
  {
    this->elm[1] -= (uint64_t)1;
    this->elm[0] = 0xFFFFFFFFFFFFFFFF;
  }
  else
  {
    this->elm[0] -= (uint64_t)1;
  }

  return temp_bigint;
}

// equal to operator == overloading for BigInt
bool BigInt::operator ==(const BigInt& bigint) const
{
  if ((this->elm[3] == bigint.elm[3]) &&
      (this->elm[2] == bigint.elm[2]) &&
      (this->elm[1] == bigint.elm[1]) &&
      (this->elm[0] == bigint.elm[0]))
  {
    return true;
  }

  return false;
}

// not equal to operator != overloading for BigInt
bool BigInt::operator !=(const BigInt& bigint) const
{
  if (!((this->elm[3] == bigint.elm[3]) &&
        (this->elm[2] == bigint.elm[2]) &&
        (this->elm[1] == bigint.elm[1]) &&
        (this->elm[0] == bigint.elm[0])))
  {
    return true;
  }

  return false;
}

// greater than operator > overloading for BigInt
bool BigInt::operator >(const BigInt& bigint) const
{
  if (bigint.elm[3] & 0x8000000000000000)
  {
    if (!(this->elm[3] & 0x8000000000000000))
    {
      return true;
    }
  }
  else
  {
    if (this->elm[3] & 0x8000000000000000)
    {
      return false;
    }
  }

  if (this->elm[3] > bigint.elm[3])
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] > bigint.elm[2]))
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] == bigint.elm[2]) &&
           (this->elm[1] > bigint.elm[1]))
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] == bigint.elm[2]) &&
           (this->elm[1] == bigint.elm[1]) &&
           (this->elm[0] > bigint.elm[0]))
  {
    return true;
  }

  return false;
}

// less than operator < overloading for BigInt
bool BigInt::operator <(const BigInt& bigint) const
{
  if (this->elm[3] & 0x8000000000000000)
  {
    if (!(bigint.elm[3] & 0x8000000000000000))
    {
      return true;
    }
  }
  else
  {
    if (bigint.elm[3] & 0x8000000000000000)
    {
      return false;
    }
  }

  if (this->elm[3] < bigint.elm[3])
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] < bigint.elm[2]))
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] == bigint.elm[2]) &&
           (this->elm[1] < bigint.elm[1]))
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] == bigint.elm[2]) &&
           (this->elm[1] == bigint.elm[1]) &&
           (this->elm[0] < bigint.elm[0]))
  {
    return true;
  }

  return false;
}

// greater than or equal to operator >= overloading for BigInt
bool BigInt::operator >=(const BigInt& bigint) const
{
  if ((this->elm[3] == bigint.elm[3]) &&
      (this->elm[2] == bigint.elm[2]) &&
      (this->elm[1] == bigint.elm[1]) &&
      (this->elm[0] == bigint.elm[0]))
  {
    return true;
  }

  if (bigint.elm[3] & 0x8000000000000000)
  {
    if (!(this->elm[3] & 0x8000000000000000))
    {
      return true;
    }
  }
  else
  {
    if (this->elm[3] & 0x8000000000000000)
    {
      return false;
    }
  }

  if (this->elm[3] > bigint.elm[3])
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] > bigint.elm[2]))
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] == bigint.elm[2]) &&
           (this->elm[1] > bigint.elm[1]))
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] == bigint.elm[2]) &&
           (this->elm[1] == bigint.elm[1]) &&
           (this->elm[0] > bigint.elm[0]))
  {
    return true;
  }

  return false;
}

// less than or equal to operator <= overloading for BigInt
bool BigInt::operator <=(const BigInt& bigint) const
{
  if ((this->elm[3] == bigint.elm[3]) &&
      (this->elm[2] == bigint.elm[2]) &&
      (this->elm[1] == bigint.elm[1]) &&
      (this->elm[0] == bigint.elm[0]))
  {
    return true;
  }

  if (this->elm[3] & 0x8000000000000000)
  {
    if (!(bigint.elm[3] & 0x8000000000000000))
    {
      return true;
    }
  }
  else
  {
    if (bigint.elm[3] & 0x8000000000000000)
    {
      return false;
    }
  }

  if (this->elm[3] < bigint.elm[3])
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] < bigint.elm[2]))
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] == bigint.elm[2]) &&
           (this->elm[1] < bigint.elm[1]))
  {
    return true;
  }
  else if ((this->elm[3] == bigint.elm[3]) &&
           (this->elm[2] == bigint.elm[2]) &&
           (this->elm[1] == bigint.elm[1]) &&
           (this->elm[0] < bigint.elm[0]))
  {
    return true;
  }

  return false;
}

// logical negation(NOT) for BigInt
bool BigInt::operator !() const
{
  if ((this->elm[3] == 0) &&
      (this->elm[2] == 0) &&
      (this->elm[1] == 0) &&
      (this->elm[0] == 0))
  {
    return true;
  }

  return false;
}

// logical AND for BigInt
bool BigInt::operator &&(const BigInt& bigint) const
{
  if (((this->elm[3] == 0) &&
       (this->elm[2] == 0) &&
       (this->elm[1] == 0) &&
       (this->elm[0] == 0)) ||
      ((bigint.elm[3] == 0) &&
       (bigint.elm[2] == 0) &&
       (bigint.elm[1] == 0) &&
       (bigint.elm[0] == 0)))
  {
    return false;
  }

  return true;
}

// logical OR for BigInt
bool BigInt::operator ||(const BigInt& bigint) const
{
  if (((this->elm[3] == 0) &&
       (this->elm[2] == 0) &&
       (this->elm[1] == 0) &&
       (this->elm[0] == 0)) &&
      ((bigint.elm[3] == 0) &&
       (bigint.elm[2] == 0) &&
       (bigint.elm[1] == 0) &&
       (bigint.elm[0] == 0)))
  {
    return false;
  }

  return true;
}

// bitwise NOT for BigInt
BigInt BigInt::operator ~() const
{
  BigInt bigint;

  bigint.elm[3] = ~this->elm[3];
  bigint.elm[2] = ~this->elm[2];
  bigint.elm[1] = ~this->elm[1];
  bigint.elm[0] = ~this->elm[0];

  return bigint;
}

// bitwise AND for BigInt
BigInt BigInt::operator &(const BigInt& bigint) const
{
  BigInt result;

  result.elm[3] = this->elm[3] & bigint.elm[3];
  result.elm[2] = this->elm[2] & bigint.elm[2];
  result.elm[1] = this->elm[1] & bigint.elm[1];
  result.elm[0] = this->elm[0] & bigint.elm[0];

  return result;
}

// bitwise OR for BigInt
BigInt BigInt::operator |(const BigInt& bigint) const
{
  BigInt result;

  result.elm[3] = this->elm[3] | bigint.elm[3];
  result.elm[2] = this->elm[2] | bigint.elm[2];
  result.elm[1] = this->elm[1] | bigint.elm[1];
  result.elm[0] = this->elm[0] | bigint.elm[0];

  return result;
}

// bitwise XOR for BigInt
BigInt BigInt::operator ^(const BigInt& bigint) const
{
  BigInt result;

  result.elm[3] = this->elm[3] ^ bigint.elm[3];
  result.elm[2] = this->elm[2] ^ bigint.elm[2];
  result.elm[1] = this->elm[1] ^ bigint.elm[1];
  result.elm[0] = this->elm[0] ^ bigint.elm[0];

  return result;
}

// bitwise left shift for BigInt
BigInt BigInt::operator <<(const int32_t offset) const
{
  if ((offset > 0) && (offset < 64))
  {
    BigInt result;
    result.elm[3] = (this->elm[3] << offset);
    result.elm[3] |= (this->elm[2] >> (64 - offset));
    result.elm[2] = (this->elm[2] << offset);
    result.elm[2] |= (this->elm[1] >> (64 - offset));
    result.elm[1] = (this->elm[1] << offset);
    result.elm[1] |= (this->elm[0] >> (64 - offset));
    result.elm[0] = (this->elm[0] << offset);
    return result;
  }
  else if ((offset > 64) && (offset < 128))
  {
    BigInt result;
    result.elm[3] = (this->elm[2] << (offset - 64));
    result.elm[3] |= (this->elm[1] >> (128 - offset));
    result.elm[2] = (this->elm[1] << (offset - 64));
    result.elm[2] |= (this->elm[0] >> (128 - offset));
    result.elm[1] = (this->elm[0] << (offset - 64));
    //result.elm[0] = 0;
    return result;
  }
  else if ((offset > 128) && (offset < 192))
  {
    BigInt result;
    result.elm[3] = (this->elm[1] << (offset - 128));
    result.elm[3] |= (this->elm[0] >> (192 - offset));
    result.elm[2] = (this->elm[0] << (offset - 128));
    //result.elm[1] = 0;
    //result.elm[0] = 0;
    return result;
  }
  else if ((offset > 192) && (offset < 256))
  {
    BigInt result;
    result.elm[3] = (this->elm[0] << (offset - 192));
    //result.elm[2] = 0;
    //result.elm[1] = 0;
    //result.elm[0] = 0;
    return result;
  }
  else if (offset == 64)
  {
    BigInt result;
    result.elm[3] = this->elm[2];
    result.elm[2] = this->elm[1];
    result.elm[1] = this->elm[0];
    //result.elm[0] = 0;
    return result;
  }
  else if (offset == 128)
  {
    BigInt result;
    result.elm[3] = this->elm[1];
    result.elm[2] = this->elm[0];
    //result.elm[1] = 0;
    //result.elm[0] = 0;
    return result;
  }
  else if (offset == 192)
  {
    BigInt result;
    result.elm[3] = this->elm[0];
    //result.elm[2] = 0;
    //result.elm[1] = 0;
    //result.elm[0] = 0;
    return result;
  }
  //else if (offset == 0)
  //{
    //return (*this);
  //}
  else if (offset > 255)
  {
    return bigint_0;
  }
  else if (offset < 0)
  {
    return bigint_0;
  }

  return (*this);
}

// bitwise left shift(BigInt type offset) for BigInt
BigInt BigInt::operator <<(const BigInt& offset_bigint) const
{
  if ((offset_bigint.elm[3] > 0) ||
      (offset_bigint.elm[2] > 0) ||
      (offset_bigint.elm[1] > 0) ||
      (offset_bigint.elm[0] > 255))
  {
    return bigint_0;
  }

  int32_t offset = (int32_t)offset_bigint.elm[0];

  if ((offset > 0) && (offset < 64))
  {
    BigInt result;
    result.elm[3] = (this->elm[3] << offset);
    result.elm[3] |= (this->elm[2] >> (64 - offset));
    result.elm[2] = (this->elm[2] << offset);
    result.elm[2] |= (this->elm[1] >> (64 - offset));
    result.elm[1] = (this->elm[1] << offset);
    result.elm[1] |= (this->elm[0] >> (64 - offset));
    result.elm[0] = (this->elm[0] << offset);
    return result;
  }
  else if ((offset > 64) && (offset < 128))
  {
    BigInt result;
    result.elm[3] = (this->elm[2] << (offset - 64));
    result.elm[3] |= (this->elm[1] >> (128 - offset));
    result.elm[2] = (this->elm[1] << (offset - 64));
    result.elm[2] |= (this->elm[0] >> (128 - offset));
    result.elm[1] = (this->elm[0] << (offset - 64));
    //result.elm[0] = 0;
    return result;
  }
  else if ((offset > 128) && (offset < 192))
  {
    BigInt result;
    result.elm[3] = (this->elm[1] << (offset - 128));
    result.elm[3] |= (this->elm[0] >> (192 - offset));
    result.elm[2] = (this->elm[0] << (offset - 128));
    //result.elm[1] = 0;
    //result.elm[0] = 0;
    return result;
  }
  else if ((offset > 192) && (offset < 256))
  {
    BigInt result;
    result.elm[3] = (this->elm[0] << (offset - 192));
    //result.elm[2] = 0;
    //result.elm[1] = 0;
    //result.elm[0] = 0;
    return result;
  }
  else if (offset == 64)
  {
    BigInt result;
    result.elm[3] = this->elm[2];
    result.elm[2] = this->elm[1];
    result.elm[1] = this->elm[0];
    //result.elm[0] = 0;
    return result;
  }
  else if (offset == 128)
  {
    BigInt result;
    result.elm[3] = this->elm[1];
    result.elm[2] = this->elm[0];
    //result.elm[1] = 0;
    //result.elm[0] = 0;
    return result;
  }
  else if (offset == 192)
  {
    BigInt result;
    result.elm[3] = this->elm[0];
    //result.elm[2] = 0;
    //result.elm[1] = 0;
    //result.elm[0] = 0;
    return result;
  }
  //else if (offset == 0)
  //{
    //return (*this);
  //}
  else if (offset > 255)
  {
    return bigint_0;
  }
  else if (offset < 0)
  {
    return bigint_0;
  }

  return (*this);
}

// bitwise right shift for BigInt
BigInt BigInt::operator >>(const int32_t offset) const
{
  bool negative_sign = false;
  if (this->elm[3] & 0x8000000000000000)
  {
    negative_sign = true;
  }

  if ((offset > 0) && (offset < 64))
  {
    BigInt result;
    result.elm[3] = (this->elm[3] >> offset);
    if (negative_sign == true)
    {
      result.elm[3] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - offset);
    }
    result.elm[2] = (this->elm[2] >> offset);
    result.elm[2] |= (this->elm[3] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    result.elm[1] = (this->elm[1] >> offset);
    result.elm[1] |= (this->elm[2] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    result.elm[0] = (this->elm[0] >> offset);
    result.elm[0] |= (this->elm[1] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    return result;
  }
  else if ((offset > 64) && (offset < 128))
  {
    BigInt result;
    int32_t adjusted_offset = offset % 64;
    result.elm[0] = (this->elm[1] >> adjusted_offset);
    result.elm[0] |= (this->elm[2] << (128 - offset));
    result.elm[1] = (this->elm[2] >> adjusted_offset);
    result.elm[1] |= (this->elm[3] << (128 - offset));
    result.elm[2] = (this->elm[3] >> adjusted_offset);
    //result.elm[3] = 0;

    if (negative_sign == true)
    {
      result.elm[2] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    //else
    //{
      //result.elm[3] = 0;
    //}
    return result;
  }
  else if ((offset > 128) && (offset < 192))
  {
    BigInt result;
    int32_t adjusted_offset = offset % 64;
    result.elm[0] = (this->elm[2] >> adjusted_offset);
    result.elm[0] |= (this->elm[3] << (192 - offset));
    result.elm[1] = (this->elm[3] >> adjusted_offset);
    //result.elm[2] = 0;
    //result.elm[3] = 0;

    if (negative_sign == true)
    {
      result.elm[1] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      result.elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    //else
    //{
      //result.elm[2] = 0;
      //result.elm[3] = 0;
    //}
    return result;
  }
  else if ((offset > 192) && (offset < 256))
  {
    BigInt result;
    int32_t adjusted_offset = offset % 64;
    result.elm[0] = (this->elm[3] >> adjusted_offset);
    //result.elm[1] = 0;
    //result.elm[2] = 0;
    //result.elm[3] = 0;

    if (negative_sign == true)
    {
      result.elm[0] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      result.elm[1] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    //else
    //{
      //result.elm[1] = 0;
      //result.elm[2] = 0;
      //result.elm[3] = 0;
    //}
    return result;
  }
  else if (offset == 64)
  {
    BigInt result;
    if (negative_sign == true)
    {
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    result.elm[2] = this->elm[3];
    result.elm[1] = this->elm[2];
    result.elm[0] = this->elm[1];
    //else
    //{
      //result.elm[3] = 0;
    //}
    return result;
  }
  else if (offset == 128)
  {
    BigInt result;
    if (negative_sign == true)
    {
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    result.elm[1] = this->elm[3];
    result.elm[0] = this->elm[2];
    //else
    //{
      //result.elm[3] = 0;
      //result.elm[2] = 0;
    //}
    return result;
  }
  else if (offset == 192)
  {
    BigInt result;
    if (negative_sign == true)
    {
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[1] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    result.elm[0] = this->elm[3];
    //else
    //{
      //result.elm[3] = 0;
      //result.elm[2] = 0;
      //result.elm[1] = 0;
    //}
    return result;
  }
  //else if (offset == 0)
  //{
    //return (*this);
  //}
  else if (offset > 255)
  {
    if (negative_sign == true)
    {
      return bigint_negative_1;
    }
    return bigint_0;
  }
  else if (offset < 0)
  {
    return bigint_0;
  }

  return (*this);
}

// bitwise right shift(BigInt type offset) for BigInt
BigInt BigInt::operator >>(const BigInt& offset_bigint) const
{
  bool negative_sign = false;
  if (this->elm[3] & 0x8000000000000000)
  {
    negative_sign = true;
  }

  if ((offset_bigint.elm[3] > 0) ||
      (offset_bigint.elm[2] > 0) ||
      (offset_bigint.elm[1] > 0) ||
      (offset_bigint.elm[0] > 255))
  {
    if (offset_bigint.elm[3] & 0x8000000000000000)
    {
      return bigint_0;
    }
    else
    {
      if (negative_sign == true)
      {
        return bigint_negative_1;
      }
      return bigint_0;
    }
  }

  int32_t offset = (int32_t)offset_bigint.elm[0];

  if ((offset > 0) && (offset < 64))
  {
    BigInt result;
    result.elm[3] = (this->elm[3] >> offset);
    if (negative_sign == true)
    {
      result.elm[3] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - offset);
    }
    result.elm[2] = (this->elm[2] >> offset);
    result.elm[2] |= (this->elm[3] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    result.elm[1] = (this->elm[1] >> offset);
    result.elm[1] |= (this->elm[2] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    result.elm[0] = (this->elm[0] >> offset);
    result.elm[0] |= (this->elm[1] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    return result;
  }
  else if ((offset > 64) && (offset < 128))
  {
    BigInt result;
    int32_t adjusted_offset = offset % 64;
    result.elm[0] = (this->elm[1] >> adjusted_offset);
    result.elm[0] |= (this->elm[2] << (128 - offset));
    result.elm[1] = (this->elm[2] >> adjusted_offset);
    result.elm[1] |= (this->elm[3] << (128 - offset));
    result.elm[2] = (this->elm[3] >> adjusted_offset);
    //result.elm[3] = 0;

    if (negative_sign == true)
    {
      result.elm[2] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    //else
    //{
      //result.elm[3] = 0;
    //}
    return result;
  }
  else if ((offset > 128) && (offset < 192))
  {
    BigInt result;
    int32_t adjusted_offset = offset % 64;
    result.elm[0] = (this->elm[2] >> adjusted_offset);
    result.elm[0] |= (this->elm[3] << (192 - offset));
    result.elm[1] = (this->elm[3] >> adjusted_offset);
    //result.elm[2] = 0;
    //result.elm[3] = 0;

    if (negative_sign == true)
    {
      result.elm[1] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      result.elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    //else
    //{
      //result.elm[2] = 0;
      //result.elm[3] = 0;
    //}
    return result;
  }
  else if ((offset > 192) && (offset < 256))
  {
    BigInt result;
    int32_t adjusted_offset = offset % 64;
    result.elm[0] = (this->elm[3] >> adjusted_offset);
    //result.elm[1] = 0;
    //result.elm[2] = 0;
    //result.elm[3] = 0;

    if (negative_sign == true)
    {
      result.elm[0] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      result.elm[1] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    //else
    //{
      //result.elm[1] = 0;
      //result.elm[2] = 0;
      //result.elm[3] = 0;
    //}
    return result;
  }
  else if (offset == 64)
  {
    BigInt result;
    if (negative_sign == true)
    {
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    result.elm[2] = this->elm[3];
    result.elm[1] = this->elm[2];
    result.elm[0] = this->elm[1];
    //else
    //{
      //result.elm[3] = 0;
    //}
    return result;
  }
  else if (offset == 128)
  {
    BigInt result;
    if (negative_sign == true)
    {
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    result.elm[1] = this->elm[3];
    result.elm[0] = this->elm[2];
    //else
    //{
      //result.elm[3] = 0;
      //result.elm[2] = 0;
    //}
    return result;
  }
  else if (offset == 192)
  {
    BigInt result;
    if (negative_sign == true)
    {
      result.elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      result.elm[1] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    result.elm[0] = this->elm[3];
    //else
    //{
      //result.elm[3] = 0;
      //result.elm[2] = 0;
      //result.elm[1] = 0;
    //}
    return result;
  }
  //else if (offset == 0)
  //{
    //return (*this);
  //}
  else if (offset > 255)
  {
    if (negative_sign == true)
    {
      return bigint_negative_1;
    }
    return bigint_0;
  }
  else if (offset < 0)
  {
    return bigint_0;
  }

  return (*this);
}

// addition assignment operator += overloading for BigInt
void BigInt::operator +=(const BigInt& addend)
{
  BigInt temp_bigint(*this);

  this->elm[3] += addend.elm[3];
  this->elm[2] += addend.elm[2];
  this->elm[1] += addend.elm[1];
  this->elm[0] += addend.elm[0];
  if (this->elm[0] < temp_bigint.elm[0])
  {
    this->elm[1] += (uint64_t)1;
  }
  if ((this->elm[1] < temp_bigint.elm[1]) ||
      ((this->elm[1] == temp_bigint.elm[1]) &&
       (addend.elm[1] != 0)))
  {
    this->elm[2] += (uint64_t)1;
  }
  if ((this->elm[2] < temp_bigint.elm[2]) ||
      ((this->elm[2] == temp_bigint.elm[2]) &&
       (addend.elm[2] != 0)))
  {
    this->elm[3] += (uint64_t)1;
  }

  return;
}

// subtraction assignment operator -= overloading for BigInt
void BigInt::operator -=(const BigInt& subtrahend)
{
  BigInt temp_bigint(*this);
  BigInt _subtrahend(subtrahend);

  _subtrahend.elm[3] = ~_subtrahend.elm[3];
  _subtrahend.elm[2] = ~_subtrahend.elm[2];
  _subtrahend.elm[1] = ~_subtrahend.elm[1];
  _subtrahend.elm[0] = ~_subtrahend.elm[0];
  if ((_subtrahend.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
      (_subtrahend.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
      (_subtrahend.elm[2] == 0xFFFFFFFFFFFFFFFF))
  {
    _subtrahend.elm[3] += 1;
    _subtrahend.elm[2] = 0;
    _subtrahend.elm[1] = 0;
    _subtrahend.elm[0] = 0;
  }
  else if ((_subtrahend.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
            (_subtrahend.elm[1] == 0xFFFFFFFFFFFFFFFF))
  {
    _subtrahend.elm[2] += 1;
    _subtrahend.elm[1] = 0;
    _subtrahend.elm[0] = 0;
  }
  else if (_subtrahend.elm[0] == 0xFFFFFFFFFFFFFFFF)
  {
    _subtrahend.elm[1] += 1;
    _subtrahend.elm[0] = 0;
  }
  else
  {
    _subtrahend.elm[0] += 1;
  }

  this->elm[3] += _subtrahend.elm[3];
  this->elm[2] += _subtrahend.elm[2];
  this->elm[1] += _subtrahend.elm[1];
  this->elm[0] += _subtrahend.elm[0];
  if (this->elm[0] < temp_bigint.elm[0])
  {
    this->elm[1] += (uint64_t)1;
  }
  if ((this->elm[1] < temp_bigint.elm[1]) ||
      ((this->elm[1] == temp_bigint.elm[1]) &&
       (_subtrahend.elm[1] != 0)))
  {
    this->elm[2] += (uint64_t)1;
  }
  if ((this->elm[2] < temp_bigint.elm[2]) ||
      ((this->elm[2] == temp_bigint.elm[2]) &&
       (_subtrahend.elm[2] != 0)))
  {
    this->elm[3] += (uint64_t)1;
  }

  return;
}

// multiplication assignment operator *= overloading for BigInt
void BigInt::operator *=(const BigInt& multiplier)
{
  BigInt _multiplier(multiplier);

  bool negative_sign = false;

  if (this->elm[3] & (uint64_t)0x8000000000000000)
  {
    negative_sign = !negative_sign;
    this->elm[3] = ~this->elm[3];
    this->elm[2] = ~this->elm[2];
    this->elm[1] = ~this->elm[1];
    this->elm[0] = ~this->elm[0];
    if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[3] += 1;
      this->elm[2] = 0;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[2] += 1;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      this->elm[1] += 1;
      this->elm[0] = 0;
    }
    else
    {
      this->elm[0] += 1;
    }
  }

  if (_multiplier.elm[3] & (uint64_t)0x8000000000000000)
  {
    negative_sign = !negative_sign;
    _multiplier.elm[3] = ~_multiplier.elm[3];
    _multiplier.elm[2] = ~_multiplier.elm[2];
    _multiplier.elm[1] = ~_multiplier.elm[1];
    _multiplier.elm[0] = ~_multiplier.elm[0];
    if ((_multiplier.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (_multiplier.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (_multiplier.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      _multiplier.elm[3] += 1;
      _multiplier.elm[2] = 0;
      _multiplier.elm[1] = 0;
      _multiplier.elm[0] = 0;
    }
    else if ((_multiplier.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (_multiplier.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      _multiplier.elm[2] += 1;
      _multiplier.elm[1] = 0;
      _multiplier.elm[0] = 0;
    }
    else if (_multiplier.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      _multiplier.elm[1] += 1;
      _multiplier.elm[0] = 0;
    }
    else
    {
      _multiplier.elm[0] += 1;
    }
  }

  // _multiplicand = (AB)(CD)(EF)(GH)
  // _multiplier = (IJ)(KL)(MN)(OP)
  // YZ = H*P
  // XY = G*P + H*O
  // WX = F*P + G*O + H*N
  // VW = E*P + F*O + G*N + H*M
  // UV = D*P + E*O + F*N + G*M + H*L
  // TU = C*P + D*O + E*N + F*M + G*L + H*K
  // ST = B*P + C*O + D*N + E*M + F*L + G*K + H*J
  // RS = A*P + B*O + C*N + D*M + E*L + F*K + G*J + H*I

  uint32_t A = (uint32_t)((this->elm[3] & 0xFFFFFFFF00000000) >> 32);
  uint32_t B = (uint32_t)(this->elm[3] & 0x00000000FFFFFFFF);
  uint32_t C = (uint32_t)((this->elm[2] & 0xFFFFFFFF00000000) >> 32);
  uint32_t D = (uint32_t)(this->elm[2] & 0x00000000FFFFFFFF);
  uint32_t E = (uint32_t)((this->elm[1] & 0xFFFFFFFF00000000) >> 32);
  uint32_t F = (uint32_t)(this->elm[1] & 0x00000000FFFFFFFF);
  uint32_t G = (uint32_t)((this->elm[0] & 0xFFFFFFFF00000000) >> 32);
  uint32_t H = (uint32_t)(this->elm[0] & 0x00000000FFFFFFFF);

  uint32_t I = (uint32_t)((_multiplier.elm[3] & 0xFFFFFFFF00000000) >> 32);
  uint32_t J = (uint32_t)(_multiplier.elm[3] & 0x00000000FFFFFFFF);
  uint32_t K = (uint32_t)((_multiplier.elm[2] & 0xFFFFFFFF00000000) >> 32);
  uint32_t L = (uint32_t)(_multiplier.elm[2] & 0x00000000FFFFFFFF);
  uint32_t M = (uint32_t)((_multiplier.elm[1] & 0xFFFFFFFF00000000) >> 32);
  uint32_t N = (uint32_t)(_multiplier.elm[1] & 0x00000000FFFFFFFF);
  uint32_t O = (uint32_t)((_multiplier.elm[0] & 0xFFFFFFFF00000000) >> 32);
  uint32_t P = (uint32_t)(_multiplier.elm[0] & 0x00000000FFFFFFFF);

  uint64_t YZ = 0;
  uint64_t XY = 0;
  uint64_t WX = 0;
  uint64_t VW = 0;
  uint64_t UV = 0;
  uint64_t TU = 0;
  uint64_t ST = 0;
  uint64_t RS = 0;

  // 4294967296 = 0x100000000
  // consider overflow except RS and YZ (YZ never overflow)
  YZ = (uint64_t)H * (uint64_t)P;

  XY = ((uint64_t)G * (uint64_t)P) + ((uint64_t)H * (uint64_t)O);
  if (XY < ((uint64_t)G * (uint64_t)P))
  {
    WX += (uint64_t)4294967296;
  }

  WX += ((uint64_t)F * (uint64_t)P);
  if (WX < ((uint64_t)F * (uint64_t)P))
  {
    VW += (uint64_t)4294967296;
  }
  WX += ((uint64_t)G * (uint64_t)O);
  if (WX < ((uint64_t)G * (uint64_t)O))
  {
    VW += (uint64_t)4294967296;
  }
  WX += ((uint64_t)H * (uint64_t)N);
  if (WX < ((uint64_t)H * (uint64_t)N))
  {
    VW += (uint64_t)4294967296;
  }

  VW += ((uint64_t)E * (uint64_t)P);
  if (VW < ((uint64_t)E * (uint64_t)P))
  {
    UV += (uint64_t)4294967296;
  }
  VW += ((uint64_t)F * (uint64_t)O);
  if (VW < ((uint64_t)F * (uint64_t)O))
  {
    UV += (uint64_t)4294967296;
  }
  VW += ((uint64_t)G * (uint64_t)N);
  if (VW < ((uint64_t)G * (uint64_t)N))
  {
    UV += (uint64_t)4294967296;
  }
  VW += ((uint64_t)H * (uint64_t)M);
  if (VW < ((uint64_t)H * (uint64_t)M))
  {
    UV += (uint64_t)4294967296;
  }

  UV += ((uint64_t)D * (uint64_t)P);
  if (UV < ((uint64_t)D * (uint64_t)P))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)E * (uint64_t)O);
  if (UV < ((uint64_t)E * (uint64_t)O))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)F * (uint64_t)N);
  if (UV < ((uint64_t)F * (uint64_t)N))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)G * (uint64_t)M);
  if (UV < ((uint64_t)G * (uint64_t)M))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)H * (uint64_t)L);
  if (UV < ((uint64_t)H * (uint64_t)L))
  {
    TU += (uint64_t)4294967296;
  }

  TU += ((uint64_t)C * (uint64_t)P);
  if (TU < ((uint64_t)C * (uint64_t)P))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)D * (uint64_t)O);
  if (TU < ((uint64_t)D * (uint64_t)O))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)E * (uint64_t)N);
  if (TU < ((uint64_t)E * (uint64_t)N))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)F * (uint64_t)M);
  if (TU < ((uint64_t)F * (uint64_t)M))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)G * (uint64_t)L);
  if (TU < ((uint64_t)G * (uint64_t)L))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)H * (uint64_t)K);
  if (TU < ((uint64_t)H * (uint64_t)K))
  {
    ST += (uint64_t)4294967296;
  }

  ST += ((uint64_t)B * (uint64_t)P);
  if (ST < ((uint64_t)B * (uint64_t)P))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)C * (uint64_t)O);
  if (ST < ((uint64_t)C * (uint64_t)O))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)D * (uint64_t)N);
  if (ST < ((uint64_t)D * (uint64_t)N))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)E * (uint64_t)M);
  if (ST < ((uint64_t)E * (uint64_t)M))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)F * (uint64_t)L);
  if (ST < ((uint64_t)F * (uint64_t)L))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)G * (uint64_t)K);
  if (ST < ((uint64_t)G * (uint64_t)K))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)H * (uint64_t)J);
  if (ST < ((uint64_t)H * (uint64_t)J))
  {
    RS += (uint64_t)4294967296;
  }

  RS += ((uint64_t)A * (uint64_t)P) +
        ((uint64_t)B * (uint64_t)O) +
        ((uint64_t)C * (uint64_t)N) +
        ((uint64_t)D * (uint64_t)M) +
        ((uint64_t)E * (uint64_t)L) +
        ((uint64_t)F * (uint64_t)K) +
        ((uint64_t)G * (uint64_t)J) +
        ((uint64_t)H * (uint64_t)I);

  //this->elm[0] = ((XY & 0x00000000FFFFFFFF) << 32) + YZ;
  //this->elm[1] = ((VW & 0x00000000FFFFFFFF) << 32) + WX + ((XY & 0xFFFFFFFF00000000) >> 32);
  //this->elm[2] = ((TU & 0x00000000FFFFFFFF) << 32) + UV + ((VW & 0xFFFFFFFF00000000) >> 32);
  //this->elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);
  // consider overflow except this->elm[3], ex: this->elm[0] = 0xFFFFFFFA00000000 + 0x9FFFFFFF6 (overflow)
  this->elm[0] = ((XY & 0x00000000FFFFFFFF) << 32);
  this->elm[1] = ((VW & 0x00000000FFFFFFFF) << 32);
  this->elm[2] = ((TU & 0x00000000FFFFFFFF) << 32);
  this->elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);

  if ((this->elm[0] + YZ) < YZ)
  {
    this->elm[0] += YZ;
    this->elm[1] += 1;
  }
  else
  {
    this->elm[0] += YZ;
  }

  if ((this->elm[1] + WX) < WX)
  {
    this->elm[1] += WX;
    this->elm[2] += 1;
  }
  else
  {
    this->elm[1] += WX;
  }
  if ((this->elm[1] + ((XY & 0xFFFFFFFF00000000) >> 32)) < ((XY & 0xFFFFFFFF00000000) >> 32))
  {
    this->elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
    this->elm[2] += 1;
  }
  else
  {
    this->elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
  }

  if ((this->elm[2] + UV) < UV)
  {
    this->elm[2] += UV;
    this->elm[3] += 1;
  }
  else
  {
    this->elm[2] += UV;
  }
  if ((this->elm[2] + ((VW & 0xFFFFFFFF00000000) >> 32)) < ((VW & 0xFFFFFFFF00000000) >> 32))
  {
    this->elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
    this->elm[3] += 1;
  }
  else
  {
    this->elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
  }

  if (negative_sign)
  {
    this->elm[3] = ~this->elm[3];
    this->elm[2] = ~this->elm[2];
    this->elm[1] = ~this->elm[1];
    this->elm[0] = ~this->elm[0];
    if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[3] += 1;
      this->elm[2] = 0;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[2] += 1;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
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

// division assignment operator /= overloading for BigInt
void BigInt::operator /=(const BigInt& divisor)
{
  BigInt remainder;
  this->div_mod((*this), divisor, remainder);

  return;
}

// modulo assignment operator %= overloading for BigInt
void BigInt::operator %=(const BigInt& divisor)
{
  BigInt quotient;
  quotient.div_mod((*this), divisor, (*this));

  return;
}

// bitwise AND assignment operator &= overloading for BigInt
void BigInt::operator &=(const BigInt& bigint)
{
  this->elm[3] &= bigint.elm[3];
  this->elm[2] &= bigint.elm[2];
  this->elm[1] &= bigint.elm[1];
  this->elm[0] &= bigint.elm[0];

  return;
}

// bitwise OR assignment operator |= overloading for BigInt
void BigInt::operator |=(const BigInt& bigint)
{
  this->elm[3] |= bigint.elm[3];
  this->elm[2] |= bigint.elm[2];
  this->elm[1] |= bigint.elm[1];
  this->elm[0] |= bigint.elm[0];

  return;
}

// bitwise XOR assignment operator ^= overloading for BigInt
void BigInt::operator ^=(const BigInt& bigint)
{
  this->elm[3] ^= bigint.elm[3];
  this->elm[2] ^= bigint.elm[2];
  this->elm[1] ^= bigint.elm[1];
  this->elm[0] ^= bigint.elm[0];

  return;
}

// bitwise left shift assignment operator <<= overloading for BigInt
void BigInt::operator <<=(const int32_t offset)
{
  if ((offset > 0) && (offset < 64))
  {
    this->elm[3] = (this->elm[3] << offset);
    this->elm[3] |= (this->elm[2] >> (64 - offset));
    this->elm[2] = (this->elm[2] << offset);
    this->elm[2] |= (this->elm[1] >> (64 - offset));
    this->elm[1] = (this->elm[1] << offset);
    this->elm[1] |= (this->elm[0] >> (64 - offset));
    this->elm[0] = (this->elm[0] << offset);
  }
  else if ((offset > 64) && (offset < 128))
  {
    this->elm[3] = (this->elm[2] << (offset - 64));
    this->elm[3] |= (this->elm[1] >> (128 - offset));
    this->elm[2] = (this->elm[1] << (offset - 64));
    this->elm[2] |= (this->elm[0] >> (128 - offset));
    this->elm[1] = (this->elm[0] << (offset - 64));
    this->elm[0] = 0;
  }
  else if ((offset > 128) && (offset < 192))
  {
    this->elm[3] = (this->elm[1] << (offset - 128));
    this->elm[3] |= (this->elm[0] >> (192 - offset));
    this->elm[2] = (this->elm[0] << (offset - 128));
    this->elm[1] = 0;
    this->elm[0] = 0;
  }
  else if ((offset > 192) && (offset < 256))
  {
    this->elm[3] = (this->elm[0] << (offset - 192));
    this->elm[2] = 0;
    this->elm[1] = 0;
    this->elm[0] = 0;
  }
  else if (offset == 64)
  {
    this->elm[3] = this->elm[2];
    this->elm[2] = this->elm[1];
    this->elm[1] = this->elm[0];
    this->elm[0] = 0;
  }
  else if (offset == 128)
  {
    this->elm[3] = this->elm[1];
    this->elm[2] = this->elm[0];
    this->elm[1] = 0;
    this->elm[0] = 0;
  }
  else if (offset == 192)
  {
    this->elm[3] = this->elm[0];
    this->elm[2] = 0;
    this->elm[1] = 0;
    this->elm[0] = 0;
  }
  //else if (offset == 0)
  //{
  //  return;
  //}
  else if (offset > 255)
  {
    memset(&this->elm[0], 0, BIGINT_SIZE);
  }
  else if (offset < 0)
  {
    memset(&this->elm[0], 0, BIGINT_SIZE);
  }

  return;
}

// bitwise left shift assignment operator <<=(BigInt type offset) overloading for BigInt
void BigInt::operator <<=(const BigInt& offset_bigint)
{
  if ((offset_bigint.elm[3] > 0) ||
      (offset_bigint.elm[2] > 0) ||
      (offset_bigint.elm[1] > 0) ||
      (offset_bigint.elm[0] > 255))
  {
    memset(this, 0, BIGINT_SIZE);
  }
  else
  {
    int32_t offset = (int32_t)offset_bigint.elm[0];

    if ((offset > 0) && (offset < 64))
    {
      this->elm[3] = (this->elm[3] << offset);
      this->elm[3] |= (this->elm[2] >> (64 - offset));
      this->elm[2] = (this->elm[2] << offset);
      this->elm[2] |= (this->elm[1] >> (64 - offset));
      this->elm[1] = (this->elm[1] << offset);
      this->elm[1] |= (this->elm[0] >> (64 - offset));
      this->elm[0] = (this->elm[0] << offset);
    }
    else if ((offset > 64) && (offset < 128))
    {
      this->elm[3] = (this->elm[2] << (offset - 64));
      this->elm[3] |= (this->elm[1] >> (128 - offset));
      this->elm[2] = (this->elm[1] << (offset - 64));
      this->elm[2] |= (this->elm[0] >> (128 - offset));
      this->elm[1] = (this->elm[0] << (offset - 64));
      this->elm[0] = 0;
    }
    else if ((offset > 128) && (offset < 192))
    {
      this->elm[3] = (this->elm[1] << (offset - 128));
      this->elm[3] |= (this->elm[0] >> (192 - offset));
      this->elm[2] = (this->elm[0] << (offset - 128));
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if ((offset > 192) && (offset < 256))
    {
      this->elm[3] = (this->elm[0] << (offset - 192));
      this->elm[2] = 0;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if (offset == 64)
    {
      this->elm[3] = this->elm[2];
      this->elm[2] = this->elm[1];
      this->elm[1] = this->elm[0];
      this->elm[0] = 0;
    }
    else if (offset == 128)
    {
      this->elm[3] = this->elm[1];
      this->elm[2] = this->elm[0];
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if (offset == 192)
    {
      this->elm[3] = this->elm[0];
      this->elm[2] = 0;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    //else if (offset == 0)
    //{
    //  return;
    //}
    else if (offset > 255)
    {
      memset(&this->elm[0], 0, BIGINT_SIZE);
    }
    else if (offset < 0)
    {
      memset(&this->elm[0], 0, BIGINT_SIZE);
    }
  }

  return;
}

// int32_t to BigInt
void BigInt::from_int32_t(int32_t int32)
{
  if (int32 < 0)
  {
    int64_t temp_element = (int64_t)int32;
    memcpy(&this->elm[0], &temp_element, SIZE_OF_8_BYTES);
    this->elm[1] = 0xFFFFFFFFFFFFFFFF;
    this->elm[2] = 0xFFFFFFFFFFFFFFFF;
    this->elm[3] = 0xFFFFFFFFFFFFFFFF;
  }
  else
  {
    this->elm[0] = (uint64_t)int32;
    //this->elm[1] = 0x0;
    //this->elm[2] = 0x0;
    //this->elm[3] = 0x0;
  }

  return;
}

// int64_t to BigInt
void BigInt::from_int64_t(int64_t int64)
{
  if (int64 < 0)
  {
    memcpy(&this->elm[0], &int64, SIZE_OF_8_BYTES);
    this->elm[1] = 0xFFFFFFFFFFFFFFFF;
    this->elm[2] = 0xFFFFFFFFFFFFFFFF;
    this->elm[3] = 0xFFFFFFFFFFFFFFFF;
  }
  else
  {
    this->elm[0] = (uint64_t)int64;
    //this->elm[1] = 0x0;
    //this->elm[2] = 0x0;
    //this->elm[3] = 0x0;
  }

  return;
}

// uint64_t to BigInt
void BigInt::from_uint64_t(uint64_t uint64)
{
  this->elm[3] = 0x0;
  this->elm[2] = 0x0;
  this->elm[1] = 0x0;
  this->elm[0] = uint64;

  return;
}

// std::string to BigInt
void BigInt::from_string(const std::string& str_int)
{
  memset(&this->elm[0], 0, BIGINT_SIZE);

  bool negative_sign = false;

  for (size_t i = 0; i < str_int.length(); ++i)
  {
    if (isdigit(str_int[i]))
    {
      uint32_t A = (uint32_t)((this->elm[3] & 0xFFFFFFFF00000000) >> 32);
      uint32_t B = (uint32_t)(this->elm[3] & 0x00000000FFFFFFFF);
      uint32_t C = (uint32_t)((this->elm[2] & 0xFFFFFFFF00000000) >> 32);
      uint32_t D = (uint32_t)(this->elm[2] & 0x00000000FFFFFFFF);
      uint32_t E = (uint32_t)((this->elm[1] & 0xFFFFFFFF00000000) >> 32);
      uint32_t F = (uint32_t)(this->elm[1] & 0x00000000FFFFFFFF);
      uint32_t G = (uint32_t)((this->elm[0] & 0xFFFFFFFF00000000) >> 32);
      uint32_t H = (uint32_t)(this->elm[0] & 0x00000000FFFFFFFF);
      uint32_t P = (uint32_t)(0x000000000000000A);

      uint64_t YZ = (uint64_t)H * (uint64_t)P;
      uint64_t XY = (uint64_t)G * (uint64_t)P;
      uint64_t WX = (uint64_t)F * (uint64_t)P;
      uint64_t VW = (uint64_t)E * (uint64_t)P;
      uint64_t UV = (uint64_t)D * (uint64_t)P;
      uint64_t TU = (uint64_t)C * (uint64_t)P;
      uint64_t ST = (uint64_t)B * (uint64_t)P;
      uint64_t RS = (uint64_t)A * (uint64_t)P;

      //this->elm[0] = ((XY & 0x00000000FFFFFFFF) << 32) + YZ;
      //this->elm[1] = ((VW & 0x00000000FFFFFFFF) << 32) + WX + ((XY & 0xFFFFFFFF00000000) >> 32);
      //this->elm[2] = ((TU & 0x00000000FFFFFFFF) << 32) + UV + ((VW & 0xFFFFFFFF00000000) >> 32);
      //this->elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);
      // consider overflow except this->elm[3], ex: this->elm[0] = 0xFFFFFFFA00000000 + 0x9FFFFFFF6 (overflow)
      this->elm[0] = ((XY & 0x00000000FFFFFFFF) << 32);
      this->elm[1] = ((VW & 0x00000000FFFFFFFF) << 32);
      this->elm[2] = ((TU & 0x00000000FFFFFFFF) << 32);
      this->elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);

      if ((this->elm[0] + YZ) < YZ)
      {
        this->elm[0] += YZ;
        this->elm[1] += 1;
      }
      else
      {
        this->elm[0] += YZ;
      }

      if ((this->elm[1] + WX) < WX)
      {
        this->elm[1] += WX;
        this->elm[2] += 1;
      }
      else
      {
        this->elm[1] += WX;
      }
      if ((this->elm[1] + ((XY & 0xFFFFFFFF00000000) >> 32)) < ((XY & 0xFFFFFFFF00000000) >> 32))
      {
        this->elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
        this->elm[2] += 1;
      }
      else
      {
        this->elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
      }

      if ((this->elm[2] + UV) < UV)
      {
        this->elm[2] += UV;
        this->elm[3] += 1;
      }
      else
      {
        this->elm[2] += UV;
      }
      if ((this->elm[2] + ((VW & 0xFFFFFFFF00000000) >> 32)) < ((VW & 0xFFFFFFFF00000000) >> 32))
      {
        this->elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
        this->elm[3] += 1;
      }
      else
      {
        this->elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
      }

      //48 = '0'
      if (((this->elm[0] + (uint64_t)(str_int[i] - 48)) < this->elm[0]) &&
          (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
          (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
      {
        this->elm[3] += (uint64_t)1;
        this->elm[2] = 0;
        this->elm[1] = 0;
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
      else if (((this->elm[0] + (uint64_t)(str_int[i] - 48)) < this->elm[0]) &&
               (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
      {
        this->elm[2] += (uint64_t)1;
        this->elm[1] = 0;
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
      else if ((this->elm[0] + (uint64_t)(str_int[i] - 48)) < this->elm[0])
      {
        this->elm[1] += (uint64_t)1;
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
      else
      {
        this->elm[0] = this->elm[0] + (uint64_t)(str_int[i] - '0');
      }
    }
    else if ((i == 0) && (str_int[i] == '-'))
    {
      negative_sign = true;
    }
    else if ((i == 0) && (str_int[i] == '+'))
    {
      //negative_sign = false;
    }
    else
    {
      std::cerr << "BigInt::from_string() error [" << str_int.c_str() << "]" << std::endl;
      abort();
    }
  }

  if (negative_sign)
  {
    this->elm[3] = ~this->elm[3];
    this->elm[2] = ~this->elm[2];
    this->elm[1] = ~this->elm[1];
    this->elm[0] = ~this->elm[0];
    if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[3] += 1;
      this->elm[2] = 0;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
             (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[2] += 1;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
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

// BigInt to std::string
std::string BigInt::to_string(void) const
{
  BigInt temp_bigint(*this);
  std::string result("");

  if ((this->elm[3] == 0) && (this->elm[2] == 0) && (this->elm[1] == 0))
  {
    std::ostringstream temp;
    temp << std::dec << this->elm[0];
    result = temp.str();
    return result;
  }

  // -57896044618658097711785492504343953926634992332820282019728792003956564819968 無法轉正.
  // -57896044618658097711785492504343953926634992332820282019728792003956564819968 % 10000000000000000000
  // = -8792003956564819968 (85FC86FBC9200000) => 會被誤認為9654740117144731648.
  if ((this->elm[3] == 0x8000000000000000) &&
      (this->elm[2] == 0) &&
      (this->elm[1] == 0) &&
      (this->elm[0] == 0))
  {
    result = "-57896044618658097711785492504343953926634992332820282019728792003956564819968";
    return result;
  }

  bool negative_sign = false;

  if (temp_bigint.elm[3] & (uint64_t)0x8000000000000000)
  {
    negative_sign = true;
    temp_bigint.elm[3] = ~temp_bigint.elm[3];
    temp_bigint.elm[2] = ~temp_bigint.elm[2];
    temp_bigint.elm[1] = ~temp_bigint.elm[1];
    temp_bigint.elm[0] = ~temp_bigint.elm[0];
    if ((temp_bigint.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (temp_bigint.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (temp_bigint.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      temp_bigint.elm[3] += 1;
      temp_bigint.elm[2] = 0;
      temp_bigint.elm[1] = 0;
      temp_bigint.elm[0] = 0;
    }
    else if ((temp_bigint.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (temp_bigint.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      temp_bigint.elm[2] += 1;
      temp_bigint.elm[1] = 0;
      temp_bigint.elm[0] = 0;
    }
    else if (temp_bigint.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      temp_bigint.elm[1] += 1;
      temp_bigint.elm[0] = 0;
    }
    else
    {
      temp_bigint.elm[0] += 1;
    }
  }

  while ((temp_bigint.elm[3] != 0) ||
          (temp_bigint.elm[2] != 0) ||
          (temp_bigint.elm[1] != 0) ||
          (temp_bigint.elm[0] != 0) )
  {
    //10000000000000000000 = 0x8AC7230489E80000
    uint64_t K = (uint64_t)(temp_bigint % (uint64_t)0x8AC7230489E80000).elm[0];
    temp_bigint /= (uint64_t)0x8AC7230489E80000;

    if ((temp_bigint.elm[3] != 0) ||
        (temp_bigint.elm[2] != 0) ||
        (temp_bigint.elm[1] != 0) ||
        (temp_bigint.elm[0] != 0) )
    {
      std::string temp_string("0000000000000000000");
      std::ostringstream temp;
      temp << std::dec << K;
      std::string num = temp.str();
      temp_string.replace(19 - num.length(), num.length(), num);
      result = temp_string + result;
    }
    else
    {
      std::ostringstream temp;
      temp << std::dec << K;
      std::string temp_string = temp.str();
      result = temp_string + result;
    }
  }

  if (negative_sign)
  {
    result = "-" + result;
  }

  return result;
}

// return sign, < 0(-1), == 0(0), > 0(1)
int64_t BigInt::sign(void) const
{
  if (this->elm[3] & 0x8000000000000000)
  {
    return -1;
  }
  else if ((this->elm[3] == 0) && (this->elm[2] == 0) && (this->elm[1] == 0) && (this->elm[0] == 0))
  {
    return 0;
  }

  return 1;
}

// + addition
void BigInt::add(const BigInt& augend, const BigInt& addend)
{
  this->elm[3] = augend.elm[3] + addend.elm[3];
  this->elm[2] = augend.elm[2] + addend.elm[2];
  this->elm[1] = augend.elm[1] + addend.elm[1];
  this->elm[0] = augend.elm[0] + addend.elm[0];
  if (this->elm[0] < augend.elm[0])
  {
    this->elm[1] += (uint64_t)1;
  }
  if ((this->elm[1] < augend.elm[1]) ||
      ((this->elm[1] == augend.elm[1]) &&
       (addend.elm[1] != 0)))
  {
    this->elm[2] += (uint64_t)1;
  }
  if ((this->elm[2] < augend.elm[2]) ||
      ((this->elm[2] == augend.elm[2]) &&
       (addend.elm[2] != 0)))
  {
    this->elm[3] += (uint64_t)1;
  }

  return;
}

// - subtraction
void BigInt::sub(const BigInt& minuend, BigInt subtrahend)
{
  BigInt _subtrahend(subtrahend);

  _subtrahend.elm[3] = ~_subtrahend.elm[3];
  _subtrahend.elm[2] = ~_subtrahend.elm[2];
  _subtrahend.elm[1] = ~_subtrahend.elm[1];
  _subtrahend.elm[0] = ~_subtrahend.elm[0];
  if ((_subtrahend.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
      (_subtrahend.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
      (_subtrahend.elm[2] == 0xFFFFFFFFFFFFFFFF))
  {
    _subtrahend.elm[3] += 1;
    _subtrahend.elm[2] = 0;
    _subtrahend.elm[1] = 0;
    _subtrahend.elm[0] = 0;
  }
  else if ((_subtrahend.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
            (_subtrahend.elm[1] == 0xFFFFFFFFFFFFFFFF))
  {
    _subtrahend.elm[2] += 1;
    _subtrahend.elm[1] = 0;
    _subtrahend.elm[0] = 0;
  }
  else if (_subtrahend.elm[0] == 0xFFFFFFFFFFFFFFFF)
  {
    _subtrahend.elm[1] += 1;
    _subtrahend.elm[0] = 0;
  }
  else
  {
    _subtrahend.elm[0] += 1;
  }

  this->elm[3] = minuend.elm[3] + _subtrahend.elm[3];
  this->elm[2] = minuend.elm[2] + _subtrahend.elm[2];
  this->elm[1] = minuend.elm[1] + _subtrahend.elm[1];
  this->elm[0] = minuend.elm[0] + _subtrahend.elm[0];
  if (this->elm[0] < minuend.elm[0])
  {
    this->elm[1] += (uint64_t)1;
  }
  if ((this->elm[1] < minuend.elm[1]) ||
      ((this->elm[1] == minuend.elm[1]) &&
       (_subtrahend.elm[1] != 0)))
  {
    this->elm[2] += (uint64_t)1;
  }
  if ((this->elm[2] < minuend.elm[2]) ||
      ((this->elm[2] == minuend.elm[2]) &&
       (_subtrahend.elm[2] != 0)))
  {
    this->elm[3] += (uint64_t)1;
  }

  return;
}

// * multiplication
void BigInt::mul(BigInt multiplicand, BigInt multiplier)
{
  bool negative_sign = false;

  if (multiplicand.elm[3] & (uint64_t)0x8000000000000000)
  {
    negative_sign = !negative_sign;
    multiplicand.elm[3] = ~multiplicand.elm[3];
    multiplicand.elm[2] = ~multiplicand.elm[2];
    multiplicand.elm[1] = ~multiplicand.elm[1];
    multiplicand.elm[0] = ~multiplicand.elm[0];
    if ((multiplicand.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (multiplicand.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (multiplicand.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      multiplicand.elm[3] += 1;
      multiplicand.elm[2] = 0;
      multiplicand.elm[1] = 0;
      multiplicand.elm[0] = 0;
    }
    else if ((multiplicand.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (multiplicand.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      multiplicand.elm[2] += 1;
      multiplicand.elm[1] = 0;
      multiplicand.elm[0] = 0;
    }
    else if (multiplicand.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      multiplicand.elm[1] += 1;
      multiplicand.elm[0] = 0;
    }
    else
    {
      multiplicand.elm[0] += 1;
    }
  }

  if (multiplier.elm[3] & (uint64_t)0x8000000000000000)
  {
    negative_sign = !negative_sign;
    multiplier.elm[3] = ~multiplier.elm[3];
    multiplier.elm[2] = ~multiplier.elm[2];
    multiplier.elm[1] = ~multiplier.elm[1];
    multiplier.elm[0] = ~multiplier.elm[0];
    if ((multiplier.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (multiplier.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (multiplier.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      multiplier.elm[3] += 1;
      multiplier.elm[2] = 0;
      multiplier.elm[1] = 0;
      multiplier.elm[0] = 0;
    }
    else if ((multiplier.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (multiplier.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      multiplier.elm[2] += 1;
      multiplier.elm[1] = 0;
      multiplier.elm[0] = 0;
    }
    else if (multiplier.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      multiplier.elm[1] += 1;
      multiplier.elm[0] = 0;
    }
    else
    {
      multiplier.elm[0] += 1;
    }
  }

  // multiplicand = (AB)(CD)(EF)(GH)
  // multiplier = (IJ)(KL)(MN)(OP)
  // YZ = H*P
  // XY = G*P + H*O
  // WX = F*P + G*O + H*N
  // VW = E*P + F*O + G*N + H*M
  // UV = D*P + E*O + F*N + G*M + H*L
  // TU = C*P + D*O + E*N + F*M + G*L + H*K
  // ST = B*P + C*O + D*N + E*M + F*L + G*K + H*J
  // RS = A*P + B*O + C*N + D*M + E*L + F*K + G*J + H*I

  uint32_t A = (uint32_t)((multiplicand.elm[3] & 0xFFFFFFFF00000000) >> 32);
  uint32_t B = (uint32_t)(multiplicand.elm[3] & 0x00000000FFFFFFFF);
  uint32_t C = (uint32_t)((multiplicand.elm[2] & 0xFFFFFFFF00000000) >> 32);
  uint32_t D = (uint32_t)(multiplicand.elm[2] & 0x00000000FFFFFFFF);
  uint32_t E = (uint32_t)((multiplicand.elm[1] & 0xFFFFFFFF00000000) >> 32);
  uint32_t F = (uint32_t)(multiplicand.elm[1] & 0x00000000FFFFFFFF);
  uint32_t G = (uint32_t)((multiplicand.elm[0] & 0xFFFFFFFF00000000) >> 32);
  uint32_t H = (uint32_t)(multiplicand.elm[0] & 0x00000000FFFFFFFF);

  uint32_t I = (uint32_t)((multiplier.elm[3] & 0xFFFFFFFF00000000) >> 32);
  uint32_t J = (uint32_t)(multiplier.elm[3] & 0x00000000FFFFFFFF);
  uint32_t K = (uint32_t)((multiplier.elm[2] & 0xFFFFFFFF00000000) >> 32);
  uint32_t L = (uint32_t)(multiplier.elm[2] & 0x00000000FFFFFFFF);
  uint32_t M = (uint32_t)((multiplier.elm[1] & 0xFFFFFFFF00000000) >> 32);
  uint32_t N = (uint32_t)(multiplier.elm[1] & 0x00000000FFFFFFFF);
  uint32_t O = (uint32_t)((multiplier.elm[0] & 0xFFFFFFFF00000000) >> 32);
  uint32_t P = (uint32_t)(multiplier.elm[0] & 0x00000000FFFFFFFF);

  uint64_t YZ = 0;
  uint64_t XY = 0;
  uint64_t WX = 0;
  uint64_t VW = 0;
  uint64_t UV = 0;
  uint64_t TU = 0;
  uint64_t ST = 0;
  uint64_t RS = 0;

  // 4294967296 = 0x100000000
  // consider overflow except RS and YZ (YZ never overflow)
  YZ = (uint64_t)H * (uint64_t)P;

  XY = ((uint64_t)G * (uint64_t)P) + ((uint64_t)H * (uint64_t)O);
  if (XY < ((uint64_t)G * (uint64_t)P))
  {
    WX += (uint64_t)4294967296;
  }

  WX += ((uint64_t)F * (uint64_t)P);
  if (WX < ((uint64_t)F * (uint64_t)P))
  {
    VW += (uint64_t)4294967296;
  }
  WX += ((uint64_t)G * (uint64_t)O);
  if (WX < ((uint64_t)G * (uint64_t)O))
  {
    VW += (uint64_t)4294967296;
  }
  WX += ((uint64_t)H * (uint64_t)N);
  if (WX < ((uint64_t)H * (uint64_t)N))
  {
    VW += (uint64_t)4294967296;
  }

  VW += ((uint64_t)E * (uint64_t)P);
  if (VW < ((uint64_t)E * (uint64_t)P))
  {
    UV += (uint64_t)4294967296;
  }
  VW += ((uint64_t)F * (uint64_t)O);
  if (VW < ((uint64_t)F * (uint64_t)O))
  {
    UV += (uint64_t)4294967296;
  }
  VW += ((uint64_t)G * (uint64_t)N);
  if (VW < ((uint64_t)G * (uint64_t)N))
  {
    UV += (uint64_t)4294967296;
  }
  VW += ((uint64_t)H * (uint64_t)M);
  if (VW < ((uint64_t)H * (uint64_t)M))
  {
    UV += (uint64_t)4294967296;
  }

  UV += ((uint64_t)D * (uint64_t)P);
  if (UV < ((uint64_t)D * (uint64_t)P))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)E * (uint64_t)O);
  if (UV < ((uint64_t)E * (uint64_t)O))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)F * (uint64_t)N);
  if (UV < ((uint64_t)F * (uint64_t)N))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)G * (uint64_t)M);
  if (UV < ((uint64_t)G * (uint64_t)M))
  {
    TU += (uint64_t)4294967296;
  }
  UV += ((uint64_t)H * (uint64_t)L);
  if (UV < ((uint64_t)H * (uint64_t)L))
  {
    TU += (uint64_t)4294967296;
  }

  TU += ((uint64_t)C * (uint64_t)P);
  if (TU < ((uint64_t)C * (uint64_t)P))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)D * (uint64_t)O);
  if (TU < ((uint64_t)D * (uint64_t)O))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)E * (uint64_t)N);
  if (TU < ((uint64_t)E * (uint64_t)N))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)F * (uint64_t)M);
  if (TU < ((uint64_t)F * (uint64_t)M))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)G * (uint64_t)L);
  if (TU < ((uint64_t)G * (uint64_t)L))
  {
    ST += (uint64_t)4294967296;
  }
  TU += ((uint64_t)H * (uint64_t)K);
  if (TU < ((uint64_t)H * (uint64_t)K))
  {
    ST += (uint64_t)4294967296;
  }

  ST += ((uint64_t)B * (uint64_t)P);
  if (ST < ((uint64_t)B * (uint64_t)P))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)C * (uint64_t)O);
  if (ST < ((uint64_t)C * (uint64_t)O))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)D * (uint64_t)N);
  if (ST < ((uint64_t)D * (uint64_t)N))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)E * (uint64_t)M);
  if (ST < ((uint64_t)E * (uint64_t)M))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)F * (uint64_t)L);
  if (ST < ((uint64_t)F * (uint64_t)L))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)G * (uint64_t)K);
  if (ST < ((uint64_t)G * (uint64_t)K))
  {
    RS += (uint64_t)4294967296;
  }
  ST += ((uint64_t)H * (uint64_t)J);
  if (ST < ((uint64_t)H * (uint64_t)J))
  {
    RS += (uint64_t)4294967296;
  }

  RS += ((uint64_t)A * (uint64_t)P) +
        ((uint64_t)B * (uint64_t)O) +
        ((uint64_t)C * (uint64_t)N) +
        ((uint64_t)D * (uint64_t)M) +
        ((uint64_t)E * (uint64_t)L) +
        ((uint64_t)F * (uint64_t)K) +
        ((uint64_t)G * (uint64_t)J) +
        ((uint64_t)H * (uint64_t)I);

  //this->elm[0] = ((XY & 0x00000000FFFFFFFF) << 32) + YZ;
  //this->elm[1] = ((VW & 0x00000000FFFFFFFF) << 32) + WX + ((XY & 0xFFFFFFFF00000000) >> 32);
  //this->elm[2] = ((TU & 0x00000000FFFFFFFF) << 32) + UV + ((VW & 0xFFFFFFFF00000000) >> 32);
  //this->elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);
  // consider overflow except this->elm[3], ex: this->elm[0] = 0xFFFFFFFA00000000 + 0x9FFFFFFF6 (overflow)
  this->elm[0] = ((XY & 0x00000000FFFFFFFF) << 32);
  this->elm[1] = ((VW & 0x00000000FFFFFFFF) << 32);
  this->elm[2] = ((TU & 0x00000000FFFFFFFF) << 32);
  this->elm[3] = ((RS & 0x00000000FFFFFFFF) << 32) + ST + ((TU & 0xFFFFFFFF00000000) >> 32);

  if ((this->elm[0] + YZ) < YZ)
  {
    this->elm[0] += YZ;
    this->elm[1] += 1;
  }
  else
  {
    this->elm[0] += YZ;
  }

  if ((this->elm[1] + WX) < WX)
  {
    this->elm[1] += WX;
    this->elm[2] += 1;
  }
  else
  {
    this->elm[1] += WX;
  }
  if ((this->elm[1] + ((XY & 0xFFFFFFFF00000000) >> 32)) < ((XY & 0xFFFFFFFF00000000) >> 32))
  {
    this->elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
    this->elm[2] += 1;
  }
  else
  {
    this->elm[1] += ((XY & 0xFFFFFFFF00000000) >> 32);
  }

  if ((this->elm[2] + UV) < UV)
  {
    this->elm[2] += UV;
    this->elm[3] += 1;
  }
  else
  {
    this->elm[2] += UV;
  }
  if ((this->elm[2] + ((VW & 0xFFFFFFFF00000000) >> 32)) < ((VW & 0xFFFFFFFF00000000) >> 32))
  {
    this->elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
    this->elm[3] += 1;
  }
  else
  {
    this->elm[2] += ((VW & 0xFFFFFFFF00000000) >> 32);
  }

  if (negative_sign)
  {
    this->elm[3] = ~this->elm[3];
    this->elm[2] = ~this->elm[2];
    this->elm[1] = ~this->elm[1];
    this->elm[0] = ~this->elm[0];
    if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[3] += 1;
      this->elm[2] = 0;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      this->elm[2] += 1;
      this->elm[1] = 0;
      this->elm[0] = 0;
    }
    else if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
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

// / division and % modulo
void BigInt::div_mod(BigInt dividend, BigInt divisor, BigInt& remainder)
{
  // S = sign, N = pure number
  // S1N1 / S2N2 = S3N3 ... S4N4
  // if (N1 >= N2)
  //    S3:
  //      if (S1 = '+' && S2 = '+') S3 = '+'
  //      if (S1 = '-' && S2 = '-') S3 = '+'
  //      if (S1 = '+' && S2 = '-') S3 = '-'
  //      if (S1 = '-' && S2 = '+') S3 = '-'
  //    N3 = N2 / N1
  //    S4:
  //      if (S1 = '+') S4 = '+'
  //      if (S1 = '-') S4 = '-'
  //    N4 = N2 % N1
  // if (N1 < N2)
  //    S3 = '+'
  //    N3 = 0
  //    S4 = S1
  //    N4 = N1
  // -5 / -2 =  2 ... -1
  //  5 / -2 = -2 ...  1
  // -5 /  2 = -2 ... -1
  // -2 / -5 =  0 ... -2
  //  2 / -5 =  0 ...  2
  // -2 /  5 =  0 ... -2
  // -2 / -2 =  1 ...  0
  //  2 / -2 = -1 ...  0
  // -2 /  2 = -1 ...  0
  if ((divisor.elm[3] == 0) &&
      (divisor.elm[2] == 0) &&
      (divisor.elm[1] == 0) &&
      (divisor.elm[0] == 0))
  {
    std::cerr << "BigInt::div_mod() error [divisor is 0]" << std::endl;
    abort();
  }

  if (dividend == divisor)
  {
    // X / X = 1 ... 0
    this->elm[3] = 0x0;
    this->elm[2] = 0x0;
    this->elm[1] = 0x0;
    this->elm[0] = 0x1;
    memset(static_cast<void*>(&remainder), 0, BIGINT_SIZE);
    return;
  }

  if (divisor == bigint_256_min)
  {
    // Except "elm[3] = 0x8000000000000000,
    //         elm[2] = 0x0000000000000000,
    //         elm[1] = 0x0000000000000000,
    //         elm[0] = 0x0000000000000000
    //         (-57896044618658097711785492504343953926634992332820282019728792003956564819968)",
    // any number of int256_t divided by
    // -57896044618658097711785492504343953926634992332820282019728792003956564819968
    // equals 0 with remainder itself.
    // X / bigint_256_min = 0 ... X
    memset(&this->elm[0], 0, BIGINT_SIZE);
    memcpy(static_cast<void*>(&remainder), &dividend, BIGINT_SIZE);
    return;
  }

  if (dividend == bigint_256_min)
  {
    memset(&this->elm[0], 0, BIGINT_SIZE);

    bool negative_sign_of_divisor = false;
    // If divisor is negative number:
    //  1. negative_sign_of_divisor = true.
    //  2. convert it to 2's complement.
    if (divisor.elm[3] & (uint64_t)0x8000000000000000)
    {
      negative_sign_of_divisor = true;
      divisor.elm[3] = ~divisor.elm[3];
      divisor.elm[2] = ~divisor.elm[2];
      divisor.elm[1] = ~divisor.elm[1];
      divisor.elm[0] = ~divisor.elm[0];
      if ((divisor.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
          (divisor.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
          (divisor.elm[2] == 0xFFFFFFFFFFFFFFFF))
      {
        divisor.elm[3] += 1;
        divisor.elm[2] = 0;
        divisor.elm[1] = 0;
        divisor.elm[0] = 0;
      }
      else if ((divisor.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
                (divisor.elm[1] == 0xFFFFFFFFFFFFFFFF))
      {
        divisor.elm[2] += 1;
        divisor.elm[1] = 0;
        divisor.elm[0] = 0;
      }
      else if (divisor.elm[0] == 0xFFFFFFFFFFFFFFFF)
      {
        divisor.elm[1] += 1;
        divisor.elm[0] = 0;
      }
      else
      {
        divisor.elm[0] += 1;
      }
    }

    dividend.elm[3] = 0x7FFFFFFFFFFFFFFF;
    dividend.elm[2] = 0xFFFFFFFFFFFFFFFF;
    dividend.elm[1] = 0xFFFFFFFFFFFFFFFF;
    dividend.elm[0] = 0xFFFFFFFFFFFFFFFF;
    size_t shl_offset = 0;
    BigInt divisor_temp(divisor << (int32_t)shl_offset);
    while ((dividend > divisor_temp) && (divisor_temp > 0))
    {
      ++shl_offset;
      divisor_temp = divisor << (int32_t)shl_offset;
    }
    if (divisor_temp < 0)
    {
      --shl_offset;
      divisor_temp = divisor << (int32_t)shl_offset;
    }
    if (dividend < divisor_temp)
    {
      --shl_offset;
      divisor_temp = divisor << (int32_t)shl_offset;
    }

    do
    {
      if (dividend >= divisor_temp)
      {
        dividend -= divisor_temp;
        (*this) += (bigint_1 << (int32_t)shl_offset);
      }
      if (shl_offset > 0)
      {
        --shl_offset;
      }
      divisor_temp = (divisor << (int32_t)shl_offset);
    } while ((dividend > 0) && (dividend >= divisor));

    ++dividend;
    if (dividend == divisor)
    {
      ++(*this);
      memset(static_cast<void*>(&remainder), 0, BIGINT_SIZE);
    }
    else
    {
      memcpy(static_cast<void*>(&remainder), &dividend, BIGINT_SIZE);
    }

    if (negative_sign_of_divisor == false)
    {
      this->elm[3] = ~this->elm[3];
      this->elm[2] = ~this->elm[2];
      this->elm[1] = ~this->elm[1];
      this->elm[0] = ~this->elm[0];
      if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
          (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
          (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
      {
        this->elm[3] += 1;
        this->elm[2] = 0;
        this->elm[1] = 0;
        this->elm[0] = 0;
      }
      else if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
                (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
      {
        this->elm[2] += 1;
        this->elm[1] = 0;
        this->elm[0] = 0;
      }
      else if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
      {
        this->elm[1] += 1;
        this->elm[0] = 0;
      }
      else
      {
        this->elm[0] += 1;
      }
    }

    remainder.elm[3] = ~remainder.elm[3];
    remainder.elm[2] = ~remainder.elm[2];
    remainder.elm[1] = ~remainder.elm[1];
    remainder.elm[0] = ~remainder.elm[0];
    if ((remainder.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (remainder.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (remainder.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      remainder.elm[3] += 1;
      remainder.elm[2] = 0;
      remainder.elm[1] = 0;
      remainder.elm[0] = 0;
    }
    else if ((remainder.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (remainder.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      remainder.elm[2] += 1;
      remainder.elm[1] = 0;
      remainder.elm[0] = 0;
    }
    else if (remainder.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      remainder.elm[1] += 1;
      remainder.elm[0] = 0;
    }
    else
    {
      remainder.elm[0] += 1;
    }

    return;
  }

  bool negative_sign_of_dividend = false;
  // If dividend is negative number:
  //  1. negative_sign_of_dividend = true.
  //  2. convert it to 2's complement.
  if (dividend.elm[3] & (uint64_t)0x8000000000000000)
  {
    negative_sign_of_dividend = true;
    dividend.elm[3] = ~dividend.elm[3];
    dividend.elm[2] = ~dividend.elm[2];
    dividend.elm[1] = ~dividend.elm[1];
    dividend.elm[0] = ~dividend.elm[0];
    if ((dividend.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (dividend.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (dividend.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      dividend.elm[3] += 1;
      dividend.elm[2] = 0;
      dividend.elm[1] = 0;
      dividend.elm[0] = 0;
    }
    else if ((dividend.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (dividend.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      dividend.elm[2] += 1;
      dividend.elm[1] = 0;
      dividend.elm[0] = 0;
    }
    else if (dividend.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      dividend.elm[1] += 1;
      dividend.elm[0] = 0;
    }
    else
    {
      dividend.elm[0] += 1;
    }
  }

  bool negative_sign_of_divisor = false;
  // If divisor is negative number:
  //  1. negative_sign_of_divisor = true.
  //  2. convert it to 2's complement.
  if (divisor.elm[3] & (uint64_t)0x8000000000000000)
  {
    negative_sign_of_divisor = true;
    divisor.elm[3] = ~divisor.elm[3];
    divisor.elm[2] = ~divisor.elm[2];
    divisor.elm[1] = ~divisor.elm[1];
    divisor.elm[0] = ~divisor.elm[0];
    if ((divisor.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
        (divisor.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
        (divisor.elm[2] == 0xFFFFFFFFFFFFFFFF))
    {
      divisor.elm[3] += 1;
      divisor.elm[2] = 0;
      divisor.elm[1] = 0;
      divisor.elm[0] = 0;
    }
    else if ((divisor.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
              (divisor.elm[1] == 0xFFFFFFFFFFFFFFFF))
    {
      divisor.elm[2] += 1;
      divisor.elm[1] = 0;
      divisor.elm[0] = 0;
    }
    else if (divisor.elm[0] == 0xFFFFFFFFFFFFFFFF)
    {
      divisor.elm[1] += 1;
      divisor.elm[0] = 0;
    }
    else
    {
      divisor.elm[0] += 1;
    }
  }

  memset(&this->elm[0], 0, BIGINT_SIZE);

  if (dividend >= divisor)
  {
    size_t shl_offset = 0;
    //BigInt divisor_temp(divisor << shl_offset);
    BigInt divisor_temp(divisor);
    while ((dividend > divisor_temp) && (divisor_temp > 0))
    {
      ++shl_offset;
      divisor_temp = divisor << (int32_t)shl_offset;
    }
    if (divisor_temp < 0)
    {
      --shl_offset;
      divisor_temp = divisor << (int32_t)shl_offset;
    }
    if (dividend < divisor_temp)
    {
      --shl_offset;
      divisor_temp = divisor << (int32_t)shl_offset;
    }

    do
    {
      if (dividend >= divisor_temp)
      {
        dividend -= divisor_temp;
        (*this) += (bigint_1 << (int32_t)shl_offset);
      }
      if (shl_offset > 0)
      {
        --shl_offset;
      }
      divisor_temp = (divisor << (int32_t)shl_offset);
    } while ((dividend > 0) && (dividend >= divisor));
    memcpy(static_cast<void*>(&remainder), &dividend, BIGINT_SIZE);

    if (((negative_sign_of_dividend == false) && (negative_sign_of_divisor == true)) ||
        ((negative_sign_of_dividend == true) && (negative_sign_of_divisor == false)))
    {
      this->elm[3] = ~this->elm[3];
      this->elm[2] = ~this->elm[2];
      this->elm[1] = ~this->elm[1];
      this->elm[0] = ~this->elm[0];
      if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
          (this->elm[1] == 0xFFFFFFFFFFFFFFFF) &&
          (this->elm[2] == 0xFFFFFFFFFFFFFFFF))
      {
        this->elm[3] += 1;
        this->elm[2] = 0;
        this->elm[1] = 0;
        this->elm[0] = 0;
      }
      else if ((this->elm[0] == 0xFFFFFFFFFFFFFFFF) &&
                (this->elm[1] == 0xFFFFFFFFFFFFFFFF))
      {
        this->elm[2] += 1;
        this->elm[1] = 0;
        this->elm[0] = 0;
      }
      else if (this->elm[0] == 0xFFFFFFFFFFFFFFFF)
      {
        this->elm[1] += 1;
        this->elm[0] = 0;
      }
      else
      {
        this->elm[0] += 1;
      }
    }
    if (negative_sign_of_dividend == true)
    {
      remainder.elm[3] = ~remainder.elm[3];
      remainder.elm[2] = ~remainder.elm[2];
      remainder.elm[1] = ~remainder.elm[1];
      remainder.elm[0] = ~remainder.elm[0];
      if ((remainder.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
          (remainder.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
          (remainder.elm[2] == 0xFFFFFFFFFFFFFFFF))
      {
        remainder.elm[3] += 1;
        remainder.elm[2] = 0;
        remainder.elm[1] = 0;
        remainder.elm[0] = 0;
      }
      else if ((remainder.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
                (remainder.elm[1] == 0xFFFFFFFFFFFFFFFF))
      {
        remainder.elm[2] += 1;
        remainder.elm[1] = 0;
        remainder.elm[0] = 0;
      }
      else if (remainder.elm[0] == 0xFFFFFFFFFFFFFFFF)
      {
        remainder.elm[1] += 1;
        remainder.elm[0] = 0;
      }
      else
      {
        remainder.elm[0] += 1;
      }
    }
  }
  else
  {
    memcpy(static_cast<void*>(&remainder), &dividend, BIGINT_SIZE);

    if (negative_sign_of_dividend == true)
    {
      remainder.elm[3] = ~remainder.elm[3];
      remainder.elm[2] = ~remainder.elm[2];
      remainder.elm[1] = ~remainder.elm[1];
      remainder.elm[0] = ~remainder.elm[0];
      if ((remainder.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
          (remainder.elm[1] == 0xFFFFFFFFFFFFFFFF) &&
          (remainder.elm[2] == 0xFFFFFFFFFFFFFFFF))
      {
        remainder.elm[3] += 1;
        remainder.elm[2] = 0;
        remainder.elm[1] = 0;
        remainder.elm[0] = 0;
      }
      else if ((remainder.elm[0] == 0xFFFFFFFFFFFFFFFF) &&
                (remainder.elm[1] == 0xFFFFFFFFFFFFFFFF))
      {
        remainder.elm[2] += 1;
        remainder.elm[1] = 0;
        remainder.elm[0] = 0;
      }
      else if (remainder.elm[0] == 0xFFFFFFFFFFFFFFFF)
      {
        remainder.elm[1] += 1;
        remainder.elm[0] = 0;
      }
      else
      {
        remainder.elm[0] += 1;
      }
    }
  }

  return;
}

// 1 bit left shift(*=2)
void BigInt::shl(void)
{
  if (this->elm[2] & (uint64_t)0x8000000000000000)
  {
    this->elm[3] <<= 1;
    this->elm[3] |= (uint64_t)0x0000000000000001;
  }
  else
  {
    this->elm[3] <<= 1;
  }

  if (this->elm[1] & (uint64_t)0x8000000000000000)
  {
    this->elm[2] <<= 1;
    this->elm[2] |= (uint64_t)0x0000000000000001;
  }
  else
  {
    this->elm[2] <<= 1;
  }

  if (this->elm[0] & (uint64_t)0x8000000000000000)
  {
    this->elm[1] <<= 1;
    this->elm[1] |= (uint64_t)0x0000000000000001;
  }
  else
  {
    this->elm[1] <<= 1;
  }

  this->elm[0] <<= 1;

  return;
}

// 1 bit right shift(/=2)
void BigInt::shr(void)
{
  if (this->elm[1] & (uint64_t)0x0000000000000001)
  {
    this->elm[0] >>= 1;
    this->elm[0] |= (uint64_t)0x8000000000000000;
  }
  else
  {
    this->elm[0] >>= 1;
  }

  if (this->elm[2] & (uint64_t)0x0000000000000001)
  {
    this->elm[1] >>= 1;
    this->elm[1] |= (uint64_t)0x8000000000000000;
  }
  else
  {
    this->elm[1] >>= 1;
  }

  if (this->elm[3] & (uint64_t)0x0000000000000001)
  {
    this->elm[2] >>= 1;
    this->elm[2] |= (uint64_t)0x8000000000000000;
  }
  else
  {
    this->elm[2] >>= 1;
  }

  if (this->elm[3] > 0x7FFFFFFFFFFFFFFF)
  {
    this->elm[3] >>= 1;
    this->elm[3] |= 0x8000000000000000;
  }
  else
  {
    this->elm[3] >>= 1;
  }

  return;
}

// == equal to
bool BigInt::compare_equalto(const BigInt& a, const BigInt& b) const
{
  if ((a.elm[3] == b.elm[3]) && (a.elm[2] == b.elm[2]) && (a.elm[1] == b.elm[1]) && (a.elm[0] == b.elm[0]))
  {
    return true;
  }

  return false;
}

// < lessthan
bool BigInt::compare_lessthan(const BigInt& a, const BigInt& b) const
{
  if (a.elm[3] & 0x8000000000000000)
  {
    if (!(b.elm[3] & 0x8000000000000000))
    {
      return true;
    }
  }
  else
  {
    if (b.elm[3] & 0x8000000000000000)
    {
      return false;
    }
  }

  if (a.elm[3] < b.elm[3])
  {
    return true;
  }
  else if ((a.elm[3] == b.elm[3]) &&
            (a.elm[2] < b.elm[2]))
  {
    return true;
  }
  else if ((a.elm[3] == b.elm[3]) &&
            (a.elm[2] == b.elm[2]) &&
            (a.elm[1] < b.elm[1]))
  {
    return true;
  }
  else if ((a.elm[3] == b.elm[3]) &&
            (a.elm[2] == b.elm[2]) &&
            (a.elm[1] == b.elm[1]) &&
            (a.elm[0] < b.elm[0]))
  {
    return true;
  }

  return false;
}

// debug mode for printing out debug information
void BigInt::debug()
{
  for (ssize_t i = ELEMENT_NUMBER - 1; i >= 0; --i)
  {
    printf("%016llX ", (unsigned long long int)this->elm[i]);
  }
  printf("\n");

  std::string str = "";
  for (size_t i = 0; i < 64; ++i)
  {
    if ((this->elm[3] << i) & (uint64_t)0x8000000000000000)
    {
      str += '1';
    }
    else
    {
      str += '0';
    }
  }

  str += " ";

  for (size_t i = 0; i < 64; ++i)
  {
    if ((this->elm[2] << i) & (uint64_t)0x8000000000000000)
    {
      str += '1';
    }
    else
    {
      str += '0';
    }
  }

  str += " ";

  for (size_t i = 0; i < 64; ++i)
  {
    if ((this->elm[1] << i) & (uint64_t)0x8000000000000000)
    {
      str += '1';
    }
    else
    {
      str += '0';
    }
  }

  str += " ";

  for (size_t i = 0; i < 64; ++i)
  {
    if ((this->elm[0] << i) & (uint64_t)0x8000000000000000)
    {
      str += '1';
    }
    else
    {
      str += '0';
    }
  }

  printf("[%s]\n", str.c_str());

  return;
}

// debug mode for printing out debug information
void BigInt::debug(std::string str)
{
  printf("%s: ", str.c_str());
  for (ssize_t i = ELEMENT_NUMBER - 1; i >= 0; --i)
  {
    printf("%016llX ", (unsigned long long int)this->elm[i]);
  }
  printf("\n");

  std::string str2 = "";
  for (size_t i = 0; i < 64; ++i)
  {
    if ((this->elm[3] << i) & (uint64_t)0x8000000000000000)
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
    if ((this->elm[2] << i) & (uint64_t)0x8000000000000000)
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

// debug mode for checking the value of current bigint
bool BigInt::debug(uint64_t* elms)
{
  bool result = true;
  result &= (bool)(elm[0] == *(elms));
  result &= (bool)(elm[1] == *(elms+1));
  result &= (bool)(elm[2] == *(elms+2));
  result &= (bool)(elm[3] == *(elms+3));
  return result;
}

// istream operator >> overloading for BigInt
std::istream& operator >>(std::istream& istrm, BigInt& bigint)
{
  std::string str("");
  istrm >> str;
  bigint.from_string(str);

  return istrm;
}

// ostream operator << overloading for BigInt
std::ostream& operator <<(std::ostream& ostrm, BigInt bigint)
{
  std::string str("");
  str = bigint.to_string();
  ostrm << str;

  return ostrm;
}

// bitwise right shift assignment operator >>= overloading for BigInt
void BigInt::operator >>=(const int32_t offset)
{
  bool negative_sign = false;
  if (this->elm[3] & 0x8000000000000000)
  {
    negative_sign = true;
  }

  if ((offset > 0) && (offset < 64))
  {
    this->elm[0] = (this->elm[0] >> offset);
    this->elm[0] |= (this->elm[1] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    this->elm[1] = (this->elm[1] >> offset);
    this->elm[1] |= (this->elm[2] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    this->elm[2] = (this->elm[2] >> offset);
    this->elm[2] |= (this->elm[3] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    this->elm[3] = (this->elm[3] >> offset);
    if (negative_sign == true)
    {
      this->elm[3] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - offset);
    }
  }
  else if ((offset > 64) && (offset < 128))
  {
    int32_t adjusted_offset = offset % 64;
    this->elm[0] = (this->elm[1] >> adjusted_offset);
    this->elm[0] |= (this->elm[2] << (128 - offset));
    this->elm[1] = (this->elm[2] >> adjusted_offset);
    this->elm[1] |= (this->elm[3] << (128 - offset));
    this->elm[2] = (this->elm[3] >> adjusted_offset);
    this->elm[3] = 0;

    if (negative_sign == true)
    {
      this->elm[2] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[3] = 0;
    }
  }
  else if ((offset > 128) && (offset < 192))
  {
    int32_t adjusted_offset = offset % 64;
    this->elm[0] = (this->elm[2] >> adjusted_offset);
    this->elm[0] |= (this->elm[3] << (192 - offset));
    this->elm[1] = (this->elm[3] >> adjusted_offset);
    this->elm[2] = 0;
    this->elm[3] = 0;

    if (negative_sign == true)
    {
      this->elm[1] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      this->elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[2] = 0;
      this->elm[3] = 0;
    }
  }
  else if ((offset > 192) && (offset < 256))
  {
    int32_t adjusted_offset = offset % 64;
    this->elm[0] = (this->elm[3] >> adjusted_offset);
    this->elm[1] = 0;
    this->elm[2] = 0;
    this->elm[3] = 0;

    if (negative_sign == true)
    {
      this->elm[0] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      this->elm[1] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[1] = 0;
      this->elm[2] = 0;
      this->elm[3] = 0;
    }
  }
  else if (offset == 64)
  {
    this->elm[0] = this->elm[1];
    this->elm[1] = this->elm[2];
    this->elm[2] = this->elm[3];
    if (negative_sign == true)
    {
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[3] = 0;
    }
  }
  else if (offset == 128)
  {
    this->elm[0] = this->elm[2];
    this->elm[1] = this->elm[3];
    if (negative_sign == true)
    {
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[3] = 0;
      this->elm[2] = 0;
    }
  }
  else if (offset == 192)
  {
    this->elm[0] = this->elm[3];
    if (negative_sign == true)
    {
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[1] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[3] = 0;
      this->elm[2] = 0;
      this->elm[1] = 0;
    }
  }
  //else if (offset == 0)
  //{
  //  return;
  //}
  else if (offset > 255)
  {
    if (negative_sign == true)
    {
      memset(&this->elm[0], -1, BIGINT_SIZE);
    }
    else
    {
      memset(&this->elm[0], 0, BIGINT_SIZE);
    }
  }
  else if (offset < 0)
  {
    memset(&this->elm[0], 0, BIGINT_SIZE);
  }

  return;
}

// bitwise right shift assignment operator >>=(BigInt type offset) overloading for BigInt
void BigInt::operator >>=(const BigInt& offset_bigint)
{
  bool negative_sign = false;
  if (this->elm[3] & 0x8000000000000000)
  {
    negative_sign = true;
  }

  if ((offset_bigint.elm[3] > 0) ||
      (offset_bigint.elm[2] > 0) ||
      (offset_bigint.elm[1] > 0) ||
      (offset_bigint.elm[0] > 255))
  {
    if (offset_bigint.elm[3] & 0x8000000000000000)
    {
      memset(&this->elm[0], 0, BIGINT_SIZE);
    }
    else
    {
      if (negative_sign == true)
      {
        memset(&this->elm[0], -1, BIGINT_SIZE);
      }
      else
      {
        memset(&this->elm[0], 0, BIGINT_SIZE);
      }
    }
    return;
  }

  int32_t offset = (int32_t)offset_bigint.elm[0];

  if ((offset > 0) && (offset < 64))
  {
    this->elm[0] = (this->elm[0] >> offset);
    this->elm[0] |= (this->elm[1] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    this->elm[1] = (this->elm[1] >> offset);
    this->elm[1] |= (this->elm[2] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    this->elm[2] = (this->elm[2] >> offset);
    this->elm[2] |= (this->elm[3] & ((uint64_t)0xFFFFFFFFFFFFFFFF >> (64 - offset))) << (64 - offset);
    this->elm[3] = (this->elm[3] >> offset);
    if (negative_sign == true)
    {
      this->elm[3] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - offset);
    }
  }
  else if ((offset > 64) && (offset < 128))
  {
    int32_t adjusted_offset = offset % 64;
    this->elm[0] = (this->elm[1] >> adjusted_offset);
    this->elm[0] |= (this->elm[2] << (128 - offset));
    this->elm[1] = (this->elm[2] >> adjusted_offset);
    this->elm[1] |= (this->elm[3] << (128 - offset));
    this->elm[2] = (this->elm[3] >> adjusted_offset);
    this->elm[3] = 0;

    if (negative_sign == true)
    {
      this->elm[2] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[3] = 0;
    }
  }
  else if ((offset > 128) && (offset < 192))
  {
    int32_t adjusted_offset = offset % 64;
    this->elm[0] = (this->elm[2] >> adjusted_offset);
    this->elm[0] |= (this->elm[3] << (192 - offset));
    this->elm[1] = (this->elm[3] >> adjusted_offset);
    this->elm[2] = 0;
    this->elm[3] = 0;

    if (negative_sign == true)
    {
      this->elm[1] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      this->elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[2] = 0;
      this->elm[3] = 0;
    }
  }
  else if ((offset > 192) && (offset < 256))
  {
    int32_t adjusted_offset = offset % 64;
    this->elm[0] = (this->elm[3] >> adjusted_offset);
    this->elm[1] = 0;
    this->elm[2] = 0;
    this->elm[3] = 0;

    if (negative_sign == true)
    {
      this->elm[0] |= (uint64_t)0xFFFFFFFFFFFFFFFF << (64 - adjusted_offset);
      this->elm[1] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[1] = 0;
      this->elm[2] = 0;
      this->elm[3] = 0;
    }
  }
  else if (offset == 64)
  {
    this->elm[0] = this->elm[1];
    this->elm[1] = this->elm[2];
    this->elm[2] = this->elm[3];
    if (negative_sign == true)
    {
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[3] = 0;
    }
  }
  else if (offset == 128)
  {
    this->elm[0] = this->elm[2];
    this->elm[1] = this->elm[3];
    if (negative_sign == true)
    {
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[3] = 0;
      this->elm[2] = 0;
    }
  }
  else if (offset == 192)
  {
    this->elm[0] = this->elm[3];
    if (negative_sign == true)
    {
      this->elm[3] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[2] = (uint64_t)0xFFFFFFFFFFFFFFFF;
      this->elm[1] = (uint64_t)0xFFFFFFFFFFFFFFFF;
    }
    else
    {
      this->elm[3] = 0;
      this->elm[2] = 0;
      this->elm[1] = 0;
    }
  }
  //else if (offset == 0)
  //{
  //  return;
  //}
  else if (offset > 255)
  {
    if (negative_sign == true)
    {
      memset(&this->elm[0], -1, BIGINT_SIZE);
    }
    else
    {
      memset(&this->elm[0], 0, BIGINT_SIZE);
    }
  }
  else if (offset < 0)
  {
    memset(&this->elm[0], 0, BIGINT_SIZE);
  }

  return;
}

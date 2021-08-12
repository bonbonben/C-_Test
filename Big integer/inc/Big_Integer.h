#include <iostream>
#include <string>

#define BIGINT_SIZE 32
#define ELEMENT_NUMBER 4

#define BigInt int256_t

class BigInt
{
  public:
    // constructor
    BigInt(void);
    // constructor: initialized by BigInt
    BigInt(const BigInt& bigint);
    // constructor: initialized by int32_t
    BigInt(int32_t int32);
    // constructor: initialized by int64_t
    BigInt(int64_t int64);
    // constructor: initialized by uint64_t
    BigInt(uint64_t uint64);
    // constructor: initialized by std::string
    BigInt(const std::string& str_int);

    // destructor
    ~BigInt(void);

    // clear BigInt object(set the value to 0)
    void clear(void);

    // Arithmetic operators
    // basic assignment operator = overloading for BigInt
    void operator =(const BigInt& bigint);
    // unary plus(positive sign) operator + overloading for BigInt
    BigInt operator +(void) const;
    // unary minus(negative sign) operator - overloading for BigInt
    BigInt operator -(void) const;
    // addition operator + overloading for BigInt
    BigInt operator +(const BigInt& addend) const;
    // subtraction operator - overloading for BigInt
    BigInt operator -(const BigInt& subtrahend) const;
    // multiplication operator * overloading for BigInt
    BigInt operator *(const BigInt& multiplier) const;
    // division operator / overloading for BigInt
    BigInt operator /(const BigInt& divisor) const;
    // modulo operator % overloading for BigInt
    BigInt operator %(const BigInt& divisor) const;
    // increment(prefix) ++ overloading for BigInt
    BigInt& operator ++();
    // increment(postfix) ++ overloading for BigInt
    const BigInt operator ++(int);
    // decrement(prefix) -- overloading for BigInt
    BigInt& operator --();
    // decrement(postfix) -- overloading for BigInt
    const BigInt operator --(int);

    // Comparison operators/relational operators
    // equal to operator == overloading for BigInt
    bool operator ==(const BigInt& bigint) const;
    // not equal to operator != overloading for BigInt
    bool operator !=(const BigInt& bigint) const;
    // greater than operator > overloading for BigInt
    bool operator >(const BigInt& bigint) const;
    // less than operator < overloading for BigInt
    bool operator <(const BigInt& bigint) const;
    // greater than or equal to operator >= overloading for BigInt
    bool operator >=(const BigInt& bigint) const;
    // less than or equal to operator <= overloading for BigInt
    bool operator <=(const BigInt& bigint) const;

    // Logical operators
    // logical negation(NOT) for BigInt
    bool operator !() const;
    // logical AND for BigInt
    bool operator &&(const BigInt& bigint) const;
    // logical OR for BigInt
    bool operator ||(const BigInt& bigint) const;

    // Bitwise operators
    // bitwise NOT for BigInt
    BigInt operator ~() const;
    // bitwise AND for BigInt
    BigInt operator &(const BigInt& bigint) const;
    // bitwise OR for BigInt
    BigInt operator |(const BigInt& bigint) const;
    // bitwise XOR for BigInt
    BigInt operator ^(const BigInt& bigint) const;
    // bitwise left shift for BigInt
    BigInt operator <<(const int32_t offset) const;
    // bitwise left shift(BigInt type offset) for BigInt
    BigInt operator <<(const BigInt& offset_bigint) const;
    // bitwise right shift for BigInt
    BigInt operator >>(const int32_t offset) const;
    // bitwise right shift(BigInt type offset) for BigInt
    BigInt operator >>(const BigInt& offset_bigint) const;

    // Compound assignment operators
    // addition assignment operator += overloading for BigInt
    void operator +=(const BigInt& addend);
    // subtraction assignment operator -= overloading for BigInt
    void operator -=(const BigInt& subtrahend);
    // multiplication assignment operator *= overloading for BigInt
    void operator *=(const BigInt& multiplier);
    // division assignment operator /= overloading for BigInt
    void operator /=(const BigInt& divisor);
    // modulo assignment operator %= overloading for BigInt
    void operator %=(const BigInt& divisor);
    // bitwise AND assignment operator &= overloading for BigInt
    void operator &=(const BigInt& bigint);
    // bitwise OR assignment operator |= overloading for BigInt
    void operator |=(const BigInt& bigint);
    // bitwise XOR assignment operator ^= overloading for BigInt
    void operator ^=(const BigInt& bigint);
    // bitwise left shift assignment operator <<= overloading for BigInt
    void operator <<=(const int32_t offset);
    // bitwise left shift assignment operator <<=(BigInt type offset) overloading for BigInt
    void operator <<=(const BigInt& offset_bigint);
    // bitwise right shift assignment operator <<= overloading for BigInt
    void operator >>=(const int32_t offset);
    // bitwise right shift assignment operator <<=(BigInt type offset) overloading for BigInt
    void operator >>=(const BigInt& offset_bigint);

    // int32_t to BigInt
    void from_int32_t(int32_t int32);
    // int64_t to BigInt
    void from_int64_t(int64_t int64);
    // uint64_t to BigInt
    void from_uint64_t(uint64_t uint64);
    // std::string to BigInt
    void from_string(const std::string& str_int);

    // BigInt to std::string
    std::string to_string(void) const;

    // return sign, < 0(-1), == 0(0), > 0(1)
    int64_t sign(void) const;

    // + addition
    void add(const BigInt& augend, const BigInt& addend);
    // - subtraction
    void sub(const BigInt& minuend, BigInt subtrahend);
    // * multiplication
    void mul(BigInt multiplicand, BigInt multiplier);
    // / division and % modulo
    void div_mod(BigInt dividend, BigInt divisor, BigInt& remainder);

    // 1 bit left shift(*=2)
    void shl(void);
    // 1 bit right shift(/=2)
    void shr(void);

    // == equal to
    bool compare_equalto(const BigInt& a, const BigInt& b) const;
    // < lessthan
    bool compare_lessthan(const BigInt& a, const BigInt& b) const;

    // debug mode for printing out debug information
    void debug();
    // debug mode for printing out debug information
    void debug(std::string str);
    // debug mode for checking the value of current bigint
    bool debug(uint64_t* elms);

    // istream operator >> overloading for BigInt
    friend std::istream& operator >>(std::istream& istrm, BigInt& bigint);
    // ostream operator << overloading for BigInt
    friend std::ostream& operator <<(std::ostream& ostrm, BigInt bigint);

  protected:

  private:
    // basic element(s)(64 bits) for constructing BigInt
    uint64_t elm[ELEMENT_NUMBER];
};

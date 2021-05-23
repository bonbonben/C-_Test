#include <iostream>
#include <string>

#define BIGINT_SIZE 16
#define ELEMENT_NUMBER 2

class BigInt
{
  public:
    // constructor
    BigInt(void);

    // destructor
    ~BigInt(void);

    // std::string to BigInt
    void from_string(const std::string& str_int);

    // debug mode for printing out debug information
    void Debug1(std::string str);
  
    // bitwise XOR assignment operator ^= overloading for BigInt
    void operator ^=(const BigInt& bigint);

  protected:

  private:
    // basic element(s)(64 bits) for constructing BigInt
    uint64_t elm[ELEMENT_NUMBER];
};

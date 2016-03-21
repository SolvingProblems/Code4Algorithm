#ifndef __IOSTREAM_H
#include <iostream>
#endif

using namespace std;

/*
 * BigInteger has a array for saving big value.
 * Most Significant index of array is used for sign value.
 * 0 is positive, 1 is negative.
 */

#undef DEBUG

#define DEFAULT_NUM_LENGTH  64
#define BASE    10
#define CHARTONUM(type, x)  ((type)((x) - '0'))
#define NUMTOCHAR(x)  ((x) + '0')

class BigInteger {
public:
    BigInteger();
    BigInteger(long num);
    ~BigInteger();

    void showNumber();

    void addAndSave(const BigInteger Big1, const BigInteger Big2);
    void setNumber(long long number);
    BigInteger& operator=(const BigInteger& ref);
    void clearNumber();

protected:
    void setAllZero();
    void allocNumberRoom();

    int internalAdd(const char*, const int, const char,
                    const char*, const int, const char,
                    char*);

private:
    unsigned int numLength;
    char *bigNumber;
    int curMaxIndex;
};

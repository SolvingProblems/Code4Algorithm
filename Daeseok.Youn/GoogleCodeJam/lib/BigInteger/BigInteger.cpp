#include <iostream>

using namespace std;

/*
 * BigInteger has a array for saving big value.
 * Most Significant index of array is used for sign value.
 * 0 is positive, 1 is negative.
 */

#define DEFAULT_NUM_LENGTH  64
#define BASE    10

class BigInteger {
public:
    BigInteger(long num) {
        numLength = DEFAULT_NUM_LENGTH;
        bigNumber = NULL;

        setNumber(num);
    }

    BigInteger() {
        numLength = DEFAULT_NUM_LENGTH;
        bigNumber = NULL;
    }

    ~BigInteger() {
        if (bigNumber != NULL)
            delete [] bigNumber;
        bigNumber = NULL;
    }

    void showNumber() {
        for (int i = curMaxIndex - 1; i >=0; i--) {
            cout << bigNumber[i];
        }
        cout << endl;
    }

    void addAndSave(const BigInteger Big1, const BigInteger Big2)
    {
        setNumber(0);
        curMaxIndex = internalAdd(Big1.bigNumber, Big1.curMaxIndex,
                                  Big2.bigNumber, Big2.curMaxIndex,
                                  bigNumber);
    }

private:
    unsigned int numLength;
    char *bigNumber;
    int curMaxIndex;

protected:
    void setAllZero() {
        for (int i = 0; i < numLength; i++) {
            bigNumber[i] = 0 + '0';
        }
    }

    void setNumber(long number) {
        if (bigNumber == NULL)
            allocNumberRoom();

        clearNumber();

        do {
            bigNumber[curMaxIndex++] = (char)((number % BASE) + '0');
            number /= BASE;
        } while(number && curMaxIndex < numLength - 1);
    }


    void allocNumberRoom() {
        bigNumber = new char[numLength];

        setAllZero();
        curMaxIndex = 0;
    }

    void clearNumber() {
        if (curMaxIndex != 0) {
            setAllZero();
            curMaxIndex = 0;
        }
    }

    int internalAdd(const char* op1, const int op1CurMax,
                    const char* op2, const int op2CurMax,
                    char* result)
    {
        int calMax = op1CurMax > op2CurMax ? op1CurMax : op2CurMax;
        int carry = 0;
        int i = 0;

        for (i = 0; i < calMax; i++) {
            int temp = ((op1[i] - '0') + (op2[i] - '0')) + carry;

            carry = temp / 10;

            result[i] = (char)(temp + '0');
        }

        if (carry != 0) {
            result[i] = carry;
            calMax++;
        }

        return calMax;
    }
};

int main(void)
{
    BigInteger bi(123456);
    BigInteger bi1(23);
    BigInteger added;

    bi.showNumber();

    bi1.showNumber();

    cout << "ADD --------------" << endl;
    added.addAndSave(bi, bi1);
    added.showNumber();

    return 0;
}

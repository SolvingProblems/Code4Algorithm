#include <iostream>

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
        if (CHARTONUM(int, bigNumber[numLength - 1]) != 0)
            cout << "-";

        for (int i = curMaxIndex - 1; i >= 0; i--) {
            cout << bigNumber[i];
        }
        cout << endl;
    }

    void addAndSave(const BigInteger Big1, const BigInteger Big2)
    {
        setNumber(0);
        curMaxIndex = internalAdd(Big1.bigNumber, Big1.curMaxIndex, Big1.bigNumber[Big1.numLength - 1],
                                  Big2.bigNumber, Big2.curMaxIndex, Big2.bigNumber[Big2.numLength - 1],
                                  bigNumber);
    }

    void setNumber(long number) {
        int signMul = 1;

        if (bigNumber == NULL)
            allocNumberRoom();

        clearNumber();

        if (number < 0) {
            bigNumber[numLength - 1] = NUMTOCHAR(1);
            signMul = -1;
        }

        do {
            bigNumber[curMaxIndex++] = NUMTOCHAR((signMul * number) % BASE);
            number /= BASE;
        } while(number && curMaxIndex < numLength - 1);
    }

private:
    unsigned int numLength;
    char *bigNumber;
    int curMaxIndex;

protected:
    void setAllZero() {
        for (int i = 0; i < numLength; i++) {
            bigNumber[i] = NUMTOCHAR(0);
        }
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

    int internalAdd(const char* op1, const int op1CurMax, const char op1Sign,
                    const char* op2, const int op2CurMax, const char op2Sign,
                    char* result)
    {
        int calMax = op1CurMax > op2CurMax ? op1CurMax : op2CurMax;
        int carry = 0;
        int i = 0;
        //cout << "sign(op1) : " << op1Sign << " sign(op2) : " << op2Sign << endl;
        if (op1Sign == op2Sign) {
            for (i = 0; i < calMax; i++) {
                int op1Num = CHARTONUM(int, op1[i]);
                int op2Num = CHARTONUM(int, op2[i]);

                int temp = op1Num + op2Num + carry;

                carry = temp / BASE;

                result[i] = NUMTOCHAR(temp % 10);
            }

            if (carry != 0) {
                result[i]++;
                calMax++;
            }

            result[numLength - 1] = op1Sign;
        } else {
            // which is the bigger value without sign?
            const char *big = NULL, *small = NULL;
            char signValue = 0;

            for (i = calMax; i >= 0; i--) {
                if (op1[i] < op2[i]) {
                    big = op2;
                    small = op1;
                    signValue = op2Sign;
                } else {
                    big = op1;
                    small = op2;
                    signValue = op1Sign;
                }

                if (big != NULL)
                    break;
            }

            if (big == NULL) {
            }

            for (i = 0; i < calMax; i++) {
                int op1Num = CHARTONUM(int, big[i]);
                int op2Num = CHARTONUM(int, small[i]);

                int temp = op1Num - op2Num + carry;
                cout << "op1Num : " << op1Num << " op2Num : " << op2Num << " result : " << temp << endl;
                cout << "carry : " << carry << endl;
                if (temp < 0) {
                    temp = BASE + temp;
                    carry = -1;
                } else {
                    carry = 0;
                }

                result[i] = NUMTOCHAR(temp);
            }

            if (carry != 0) {
                result[i]--;
                if (CHARTONUM(int, result[i]) == 0)
                    calMax--;
            }

            result[numLength - 1] = signValue;

        }

        return calMax;
    }
};

#ifdef DEBUG
int main(void)
{
    BigInteger bi(123456);
    BigInteger bi1(82323);
    BigInteger added;

    bi.showNumber();

    bi1.showNumber();

    cout << "ADD --------------" << endl;
    added.addAndSave(bi, bi1);
    added.showNumber();

    bi.setNumber(-543);
    bi1.setNumber(-1837);

    cout << "ADD2 --------------" << endl;
    added.addAndSave(bi, bi1);
    added.showNumber();

    return 0;
}
#endif

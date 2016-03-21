#include "BigInteger.h"

BigInteger::BigInteger(long num) {
    numLength = DEFAULT_NUM_LENGTH;
    bigNumber = NULL;

    setNumber(num);
}

BigInteger::BigInteger() {
    numLength = DEFAULT_NUM_LENGTH;
    bigNumber = NULL;
}

BigInteger::~BigInteger() {
    if (bigNumber != NULL)
        delete [] bigNumber;
    bigNumber = NULL;
}

BigInteger& BigInteger::operator=(const BigInteger& ref)
{
    if (this == &ref)
        return *this;

    if (bigNumber)
        delete [] bigNumber;

    allocNumberRoom();
    curMaxIndex = ref.curMaxIndex;
    numLength = ref.numLength;

    for (int i = 0; i < curMaxIndex; i++)
        bigNumber[i] = ref.bigNumber[i];

    bigNumber[numLength - 1] = ref.bigNumber[numLength - 1];

    return *this;
}

void BigInteger::showNumber() {
    if (CHARTONUM(int, bigNumber[numLength - 1]) != 0)
        cout << "-";

    for (int i = curMaxIndex - 1; i >= 0; i--) {
        cout << bigNumber[i];
    }
}

void BigInteger::addAndSave(const BigInteger Big1, const BigInteger Big2)
{
    setNumber(0);
    curMaxIndex = internalAdd(Big1.bigNumber, Big1.curMaxIndex, Big1.bigNumber[Big1.numLength - 1],
                              Big2.bigNumber, Big2.curMaxIndex, Big2.bigNumber[Big2.numLength - 1],
                              bigNumber);
}

void BigInteger::setNumber(long long number) {
    int signMul = 1;

    cout << "number : " << number << "is set" << endl;
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

void BigInteger::setAllZero() {
    for (int i = 0; i < numLength; i++) {
        bigNumber[i] = NUMTOCHAR(0);
    }
}

void BigInteger::allocNumberRoom() {
    bigNumber = new char[numLength];

    setAllZero();
    curMaxIndex = 0;
}

void BigInteger::clearNumber() {
    if (curMaxIndex != 0) {
        setAllZero();
        curMaxIndex = 0;
    }
}

int BigInteger::internalAdd(const char* op1, const int op1CurMax, const char op1Sign,
        const char* op2, const int op2CurMax, const char op2Sign,
        char* result)
{
    int calMax = op1CurMax > op2CurMax ? op1CurMax : op2CurMax;
    int carry = 0;
    int i = 0;

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

int main(void)
{
    BigInteger bi(123456);
    BigInteger bi1(82323);
    BigInteger added;

    bi.setNumber(-100000 * 100000);
    bi1.setNumber(0);
    cout << endl;

    cout << "ADD2 --------------" << endl;
    cout << endl;
    added.addAndSave(bi, bi1);
    cout << endl;
    added.showNumber();

    return 0;
}

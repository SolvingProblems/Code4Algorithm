#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXARRAYSIZE    256
class BigIntegers
{

public:
    int digit[MAXARRAYSIZE];
    int index;

    BigIntegers() {
    }

    void resetArray(int *num)
    {
        for (int i = 0; i < MAXARRAYSIZE; i++)
            digit[i] = 0;
    }

    void setArrayNum(int *num) {
        int i;
        resetArray(digit);

        for(i = 0; i < MAXARRAYSIZE; i++){
            //cout << "set : " << num[i] << endl;
            digit[i] = num[i];
        }
        index = i - 1;
    }

    BigIntegers operator =(int num) {
        int i = 0;

        resetArray(digit);

        while (num > 0) {
            digit[i++] = num % 10;
            num = num / 10;
        }

        index = i;
        return *this;
    }

    friend std::ostream& operator <<(std::ostream& out,BigIntegers a)
    {
        for(unsigned int i=0; i < a.index; i++){
            out << a.digit[i];
        }
        return out;
    }
};

void printArray(int *result)
{
    bool startFlag = false;
    for(int i = MAXARRAYSIZE - 1; i >= 0; i--){
        if (!startFlag && result[i] == 0) {
            continue;
        } else {
            startFlag = true;
        }
        cout << result[i];
    }
    cout << endl;
}

BigIntegers multiply(const BigIntegers& a, const BigIntegers& b) {
    int aIndex = 0, bIndex = 0;
    int result[MAXARRAYSIZE]  = {0 ,};
    int i, carry = 0;

    while (bIndex < b.index)
    {
        for (i = 0; i < a.index; i++) {
            int temp = result[bIndex + i] + b.digit[bIndex] * a.digit[i] + carry;
            result[bIndex + i] = temp % 10;
            carry = (temp / 10);
        }
        bIndex++;
        if (carry != 0) {
            result[bIndex + i - 1] = carry;
            carry = 0;
        }
    }

    BigIntegers contain;
    contain.setArrayNum(result);

    return contain;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num = 0;

    cin >> num;
    BigIntegers a, b, c;

    b = 1;
    for (int i = 1; i <= num; i++) {
        a = i;
        b = multiply(b, a);
    }

    printArray(b.digit);
    return 0;
}

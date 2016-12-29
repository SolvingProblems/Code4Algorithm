#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>

#include "BigInteger.h"

using namespace std;

class MinScalar {
public:
    void setVecNum(int input, int aorb)
    {
        if (aorb) {
            vecB.push_back(input);
        } else {
            vecA.push_back(input);
        }
    }

    void reset()
    {
        vecA.clear();
        vecB.clear();
        result.clearNumber();
    }

    void sortVec()
    {
        sort(vecA.begin(), vecA.end());
        sort(vecB.begin(), vecB.end(), greater<int>());
    }

    void calScalar()
    {
        BigInteger previous(0);

        for (int i = 0; i < vecA.size(); i++) {
            BigInteger a((long)(vecA.at(i) * vecB.at(i)));
            result.addAndSave(previous, a);
            previous = result;
        }
    }

    void getResult()
    {
        result.showNumber();;
    }

    MinScalar() {
        result.setNumber(0);
    }

private:
    vector<int> vecA;
    vector<int> vecB;
    BigInteger result;
};

int main(void)
{
    int testCase = 0;
    MinScalar ms;
    int testCaseCount = 1;

    cin >> testCase;

    while (testCase-- > 0) {
        int num;

        cin >> num;

        for (int i = 0; i < num * 2; i++) {
            int temp;

            cin >> temp;

            if (i >= num) {
                ms.setVecNum(temp, 1);
            } else {
                ms.setVecNum(temp, 0);
            }
        }

        ms.sortVec();
        ms.calScalar();
        //cout << "Case #" << testCaseCount++ << ": " << ms.getResult() << endl;
        ms.getResult();
        ms.reset();
    }
}

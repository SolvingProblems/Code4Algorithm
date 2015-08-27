#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class BiggerIsGreater {
public:
    string given;
    bool swaped;

    BiggerIsGreater(string input)
    {
        given = input;
        swaped = true;
    }

    BiggerIsGreater()
    {
        swaped = true;
    }

    ~BiggerIsGreater()
    {
        swaped = true;
    }

    void setString(string input)
    {
        given.clear();
        given.assign(input.begin(), input.end());
    }

    void swap(int indexA, int indexB)
    {
#if DEBUG
        cout << "swap : " << endl;
        cout << "index A : " << indexA << " indexB : " << indexB << endl;
        cout << "ch A : " << given.at(indexA) << " ch B : " << given.at(indexB) << endl;
#endif

        char temp = given.at(indexA);
        given.at(indexA) = given.at(indexB);
        given.at(indexB) = temp;
    }

    void reArange(int start)
    {
        if (given.begin() + start != given.end())
            sort(given.begin() + start, given.end());
    }

    void findNextPermutation()
    {
        int leftMostIndex = given.length() - 1;
        int pivotIndex = leftMostIndex;
        int swapTarget = leftMostIndex;

        while (pivotIndex >= 1) {
            if (given.at(pivotIndex) > given.at(pivotIndex - 1))
                break;
            pivotIndex--;
        }

        while (pivotIndex > 0 && swapTarget > pivotIndex) {
            if (given.at(pivotIndex - 1) < given.at(swapTarget)) {
                break;
            }
            swapTarget--;
        }

        if (pivotIndex > 0 && swapTarget > 0) {
            swap(pivotIndex - 1, swapTarget);
            reArange(pivotIndex);
            swaped = true;
        } else {
            swaped = false;
        }
    }
#if 0
    void findFirstReplace()
    {
        int index = given.length() - 1;

        while (index >= 0) {
            for (int i = index - 1; i >= 0; i--) {
                if (given.at(index) > given.at(i)) {
                    //cout << "index : " << index << " i : " << i << endl;
                    //cout << "swap:: " << " index : " << given.at(index) << " i : " << given.at(i) << endl;
                    swap(index, i);
                    reArange(i + 1);
                    swaped = true;
                    break;
                }
            }

            if (swaped)
                break;
            index--;
        }
    }
#endif
    void printString()
    {
        if (swaped)
            cout << given << endl;
        else
            cout << "no answer" << endl;
    }
};

int main(void)
{
    //cout << "rebjvsszebhehuojrkkhszxltyqfdvayusylgmgkdivzlpmmtvbsavxvydlmdmsy" << endl;
    int testCase = 0;

    cin >> testCase;

    BiggerIsGreater big;
    while (testCase) {
        string temp;

        cin  >> temp;

        big.setString(temp);
        big.findNextPermutation();
        big.printString();
        testCase--;
    }

    return 1;
}

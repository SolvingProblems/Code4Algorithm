#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class ShelocAndArray {
public:
    ShelocAndArray() {
        // add first element as dummy
        listReset();
    }

    void setListSize(int size) {
        listSize = size;
    }

    void setNum(int input) {
        vList.push_back(input);
    }

    void printVec() {
        for (int i = 0; i < vList.size(); i++) {
            cout << vList.at(i) << " ";
        }
        cout << endl;
    }

    void listReset() {
        vList.clear();
        vList.push_back(-1);
        left = 0; right = 0;
        same = false;
    }

    void sumLeftRight() {
        for (int i = 1; i > 0; i--)
            left += vList.at(i);

        for (int j = 3; j <= listSize; j++)
            right += vList.at(j);

        if (right == 0 && listSize < 2)
            same = true;

        //cout << "init, left : " << left << " right : " << right << endl;
    }

    string checkArray(void) {
        int index = 3;

        //cout << "left : " << left << " right : " << right << endl;
        if (left == right)
            return "YES";

        while (index < listSize) {
            left += vList.at(index - 1);
            right -= vList.at(index);

            if (left == right) {
                same = true;
                break;
            }
            index++;
        }

        return same ? "YES" : "NO";
    }

private:
    int listSize;
    unsigned int left;
    unsigned int right;
    bool same;

    vector<int> vList;
};

int main() {

    int testCase = 0;
    ShelocAndArray saa;
    cin >> testCase;

    while (testCase > 0) {
        int arSize = 0;
        cin >> arSize;
        saa.setListSize(arSize);

        for (int i = 0; i < arSize; i++) {
            int temp = 0;
            cin >> temp;
            saa.setNum(temp);
        }

        saa.sumLeftRight();

        cout << saa.checkArray() << endl;
        saa.listReset();
        testCase--;
    }

    return 0;
}


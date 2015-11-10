#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class FullCountingSort {
public:
    FullCountingSort() {
    }

    void setSizeArr(int size) {
        arrSize = size;
        ai = new arrayInfo[size];
    }

    void setString(int index, string str) {
        ai[index].strs.push_back(str);
    }

    ~FullCountingSort() {
        delete [] ai;
    }

    void printStrings() {
        for (int i = 0; i < arrSize; i++) {
            int size = ai[i].strs.size();

            for (int j = 0; j < size; j++) {
                cout << ai[i].strs.at(j) << " ";
            }
        }
        cout << endl;
    }
private:
    int arrSize;

    struct arrayInfo {
        vector<string> strs;
    };

    struct arrayInfo *ai;
};

int main(void)
{
    int testCase = 0;
    int half = 0;
    FullCountingSort fcs;
    cin >> testCase;

    fcs.setSizeArr(testCase);
    half = testCase / 2;

    while (testCase > 0) {
        int temp = 0;
        string tStr;

        cin >> temp >> tStr;

        if (testCase <= half)
            fcs.setString(temp, tStr);
        else
            fcs.setString(temp, "-");
        testCase--;
    }

    fcs.printStrings();
}

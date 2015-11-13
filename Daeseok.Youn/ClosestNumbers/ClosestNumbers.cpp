#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class ClosestNumbers {
public:
    ClosestNumbers() {
        minDiff = INT_MAX;
    }

    void setListSize(int size) {
        indexAr = new int[size];
        mapSize = size;

        for (int i = 0; i < size; i++)
            indexAr[i] = -1;
    }

    void addItemToList(int num) {
        numList.push_back(num);
    }

    void listSort() {
        sort(numList.begin(), numList.end());
    }

    void findDiff() {
        int index = 0;

        while (index < numList.size() - 1) {
            int currNum = numList.at(index);

            int diff = abs(currNum - numList.at(index + 1));
            if (diff != 0 && diff <= minDiff) {
                minDiff = diff;
                indexAr[index] = index + 1;
            }
            index++;
        }

        cout << "minDiff : " << minDiff;
        cout << endl;
    }

    void printResult() {
        for (int i = 0; i < mapSize; i++) {
            int a, b;

            if (indexAr[i] == -1)
                continue;

            a = numList.at(i);
            b = numList.at(indexAr[i]);

            if (abs(a - b) != minDiff)
                continue;

            cout << a << " " << b << " ";
        }
        cout << endl;
    }

    ~ClosestNumbers() {
        delete [] indexAr;
    }

private:
    vector<int> numList;
    int *indexAr;
    unsigned int mapSize;
    int minDiff;
};

int main() {
    ClosestNumbers cn;

    int inputSize = 0;
    cin >> inputSize;
    cn.setListSize(inputSize);

    while (inputSize > 0) {
        int temp = 0;
        cin >> temp;
        cn.addItemToList(temp);

        inputSize--;
    }

    cn.listSort();
    cn.findDiff();
    cn.printResult();
    return 0;
}


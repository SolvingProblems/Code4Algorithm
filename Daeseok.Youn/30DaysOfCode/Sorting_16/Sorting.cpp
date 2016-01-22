#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Sorting {
    public:
        Sorting() {};
        ~Sorting() {};

        void setList(vector<int> input) {
            listNum = input;
        }

        void sortingList() {
            int keyVal;

            for (int i = 0; i < listNum.size(); i++) {
                int j = i - 1;

                keyVal = listNum.at(i);

                while (j >= 0 && keyVal < listNum[j]) {
                    listNum[j + 1] = listNum[j];
                    j--;
                }
                listNum[j + 1] = keyVal;
            }
        }

        /*
        void printVector() {
            for (int i = 0; i < listNum.size(); i++) {
                cout << listNum[i] << " ";
            }
            cout << endl;
        }*/

        void printVector() {
            for (int i = 0; i < minimumList.size(); i++) {
                cout << minimumList[i] << " ";
            }
            cout << endl;
        }

        int findMinDiff() {
            int minVal = numeric_limits<int>::max();
            for (int i = 0; i < listNum.size() - 1; i++) {
                int diff = abs(listNum.at(i) - listNum.at(i+1));
                if (minVal > diff)
                    minVal = diff;
            }

            return minVal;
        }

        void makeListsMinVal() {
            int min = findMinDiff();

            for (int i = 0; i < listNum.size() - 1; i++) {
                int diff = abs(listNum.at(i) - listNum.at(i+1));
                if (min == diff) {
                    minimumList.push_back(listNum.at(i));
                    minimumList.push_back(listNum.at(i+1));
                }
            }
        }
    private:
        vector<int> listNum;
        vector<int> minimumList;
};

int main() {

    int listSize = 0;
    vector<int> input;
    Sorting s;

    cin >> listSize;
    while (listSize-- > 0) {
        int temp = 0;

        cin >> temp;

        input.push_back(temp);
    }

    s.setList(input);
    s.sortingList();
    s.findMinDiff();
    s.makeListsMinVal();
    s.printVector();

    return 0;
}


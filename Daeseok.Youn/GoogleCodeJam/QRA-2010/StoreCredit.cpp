/*
 * This problem see through https://code.google.com/codejam/contest/351101/dashboard#s=p0
 * It seems to simillar with the problem of HackerRank that is in
 * https://www.hackerrank.com/challenges/icecream-parlor.
 * It could be solved with "binary search".
 * BF(Brute force) method cannot be completed on limited time.
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class StoreCredit {
public:
    void setCredit(int c) {
        credit = c;
        index1 = 0;
        index2 = 0;
    }

    void setNumber(int p) {
        listItems.push_back(p);
   }

    static bool increseOrder(int i, int j) {
        return i < j;
    }

    void copyVectorAndSort() {
        sortedItems = listItems;

        sort(sortedItems.begin(), sortedItems.end(),
             increseOrder);

#if 0
        for (int i = 0; i < sortedItems.size(); i++) {
            cout << sortedItems.at(i) << " ";
        }
        cout << endl;
#endif
    }

    int findValue(int value) {
        int start = 0;
        int end = sortedItems.size() - 1;
        int mid = (start + end) / 2;
        //cout << "start : " << start << " mid : " << mid << " end : " << end << endl;

        while (start <= end) {
            int temp = sortedItems.at(mid);
            if (temp + value > credit) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }

            if ((temp + value) == credit) {
                return temp;
            }

            mid = (start + end) / 2;
            //cout << "in start : " << start << " mid : " << mid << " end : " << end << endl;
        }

        return -1;
    }

    int findIndex(int cur, int value) {
        for (int i = cur + 1; i < listItems.size(); i++) {
            if (listItems.at(i) == value)
                return i + 1;
        }

        // code cannot reach this code.
        return -1;
    }

    void searchValue() {
        int i = 0;

        while (i < listItems.size()) {
            int value = listItems.at(i);

            int value2 = findValue(value);
            //cout << " value 2: " << value2 << endl;
            if (value2 > 0) {
                index2 = findIndex(i, value2);
            }

            if (index2 > 0)
                break;

            i++;
        }

        index1 = i + 1;
    }

    void getResult() {
        static int i = 1;
        cout << "Case #" << i++ << ": " << index1 << " " << index2 << endl;
    }

    void clearList() {
        listItems.clear();
        credit = 0;

        index1 = 0; index2 = 0;
    }

private:
    vector<int> listItems;
    vector<int> sortedItems;

    unsigned int credit;
    int index1, index2;
};

int main(void)
{
    int testCase;
    StoreCredit sc;

    cin >> testCase;

    while (testCase-- > 0) {
        int credit, n;
        cin >> credit;
        cin >> n;

        sc.setCredit(credit);
        for (int i = 0; i < n; i++) {
            int temp;

            cin >> temp;

            sc.setNumber(temp);
        }

        sc.copyVectorAndSort();
        sc.searchValue();

        sc.getResult();
        sc.clearList();
    }
}

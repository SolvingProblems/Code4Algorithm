#include <iostream>
#include <vector>

using namespace std;

// Sort the array in non-increasing order.
// This problem is from codemonk
// https://www.hackerearth.com/code-monk-sorting/algorithm/chandu-and-his-girlfriend/

// I used mergeSort for solving this problem.
class SortArray {
public:
    void setSizeofArr(int size) {
        static bool assigned = false;

        if (assigned) {
            arr.resize(size);
        } else {
            arr.assign(size, 0);
        }
    }

    void clearArray() {
        arr.clear();
    }

private:
    vector<int> arr;
};

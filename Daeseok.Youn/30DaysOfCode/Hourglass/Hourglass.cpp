#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define arrLen_i    6
#define arrLen_j    6

void printVec2D(vector< vector<int> > arr)
{
    for (int i = 0; i < arrLen_i; i++) {
        for (int j = 0; j < arrLen_j; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int hourglass(vector< vector<int> > arr, int i, int j)
{
    int top = 0, mid = 0, bottom = 0;

    top = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
    mid = arr[i + 1][j + 1];
    bottom = arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];

    return (top + mid + bottom);
}

int getMaxValFromMatrix(vector< vector<int> > arr)
{
    int i = 0, j = 0;
    int maxVal = 0;

    while (j < arrLen_j - 2) {
        int v = 0;

        if (i >= arrLen_i - 2) {
            j++; i = 0;
            continue;
        }

        v = hourglass(arr, i, j);
        maxVal = maxVal >= v ? maxVal : v;
        i++;
    }

    return maxVal;
}

int main(){
    vector< vector<int> > arr(arrLen_i, vector<int>(arrLen_j));
    for(int arr_i = 0; arr_i < arrLen_i; arr_i++){
       for(int arr_j = 0; arr_j < arrLen_j; arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }

    cout << getMaxValFromMatrix(arr) << endl;
//    cout << endl;
//    printVec2D(arr);
    return 0;
}


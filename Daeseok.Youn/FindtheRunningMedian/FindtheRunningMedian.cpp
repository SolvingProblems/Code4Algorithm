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

float findMeidan(vector<int> a, int inputIndex) {
    int newItem = a[inputIndex];

    float res = 0.0;
    int inx = 0;

    for (int i = 0; i < inputIndex; i++) {
        if (newItem < a.at(i)) {
            int temp = a.at(i);
            a[i] = newItem;
            newItem = temp;
        }
    }

    a[inputIndex] = newItem;
    for (int i = 0; i < a.size(); i++) {
        cout << a.at(i) << " ";
    }
    cout << endl;

    inx = (inputIndex + 1) / 2;

    if ((inputIndex + 1) % 2 != 0) {
        res = a.at(inx);
    } else {
        res = ((float)a.at(inx) + (float)a.at(inx - 1)) / 2.0;
        cout << inx << " : " << a.at(inx) << " inx - 1 " << a.at(inx-1) << endl;
        cout << ((float)a.at(inx) + (float)a.at(inx - 1)) << endl;
        cout << res << endl;
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];

        cout << fixed;
        cout.precision(1);
        cout << findMeidan(a, a_i) << endl;
    }
    return 0;
}


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

bool is_balanced(string expression) {
    char open[3] = { '{', '[', '(' };
    char close[3] = { '}', ']', ')' };
    /*
     * Workaround: in case of '))'
     */
    bool opened = false;
    stack<int> s;

    for (int i = 0; i < expression.size(); i++) {

        char temp = expression.at(i);
        int j = 0;

        for (j = 0; j < 3; j++) {
            if (temp == open[j]) {
                opened = true;
                s.push(j);
                break;
            }
        }

        if (j >= 3 && !s.empty()) {
           int idx = s.top();

           if (temp != close[idx])
               return false;

           s.pop();
        }
    }

    if (!s.empty() || !opened)
        return false;

    return true;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


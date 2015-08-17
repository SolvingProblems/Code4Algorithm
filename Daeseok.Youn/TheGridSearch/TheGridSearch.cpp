#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void makeGridInfo(vector<string> &vec, int row)
{
    int i = 0;

    for (i = 0; i < row; i++) {
        string temp;

        cin >> temp;
        vec.push_back(temp);
    }
}

int findPattern(vector<string> grid, vector<string> pattern)
{
    int index = 0;
    int i = 0;
    size_t pos, prevPos = string::npos;

    for (i = 0; i < grid.size(); i++) {
        string temp = pattern.at(index);
        pos = grid.at(i).find(temp);

        if (pos == string::npos) {
            index = 0;
            continue;
        }

        cout << "i : " << i << " pos : " << pos << endl;
        if (prevPos == string::npos) {
            prevPos = pos;
            index++;
        } else if (prevPos == pos) {
            index++;
        } else {
            index = 0;
            prevPos = string::npos;
        }

        if (index >= pattern.size())
            break;
    }

    cout << "pattern size " << pattern.size() << " index : " << index << endl;
    return index;
}

int main() {

    int testCase = 0;
    vector<string> largeGrid;
    int gridN = 0, gridM = 0;
    vector<string> pattern;
    int patN = 0, patM = 0;

    cin >> testCase;
    while (testCase > 0) {
        int result = -1;
        cin >> gridN >> gridM;

        makeGridInfo(largeGrid, gridN);

        cin >> patN >> patM;
        cout << "pattern : " << patN << " " << patM << endl;
        makeGridInfo(pattern, patN);
        result = findPattern(largeGrid, pattern);

        if (result == pattern.size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        largeGrid.clear();
        pattern.clear();

        testCase--;
    }
    return 0;
}


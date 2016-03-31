#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Rotate {
public:
    Rotate() {
    }
    ~Rotate() {
    }

    void reset() {
        start.clear();
        joinK = 0;
        tableSize = 0;
        rotate.clear();
    }

    void setLine(string line) {
        start.push_back(line);
    }

    void setSizes(int t, int k) {
        tableSize = t;
        joinK = k;
    }

    void printTable(vector<string> p) {
        for (int i = 0; i < p.size(); i++) {
            cout << p.at(i) << endl;
        }
    }

    void rotateTable() {
        int index = 0;

        while (index < tableSize) {
            string temp;

            for (int i = start.size() - 1; i >= 0; i--) {
                string line = start.at(i);

                temp.push_back(line.at(index));
            }
            index++;
            rotate.push_back(temp);
        }
    }

    int nextBlank(string temp, int position) {
        for (int i = position - 1; i >= 0; i--) {
            if (temp.at(i) == '.')
                return i;
        }
    }

    bool horizontalCheck(int line, int pos) {
        string temp = rotate.at(line);
        int cnt = 0;

        if (pos + joinK > temp.size())
            return false;

        for (int i = pos; i < pos + joinK; i++)
            if (temp.at(pos) == temp.at(i))
                cnt++;

        return cnt >= joinK ? true : false;
    }

    bool verticalCheck(int line, int pos) {
        string temp = rotate.at(line);
        int cnt = 0;

        if (line + joinK > rotate.size())
            return false;

        for (int i = line; i < line + joinK; i++)
            if (temp.at(pos) == rotate.at(i).at(pos))
                cnt++;

        return cnt >= joinK ? true : false;
    }

    bool diagonalCheck(int line, int pos) {
        string temp = rotate.at(line);
        int cnt = 0;
        int tempPos = pos;

        if (line + joinK <= rotate.size() &&
            pos + joinK <= temp.size()) {

            for (int i = line + 1; i < line + joinK; i++)
                if (temp.at(pos) == rotate.at(i).at(++tempPos))
                    cnt++;
                else
                    break;
        }

        if (cnt < joinK &&
            (pos >= (joinK - 1) && (rotate.size() - line) >= joinK)) {
            tempPos = pos;
            for (int i = line + 1; i < rotate.size(); i++) {
                if (tempPos > 0 && temp.at(pos) == rotate.at(i).at(--tempPos))
                    cnt++;
                else
                    break;
            }
        }

        return cnt >= (joinK - 1) ? true : false;
    }

    int checkKPieces() {
        // 1 : RED, 2 : BLUE, 3 : Both, 0 : Neither.
        int checked = 0;

        for (int i = 0; i < rotate.size(); i++) {
            string temp = rotate.at(i);
            for (int j = 0; j < temp.size(); j++) {
                if (temp.at(j) == '.' ||
                    (temp.at(j) == 'R' && (checked & 1)) ||
                    (temp.at(j) == 'B' && (checked & 2)))
                    continue;
                else {
                    bool check = false;

                    check |= horizontalCheck(i, j);
                    check |= verticalCheck(i, j);
                    check |= diagonalCheck(i, j);

                    if (check) {
                        if (checked == 0 && temp.at(j) == 'R')
                            checked = 1;
                        else if (checked == 0 && temp.at(j) == 'B')
                            checked = 2;
                        else
                            checked = 3;
                    }
                }
            }
        }

        return checked;
    }

    string getResultString(int value) {
        switch(value) {
            case 0:
                return "Neither";
            case 1:
                return "Red";
            case 2:
                return "Blue";
            case 3:
                return "Both";
        }

        return "error";
    }

    void applyGravity() {
        int index = 0;
        vector<string> gravity;

        while (index < start.size()) {
            string temp = start.at(index);

            int bottom = temp.size() - 1;

            if (temp.at(bottom) != '.')
                bottom = nextBlank(temp, bottom);
            int redBlue = bottom - 1;

            for (int i = redBlue; i >= 0; i--) {
                if (temp.at(i) != '.') {
                    swap(temp.at(bottom), temp.at(i));
                    bottom = nextBlank(temp, bottom);
                }
            }

            index++;
            gravity.push_back(temp);
        }

        start.clear();
        start = gravity;
    }

private:
    vector<string> start;
    vector<string> rotate;
    int tableSize;
    int joinK;
};

int main(void)
{
    int testCase;
    int casenum = 1;
    Rotate r;

    cin >> testCase;

    while (testCase-- > 0) {
        int tsize, joink;

        cin >> tsize >> joink;

        r.setSizes(tsize, joink);

        for (int i = 0; i < tsize; i++) {
            string temp;

            cin >> temp;
            r.setLine(temp);
        }
        r.applyGravity();
        r.rotateTable();
        cout << "Case #" << casenum++ << ": " << r.getResultString(r.checkKPieces()) << endl;
        r.reset();
    }

    return 0;
}

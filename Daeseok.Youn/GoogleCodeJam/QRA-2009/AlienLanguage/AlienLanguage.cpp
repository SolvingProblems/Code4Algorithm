#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

#define MAXLENGTH   15
#define ALPHABETCNT 26

class AlienLanguage {
public:
    AlienLanguage() {
        length = 0;
    }

    ~AlienLanguage() {
        for (int i = 0; i < length; i++)
            delete [] alphabet[i];
        delete [] alphabet;
    }

    void setLength(int len) {
        length = len;

        alphabet = new bool*[length];

        for (int i = 0; i < length; i++) {
            alphabet[i] = new bool[ALPHABETCNT];
        }
    }

    void clearPatArr() {
        for (int i = 0; i < length; i++)
            for (int j = 0; j < ALPHABETCNT; j++)
                alphabet[i][j] = 0;
    }

    void pushData(string input) {
        storeData.push_back(input);
    }

    int checkPatten() {
        int count = 0;

        for (int i = 0; i < storeData.size(); i++) {
            string temp = storeData.at(i);

            int j = 0;
            for (j = 0; j < temp.size(); j++) {
                if (!alphabet[j][temp.at(j) - 'a'])
                    break;
            }

            if (j == temp.size())
                count++;
        }

        return count;
    }

    int getPatternCnt(string alien) {
        int index = 0;
        int strIndex = 0;
        bool parenthesis = false;

        clearPatArr();

        while (strIndex < alien.size()) {
            if (alien.at(strIndex) == '(') {
                parenthesis = true;
                strIndex++;
                continue;
            }

            if (alien.at(strIndex) == ')') {
                index++;
                parenthesis = false;
            } else {
                alphabet[index][alien.at(strIndex) - 'a'] = true;
                if (!parenthesis)
                    index++;
            }

            strIndex++;
        }

        return checkPatten();
    }

private:
    vector<string> storeData;
    int length;
    bool **alphabet;
};

int main(void)
{
    int Length, dataSet, testCase;
    AlienLanguage al;
    int printCaseNum = 1;

    cin >> Length >> dataSet >> testCase;
    al.setLength(Length);

    while (dataSet-- > 0) {
        string temp;

        cin >> temp;
        al.pushData(temp);
    }

    while (testCase-- > 0) {
        string temp;
        cin >> temp;

        cout << "Case #" << printCaseNum++ << ": ";
        cout << al.getPatternCnt(temp) << endl;
    }

    return 0;
}

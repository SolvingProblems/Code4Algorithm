#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ALPHABET_COUNT  26
class CommonChild {
public:
    CommonChild(string a, string b)
    {
        aStr = a;
        bStr = b;
        maxLength = 0;

        LCS = new unsigned int*[aStr.length() + 1];
        for (int i = 0; i <= aStr.length(); i++)
            LCS[i] = new unsigned int[bStr.length() + 1];

        // Intialize array
        for (int j = 0; j <= aStr.length(); j++)
            for (int k = 0; k <= bStr.length(); k++)
                LCS[j][k] = 0;
    }

    ~CommonChild()
    {
        for (int i = 0; i <= aStr.length(); i++)
            delete [] LCS[i];

        delete [] LCS;
    }

    unsigned int max(unsigned int a, unsigned int b)
    {
        return a > b ? a : b;
    }

    void longestCommonSeqCount()
    {
        int i = 0;
        int j = 0;

        for (i = 0; i < bStr.length(); i++) {
            for (j = 0; j < aStr.length(); j++) {
                if (bStr.at(i) == aStr.at(j)) {
                    LCS[i + 1][j + 1] = LCS[i][j] + 1;
                } else {
                    LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]);
                }
                maxLength = max(maxLength, LCS[i + 1][j + 1]);
            }
        }
    }

    unsigned int getMax()
    {
        return maxLength;
    }

private:
    string aStr, bStr;
    unsigned int maxLength;
    unsigned int **LCS;
};

int main() {
    CommonChild cc("HARRY", "SALLY");
    //CommonChild cc("ABCDEF", "FBDAMN");
    //CommonChild cc("SHINCHAN", "NOHARAAA");
    //CommonChild cc("WEWOUCUIDGCGTRMEZEPXZFEJWISRSBBSYXAYDFEJJDLEBVHHKS", "FDAGCXGKCTKWNECHMRXZWMLRYUCOCZHJRRJBOAJOQJZZVUYXIC");
    cc.longestCommonSeqCount();
    cout << cc.getMax() << endl;

    return 0;
}

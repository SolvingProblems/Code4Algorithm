#include <string>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

class Alignment {
public:
    int align(string A, string B, int x)
    {
        int i, j, k;
        int lengthA = A.size();
        int lengthB = B.size();

        int **score;

        score = new int*[lengthA + 1];
        for (i = 0; i <= lengthA; ++i)
            score[i] = new int[lengthB + 1];

        for (i = 0; i <= lengthA; i++)
            for (j = 0; j <= lengthB; j++)
                score[i][j] = numeric_limits<int>::max();

        for (i = 1; i <= lengthA; i++)
            score[i][0] = x + i;

        for (j = 1; j <= lengthB; j++)
            score[0][j] = x + j;

        score[0][0] = 0;

        for (i = 1; i <= lengthA; i++) {
            for (j = 1; j <= lengthB; j++) {
                if (A.at(i-1) == B.at(j-1))
                    score[i][j] = score[i-1][j-1];

                for (k = 1; k <= i; k++)
                    score[i][j] = min(score[i][j], x + k + score[i - k][j]);
                for (k = 1; k <= j; k++)
                    score[i][j] = min(score[i][j], x + k + score[i][j - k]);
            }
        }

        printArray(score, lengthA, lengthB);
        return score[lengthA][lengthB];
    }

    void printArray(int **score, int x, int y)
    {
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++)
                cout << " " << score[i][j];
            cout << endl;
        }
    }
};

int main(void)
{
    Alignment am;

    /*
     *     string a = "ABC";
     *         string b = "ACE";
     *
     *             am.align(a, b, 1);
     *                 */
    string a = "AAABAAAABAA";
    string b = "AAAABAABAAA";

    /*
     *     am.align(a, b, 1);
     *         */

    /*
     *     string a = "AAABAAAABAA";
     *         string b = "AAAABAABAAA";
     *
     */

    cout << am.align(a, b, 10) << endl;
}

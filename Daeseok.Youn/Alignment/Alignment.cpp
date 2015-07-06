#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Alignment {
public:
    int traversSub(string S, int x)
    {
        int i = 0;
        int scoreContinue = 0;
        int total = 0;

        while (i < S.size()) {
            if (S.at(i++) == '-') {
                scoreContinue++;
                if (i != S.size())
                    continue;
            }

            if (scoreContinue != 0)
                total += (x + scoreContinue);
            scoreContinue = 0;
        }

        return total;
    }

    int getScore(string A, string B, int x)
    {
        return traversSub(A, x) + traversSub(B, x);
    }

    int align(string A, string B, int x)
    {
        if (A.size() < 1 || A.size() > 50 ||
            B.size() < 1 || B.size() > 50 ||
            (x < 0 || x > 100))
            return 0;

        string ADash, BDash;
        int indexA = 0, indexB = 0;
        while (indexA < A.size() && indexB < B.size()) {
            int AValue = A.at(indexA) - 'A';
            int BValue = B.at(indexB) - 'A';

            if (AValue < BValue) {
                ADash.push_back(A.at(indexA++));
                BDash.push_back('-');
            } else if (AValue > BValue) {
                ADash.push_back('-');
                BDash.push_back(B.at(indexB++));
            } else {
                ADash.push_back(A.at(indexA++));
                BDash.push_back(B.at(indexB++));
            }
        }

        while (indexA < A.size()) {
            ADash.push_back(A.at(indexA++));
            BDash.push_back('-');
        }

        while (indexB < B.size()) {
            BDash.push_back(B.at(indexB++));
            ADash.push_back('-');
        }

        cout << "ADash : " << ADash << endl;
        cout << "BDash : " << BDash << endl;
        return getScore(ADash, BDash, x);
    }
};

int main(void)
{
    Alignment am;

    /*
    string a = "ABC";
    string b = "ACE";

    am.align(a, b, 1);
    */
    string a = "AAABAAAABAA";
    string b = "AAAABAABAAA";

    /*
    am.align(a, b, 1);
    */

    /*
    string a = "AAABAAAABAA";
    string b = "AAAABAABAAA";
    */

    cout << am.align(a, b, 10) << endl;

    return 0;
}

/*
 * TopCoder
 * Name : AB (250 point)
 */
#include <iostream>
#include <string>

using namespace std;

class AB {
public:
    int getPairCount(string ab)
    {
        int count = 0;
        int countA = 0;
        int n = ab.length();
        for (int i = 0; i < n; i++) {
            if ('A' == ab.at(i)) {
                count += (n - i - (++countA));
            }
        }

        return count;
    }

    void setCharA(string &ab, int pairCount, int k)
    {
        for (int i = 0; i < ab.length(); i++) {
            if (ab.at(i) != 'A' && pairCount < k) {
                ab[i] = 'A';
                if (getPairCount(ab) > k)
                    ab[i] = 'B';
                else
                    break;
            }
        }
    }

    string createString(int n, int k) {

        if (k < 0 || (k > (n*(n - 1)/2))
            || (k > ((n/2) * (n - n/2)))) {
            return "";
        }

        string abString(n, 'B');
        unsigned int pairCount = 0;

        while (pairCount < k) {
            pairCount = getPairCount(abString);
            setCharA(abString, pairCount, k);
        }

        return abString;
    };
};

int main(void)
{
    class AB abControl;

    cout << abControl.createString(5, 8) << endl;

    return 0;
}

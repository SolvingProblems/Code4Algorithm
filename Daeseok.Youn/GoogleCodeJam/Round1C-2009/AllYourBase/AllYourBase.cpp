#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

class AllYourBase {
public:

    AllYourBase() {
        maxBase = 2;
    }

    void setAlienSym(string sym) {
        alienSym = sym;
    }

    void clear() {
        alienSym.clear();
        converted.clear();
        m.clear();
        maxBase = 2;
    }

    unsigned long long myPow(unsigned int base, unsigned pos) {
        long long temp = 1ll;

        while (pos) {
            temp *= base;
            pos--;
        }
        return temp;
    }

    unsigned long long getSeconds() {
        int pos = converted.size() - 1;
        unsigned long long seconds = 0;

        for (int i = 0; i < converted.size(); i++) {
#if STD_POW
            /*
             * NOTE: pow function gives me wrong value.
             * I didn't figure out why it is happend.
             * TestCase : 15^14
             * pow(15, 14) => 29192926025390624
             * myPow(15, 14) => 29192926025390625
             * These values are differ each other, pow function may be
             * not working propery some large number of result.
             */
            seconds += (unsigned long long)((converted.at(i) - '0') *
                        (pow(maxBase, pos - i)));
#else
            seconds += (unsigned long long)((converted.at(i) - '0') *
                        (myPow(maxBase, pos - i)));
#endif
        }

        return seconds;
    }

    void replace2Value() {
        int value = 0;

        for (int i = 0; i < alienSym.size(); i++) {
            char ch = alienSym.at(i);
            map<char, int>::iterator it = m.find(ch);

            if (!m.empty() && it != m.end()) {
                converted.push_back(it->second + '0');
            } else if (m.empty()) {
                m.insert(pair<char, int>(ch, 1));
                converted.push_back('1');
            } else {
                m.insert(pair<char, int>(ch, value));
                converted.push_back(value + '0');

                value++;

                if (value == 1)
                    value = 2;
            }
        }

        if (maxBase < value)
            maxBase = value;

 //       cout << "converted : " << converted << " base : " << maxBase << endl;
    }

private:
    string alienSym;
    string converted;
    int maxBase;
    map <char, int> m;
};

int main(void)
{
    int testCase;
    int showCase = 1;
    AllYourBase ayb;

    cin >> testCase;

    while (testCase-- > 0) {
        string temp;

        cin >> temp;

        ayb.setAlienSym(temp);
        ayb.replace2Value();
        cout << "Case #" << showCase++ << ": " << ayb.getSeconds() << endl;
        ayb.clear();
    }

    return 0;
}

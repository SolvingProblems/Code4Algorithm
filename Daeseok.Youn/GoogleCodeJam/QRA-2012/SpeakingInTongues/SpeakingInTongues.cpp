#include <iostream>
#include <string>

using namespace std;

static char transTable[26] = {
    'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
    'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't',
    'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
};

int main(void)
{
    int testCase;

    cin >> testCase;
    cin.ignore();

    while (testCase-- > 0) {
        string temp;
        static int casenum = 1;

        getline(cin, temp);
        cout << "Case #" << casenum++ << ": ";

        for (int i = 0; i < temp.size(); i++) {
            if (temp.at(i) != ' ')
                cout << transTable[temp.at(i) - 'a'];
            else
                cout << temp.at(i);
        }
        cout << endl;
    }

    return 0;
}

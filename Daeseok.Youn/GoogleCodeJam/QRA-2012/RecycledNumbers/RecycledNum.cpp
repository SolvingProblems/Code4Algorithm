#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int checkRotateValue(string A, string B) {
    int Bnum = 0;
    int Anum = 0;
    unsigned int count = 0;
    string temp = A;
    string::size_type sz;

    Bnum = atoi(B.c_str());
    Anum = atoi(A.c_str());

    for (int i = 0; i < A.size(); i++) {
        char tempch = temp.at(temp.length() - 1);
        temp.erase(temp.end() - 1);
        temp.insert(0, &tempch);

        int num = 0;

        num = atoi(temp.c_str());
    }

    return 0;
}

int main(void)
{
    int testCase;
    int casenum = 1;

    cin >> testCase;

    while (testCase-- > 0) {
        // start implementation
        // end
        string A, B;
        cin >> A >> B;

        unsigned count = 0;

        count = checkRotateValue(A, B);

        cout << "Case #" << casenum++ << ": ";
        cout << count << endl;
    }

    return 0;
}

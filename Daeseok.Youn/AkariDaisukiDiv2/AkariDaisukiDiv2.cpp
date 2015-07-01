#include <iostream>
#include <string>

using namespace std;

class AkariDaisukiDiv2 {
public:
    int countTuples(string S) {
        if (S.size() < 1 || S.size() > 50)
            return 0;

        int result = 0;
        int alphabetIndex[26] = {0,};
        int i;

        for (i = 1; i < S.size() - 1; i++)
            alphabetIndex[S.at(i) - 'a']++;

        for (i = 0; i < 26; i++) {
            char ch;
            if (alphabetIndex[i] != 0) {
                ch = 'a' + i;
                cout << ch << " : " << alphabetIndex[i] << endl;
            }
        }

        for (i = 0; i < 26; i++) {
            if (alphabetIndex[i] == 2)
                result++;
            else if (alphabetIndex[i] > 2)
                result += (alphabetIndex[i] * 2) - 1;
        }

        return result;
    }
};

int main(void)
{
    AkariDaisukiDiv2 adv;
    //string s = "topcoderdivtwo";
    //string s = "foxciel";
    //string s = "magicalgirl";
    string s = "waaiusushioakariusushiodaisuki";

    cout << adv.countTuples(s) << endl;

    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class permutationOfString {
private:
    string origin;
    vector<string> anigma;
    int index;
    int alphabetArr[26];

public:
    permutationOfString(string input);
    string swap(string curr, int indexA, int indexB);
    bool checkSameStrinVec(string str);
    void printVec();
    void permute();
    bool isPalindrome(string str);
    bool checkPossiblePalindrom();
    void minimizeString();
};

bool permutationOfString::checkSameStrinVec(string str)
{
    if (anigma.size() > 0 &&
        find(anigma.begin(), anigma.end(), str) != anigma.end()) {
        return false;
    }
    return true;
}

string permutationOfString::swap(string curr,
                                 int indexA, int indexB)
{
    char ch = curr.at(indexA);
    curr.at(indexA) = curr.at(indexB);
    curr.at(indexB) = ch;

    return curr;
}

permutationOfString::permutationOfString(string input)
{
    index = 0;
    for (int i = 0; i < 26; i++)
        alphabetArr[i] = 0;
    origin = input;
}

void
permutationOfString::printVec()
{
    for (int i = 0; i < anigma.size(); i++)
        cout << anigma.at(i) << endl;
}

bool
permutationOfString::isPalindrome(string str)
{
    int i;
    for (i = 0; i < str.length() / 2; i++) {
        if (str.at(i) != str.at(str.length() - 1 - i))
            break;
    }

    if (i != str.length() / 2)
        return false;
    return true;
}

void permutationOfString::minimizeString()
{
    string temp;
    int total = 0;

    for (int i = 0; i < 26; i++) {
        int count = alphabetArr[i];
        if (count > 2) {
            temp.insert(total, total + 2, i + 'a');
        }
    }
    anigma.push_back(temp);
}

void
permutationOfString::permute()
{
    if (!checkPossiblePalindrom()) {
        cout << "can not make palindrome this str" << endl;
    } else {
        cout << "can make palindrom this str" << endl;
    }

    return;
#if 0
    minimizeString();

    while (index < anigma.size())
    {
        int i = 0;

        string curString = anigma.at(index++);

        for (i = 0; i < curString.length() - 1; i++) {
            string temp = swap(curString, i, i + 1);

            if (checkSameStrinVec(temp)) {
                anigma.push_back(temp);
                if (isPalindrome(temp)) {
                    cout << " palindrom str : " << temp << endl;
                    return;
                }
            }
        }
    }
#endif
}

bool permutationOfString::checkPossiblePalindrom()
{
    int oddCount = 0;

    int i = 0;
    for (; i < origin.length(); i++) {
        alphabetArr[origin.at(i) - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        if (alphabetArr[i] % 2 != 0)
            oddCount++;
    }

    oddCount = origin.length() % 2 == 0 ? oddCount: oddCount - 1;

 //   cout << "oddCount : " << oddCount << endl;
    if (oddCount == 0)
        return true;

    return false;
}

int main(void)
{
    permutationOfString pos("cdefghmnopqrstuvw");

    pos.permute();
}

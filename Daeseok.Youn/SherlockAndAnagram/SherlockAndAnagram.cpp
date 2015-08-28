#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define ALPHABET_LENG   26

class SherlockAnagrams {
private:
    string inputString;
    map <string, int> permutes;

public:
    SherlockAnagrams()
    {
    }

    void setString(string str)
    {
        inputString.clear();

        inputString.assign(str.begin(), str.end());
        permutes.clear();
    }

    void findAnagrams()
    {
        int i, j;
        size_t strLength = inputString.length();
        unsigned int count = 0;
        map<string, int>::iterator it;

        for (i = 0; i < strLength; i++) {
            for (j = 1; i + j - 1 < strLength; j++) {
                string temp = inputString.substr(i, j);
                sort(temp.begin(), temp.end());

                permutes[temp]++;
            }
        }

        for (it = permutes.begin(); it != permutes.end(); it++) {
            //cout << "key : " << it->first << " value : " << it->second << endl;
            count += (unsigned int)(it->second) * (it->second - 1) / 2;
            //cout << "count : " << count << endl;
        }

        cout << count <<  endl;
    }
};

int main(void)
{
    SherlockAnagrams sa;

    //sa.setString("abba");
    sa.setString("pvmupwjjjf");
    //sa.setString("abccba");
    sa.findAnagrams();

    return 1;
}

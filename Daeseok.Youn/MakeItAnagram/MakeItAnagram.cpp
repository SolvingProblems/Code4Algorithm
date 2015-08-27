#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define ALPHABETLENGTH  26

class MakeItAnagram {
public:
    MakeItAnagram();
    ~MakeItAnagram();

    void inputString(string a, string b);
    int getTotalDeletion();

private:
    unsigned int totalDeletion;
};

MakeItAnagram::MakeItAnagram()
{
    totalDeletion = 0;
}

MakeItAnagram::~MakeItAnagram()
{
}

int MakeItAnagram::getTotalDeletion()
{
    return totalDeletion;
}

void MakeItAnagram::inputString(string a, string b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int indexA = 0, indexB = 0;
    while (indexA < a.length() && indexB < b.length())
    {
        if (a.at(indexA) == b.at(indexB)) {
            indexA++;
            indexB++;
        } else if (a.at(indexA) > b.at(indexB)) {
            indexB++;
            totalDeletion++;
        } else {
            indexA++;
            totalDeletion++;
        }
    }

    if (indexA < a.length()) {
        totalDeletion += (a.length() - indexA);
    }
    if (indexB < b.length()) {
        totalDeletion += (b.length() - indexB);
    }
}

int main(void)
{
    MakeItAnagram mia;

    string a, b;
    cin >> a;
    cin >> b;

    mia.inputString(a, b);

    cout << mia.getTotalDeletion() << endl;

    return 0;
}

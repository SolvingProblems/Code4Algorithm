#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SetPartialOrder {
    public:
    string compareSets(vector <int> a, vector <int> b) {
        int aIdx = 0, bIdx = 0;
        int count = 0;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        while (aIdx < a.size() &&
               bIdx < b.size()) {
            if (a.at(aIdx) == b.at(bIdx)) {
                aIdx++; bIdx++; count++;
            } else if (a.at(aIdx) > b.at(bIdx)) {
                bIdx++;
            } else {
                aIdx++;
            }
        }

        if (count != a.size() && count != b.size())
            return "INCOMPARABLE";
        else if (count == a.size() && count == b.size())
            return "EQUAL";
        else if (count < a.size())
            return "GREATER";

        return "LESS";
    }

    private:
};

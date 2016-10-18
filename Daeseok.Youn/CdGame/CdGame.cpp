#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Cdgame {
public:
    int rescount(vector<int> a, vector<int> b) {
        unordered_map<int, int> mapNum;

        int aTotal = 0;
        int bTotal = 0;
        int count = 0;

        for (int i = 0; i < a.size(); i++)
            aTotal += a.at(i);
        for (int i = 0; i < b.size(); i++)
            bTotal += b.at(i);

        for (int i = 0; i < a.size(); i++) {
            int production = 0;
            for (int j = 0; j < b.size(); j++) {
                production = (aTotal - a.at(i) + b.at(j)) *
                             (bTotal - b.at(j) + a.at(i));

                if (mapNum.find(production) == mapNum.end()) {
                    count++;
                    mapNum[production] = 1;
                }
            }
        }

        return count;
    }
private:
};

int main(void)
{
    vector<int> a = {3, 3, 4, 1};
    vector<int> b = {2, 2, 2, 100};

    Cdgame cd;

    cout << cd.rescount(a, b) << endl;
    return 0;
}


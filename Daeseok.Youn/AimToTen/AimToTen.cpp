#include <iostream>
#include <vector>

using namespace std;

class AimToTen {
public:
    int need(vector<int> marks) {
        if (marks.size() > 50 || marks.size() < 1)
            return 0;

        double average = 0.0;
        double total = 0;
        int i;

        for (i = 0; i < marks.size(); i++)
            total += marks.at(i);

        average = total / marks.size();

        i = 0;
        while (average < 9.5) {
            total += 10;
            ++i;
            average = total / (marks.size() + i);
        }

        return i;
    }
};

int main(void)
{
    int input[50] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> vec;

    for (int i = 0; i < 50; i++)
        vec.push_back(input[i]);

    AimToTen at;

    cout << at.need(vec) << endl;

    return 0;
}

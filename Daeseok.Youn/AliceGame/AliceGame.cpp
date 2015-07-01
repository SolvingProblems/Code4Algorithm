
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class AliceGame {
public:
    long long findMinimumValue(long long x, long long y)
    {
        long long total = x + y;
        long long end = (long long)sqrt(total);
        int i  = end;

        if (end * end != total || x == 2 || y == 2)
            return - 1;

        if (x == 0)
            return 0;

        int count = 0;
        long long value = 0;
        while (i >= 1) {
            count++;
            value += (2 * i) - 1;

            if (value >= x && (value % 2) == (x % 2))
                return count;
            i--;
        }

        return -1;

     }
};

int main(void)
{
    AliceGame ag;

    //cout << ag.findMinimumValue(9, 9) << endl;
    cout << ag.findMinimumValue(500000, 500000) << endl;
    //cout << ag.findMinimumValue(17, 8) << endl;

    return 0;
}

/*
 * TopCoder
 * Name : AddMultiply
 */
#include <iostream>
#include <vector>

using namespace std;

class AddMultiply {
public:
    vector<int> makeExpression(int y)
    {
        int x1 = 2, x2;
        vector<int> result;
        if (y == 0) {
            x1 = 2;
        } else {
            for (int i = 2; i < y/2; i++) {
                if (y % i == 0) {
                    x1 = i;
                    break;
                }
            }
        }

        result.push_back(x1);
        x2 = x1 + 1;

        if (x1 * x2 == y ||
           (y - (x1 * x2) == 1))
            x2 += 1;

        result.push_back(x2);
        result.push_back((y - (x1 * x2)));

        return result;
    }
};

int main(void)
{
    AddMultiply am;
    vector<int> result;

    result = am.makeExpression(6);
    // result {2, 4, -2}

    result = am.makeExpression(11);
    // result {2, 3, 5}

    return 1;
}

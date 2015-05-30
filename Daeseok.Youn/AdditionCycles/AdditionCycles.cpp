/*
 * TopCoder
 * Name : AdditionCycles 250 point
 */
#include <iostream>

using namespace std;

class AdditionCycles {
public:
    int cycleLength(int n) {
        if (n < 0 || n > 99)
            return 0;

        int underTen = 0;
        int overTen = 0;
        int total = 0;
        int newNumber = 0;

        if (n == 0)
            return 1;

        newNumber = n;

        while (true) {
            underTen = newNumber % 10;
            overTen = newNumber - underTen;

            newNumber = (underTen * 10) +
                (((overTen/10) + underTen) % 10);

            if (n == newNumber)
                break;

            total++;
        }

        return ++total;
    }
private:
};

int main(void)
{
    AdditionCycles ac;

    cout << ac.cycleLength(26) << endl;
    cout << ac.cycleLength(55) << endl;
    cout << ac.cycleLength(0) << endl;
    cout << ac.cycleLength(71) << endl;
    return 0;
}

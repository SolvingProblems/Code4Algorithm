#include <iostream>

using namespace std;

class AdditionGame {
public:
    int getMaximumPoints(int A, int B, int C, int N) {
        if (A < 1 || A > 50 || B < 1 || B > 50 ||
            C < 1 || C > 50 || N < 1 || N > 150)
            return 0;

        int point = 0;
        int choosen = 0;

        while (N > 0) {
            if (A == 0 && B == 0 && C == 0)
                break;
            choosen = (A > B) ? ((A > C) ? A : C) :
                                ((B > C) ? B : C);

            point += choosen;

            if (choosen == A)
                A--;
            else if (choosen == B)
                B--;
            else
                C--;

            N--;
        }

        return point;
    }
};

int main(void)
{
    AdditionGame ag;

    cout << ag.getMaximumPoints(3, 4, 5, 3) << endl;
    cout << ag.getMaximumPoints(1, 1, 1, 8) << endl;
    cout << ag.getMaximumPoints(3, 5, 48, 40) << endl;
    cout << ag.getMaximumPoints(36, 36, 36, 13) << endl;
    cout << ag.getMaximumPoints(8, 2, 6, 13) << endl;

    return 0;
}

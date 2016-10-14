#include <iostream>
#include <string>

using namespace std;

class CoinFlipsDiv2 {
public:
    int countCoins(string state) {
        int count  = 0;
        int size = state.size();

        bool bState[50] = {false};

        for (int i = 0; i < size; i++) {
            if (state[i] == 'H')
                bState[i] = true;
        }

        for (int j = 0; j < size; j++) {
            if ((j < size - 1 && (bState[j] ^ bState[j+1])) ||
                (j > 0 && (bState[j - 1] ^ bState[j]))) {
                count++;
            }
        }
        return count;
    }
private:
};

int main(void)
{
    CoinFlipsDiv2 cf;
    string a = "HHHTTTHHHTTTHTHTH";

    cout << cf.countCoins(a) << endl;
    return 0;
}

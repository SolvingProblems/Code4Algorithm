#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class BearNSWE {
public:
    double totalDistance(vector<int> a, string dir) {
        double x = 0.0L;
        double y = 0.0L;
        double total = 0.0L;

        for (int i = 0; i < dir.size(); i++) {
            switch(dir[i]) {
                case 'E':
                    x += a[i];
                    break;
                case 'W':
                    x -= a[i];
                    break;
                case 'N':
                    y += a[i];
                    break;
                case 'S':
                    y -= a[i];
                    break;
            }

            total += a[i];
        }

        total += sqrt(x * x + y * y);

        return total;
    }

private:
};

int main(void)
{
    //vector<int> a = {1, 3, 3};
    //vector<int> a = {10, 10, 10, 10};
    vector<int> a = {10,10,10,15,8,20,5};
    string dir = "NEWEWWE";
    BearNSWE b;

    cout << b.totalDistance(a, dir) << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Aircraft {
public:
    string nearMiss(vector<int> p1, vector<int> v1,
                    vector<int> p2, vector<int> v2, int R)
    {
        if (p1.size() != 3 || v1.size() != 3 || p2.size() != 3 ||
            v2.size() != 3) {
            return "NO";
        }

        double time = 0.0;
        double currDistance = 0.0;
        double preDistance = 0.0;
        int growingCount = 0;
        int yesOrNo = false;
        double RSquare = pow(R, 2);

        while (true) {

            currDistance = getDistance(p1, v1, p2, v2, time);
            time += 0.01;

            currDistance = trunc(currDistance * 1000) / 1000;

            if (RSquare >= currDistance) {
                yesOrNo = true;
                break;
            }

            if (preDistance != 0.0 &&
                currDistance > preDistance)
                growingCount++;

            preDistance = currDistance;

            if (growingCount > 1000) {
                cout << "growing count : " << growingCount << endl;
                break;
            }
        }

        return yesOrNo ? "YES" : "NO";
    }

    double getDistance(vector<int> p1, vector<int> v1,
                     vector<int> p2, vector<int> v2, double time)
    {
        int i = 0;
        double result = 0.0;
        vector<double> movedP1, movedP2;

        for (i = 0; i < p1.size(); i++) {
            movedP1.push_back((double)p1.at(i) + (double)v1.at(i) * time);
            movedP2.push_back((double)p2.at(i) + (double)v2.at(i) * time);
        }

        for (i = 0; i < p1.size(); i++) {
            result += pow((movedP1.at(i) - movedP2.at(i)), 2);
        }

        return result;
    }
};

int main(void)
{
    Aircraft ac;
/*
    int p1[3] = {15, 50, 5};
    int v1[3] = {25, 1, 0};

    int p2[3] = {161, 102, 9};
    int v2[3] = {-10, -10, -1};
*/

    /*
    int p1[3] = {0, 0, 0};
    int v1[3] = {-2, 2, 0};

    int p2[3] = {9, 0, 5};
    int v2[3] = {2, 2, 0};
    int R = 5;
    */

    /*
    int p1[3] = {-2838,-7940,-2936};
    int v1[3] = {1, 1, -2};

    int p2[3] = {532,3850,9590};
    int v2[3] = {1, 0, -3};

    int R = 3410;
    */

    /*
    int p1[3] = {-7163,-371,-2459};
    int v1[3] = {-59,-41,-14};

    int p2[3] = {-2398,-426,-5487};
    int v2[3] = {-43,27,67};

    int R = 5410;
    */

    /*
    int p1[3] = {3731,8537,5661};
    int v1[3] = {-70,71,32};

    int p2[3] = {8701,-1886,-5115};
    int v2[3] = {28,-13,7};

    int R = 9766;
    */

    /*
    int p1[3] = {-8509,9560,345};
    int v1[3] = {-89,-33,62};

    int p2[3] = {-5185,-1417,2846};
    int v2[3] = {-58,24,26};

    int R = 8344;
    */

    /*
    int p1[3] = {0,0,0};
    int v1[3] = {1,0,0};

    int p2[3] = {0,0,1};
    int v2[3] = {0,1,0};

    int R = 1;
    */
/*
    int p1[3] = {0, 2856, -2856};
    int v1[3] = {98, -9996, 9996};

    int p2[3] = {10000, -2856, 2856};
    int v2[3] = {98, 9996, -9996};

    int R = 10000;
    */

    /*
    int p1[3] = {-8509, 9560, 345};
    int v1[3] = {-89, -33, 62};

    int p2[3] = {-5185, -1417, 2846};
    int v2[3] = {-58, 24, 26};
    int R = 8343;
    */
    // {{0, 1, -1}, {3, -3, 3}, {1, -1, 1}, {3, 3, -3}, 1}

    /*
    int p1[3] = {0, 1, -1};
    int v1[3] = {3, -3, 3};

    int p2[3] = {1, -1, 1};
    int v2[3] = {3, 3, -3};
    int R = 1;
    */

    // {{-7163, -371, -2459}, {-59, -41, -14}, {-2398, -426, -5487}, {-43, 27, 67}, 5410}

    /*
    int p1[3] = {-7163, -371, -2459};
    int v1[3] = {-59, -41, -14};

    int p2[3] = {-2398, -426, -5487};
    int v2[3] = {-43, 27, 67};
    int R = 5410;
    */
    // {{0, 2856, -2856}, {98, -9996, 9996}, {10000, -2856, 2856}, {98, 9996, -9996}, 10000}

    int p1[3] = {0, 2856, -2856};
    int v1[3] = {98, -9996, 9996};

    int p2[3] = {10000, -2856, 2856};
    int v2[3] = {98, 9996, -9996};
    int R = 10000;

    vector<int> p1vec;
    vector<int> p2vec;
    vector<int> v1vec;
    vector<int> v2vec;

    for (int i = 0; i < 3; i++) {
        p1vec.push_back(p1[i]);
        p2vec.push_back(p2[i]);
        v1vec.push_back(v1[i]);
        v2vec.push_back(v2[i]);
    }

    cout << ac.nearMiss(p1vec, v1vec, p2vec, v2vec, R) << endl;

    return 0;
}

/*
 * TopCoder
 * Name : ApplesAndOrangesEasy (250 point)
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ApplesAndOrangesEasy {
public:
    int maximumApples(int N, int K, vector<int> info);
    int getApplesCount(vector<int> map);
    void rollbackApple(vector<int> &fruit, int start,
                       int end, int rbCount);
    void printVector(vector<int> map);
private:
};

int ApplesAndOrangesEasy::getApplesCount(vector<int> map)
{
    int count = 0;

    for (int i = 0; i < map.size(); i++)
        if (map.at(i) == 1 || map.at(i) == 3)
            count++;

    return count;
}

void ApplesAndOrangesEasy::rollbackApple(vector<int> &fruit, int start,
                                         int end, int rbCount)
{
    while (rbCount > 0 && start < end) {
        if (fruit.at(start) == 3) {
            fruit.at(start++) = 2;
            rbCount--;
        }
    }
}

int ApplesAndOrangesEasy::maximumApples(int N, int K,
                                        vector<int> info)
{
    if (N < 2 || N > 2000 || K < 2 || K > N) {
        return 0;
    }

    vector<int> fruitMap(N, 0);
    int maxApples = 0;
    int i, toN = 0;

    for (i = 0; i < info.size(); i++)
        fruitMap.at(info.at(i) - 1) = 1;

    while (toN < N) {
        int count = 0;
        for (i = toN; i < toN + K; i++)
            if (i < N && fruitMap.at(i) == 1)
                    count++;

        if (count > (K/2)) {
            rollbackApple(fruitMap, toN,
                          toN + K - 1, count - (K/2));
            toN++;
            continue;
        }

        for (i = toN; i < toN + K; i++) {
            if (!(i < N))
                break;
            if (count < (K/2) && fruitMap.at(i) != 2
                && fruitMap.at(i) != 1) {
                    fruitMap.at(i) = 3;
                    count++;
            } else if (fruitMap.at(i) != 1) {
                fruitMap.at(i) = 2;
            }
        }
        toN++;
    }

    maxApples = getApplesCount(fruitMap);
    return maxApples;
}

void ApplesAndOrangesEasy::printVector(vector<int> map)
{
    for (int i = 0; i < map.size(); i++)
        cout << " " << map.at(i);

    cout << endl;
}

int main(void)
{
    ApplesAndOrangesEasy a;
    vector<int> info;

    cout << a.maximumApples(3, 2, info) << endl;

    info.push_back(3);
    info.push_back(8);
    cout << a.maximumApples(10, 3, info) << endl;

    vector<int> info2;

    info2.push_back(1);
    info2.push_back(4);
    cout << a.maximumApples(9, 4, info2) << endl;

    vector<int> info3;
    info3.push_back(2);
    info3.push_back(4);
    cout << a.maximumApples(9, 4, info3) << endl;

    vector<int> info4;
    info4.push_back(3);
    info4.push_back(2);
    info4.push_back(9);
    info4.push_back(1);
    info4.push_back(15);
    info4.push_back(23);
    info4.push_back(20);
    info4.push_back(19);
    cout << a.maximumApples(23, 7, info4) << endl;
}

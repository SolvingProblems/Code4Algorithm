/*
 * Topcoder
 * Name : ANDEquation (250 point)
 */
#include <iostream>
#include <vector>

using namespace std;

class ANDEquation {
public:
    int restoreY(vector<int> A);
    bool isUsed(vector<int> used, int Y);
    vector<int> removeDupOperator(vector<int> input,
                                  int resultIndex);
    void printVector(vector<int> map);
private:
};

bool ANDEquation::isUsed(vector<int> used, int Y)
{
    for (int i = 0; i < used.size(); i++)
        if (used.at(i) == Y)
            return true;
    return false;
}

vector<int> ANDEquation::removeDupOperator(vector<int> input,
                                           int resultIndex)
{
    vector<int> result;
    bool added = false;

    for (int i = 0; i < input.size(); i++) {
        if (i == resultIndex)
            continue;
        if (input.at(i) != input.at(resultIndex))
            result.push_back(input.at(i));
        else if (!added) {
            result.push_back(input.at(i));
            added = true;
        }
    }

    return result;
}

int ANDEquation::restoreY(vector<int> A)
{
    int size = A.size();
    if (size < 2 || size > 50)
        return -1;

    int count = 0;
    bool found = false;
    int result;
    vector<int> used;

    while(count < size) {
        result = A.at(count);
        int bitwised = 0;
        vector<int> operators;

        if (isUsed(used, result)) {
            count++;
            continue;
        }

        used.push_back(result);
        operators = removeDupOperator(A, count);
        bitwised = operators.at(0);
        for (int i = 1; i < operators.size(); i++)
                bitwised &= operators.at(i);

        if (result == bitwised) {
            found = true;
            break;
        }
    }

    return found ? result : -1;
}

void ANDEquation::printVector(vector<int> map)
{
    for (int i = 0; i < map.size(); i++)
        cout << " " << map.at(i);

    cout << endl;
}

static void initializeVector(vector<int>& vec, int *input, int n)
{
    vec.insert(vec.end(), &input[0], &input[n]);
}

int main(void)
{
    ANDEquation andOp;
    //int input[] = {1, 3, 5};
    //int input[] = {31, 7, 7};
    //int input[] = {191411,256951,191411,191411,191411,256951,195507,191411,192435,191411, 191411,195511,191419,191411,256947,191415,191475,195579,191415,191411, 191483,191411,191419,191475,256947,191411,191411,191411,191419,256947, 191411,191411,191411};
    //int input[] = {1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211};
    int input[] = {1, 1};
    //int input[] = {1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0, 0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1};
    vector<int> a;
    initializeVector(a, input, sizeof(input) / sizeof(int));

    cout << andOp.restoreY(a) << endl;
}

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

static void printVec(vector<int>);
static int printedCount;

class AfraidOfEven {
public:
    vector<int> restoreProgression(vector<int> seq)
    {
        if (seq.size() < 4 || seq.size() > 50)
            return vector<int>();

        int sizeSeq = seq.size();
        int i = 1;
        int diff = 0, diffSave = 0;

        while (i < sizeSeq - 1) {
            int temp = 0;

            temp = (seq.at(i+1) + seq.at(i-1))/2;
            if (temp % seq.at(i) == 0 &&
                temp != seq.at(i)) {
                seq.at(i) = temp;
                diff = temp - seq.at(i-1);
            }
            i++;
        }

        if (diff != 0 && seq.at(0) + diff != seq.at(1))
            seq.at(0) = seq.at(1) - diff;
        if (diff != 0 &&
            seq.at(sizeSeq - 1) - diff != seq.at(sizeSeq - 2))
            seq.at(sizeSeq - 1) = seq.at(sizeSeq - 2) + diff;

        return seq;
    }
};

static void printVec(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << " ";

    cout << endl;
    if (++printedCount == 10)
        exit(1);
}

int main(void)
{
    //int input [] = {1, 1, 3, 1, 5};
    int input [] = {9, 7, 5, 3, 1};
    //int input [] = {7, 47, 5, 113, 73, 179, 53};

    vector<int> inputVec;
    vector<int> outputVec;

    AfraidOfEven ae;

    for (int i = 0; i < 5; i++) {
        inputVec.push_back(input[i]);
    }

    outputVec = ae.restoreProgression(inputVec);

    for (int i = 0; i < 5; i++) {
        cout << outputVec.at(i) << " ";
    }
    cout << endl;

    return 0;
}

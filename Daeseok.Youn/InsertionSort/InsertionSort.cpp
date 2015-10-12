#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class RunTimeInsertion {
public:
    RunTimeInsertion()
    {
        shifted = 0;
    }

    void InsertionSort(int *arr, int arrSize)
    {
        int i;

        for (i = 1; i < arrSize; i++) {
            int keyVal = arr[i];

            int j = i - 1;

            while (j >= 0 && keyVal < arr[j]) {
                shifted++;
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = keyVal;
        }

        printArr(arr, arrSize);
    }

    void printArr(int *arr, int arrSize)
    {
        for (int i = 0; i < arrSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    unsigned int getShifedCount()
    {
        return shifted;
    }

private:
    unsigned int shifted;
};

int main(void)
{
    RunTimeInsertion rti;
    int arr[5] = {2, 1, 3, 1, 2};
    rti.InsertionSort(arr, 5);
    cout << "shifted : " << rti.getShifedCount() << endl;

    return 0;
}

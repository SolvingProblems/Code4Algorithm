#include <iostream>

using namespace std;

class LeftRotation {
public:
    LeftRotation() {
        size = 0;
        idx = 0;
    };

    ~LeftRotation() {
        if (oriArr)
            delete oriArr;

        size = 0;
        idx = 0;
    };

    void inputData(int num) {
        oriArr[idx++] = num;
    }

    void leftRotate(int d) {
        int *newArr = new int[size];

        int newIdx = (size - 1) - (d % size);
        int lastIdx = size - 1;
        int loop = size;

        while (--loop >= 0) {
            newArr[newIdx % size] = oriArr[lastIdx % size];
            newIdx++;

            lastIdx++;
        }

        for (int i = 0; i < size; i++) {
            cout << newArr[i] << " ";
        }
        cout << endl;

        delete newArr;
    }

    int setSizeArr(int n) {
        oriArr = new int[n];
        size = n;
    }

    void clearArr() {
        delete oriArr;
    }

private:
    int *oriArr;
    unsigned int size;
    unsigned int idx;
};

int main(void)
{
    int size = 0, rotate = 0;
    LeftRotation lr;

    cin >> size >> rotate;
    lr.setSizeArr(size);

    for (int i = 0; i < size; i++) {
        int temp = 0;
        cin >> temp;
        lr.inputData(temp);
    }
    lr.leftRotate(rotate);

    return 0;
}

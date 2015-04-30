#include <iostream>

using namespace std;

static int xPos[4] = {0, 1, 0, -1};
static int yPos[4] = {1, 0, -1, 0};

class snailArray {
    public:
        snailArray();
        // N * N array
        snailArray(unsigned int size);
        // N * M array
        snailArray(unsigned int nSize, unsigned int mSize);
        ~snailArray();
        void initializeArray(void);
        void printArray(void);
        void makesArray(void);
    private:
        unsigned int nArraySize;
        unsigned int mArraySize;
        int **snail;
};

snailArray::snailArray(void)
{
    /*
     * The default size of array is 5
     * 5 * 5 array
     */
    nArraySize = 5;
    mArraySize = 5;

}

snailArray::snailArray(unsigned int size)
{
    nArraySize = size;
    mArraySize = size;
}

snailArray::snailArray(unsigned int nSize, unsigned int mSize)
{
    nArraySize = nSize;
    mArraySize = mSize;
}

snailArray::~snailArray(void)
{
    for (int i = 0; i < mArraySize; i++) {
        delete [] snail[i];
    }

    delete[] snail;
}

void snailArray::makesArray(void)
{
    int i, j;
    int pos = 0;
    int n = 1, m = 1;
    int num = 1;

    while ( num <= ((nArraySize - 2) * (mArraySize - 2))) {
        if (num != 1) {
            n = n + xPos[pos];
            m = m + yPos[pos];
        }

        if (snail[n][m] != 0) {
            n = n - (xPos[pos]);
            m = m - (yPos[pos]);
            pos = ++pos % 4;
            continue;
        }

        snail[n][m] = num++;
    }
}

void snailArray::initializeArray(void)
{
    int i, j;

    /*
     * for making wall of this Array.
     * Sample
     * N = 2
     * -1 -1 -1 -1
     * -1  0  0 -1
     * -1  0  0 -1
     * -1 -1 -1 -1
     */
    nArraySize = nArraySize + 2;
    mArraySize = mArraySize + 2;

    snail = new int*[nArraySize];
    for (i = 0; i < mArraySize; i++) {
        snail[i] = new int[mArraySize];
    }

    for (i = 0; i < nArraySize; i++) {
        for (j = 0; j < mArraySize; j++) {
            if (i == 0 || j == 0 ||
                i == nArraySize - 1 ||
                j == mArraySize -1)
                snail[i][j] = -1;
            else
                snail[i][j] = 0;
        }
    }
}

void snailArray::printArray(void)
{
    cout << "Result : Snail Array - " << endl;
    cout << "n : " << nArraySize << " m : " << mArraySize << endl;
    for (int i = 0; i < nArraySize; i++) {
        for (int j = 0; j < nArraySize; j++) {
            if (snail[i][j] != -1)
                cout << snail[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(void)
{
    /*
     * snailArray initialize
     * snailArray snail; ==> default array 5 x 5
     * snailArray snail(6) ==> array 6 x 6
     * snailArray snail(4,5) ==> array 4 x 5
     */
    snailArray snail(4, 5);
    snail.initializeArray();
    snail.makesArray();
    snail.printArray();

    return 0;
}

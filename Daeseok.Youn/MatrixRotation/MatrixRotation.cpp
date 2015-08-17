#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

static int totalRotatedElement = 0;
static int totalArraySize = 0;


int **makesArr(int m, int n)
{
    int i, j;
    int **mat = new int*[m];
    for (i = 0; i < m; i++) {
        mat[i] = new int[n];
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            mat[i][j] = temp;
        }
    }

    return mat;
}

void rotateLocalArray(int *arr, int arrSize, int r)
{
    if (arrSize <= 0) {
        return;
    }

    int *tempArr = new int[arrSize];
    memcpy(tempArr, arr, sizeof(int) * arrSize);

    while (arrSize <= r) {
        r -= arrSize;
    }

    for (int i = 0; i < arrSize; i++) {
        int index = i - r;

        if (index < 0) {
            index = arrSize + index;
        }
        arr[index] = tempArr[i];
    }

    if (tempArr) {
        delete [] tempArr;
        tempArr = NULL;
    }
}

static int xMov[4] = {1, 0, -1, 0};
static int yMov[4] = {0, 1, 0, -1};

void applyArrayToMat(int *arr, int arrLength,
                     int **mat, int s, int m, int n)
{
    int i, dir = 0;
    int xPos = s, yPos = s;

    for (i = 0; i < arrLength; i++)
    {
        mat[xPos][yPos] = arr[i];

        if ((xPos == (m + s - 1) && yPos == (n + s - 1)) ||
            (xPos == s && yPos == (n + s - 1)) ||
            (yPos == s && xPos == (m + s - 1))) {
            dir++;
        }

        xPos = xPos + yMov[dir];
        yPos = yPos + xMov[dir];
    }
}

void rotateArray(int **mat, int s, int m, int n, int r)
{
    int arrLength = (m * n) -
                    ((m - 2 < 0 ? 0 : m - 2) *
                     (n - 2 < 0 ? 0 : n - 2));

    if (arrLength <= 1 || totalArraySize == totalRotatedElement)
        return;

    totalRotatedElement += arrLength;
    int *arr = new int[arrLength];

    int i, dir = 0;
    int xPos = s, yPos = s;

    for (i = 0; i < arrLength; i++)
    {
        arr[i] = mat[xPos][yPos];

        if ((xPos == (m + s - 1) && yPos == (n + s - 1)) ||
            (xPos == s && yPos == (n + s - 1)) ||
            (yPos == s && xPos == (m + s - 1))) {
            dir++;
        }

        xPos = xPos + yMov[dir];
        yPos = yPos + xMov[dir];
    }

    rotateLocalArray(arr, arrLength, r);
    applyArrayToMat(arr, arrLength, mat, s, m, n);

    if (arr) {
        delete [] arr;
        arr = NULL;
    }

    rotateArray(mat, s + 1, m - 2, n - 2, r);
}

void printMatrix(int **mat, int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void release(int** mat, int m, int n)
{
    for (int i = 0; i < m; i++)
        delete [] mat[i];
    delete [] mat;
}

int main() {

    int m, n, r;
    cin >> m >> n >> r;

    int **mat;
    int **ret;
    mat = makesArr(m, n);

    totalArraySize = m * n;

    rotateArray(mat, 0, m, n, r);

    printMatrix(mat, m, n);
    release(mat, m, n);
    return 0;
}


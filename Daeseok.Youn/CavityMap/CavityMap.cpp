#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int **makeSquare(int n)
{
    int **square = new int*[n];
    int i, j;
    for (i = 0; i < n; i++)
        square[i] = new int[n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            square[i][j] = (int)(temp - '0');
            //cout << "square [" << i << "][" << j << "] : " << square[i][j] << endl;
        }
    }
    return square;
}

void createCavityMap(int **square, int n)
{
    int i, j;

    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            int curr = square[i][j];
            if (square[i - 1][j] == -1 || square[i + 1][j] == -1 ||
                square[i][j - 1] == -1 || square[i][j + 1] == -1)
                continue;

            if (square[i - 1][j] < curr && square[i + 1][j] < curr &&
               square[i][j - 1] < curr && square[i][j + 1] < curr)
                square[i][j] = -1;
        }
    }
}

void printMap(int **square, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp = square[i][j];
            if (temp == -1)
                cout << 'X';
            else
                cout << temp;
        }
        cout << endl;
    }
}

void releaseMap(int **square, int n)
{
    for (int i = 0; i < n; i++)
       delete [] square[i];
    delete [] square;
}

int main() {

    int n = 0;
    cin >> n;

    int i, j;
    int **square;

    square = makeSquare(n);
    //cout << square[1][1] << endl;
    createCavityMap(square, n);
    printMap(square, n);

    releaseMap(square, n);
    return 0;
}


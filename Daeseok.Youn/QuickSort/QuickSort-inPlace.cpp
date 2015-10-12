#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << " ";
    cout << endl;
}

void printVecRange(vector<int> arr, int left, int right)
{
    for (int i = left; i < right; i++)
        cout << arr.at(i) << " ";
    cout << endl;
}

void swap(vector<int> &arr, int i, int q)
{
    if (i == q || i < 0 || q < 0 ||
        q >= arr.size())
        return;

    int temp = arr.at(i);
    arr.at(i) = arr.at(q);
    arr.at(q) = temp;
}

/*
 * partitioning algorithm refer from
 * http://me.dt.in.th/page/Quicksort/
 */
int partitioning(vector<int> &arr, int left, int right)
{
    int pivot = arr.at(right);
    int q = left;

    int i = left;

    for (; i < right; i++) {
        if (pivot > arr.at(i)) {
            swap(arr, i, q);
            q++;
        }
    }

    if (pivot < arr.at(q))
        swap(arr, q, right);

    return q;
}

void q_sort(vector<int> &arr, int left, int right)
{
    if (right - left < 2)
        return;

    int partIndex = 0;

    partIndex = partitioning(arr, left, right);
    printVector(arr);

    q_sort(arr, left, partIndex - 1);
    q_sort(arr, partIndex, right);
}

void quickSort(vector <int> &arr) {
   q_sort(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}

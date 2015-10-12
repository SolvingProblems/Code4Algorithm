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

    vector <int> arr(100);
    int temp[100] = {
    406,157,415,318,472,46,252,187,364,481,450,90,390,35,452,74,196,312,142,160,143,220,483,392,443,488,79,234,68,150,356,496,69,88,177,12,288,120,222,270,441,422,103,321,65,316,448,331,117,183,184,128,323,141,467,31,172,48,95,359,239,209,398,99,440,171,86,233,293,162,121,61,317,52,54,273,30,226,421,64,204,444,418,275,263,108,10,149,497,20,97,136,139,200,266,238,493,22,17,39};
    for(int i = 0; i < 100; ++i) {
        arr[i] = temp[i];
    }

    quickSort(arr);

    return 0;
}

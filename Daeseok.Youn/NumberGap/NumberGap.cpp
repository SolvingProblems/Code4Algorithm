#include <iostream>
#include <vector>

using namespace std;

void printNum(vector<int> a)
{
    bool num[101] = {0,};

    for (int i = 0; i < a.size(); i++)
        num[a.at(i)] = true;

    for (int i = 0; i < a.size(); i++) {

        cout << a.at(i);
        int idx = a.at(i);

        if (idx < 99 && num[idx + 1])
            cout << ",";
        else if (idx < 99)
            cout << "-";
    }

    cout << endl;
}

int main(void)
{
    int n;

    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    printNum(a);

    return 0;
}

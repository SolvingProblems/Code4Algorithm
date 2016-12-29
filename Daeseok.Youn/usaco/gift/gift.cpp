/*
ID: daeseok1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    map<string, int> mapGift;
    vector<string> names;

    int np = 0;
    int temp = 0;
    int money = -1;
    int friends = -1;

    fin >> np;
    temp = np;

    while (temp--) {
        string name;

        fin >> name;
        mapGift[name] = 0;
        names.push_back(name);
    }

    temp = np;

    while (temp--) {
        string giver;
        int split = 0;

        fin >> giver;
        fin >> money >> friends;

        mapGift[giver] -= money;
        if (friends != 0) {
            split = money / friends;
            mapGift[giver] += (money - (split * friends));
        }

        for (int i = 0; i < friends; i++) {
            string fri;

            fin >> fri;

            mapGift[fri] += split;
        }
    }

    for (int i = 0; i < names.size(); i++) {
        fout << names.at(i) << " " << mapGift[names.at(i)] << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

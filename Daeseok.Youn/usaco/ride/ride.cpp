/*
ID: daeseok1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    int aTotal = 1, bTotal = 1;
    fin >> a >> b;

    for (int i = 0; i < a.length(); i++) {
        aTotal *= (a.at(i) - 'A' + 1);
    }

    for (int j = 0; j < b.length(); j++) {
        bTotal *= (b.at(j) - 'A' + 1);
    }

    if ((aTotal % 47) == (bTotal % 47)) {
        fout << "GO\n";
    } else {
        fout << "STAY\n";
    }

    return 0;
}

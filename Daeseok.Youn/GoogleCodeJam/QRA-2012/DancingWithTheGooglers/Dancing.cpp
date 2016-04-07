#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int testCase;
    int casenum = 1;

    cin >> testCase;

    while (testCase-- > 0) {

       // start implementation
       int N, S, P;
       int maxGoogler = 0;

       cin >> N >> S >> P;

       for (int i = 0; i < N; i++) {
           int temp = 0;
           int remain = 0;
           int value = 0;

           cin >> temp;

           value = temp / 3;
           remain = temp % 3;

           switch(remain) {
           case 0:
               if (value >= P) {
                   maxGoogler++;
               } else if (value > 0 && S > 0 && value + 1 >= P) {
                   S--; maxGoogler++;
               }
               break;
           case 1:
               if (value + 1 >= P) {
                   maxGoogler++;
               }
               break;
           case 2:
               if (S > 0 && value + 2 >= P && value + 2 <= 10) {
                   S--; maxGoogler++;
               } else if (value + 1 >= P) {
                   maxGoogler++;
               }
           }
       }

       cout << "Case #" << casenum++ << ": ";
       cout << maxGoogler << endl;
       // end
    }

    return 0;
}

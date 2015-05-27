/*
 * TopCoder
 * Name : AccountBalance
 * build on linux : g++ AccountBalance.cpp -std=c++0x
 * Avoid an error with "error: ‘stoi’ was not declared in this scope"
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class AccountBalance {
public:
    int processTransactions(int startingBalance,
                            vector<string> transactions)
    {
        if (startingBalance < 0 || startingBalance > 1000000 ||
            transactions.size() > 50)
            return 0;

        signed int remains = startingBalance;

        for (int i = 0; i < transactions.size(); i++)
            remains += getTransactionValue(transactions.at(i));

        return remains;
    }

    int getTransactionValue(string transAction)
    {
        int isPositive = 1;
        vector<string> typeAndBalance;
        string buf;
        stringstream ss(transAction);

        while (ss >> buf)
            typeAndBalance.push_back(buf);

        if (typeAndBalance.at(0) == "D")
            isPositive = -1;

        return (isPositive) * (stoi(typeAndBalance.at(1), NULL));
    }
};

/*
 * Test Case
 * startingBalance : 100
 * type and amount : {"C 1000", "D 500", "D 350"}
 */

int main(void)
{
    AccountBalance ab;
    string input [] = {"C 1000", "D 500", "D 350"};
    vector<string> typeAndAmount;
    unsigned int sizeInput = (sizeof(input) / sizeof(input[0]));

    for (int i = 0; i < sizeInput; i++)
        typeAndAmount.push_back(input[i]);

    int startingBalance = 100;

    cout << ab.processTransactions(startingBalance, typeAndAmount) << endl;

    return 0;
}

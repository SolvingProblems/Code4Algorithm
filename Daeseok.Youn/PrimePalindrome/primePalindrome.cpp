#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class prime {
public:
    prime(void) {};
    ~prime(void) {};
    bool isPrime(unsigned int num);
private:
};

bool prime::isPrime(unsigned int num)
{
    unsigned int sqrtResult;
    sqrtResult = (unsigned int)sqrt(num);

    for (int i = 2; i < sqrtResult; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

class palindrome {
public:
    palindrome(void) {};
    ~palindrome(void) {};
    bool isPalindrome(string str);
private:
};

bool palindrome::isPalindrome(string str)
{
    unsigned int strLength = str.length();
    for (int i = 0; i < strLength/2; i++)
        if (i != (strLength - 1 - i) &&
            str.at(i) != str.at(strLength - 1 - i))
            return false;
    return true;
}

/*
 * Reference : http://www.cplusplus.com/articles/D9j2Nwbp/
 * Convert Number To String and vice versa.
 */
template <typename T>
string NumberToString(T Number)
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

template <typename T>
T StringToNumber (const string &Text)
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}

static string isPrimePalindrome(string startNum)
{
    prime primeChecker;
    palindrome palindromeChecker;

    unsigned int number = StringToNumber<unsigned int>(startNum);

    if (number % 2 == 0) {
        number += 1;
        startNum = NumberToString<unsigned int>(number);
    }

    while (1) {
        if (palindromeChecker.isPalindrome(startNum) &&
            primeChecker.isPrime(number)) {
            break;
        }
        number += 2;
        startNum = NumberToString<unsigned int>(number);
    }

    return startNum;
}

int main(void)
{
    string input, output;

    cout << "Input number : ";
    cin >> input;

    output = isPrimePalindrome(input);

    cout << "result : " << output << endl;

    return 0;
}

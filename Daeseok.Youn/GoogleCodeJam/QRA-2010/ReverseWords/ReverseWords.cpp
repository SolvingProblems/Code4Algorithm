#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class ReverseWords {
public:
    void setWords(string input) {
        words = input;
    }

    void split(char ch) {
        size_t pos = words.find(ch);
        size_t initPos = 0;

        while (pos != string::npos) {
            splitWords.push_back(words.substr(initPos, pos - initPos + 1));
            initPos = pos + 1;

            pos = words.find(ch, initPos);
        }

        splitWords.push_back(words.substr(initPos,
                             std::max(initPos, words.size())));
    }

    void printReverseWords() {
        static int count = 1;
        int i = 0;
        cout << "Case #" << count++ << ": ";
        for (i = splitWords.size() - 1; i >= 0; i--) {
            string temp = splitWords.at(i);
            cout << temp.substr(0, temp.find_last_of(' '));

            if (i != 0)
                cout << " ";
        }

        cout << endl;
    }

    void reset() {
        splitWords.clear();
        words.clear();
    }

private:
    string words;
    vector<string> splitWords;
};

int main(void)
{
    int testCase = 0;

    ReverseWords rw;
    cin >> testCase;

    cin.get();

    while (testCase > 0) {
        string temp;
        getline(cin, temp);

        rw.setWords(temp);
        rw.split(' ');
        rw.printReverseWords();

        rw.reset();
        testCase--;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct str {
    char a;
    int idx;
};

bool compare(const struct str &a, const struct str &b) {
    return a.idx < b.idx;
}

class VerySecureEncryption {
public:
    string encrypt(string message, vector <int> key, int K) {
        vector<str> b;
        string res;

        for (int i = 0; i < message.size(); i++) {
            struct str temp;
            temp.a = message[i];
            temp.idx = i;

            b.push_back(temp);
        }

        for (int i = 0; i < K; i++) {
            for (int j = 0; j < key.size(); j++) {
                int idx = b[j].idx;
                b[j].idx = key[idx];
            }
        }

        sort(b.begin(), b.end(), compare);

        for (int i = 0; i < b.size(); i++)
            res.push_back(b[i].a);

        return res;
    }
private:
};

int main(void)
{
    string msg = "abcde";
    vector<int> key(5);
    key = { 4, 3, 2, 1, 0 };
    int K = 2;

    VerySecureEncryption vs;
    cout << vs.encrypt(msg, key, K) << endl;

    return 0;
}

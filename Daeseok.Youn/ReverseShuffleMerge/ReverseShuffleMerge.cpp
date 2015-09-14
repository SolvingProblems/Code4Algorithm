#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define ALPHABET_COUNT  26
#define INDEXTOCHAR(x)  ((char)(x + 'a'))

class ReverseShuffleMerge {
public:
    ReverseShuffleMerge(string in)
    {
        minCharIndex = ALPHABET_COUNT;
        input = in;
        for (int i = 0; i < ALPHABET_COUNT; i++)
            alphabet[i] = 0;

        countAlphabet();
    }

    void countAlphabet()
    {
        for (int i = 0; i < input.length(); i++) {
            int index = input.at(i) - 'a';

            alphabet[index]++;
            minCharIndex = (minCharIndex > index) ? index : minCharIndex;
        }

        for (int j = 0; j < ALPHABET_COUNT; j++) {
            halfAlphabet[j] = alphabet[j] / 2;
        }
    }

    string reverse(string ori)
    {
        string reverse;
        for (int i = ori.length() - 1; i >= 0; i--)
            reverse.push_back(ori.at(i));

        return reverse;
    }

    string getResult()
    {
        return findAString;
    }

    int getMinCharIndex() {
        int i = 0;
        for (i = 0; i < ALPHABET_COUNT; i++) {
            if (halfAlphabet[i] > 0)
                break;
        }
        return i;
    }

    int getMinCharIndex2() {
        int i = 0;
        for (i = 0; i < ALPHABET_COUNT; i++) {
            if (halfAlphabet[i] > 0 &&
                alphabet[i] > halfAlphabet[i])
                break;
        }
        return i;
    }


    void makeAString()
    {
        int i;
        int lastInput = 0;
        string temp;

        for (i = input.length() - 1; i >= 0; i--) {
            int index = input.at(i) - 'a';

            if (minCharIndex < index &&
                alphabet[index] > halfAlphabet[index] &&
                lastInput <= index) {
                --alphabet[index];
                continue;
            }

            if (halfAlphabet[index] > 0) {
                temp.push_back((char)(index + 'a'));
            }

            if (alphabet[index] > 0 || halfAlphabet[index] > 0) {
                --alphabet[index];
                --halfAlphabet[index];
            }

            if (lastInput <= index || alphabet[index] <= halfAlphabet[index]) {
                drainTempChars(temp, lastInput < index ? lastInput : index);
                lastInput = index;
            }

            minCharIndex = getMinCharIndex();
        }
    }

    void clearResult()
    {
        minCharIndex = ALPHABET_COUNT;
        for (int i = 0; i < ALPHABET_COUNT; i++)
            alphabet[i] = 0;

        countAlphabet();

        findAString.clear();
    }

    void makeBString()
    {
        int i;
        int lastInput = 0;
        string temp;

        for (i = input.length() - 1; i >= 0; i--) {
            int index = input.at(i) - 'a';
            if (minCharIndex < index &&
                alphabet[index] > halfAlphabet[index] &&
                lastInput <= index) {
                --alphabet[index];
                continue;
            }

            if (halfAlphabet[index] > 0) {
                temp.push_back((char)(index + 'a'));
            }

            if (alphabet[index] > 0 || halfAlphabet[index] > 0) {
                --alphabet[index];
                --halfAlphabet[index];
            }

            if (lastInput <= index || alphabet[index] <= halfAlphabet[index]) {
                drainTempChars(temp, lastInput < index ? lastInput : index);
                lastInput = index;
            }

            minCharIndex = getMinCharIndex2();
        }
    }

    void drainTempChars(string &temp, int currIndex)
    {
        for (int i = 0; i < temp.length(); i++) {
            int index = (temp.at(i) - 'a');
            if (alphabet[index] <= halfAlphabet[index]) {
                findAString.push_back(temp.at(i));
                continue;
            }

            if ((temp.length() == 1 && currIndex < index) ||
                INDEXTOCHAR(currIndex) >= temp.at(i)) {
                findAString.push_back(temp.at(i));
            } else {
                ++halfAlphabet[index];
            }
        }

        temp.clear();
    }

private:
    int alphabet[ALPHABET_COUNT];
    int halfAlphabet[ALPHABET_COUNT];
    int minCharIndex;
    string input;
    string findAString;
};

int main(void)
{
    //ReverseShuffleMerge rsm("djjcddjggbiigjhfghehhbgdigjicafgjcehhfgifadihiajgciagicdahcbajjbhifjiaajigdgdfhdiijjgaiejgegbbiigida");
    ReverseShuffleMerge rsm("bdabaceadaedaaaeaecdeadababdbeaeeacacaba");
    //ReverseShuffleMerge rsm("sbcnzxqnrygkocahxjebvueaawwcythjdrhvizqsshgtwdolmillxpshxpxqrywkivceufclhydhshrklkphajbftuapiocjlcthfirhgaohfysqjolssbzhbovdstbyqdpnjbpfmgqrzfctcwcrztvgbegunarvecseoulabaonguckqbtrvuagreyclyjytpvozqdnhldlnsocenuzksawirgsbjobpldjdlrxbricrauuksbmecvvwagnnacaqghmjpzrlsvlpbbcuaddgvlhvuvkxexjcfhxrodmcwlrzyyiksuksshhonahsyzbbprwuitmoyoqurtqsaslevgvpfbzkkhgcnpjdpseuiylluvdetsqssbrxpiclxxvosuqipsqvvwsezhl");
    //ReverseShuffleMerge rsm("bbcbccbabcbabcbaaccccaaabcbcaacacbabbbbcabcbbbbacbcaccccbcccbccaaabcabacccbaccccbbababccbccacbaccacbcccacbaaacacbbcbaaabbabbaaccbbbabccbccacacacabaababbcbcccbbcacabcabbbccababbcccacccccabbcbcbbaabbaabacabaabbbbcccccccacabaacbbbbbcbbabccbacbaabccbabccbbabccbacccaaaababccbbbacaacaabcabbbabaabbcbcacbcabcabcacbabaaabbbcbbbcccaaacbcacccaabccabbcbbabbcaacabbcacabcbbaccaabbcccaaaaacbabbbccbbcccbaacaaccbccabaccbaabaacbaaaccbbcabbbacccaccaaccbcccbccacbaacbccbbaabbbaccbacaaabaaabcaacabcaccbbaaabcacacbaaacbccbabbbcbabbaaccccbcacaabacbbabbaccabccbacbabccbbaacacbacaccbacbbbaaabcaccabccaabccabbccbaacacbbbbccabcccaaabbcaccaaaaaaacccabcbaabccacaaaaacacacbbaaabbccaabccbaaccbbcabacaaaaabbbbbababacaaabbbcccbbbcacabaacabcbaaccbabbbabbaccacacaabcabbcaabbacaaacabbaccabcbcccccaacccaaacbcabbcbacabacbaccbccbbbbccbacabacabbbbbbbbccccbccccaabaabbcbacabaababcbbacbcabcccbabbcbcaacbaabbbccbbaccaccbbbccbacbccbcaccbccabacccbbccacbbcacaabaccbbccacbabaccaacbbbcacbbaccbcaaacbbabacacbaababbbacaabcccabbcbabccccaabcaaccbbbcbaababacbcaccaacabcbbbbcabbcccacbcbaccaabcccbcabcbaccbcbcccbccaacbccbaccacbccbabccbccaaaaaabcbacccbbbcbbacbacbabaacbbacacbbabccbccbcbbcbccaabaacccabbbbcbcbaccabcabacabccabbacccbabaccacabcbcbcacbabcccacbbaacbccaabcbaacaabaccaccbbcaabbbaabbbcbcabccabbabaccbbaccacccbabbbabaacbbbbaccaaaaabbcabbbbaabcbacbcccbacbcbbbacbcababbcbcbbbacaabbcaacaacbbbacabaacccaaccaacabbabcabccbbabccabacbccbaacacbacabbcaaccabaacccbcbcbccbbabacbcacbacaaaabbacacbcbbccbbbbccaacaabbabaacbbaaaababcccabcababccacbabbccaaccbccbbabaccacccbbacaaabcbaabbccccaababbcaabcabbccbbcbabcaabcbcbaccaaaaccbccacababbaacbaacbccbacabccabbbbbacbcbabacbaccbcabcbaabbcbcbbaccbabccababcbcbcbabbabbaabccacccbcabaccacbcbcbccbaacaabacbabccabaacbbabcbaccbcabcaaacacbaccccbcabbccccabcbaccabbbababbacabbacacbbaabaaaaababbcbbaabcbcacccbbbaabccaccabcbbbbbaababbbcaacbaaaaabbcbbabbaccbbacacbaaaabbcccbbcbcaacacbbaacaaabaacbaababbcaccaacbacabccabbabaaaacacabbabaabbaaacabccaabacaabcbaabbacaaaaacbbcbcabcacababcbabcbbbaacccbcbcacbbccbcacabcacbbbbcbabcbaaaacb");
    string result, result2;
    rsm.makeAString();

    // input bdabaceadaedaaaeaecdeadababdbeaeeacacaba
    // output aaaaaabaaceededecbdb
    //
    result = rsm.getResult();
    cout << result << endl;
    rsm.clearResult();
    cout << "--------------------------" << endl;
    rsm.makeBString();
    result2 = rsm.getResult();
    cout << result2 << endl;

    cout << "--------------------------" << endl;
    if (result <= result2)
        cout << result << endl;
    else
        cout << result2 << endl;

    return 0;
}

/*
 * TopCoder
 * Name : AccessChanger (250 point)
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AccessChanger {
public:
    vector<string> convert(vector<string> program);
    void replaceString(string &str, size_t limit,
                       const string& ori, const string& re);
};

void AccessChanger::replaceString(string &str, size_t limit,
                                  const string& ori, const string& re)
{
    size_t pos = 0;
    while ((pos = str.find(ori, pos)) != string::npos) {
        if (pos > limit)
            break;
        str.replace(pos, ori.length(), re);
        pos += re.length();
        limit--;
    }
}

vector<string> AccessChanger::convert(vector<string> program)
{
    if (program.size() > 50)
        return vector<string>();

    size_t commentedOutPos = 0;
    const char *commentedOut = "//";

    for (int i = 0; i < program.size(); i++) {
        commentedOutPos = program[i].find(commentedOut, 0);

        if (commentedOutPos == string::npos)
            commentedOutPos = program[i].length() - 1;

        replaceString(program[i], commentedOutPos, "->" , ".");
    }

    return program;
}

static void printVector(vector<string> map)
{
    for (int i = 0; i < map.size(); i++)
        cout << " " << map.at(i);

    cout << endl;
}

int main(void)
{
    AccessChanger ac;
    string programInput[] = {"Test* t = new Test();",
                             "t->a = 1;",
                             "t->b = 2;",
                             "t->go(); // a=1, b=2 --> a=2, b=3"};
    vector<string> program;
    vector<string> result;

    program.assign(programInput,
            programInput + (sizeof(programInput) / sizeof(programInput[0])));

    result = ac.convert(program);
    printVector(result);

    return 0;
}



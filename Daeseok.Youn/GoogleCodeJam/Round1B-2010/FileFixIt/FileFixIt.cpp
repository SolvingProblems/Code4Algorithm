#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class FileFixit {
public:
    FileFixit() {
        // make root directory
        mkRootDir("/");
    }

    typedef struct _dentry {
        vector<struct _dentry*> dnode;
        string dname;
    } dentry;

    void mkRootDir(string path) {
        root = new dentry;

        root->dname = path;
        makeCnt = 0;
    }

    void regCurrDir(string path) {
        mkdir(path, false);
    }

    void mkdir(string path, bool noCnt) {
        vector<string> splitedPath;
        int index = 0;
        dentry *temp = root;

        split(path, splitedPath, '/');

#if 0
        for (int i = 0; i < splitedPath.size(); i++)
            cout << "path : " << splitedPath.at(i) << " ";

        cout << endl;
#endif
        while (index < splitedPath.size()) {
            vector<dentry *> listDentry = temp->dnode;
            int i = 0;

#if 0
            cout << "temp dnode name : " << temp->dname;
#endif
            for (i = 0; i < listDentry.size(); i++) {
                string getName = listDentry.at(i)->dname;
                if (splitedPath.at(index) == getName) {
                    index++;
                    break;
                }
            }

            if (i == listDentry.size())
                break;
            temp = listDentry.at(i);
        }

        for (int j = index; j < splitedPath.size(); j++) {
            dentry *node = new dentry;

            node->dname = splitedPath.at(j);
            //cout << "added dname : " << node->dname << endl;
            temp->dnode.push_back(node);
            temp = node;
            if (noCnt)
                makeCnt++;
        }
    }

    void cleanDentry() {
        dentry *temp = root;
        vector<dentry*> stackEntry;

        do {
            for (int i = 0; i < temp->dnode.size(); i++) {
                stackEntry.push_back(temp->dnode.at(i));
             //   cout << "dir : " << temp->dnode.at(i)->dname << endl;
            }

            if (stackEntry.empty())
                break;

            delete temp;
            temp = NULL;
            temp = stackEntry.at(stackEntry.size() - 1);
            stackEntry.pop_back();
        } while (1);
        makeCnt = 0;
        mkRootDir("/");
    }

    void split(string words, vector<string>& splitWords, char ch) {
        size_t pos = words.find(ch);
        size_t initPos = 0;

        while (pos != string::npos) {
            string temp = words.substr(initPos, pos - initPos);
            if (temp.size() != 0)
                splitWords.push_back(temp);
            initPos = pos + 1;

            pos = words.find(ch, initPos);
        }

        splitWords.push_back(words.substr(initPos,
                             std::max(initPos, words.size())));
    }

    int getMkCnt() {
        return makeCnt;
    }

private:
    dentry *root;
    int makeCnt;
};

int main(void)
{
    int testCase;
    int reservedCnt;
    int mkdirCnt;
    int caseCnt = 1;
    FileFixit ffi;

    cin >> testCase;

    while (testCase-- > 0) {
        cin >> reservedCnt >> mkdirCnt;
        int i = 0;

        for (i = 0; i < reservedCnt; i++) {
            string temp;
            cin >> temp;
            ffi.mkdir(temp, false);
        }

        for (i = 0; i < mkdirCnt; i++) {
            string temp;
            cin >> temp;
            ffi.mkdir(temp, true);
        }

//        ffi.traverseDentry();

        cout << "Case #" << caseCnt++ << ": ";
        cout << ffi.getMkCnt() << endl;
        ffi.cleanDentry();
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AccessLevel {
    public:
        string canAccess(vector<int> rights, int minPermission) {
            if (rights.size() > 50 || rights.empty())
                return "";

            string hasPermission(rights.size(), 'D');

            for (int i = 0; i < rights.size(); i++)
                if (rights.at(i) >= minPermission)
                    hasPermission[i] = 'A';

            return hasPermission;
        }
};

/*
 * Test Case
 * rights : {0,1,2,3,4,5}
 * minPermisstion : 2
 */
int main(void)
{
    int rightsArray[] = {0,1,2,3,4,5};
    unsigned int sizeofArray = (sizeof(rightsArray)/sizeof(rightsArray[0]));
    vector<int> rights;

    for (int i = 0; i < sizeofArray; i++)
        rights.push_back(rightsArray[i]);

    int minPerm = 2;
    AccessLevel al;

    cout << al.canAccess(rights, minPerm) << endl;

    return 0;
}

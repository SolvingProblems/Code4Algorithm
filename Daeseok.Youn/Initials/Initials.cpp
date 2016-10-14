#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>

using namespace std;

class Initials
{
public:
    string getInitials(string name) {
#if 0
        bool space = true;

        string initials;
        int index = 0;

        for (int i = 0; i < name.size(); i++) {
            if (space && !isspace(name.at(i))) {
                initials += name.at(i);
                space = false;
            } else if (isspace(name.at(i))) {
                space = true;
            }
        }

        return initials;
#else
        size_t found = name.find_first_of(" ");

        string initials;
        initials += name.at(0);

        while (found != 0 && found != string::npos) {
            initials += name.at(found + 1);

            found = name.find_first_of(" ", found + 1);
        }

        return initials;
#endif
    };
private:
};

int main(void)
{
    Initials init;
    string a("john fitzgerald kennedy");

    cout << init.getInitials(a) << endl;

    return 0;
}

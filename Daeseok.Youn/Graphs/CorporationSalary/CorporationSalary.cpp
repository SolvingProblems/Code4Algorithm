#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CorporationSalary {
public:
    long totalSalary(vector<string> relations) {
        long total = 0;

        salary = new int[relations.at(0).size()];

        for (int i = 0; i < relations.at(0).size(); i++)
            salary[i] = 0;

        for (int i = 0; i < relations.size(); i++) {
            total += getSalary(i, relations);
        }

        delete salary;

        return total;
    }

    long getSalary(int i, vector<string> rel) {

        if (salary[i] == 0) {
            long lsalary = 0;
            string relation = rel[i];

            for (int j = 0; j < relation.size(); j++) {
                if (relation[j] == 'Y') {
                    lsalary += getSalary(j, rel);
                }
            }

            if (lsalary == 0) lsalary = 1;

            salary[i] = lsalary;
        }

    }
private:
    int *salary;
};

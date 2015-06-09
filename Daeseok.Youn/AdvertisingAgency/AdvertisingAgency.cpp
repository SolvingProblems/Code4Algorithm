#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class AdvertisingAgency {
public:
    int numberOfRejections(vector<int> requests) {
        int max = 0;
        int count = 0;
        int ordered = 0;

        sort(requests.begin(), requests.end());

        while(count < requests.size()) {
            int requestValue = requests.at(count);
            if (max < requestValue) {
                max = requestValue;
                ordered++;
            }
            count++;
        }

        return count - ordered;
    }
};

// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        auto cmp = [](const auto& prop1, const auto& prop2) {
            if (prop1[0] == prop2[0]) { return prop1[1] < prop2[1]; }
            return prop1[0] > prop2[0];
        };

        sort(properties.begin(), properties.end(), cmp);
        int result = 0;
        int maxDefense = properties.front()[1];

        for (int i = 1; i < properties.size(); ++i) {
            if (properties[i][1] < maxDefense) {
                ++result;
            } else if (properties[i][1] > maxDefense) {
                maxDefense = properties[i][1];
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
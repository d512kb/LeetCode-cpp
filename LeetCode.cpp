// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, size_t> rulesIndexes{ {"type", 0}, {"color", 1}, {"name", 2} };
        const size_t ruleIndex = rulesIndexes[ruleKey];

        int ans = 0;
        for (int i = 0; i < items.size(); ++i) {
            if (items[i][ruleIndex] == ruleValue) {
                ++ans;
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
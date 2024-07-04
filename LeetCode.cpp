// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<int64_t> dp(questions.size());
        auto dpIter = dp.rbegin();
        int64_t result = 0;

        for (auto iter = questions.rbegin(), iterEnd = questions.rend(); iter < iterEnd; ++iter, ++dpIter) {
            int64_t val = (*iter)[0];
            int steps = (*iter)[1];

            if (distance(dp.rbegin(), dpIter) > steps) {
                val += *prev(dpIter, steps + 1);
            }

            result = max(result, val);
            *dpIter = result;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    Solution sol;
    vector<vector<int>> v {{3,2 }, { 4,3 }, { 4,4 }, { 2,5 }};
    sol.mostPoints(v);

    PRINT_ELAPSED(timer);
    return 0;
}
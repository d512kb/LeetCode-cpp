// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if (x == 0) { return 0; }

        auto ans = numeric_limits<int>::max();
        multiset<int> previousValues;

        for (int j = x; j < nums.size(); ++j) {
            previousValues.insert(nums[j - x]);
            auto iter = previousValues.lower_bound(nums[j]);
            if (iter == previousValues.end()) { --iter; } else if (iter != previousValues.begin()) {
                ans = min(ans, abs(nums[j] - *prev(iter)));
            }

            ans = min(ans, abs(nums[j] - *iter));
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
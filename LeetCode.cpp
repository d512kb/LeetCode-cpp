// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sz = nums.size();
        vector<int> counts(2 * sz + 1, sz);
        counts[sz] = 0;
        int counter = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) { ++counter; } else { --counter; }

            counts[counter + sz] = min(counts[counter + sz], i + 1);
            ans = max(ans, i - counts[sz + counter] + 1);
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
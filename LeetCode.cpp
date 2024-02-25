// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check;

        for (int i = 0; i < nums.size(); ++i) {
            check.insert(nums[i]);
        }

        int maxLen = 0;

        while (!check.empty()) {
            int m = *check.begin();
            int v = m;
            int len = 0;

            while (check.erase(v--)) {
                ++len;
            }

            v = m + 1;

            while (check.erase(v++)) {
                ++len;
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

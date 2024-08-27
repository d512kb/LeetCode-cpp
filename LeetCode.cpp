// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int sz = nums.size() - 1;
        unordered_map<int, int> mp;

        for (int i = 0; i < sz; ++i) {
            if (++mp[nums[i] + nums[i + 1]] > 1) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
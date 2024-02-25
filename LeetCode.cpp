// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> metNums;

        for (int i = 0; i < nums.size(); ++i) {
            auto ins = metNums.emplace(nums[i], i);
            if (!ins.second) {
                if (i - ins.first->second <= k) {
                    return true;
                } else {
                    ins.first->second = i;
                }
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

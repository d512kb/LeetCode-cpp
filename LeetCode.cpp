// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int preLoot = 0;
        int loot = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int tmp = loot;
            loot = max(nums[i] + preLoot, loot);
            preLoot = tmp;
        }

        return loot;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

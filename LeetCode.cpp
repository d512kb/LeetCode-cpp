// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpCount = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i + nums[i] >= nums.size() - 1) {
                return jumpCount + 1; // last jump
            }

            int maxJumpIndex = i + 1;
            int maxJump = nums[maxJumpIndex] + 1; // count an extra step
            int jumpMaxIndex = i + nums[i];

            for (int j = maxJumpIndex, k = 1; j <= jumpMaxIndex; ++j, ++k) {
                if (nums[j] + k >= maxJump) {
                    maxJumpIndex = j;
                    maxJump = nums[maxJumpIndex] + k;
                }
            }

            i = maxJumpIndex - 1;
            ++jumpCount;
        }

        return jumpCount;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    vector<int> v{ 2,3,1,1,4 };
    sol.jump(v);

    PRINT_ELAPSED(timer);
    return 0;
}

// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = 1;

        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < steps) {
                ++steps;
            } else {
                steps = 1;
            }
        }

        return steps == 1;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}

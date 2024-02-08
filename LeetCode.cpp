// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int stepBack = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                ++stepBack;
            } else {
                nums[i - stepBack] = nums[i];
            }
        }

        return nums.size() - stepBack;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}

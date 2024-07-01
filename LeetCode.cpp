// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, z = 0, sz = nums.size(); i < sz; ++i) {
            if (nums[i]) {
                swap(nums[z++], nums[i]);
            }
        }
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
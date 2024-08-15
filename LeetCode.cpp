// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 0;
        int left = 0;
        int right = 0;
        bool c = false;

        for (int sz = nums.size(); right < sz; ++right) {
            if (nums[right] == 0) {
                while (c) {
                    if (nums[left++] == 0) {
                        c = false;
                    }
                }

                c = true;
            }

            len = max(len, right - left + 1);
        }

        return len - 1;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
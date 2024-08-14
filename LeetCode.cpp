// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0;

        for (int left = 0, right = 0, c = 0, sz = nums.size(); right < sz; ++right) {
            if (!nums[right]) {
                while (c == k) {
                    if (!nums[left++]) {
                        --c;
                    }
                }

                ++c;
            }

            len = max(len, right - left + 1);
        }

        return len;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
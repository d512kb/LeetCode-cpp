// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int ans = 0;

        for (int c = 2; c < sz; ++c) {
            int a = 0;
            int b = c - 1;

            while (a < b) {
                if (nums[a] + nums[b] > nums[c]) {
                    ans += b - a;
                    --b;
                } else {
                    ++a;
                }
            }
        }

        return ans;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
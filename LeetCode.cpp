// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                if (abs(i - start) < ans) {
                    ans = abs(i - start);
                }
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
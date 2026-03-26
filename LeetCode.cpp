// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        const int targetScore = nums[0] + nums[1];
        int ans = 0;

        for (int i = 0; i + 1 < nums.size() && nums[i] + nums[i + 1] == targetScore; i += 2) {
            ++ans;
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
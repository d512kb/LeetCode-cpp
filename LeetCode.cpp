// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + indexDifference; j < nums.size(); ++j) {
                if (abs(nums[i] - nums[j]) >= valueDifference) {
                    return { i, j };
                }
            }
        }

        return { -1, -1 };
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
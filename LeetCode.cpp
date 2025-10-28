// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto iter = nums.begin();
        int prevVal = 0;

        while (iter != nums.end()) {
            int frameSize = distance(iter, nums.end());

            if (*iter >= frameSize && frameSize > prevVal) {
                return frameSize;
            }

            prevVal = *iter;
            iter = upper_bound(iter, nums.end(), *iter);
        }

        return -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
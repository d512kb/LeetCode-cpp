// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int currentSeqLen = 1;
        int maxSeqLen = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                if (++currentSeqLen > maxSeqLen) {
                    maxSeqLen = currentSeqLen;
                }
            }
            else {
                currentSeqLen = 1;
            }
        }

        return maxSeqLen;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
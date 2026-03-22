// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prevRun = 1, currentRun = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++currentRun;
                if (currentRun >= 2 * k || (prevRun >= k && currentRun >= k)) { return true; }
            }
            else {
                prevRun = currentRun;
                currentRun = 1;
            }
        }

        return currentRun >= 2 * k || (prevRun >= k && currentRun >= k);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
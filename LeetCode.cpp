// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = 0;
        int large = 0;
        int ans = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > largest) {
                large = largest;
                largest = nums[i];
                ans = i;
            }
            else if (nums[i] > large) {
                large = nums[i];
            }
        }

        return largest >= large * 2 ? ans : -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
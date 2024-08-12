// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int result = 0;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum < k) {
                ++left;
            } else if (sum > k) {
                --right;
            } else {
                ++result;
                ++left;
                --right;
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int a = 0;
        int b = nums.size() - 1;
        int minVal = nums[0];

        while (a <= b) {
            int mid = (a + b) / 2;
            int n = nums[mid];
            minVal = min(minVal, n);

            if (nums[a] == nums[b]) {
                ++a;
                --b;
                continue;
            }

            if (n <= nums[b]) {
                b = mid - 1;
            } else {
                a = mid + 1;
            }
        }

        return minVal;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a = 0;
        int b = nums.size() - 1;

        while (a <= b) {
            int mid = (a + b) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[a] <= nums[mid]) {
                if (nums[a] <= target && target <= nums[mid]) {
                    b = mid - 1;
                } else {
                    a = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[b]) {
                    a = mid + 1;
                } else {
                    b = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

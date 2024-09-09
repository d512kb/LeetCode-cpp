// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a = 0;
        int b = nums.size() - 1;

        while (a < b) {
            int mid = (a + b) / 2;
            if (mid % 2) { --mid; }

            if (nums[mid] == nums[mid + 1]) {
                a = mid + 2;
            } else {
                b = mid;
            }
        }

        return nums[a];
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
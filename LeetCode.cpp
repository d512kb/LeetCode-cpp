// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int a = 0;
        int b = nums.size() - 1;
        int mid = 0;

        while (a < b) {
            mid = (a + b) / 2;

            if (nums[mid] < nums[b]) {
                b = mid;
            } else {
                a = mid + 1;
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

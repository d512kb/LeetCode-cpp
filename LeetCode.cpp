// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int a = 0;
        int b = nums.size() - 1;
        int mid = 0;

        while (a < b) {
            mid = (a + b) / 2;

            if (nums[mid + 1] > nums[mid]) {
                a = mid + 1;
            } else {
                b = mid;
            }
        }

        return a;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

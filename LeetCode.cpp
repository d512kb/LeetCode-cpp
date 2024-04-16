// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearchRecur(nums, target, 0, nums.size() - 1);
    }

    int searchInsertIter(vector<int>& nums, int target) {
        if (target < nums.front())
            return 0;
        else if (target > nums.back())
            return nums.size();

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        int val = 0;

        while (left <= right) {
            mid = (left + right) / 2;
            val = nums[mid];

            if (val < target) {
                left = mid + 1;
            } else if (target < val) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return left;
    }
private:
    int binarySearchRecur(vector<int>& nums, int target, int a, int b) {
        if (a > b)
            return a;

        int mid = (a + b) / 2;
        int val = nums[mid];

        if (val < target) {
            return binarySearchRecur(nums, target, mid + 1, b);
        } else if (target < val) {
            return binarySearchRecur(nums, target, a, mid - 1);
        }

        return mid;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        k = right - k + 1;
        mt19937 engine{ random_device()() };

        while (left < right) {
            int pivotPoint = uniform_int_distribution(left, right)(engine);
            swap(nums[pivotPoint], nums[right]);
            int pivot = nums[right];
            int i = left;
            int r = right;

            for (int j = left; j <= r; ++j) {
                if (nums[j] < pivot) {
                    swap(nums[i], nums[j]);
                    ++i;
                } else if (nums[j] > pivot) {
                    swap(nums[r], nums[j]);
                    --r;
                    --j; // for for
                }
            }

            if (k >= i && k <= r) {
                return nums[k];
            } else if (k > r) {
                left = r + 1;
            } else {
                right = i - 1;
            }
        }

        return nums[left];
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

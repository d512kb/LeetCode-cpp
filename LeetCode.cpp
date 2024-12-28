// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int diff = accumulate(nums2.begin(), nums2.end(), 0) - accumulate(nums1.begin(), nums1.end(), 0);

        if (diff == 0) { return 0; }
        if (diff < 0) {
            swap(nums1, nums2);
            diff = -diff;
        }

        vector<int> count(6);
        for (int n : nums1) { ++count[6 - n]; }
        for (int n : nums2) { ++count[n - 1]; }

        int result = 0;

        for (int i = 5; i > 0; --i) {
            result += count[i];
            diff -= i * count[i];

            if (diff <= 0) {
                result -= -diff / i;
                return result;
            }
        }

        return -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
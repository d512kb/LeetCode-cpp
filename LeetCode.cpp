// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1Set(nums1.begin(), nums1.end());
        unordered_set<int> nums2Set(nums2.begin(), nums2.end());

        int ans1 = 0;
        int ans2 = 0;

        for (int n : nums1) {
            if (nums2Set.contains(n)) {
                ++ans1;
            }
        }

        for (int n : nums2) {
            if (nums1Set.contains(n)) {
                ++ans2;
            }
        }

        return { ans1, ans2 };
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
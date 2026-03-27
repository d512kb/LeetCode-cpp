// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> intersec;

        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(intersec));

        if (!intersec.empty()) { return intersec.front(); }

        if (nums1.front() < nums2.front()) {
            return nums1.front() * 10 + nums2.front();
        }
        else {
            return nums2.front() * 10 + nums1.front();
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
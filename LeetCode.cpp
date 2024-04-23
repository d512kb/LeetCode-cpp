// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int nHalf = (n1 + n2) / 2;

        int low = 0;
        int high = n1;

        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = nHalf - mid1;

            int left1 = numeric_limits<int>::min();
            int right1 = numeric_limits<int>::max();
            int left2 = left1;
            int right2 = right1;

            if (mid1 > 0) left1 = nums1[mid1 - 1];
            if (mid1 < n1) right1 = nums1[mid1];
            if (mid2 > 0) left2 = nums2[mid2 - 1];
            if (mid2 < n2) right2 = nums2[mid2];

            if (left1 <= right2 && left2 <= right1) {
                if ((n1 + n2) % 2) {
                    return min(right1, right2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            } else if (left1 > right2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }

        return 0;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

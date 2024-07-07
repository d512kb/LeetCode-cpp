// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();

        vector<int> dpCurr(sz2 + 1);
        vector<int> dpPrev(sz2 + 1);

        for (int i = 0; i < sz1; ++i) {
            swap(dpCurr, dpPrev);

            for (int j = 0; j < sz2; ++j) {
                if (nums1[i] == nums2[j]) {
                    dpCurr[j + 1] = 1 + dpPrev[j];
                } else {
                    dpCurr[j + 1] = max(dpCurr[j], dpPrev[j + 1]);
                }
            }
        }

        return dpCurr.back();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
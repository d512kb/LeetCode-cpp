// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1Set(nums1.begin(), nums1.end());
        set<int> nums2Set(nums2.begin(), nums2.end());

        vector<vector<int>> result(2);

        set_difference(nums1Set.begin(), nums1Set.end(), nums2Set.begin(), nums2Set.end(), back_inserter(result[0]));
        set_difference(nums2Set.begin(), nums2Set.end(), nums1Set.begin(), nums1Set.end(), back_inserter(result[1]));

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
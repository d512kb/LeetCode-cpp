// LeetCode.cpp : Defines the entry point for the application.
//

#include <vector>
#include <algorithm>

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>&& nums1, vector<int>&& nums2) {
        vector<int> result;
        result.reserve(nums1.size() + nums2.size());

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(result));

        double medianIndex = (result.size() + 1) / 2.;
        double frac = modf(medianIndex, &medianIndex);
        
        --medianIndex;
        frac = ceil(frac);

        return !result.empty() ? (result[medianIndex] + result[medianIndex + frac]) / 2. : 0;
    }
};

int main()
{
    Solution sol;
    cout << sol.findMedianSortedArrays({ }, { }) << endl;
    cout << sol.findMedianSortedArrays({ 1, 3 }, { 2 }) << endl;
    cout << sol.findMedianSortedArrays({ 1, 2 }, { 3, 4 }) << endl;
	return 0;
}

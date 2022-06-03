// LeetCode.cpp : Defines the entry point for the application.
//

#include <vector>
#include <algorithm>

#include "LeetCode.h"

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>&& nums1, vector<int>&& nums2) {
		if (nums1.empty() && nums2.empty())
			return 0;
		
		auto nums1Iter = nums1.cbegin();
		auto nums2Iter = nums2.cbegin();
		auto lastIter = nums1.empty() ? nums2.cbegin() : nums1.cbegin();
		auto medianIndex = (nums1.size() + nums2.size()) / 2;

		for (int i = 0; i < medianIndex; ++i) {
			if (nums1Iter == nums1.cend()) {
				lastIter = nums2Iter++;
			} else if (nums2Iter == nums2.cend()) {
				lastIter = nums1Iter++;
			} else if (*nums1Iter <= *nums2Iter) {
				lastIter = nums1Iter++;
			} else {
				lastIter = nums2Iter++;
			}
		}

		auto minMedian = min(nums1Iter == nums1.cend() ? *nums2Iter : *nums1Iter,
							 nums2Iter == nums2.cend() ? *nums1Iter : *nums2Iter);

		if ((nums1.size() + nums2.size()) % 2) { // odd number of elements, exact one median	
			return minMedian;
		} else { // find median by calculating mean of two numbers
			return (*lastIter + minMedian) / 2.0;
		}
	}
};

int main()
{
	Solution sol;
	cout << sol.findMedianSortedArrays({ 1, 3,4,5,6,7 }, { 2 }) << endl;
	cout << sol.findMedianSortedArrays({ 1, 2, 5 }, { 3, 4 }) << endl;
	cout << sol.findMedianSortedArrays({ 3 }, { 1, 2, 3, 4, 5 }) << endl;
	cout << sol.findMedianSortedArrays({  }, { 3, 4, 5, 6 }) << endl;
	cout << sol.findMedianSortedArrays({ 1, 2 }, { 3,4 }) << endl;
	cout << sol.findMedianSortedArrays({ 3, 4 }, { 1, 2 }) << endl;
	return 0;
}

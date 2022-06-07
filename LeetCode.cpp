// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {      
        std::merge(nums1.rend() - m, nums1.rend(),
                   nums2.rbegin(), nums2.rend(), nums1.rbegin(), std::greater<>());
    }
    void handMerge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        auto nums1Iter = nums1.rend() - m;
        auto nums2Iter = nums2.rbegin();
        auto resultIter = nums1.rbegin();

        while (resultIter != nums1.rend()) {
            if (nums1Iter == nums1.rend()) { copy(nums2Iter, nums2.rend(), resultIter); break; }
            if (nums2Iter == nums2.rend()) { break; }
            *resultIter++ = *nums1Iter > *nums2Iter ? *nums1Iter++ : *nums2Iter++;
        }
    }
};

int main() {

    Solution sol;

    vector<int> vec1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> vec2 = { 2, 5, 6 };
    vector<int> vec3 = { 2, 0 };
    vector<int> vec4 = { 1 };

    sol.handMerge(vec3, 1, vec4, 1);

    return 0;
}

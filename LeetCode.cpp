// LeetCode.cpp : Defines the entry point for the application.
//

#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <functional>

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty())
            return 0;

        if (nums1.empty()) {
            double med = nums2.size() / 2.0;
            double even = 1 - ceil(modf(med, &med));

            return (nums2[med - even] + nums2[med]) / 2.0;
        }

        if (nums2.empty()) {
            double med = nums1.size() / 2.0;
            double even = 1 - ceil(modf(med, &med));

            return (nums1[med - even] + nums1[med]) / 2.0;
        }

        auto nums1Iter = nums1.cbegin();
        auto nums2Iter = nums2.cbegin();
        auto prevIter = nums1.cbegin();
        auto medianIndex = (nums1.size() + nums2.size()) / 2;
        auto odd = (nums1.size() + nums2.size()) & 0x1;
        
        while (medianIndex > 0 && 
                nums1Iter != nums1.cend() &&
                nums2Iter != nums2.cend()) {
            if (*nums1Iter < *nums2Iter) {
                prevIter = nums1Iter++;
            } else {
                prevIter = nums2Iter++;
            }
            --medianIndex;
        }

        double result;

        if (nums1Iter == nums1.cend()) {
            advance(nums2Iter, medianIndex);
            prevIter = medianIndex > 0 ? nums2Iter - 1 : prevIter;
            result = odd ? *nums2Iter : (*prevIter + *nums2Iter) / 2.0;
        } else if (nums2Iter == nums2.cend()) {
            advance(nums1Iter, medianIndex);
            prevIter = medianIndex > 0 ? nums1Iter - 1 : prevIter;
            result = odd ? *nums1Iter : (*prevIter + *nums1Iter) / 2.0;
        } else {
            result = odd ? min(*nums1Iter, *nums2Iter) : (min(*nums1Iter, *nums2Iter) + *prevIter) / 2.0;
        }
        
        return result;
    }
};

int main() {
    minstd_rand engine;
    uniform_int_distribution distribution(0, 200000);

    auto f = [&distribution, &engine]() { return distribution(engine); };

    vector<int> v1, v2;
    generate_n(back_inserter(v1), 1000000, f);
    generate_n(back_inserter(v2), 1000000, f);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    Solution sol;
    cout << sol.findMedianSortedArrays(v1, v2) << endl;
    //cout << sol.findMedianSortedArrays({ 1,10,13 }, { 1, 2, 3, 4, 5 }) << endl;
    //cout << sol.findMedianSortedArrays({ 1,3,5 }, { 2,4 }) << endl;
    //cout << sol.findMedianSortedArrays({ 1 }, { 2, 3,4 }) << endl;
    //cout << sol.findMedianSortedArrays({ 2 }, { 1, 3 }) << endl;
    //cout << sol.findMedianSortedArrays({ 1 }, { 3, 4, 5, 6 }) << endl;
    //cout << sol.findMedianSortedArrays({ 3, 4 }, { 1, 2 }) << endl;

    return 0;
}

// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();

        vector<vector<int>> result;

        while (iter1 != nums1.end() && iter2 != nums2.end()) {
            if (iter1->front() < iter2->front()) {
                result.push_back(std::move(*iter1++));
            }
            else if (iter1->front() > iter2->front()) {
                result.push_back(std::move(*iter2++));
            }
            else {
                result.push_back({ iter1->front(), iter1->back() + iter2->back() });
                ++iter1;
                ++iter2;
            }
        }

        while (iter1 != nums1.end()) {
            result.push_back(std::move(*iter1++));
        }

        while (iter2 != nums2.end()) {
            result.push_back(std::move(*iter2++));
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
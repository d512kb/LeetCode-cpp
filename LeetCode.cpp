// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();

        while (iter1 != nums1.end() && iter2 != nums2.end()) {
            if (*iter1 == *iter2) { return *iter1; }

            if (*iter1 < *iter2) {
                ++iter1;
            }
            else {
                ++iter2;
            }
        }

        return -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
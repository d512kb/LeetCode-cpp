﻿// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;

        while (mid <= right) {
            switch (nums[mid]) {
            case 0:
                swap(nums[left++], nums[mid++]);
                break;
            case 1:
                ++mid;
                break;
            case 2:
                swap(nums[mid], nums[right--]);
                break;
            }
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lessNums, greaterNums;

        for (int n : nums) {
            if (n < pivot) {
                lessNums.push_back(n);
            }
            else if (n > pivot) {
                greaterNums.push_back(n);
            }
        }

        auto ans(std::move(lessNums));
        fill_n(back_inserter(ans), nums.size() - ans.size() - greaterNums.size(), pivot);
        ans.insert(ans.end(), greaterNums.begin(), greaterNums.end());

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
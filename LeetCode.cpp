// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        if (nums.size() == 1) { return min(abs(goal), abs(goal - nums.front())); }

        int mid = nums.size() / 2;
        vector<int> halfNums(nums.begin(), nums.begin() + mid);
        sort(halfNums.begin(), halfNums.end());

        vector<int> sums;
        generateSubsetsSums(halfNums, 0, 0, sums);

        sort(sums.begin(), sums.end());
        sums.erase(unique(sums.begin(), sums.end()), sums.end());

        halfNums.assign(nums.begin() + mid, nums.end());
        sort(halfNums.begin(), halfNums.end());
        vector<int> rightSums;
        generateSubsetsSums(halfNums, 0, 0, rightSums);

        int ans = numeric_limits<int>::max();

        for (int sum : rightSums) {
            auto iter = lower_bound(sums.begin(), sums.end(), goal - sum);

            if (iter != sums.end()) {
                ans = min(ans, abs(goal - sum - *iter));
            }

            if (iter != sums.begin()) {
                ans = min(ans, abs(goal - sum - *prev(iter)));
            }
        }

        return ans;
    }
private:
    void generateSubsetsSums(const vector<int>& nums, int index, int sum, vector<int>& sums) {
        if (index == nums.size()) { return sums.push_back(sum); return; }

        generateSubsetsSums(nums, index + 1, sum + nums[index], sums);

        while (index < nums.size() - 1 && nums[index] == nums[index + 1]) { ++index; }

        generateSubsetsSums(nums, index + 1, sum, sums);
    }
};


int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
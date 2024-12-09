// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int midSize = nums.size() / 2;
        vector<vector<int>> leftSums(midSize + 1), rightSums(midSize + 1);

        vector<int> halfNums(nums.begin(), nums.begin() + midSize);
        sort(halfNums.begin(), halfNums.end());
        generateSubsetsSums(halfNums, 0, 0, 0, leftSums);
        halfNums.assign(nums.begin() + midSize, nums.end());
        sort(halfNums.begin(), halfNums.end());
        generateSubsetsSums(halfNums, 0, 0, 0, rightSums);

        for (auto& sums : rightSums) { sort(sums.begin(), sums.end()); }

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int targetSum = totalSum / 2.;
        int ans = numeric_limits<int>::max();

        for (int i = 0; i <= midSize; ++i) {
            const auto& otherSums = rightSums[midSize - i];

            for (int sum : leftSums[i]) {
                int neededSum = targetSum - sum;
                int left = 0; int right = otherSums.size() - 1;
                int otherSum = otherSums[left];

                while (left < right) {
                    int mid = (left + right) / 2;
                    int midSum = otherSums[mid];

                    if (midSum < neededSum) {
                        left = mid + 1;
                    } else if (midSum > neededSum) {
                        right = mid - 1;
                    } else {
                        left = right = mid;
                    }
                }

                ans = min(ans, abs(totalSum - 2 * (sum + otherSums[left])));

                if (left > 0) { // if we have 2 potential sums we have to check which gives us lesser difference
                    // between PotentialSum and its complement (TotalSum - PotentialSum). The diffence
                    // is abs(TotalSum-PotentialSum - PotentialSum) which is abs(TotalSum - 2*PotentialSum)
                    ans = min(ans, abs(totalSum - 2 * (sum + otherSums[left - 1])));
                }
            }
        }

        return ans;
    }

private:
    void generateSubsetsSums(vector<int>& nums, int index, int usedItems, int sum, vector<vector<int>>& sums) {
        if (index == nums.size()) { sums[usedItems].push_back(sum); return; }

        generateSubsetsSums(nums, index + 1, usedItems + 1, sum + nums[index], sums);

        while (index < nums.size() - 1 && nums[index] == nums[index + 1]) { ++index; }

        generateSubsetsSums(nums, index + 1, usedItems, sum, sums);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
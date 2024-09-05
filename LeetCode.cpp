// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = accumulate(nums.begin(), nums.end(), 0);

        if (target % k) { return false; }

        target /= k;
        sort(nums.begin(), nums.end());
        vector<char> cache(1 << nums.size(), -1);

        return checkPartition(nums, cache, 0, k, 0, target, target);
    }
private:
    int checkPartition(vector<int>& nums, vector<char>& cache, uint16_t used, char bucket, char from, int rest, int target) {
        if (bucket == 1) { return true; }
        if (cache[used] != -1) { return cache[used]; }

        for (int i = from; i < nums.size(); ++i) {
            if (used & 1 << i) { continue; }
            if (nums[i] > rest) { break; }

            if (rest == nums[i] && checkPartition(nums, cache, used | 1 << i, bucket - 1, 0, target, target)) {
                return cache[used] = 1;
            } else if (checkPartition(nums, cache, used | 1 << i, bucket, i + 1, rest - nums[i], target)) {
                return cache[used] = 1;
            }
        }

        return cache[used] = 0;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
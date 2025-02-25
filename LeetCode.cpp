// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> counts;
        int result = 0;
        int maxCount = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == key) {
                if (++counts[nums[i + 1]] > maxCount) {
                    maxCount = counts[nums[i + 1]];
                    result = nums[i + 1];
                };
            }
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
// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) { return {}; }
        }

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i += 3) {
            result.push_back({ nums[i], nums[i + 1], nums[i + 2] });
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
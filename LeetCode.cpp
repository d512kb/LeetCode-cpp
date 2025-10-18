// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result(nums);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            result[i] = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), result[i]));
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
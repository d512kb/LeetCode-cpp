// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            result.insert(result.begin() + index[i], nums[i]);
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
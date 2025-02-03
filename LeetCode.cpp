// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int sz = nums.size();
        vector<int> result(sz, -1);
        vector<uint16_t> monoStack;

        for (int i = 0; i < sz; ++i) {
            while (!monoStack.empty() && nums[monoStack.back()] < nums[i]) {
                result[monoStack.back()] = nums[i];
                monoStack.pop_back();
            }

            monoStack.push_back(i);
        }

        for (int i = 0; i < monoStack.back(); ++i) {
            while (nums[monoStack.back()] < nums[i]) {
                result[monoStack.back()] = nums[i];
                monoStack.pop_back();
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
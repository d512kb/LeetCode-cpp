// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int sz = nums.size();
        int pos = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), 0));
        int neg = pos - 1;

        vector<int> result(sz);

        for (int i = 0; i < sz; ++i) {
            int idx = 0;

            if (pos == sz) { idx = neg--; } else if (neg < 0) { idx = pos++; } else {
                if (abs(nums[neg]) < nums[pos]) {
                    idx = neg--;
                } else {
                    idx = pos++;
                }
            }

            result[i] = nums[idx] * nums[idx];
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
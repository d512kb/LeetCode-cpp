// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        const int sz = nums.size();
        int ans = 0;
        int count = 0;
        int negativeCount = 0;
        int preNegativeCount = sz;
        int lastNegativePos = -1;

        for (int i = 0; i < sz; ++i) {
            if (nums[i] == 0) {
                if (negativeCount % 2) {
                    ans = max(ans, max(count - preNegativeCount, count - (i - lastNegativePos)));
                } else {
                    ans = max(ans, count);
                }

                count = 0;
                negativeCount = 0;
                preNegativeCount = sz;
                lastNegativePos = -1;

                continue;
            }

            ++count;

            if (nums[i] < 0) {
                ++negativeCount;
                preNegativeCount = min(preNegativeCount, count);
                lastNegativePos = max(lastNegativePos, i);
            }
        }

        if (negativeCount % 2) {
            ans = max(ans, max(count - preNegativeCount, count - (sz - lastNegativePos)));
        } else {
            ans = max(ans, count);
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
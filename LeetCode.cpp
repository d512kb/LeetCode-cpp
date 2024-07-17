// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dpLis(sz);
        vector<int> dpLisCount(sz);

        dpLis[0] = 1;
        dpLisCount[0] = 1;
        int maxLis = 1;
        int result = 1;

        for (int i = 1; i < sz; ++i) {
            int lis = 1;
            int lisCount = 1;

            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    int currLis = 1 + dpLis[j];

                    if (currLis > lis) {
                        lis = currLis;
                        lisCount = dpLisCount[j];
                    } else if (currLis == lis) {
                        lisCount += dpLisCount[j];
                    }
                }
            }

            dpLis[i] = lis;
            dpLisCount[i] = lisCount;

            if (lis > maxLis) {
                maxLis = lis;
                result = lisCount;
            } else if (lis == maxLis) {
                result += lisCount;
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
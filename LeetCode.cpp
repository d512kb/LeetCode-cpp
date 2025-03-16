// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int result = *max_element(nums.begin(), nums.end());
        if (result < 0) { return result; }
        result = 0;

        unordered_set<int> nset;

        for (int n : nums) {
            if (n > 0 && nset.insert(n).second) {
                result += n;
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
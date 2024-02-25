// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        int a = 0;
        int b = 0;

        while (a < nums.size()) {
            while (b < nums.size() - 1 && nums[b + 1] == nums[b] + 1) {
                ++b;
            }

            result.push_back(a == b ? to_string(nums[a]) : to_string(nums[a]) + "->" + to_string(nums[b]));
            a = b = b + 1;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

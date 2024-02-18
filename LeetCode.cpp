// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int a = 0, b = 0;
        int sum = 0;
        int minLen = nums.size() + 1;

        while (b < nums.size()) {
            sum += nums[b++];

            while (sum >= target) {
                minLen = min(minLen, b - a);
                sum -= nums[a++];
            }
        }

        return minLen == nums.size() + 1 ? 0 : minLen;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

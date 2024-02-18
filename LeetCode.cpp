// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int a = 0;
        int sum = 0;
        vector<vector<int>> result;

        while (a < nums.size() - 2) {
            int b = a + 1;
            int c = nums.size() - 1;

            while (b < c) {
                sum = nums[a] + nums[b] + nums[c];

                if (sum < 0) {
                    ++b;
                } else if (sum > 0) {
                    --c;
                } else {
                    result.push_back({ nums[a], nums[b], nums[c] });
                    ++b; --c;
                    while (b < c && nums[b] == nums[b - 1]) ++b;
                    while (b < c && nums[c] == nums[c + 1]) --c;
                }
            }

            ++a;
            while (a < b && nums[a] == nums[a - 1])
                ++a;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

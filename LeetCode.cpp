// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector sorted(nums);
        sort(sorted.begin(), sorted.end());

        int a = 0, b = nums.size() - 1;

        while (a < b) {
            int sum = sorted[a] + sorted[b];

            if (sum > target) {
                --b;
            } else if (sum < target) {
                ++a;
            } else {
                break;
            }
        }

        a = sorted[a];
        b = sorted[b];
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == a || nums[i] == b) {
                result.push_back(i);
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

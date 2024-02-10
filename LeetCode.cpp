// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums);

        for (int i = 1, j = nums.size() - 2; i < nums.size(), j >= 0; ++i, --j) {
            nums[i] *= nums[i - 1];
            result[j] *= result[j + 1];
        }

        result.front() = result[1];

        for (int i = 1; i < nums.size() - 1; ++i) {
            result[i] = nums[i - 1] * result[i + 1];
        }

        result.back() = nums[nums.size() - 2];

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

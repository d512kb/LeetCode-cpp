// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int lastInsertedNum = numeric_limits<int>::min();
        int lastInsertIndex = 0;
        vector<vector<int>> result;

        for (int n : nums) {
            int endIndex = result.size();

            if (n != lastInsertedNum) {
                lastInsertedNum = n;
                lastInsertIndex = 0;

                result.emplace_back(1, n);
            }

            for (int i = lastInsertIndex; i < endIndex; ++i) {
                result.push_back(result[i]);
                result.back().push_back(n);
            }

            lastInsertIndex = endIndex;
        }

        result.emplace_back();

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
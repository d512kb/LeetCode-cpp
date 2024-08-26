// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        subsets.reserve(2 << nums.size());

        for (int n : nums) {
            auto iterEnd = subsets.end();
            subsets.push_back({ n });
            for (auto iter = subsets.begin(); iter < iterEnd; ++iter) {
                subsets.push_back(*iter);
                subsets.back().push_back(n);
            }
        }

        subsets.emplace_back();

        return subsets;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
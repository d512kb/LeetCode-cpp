// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> vec;
        const char offset = 10;
        vector<char> usedIndexes(21, -1);

        auto perm = [&](auto&& self, vector<int>& vec) -> void {
            if (vec.size() == nums.size()) {
                result.push_back(vec);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (usedIndexes[nums[i] + offset] < i) {
                    int prevUsedIndex = usedIndexes[nums[i] + offset];
                    usedIndexes[nums[i] + offset] = i;
                    vec.push_back(nums[i]);
                    self(self, vec);
                    vec.pop_back();
                    usedIndexes[nums[i] + offset] = prevUsedIndex;
                }
            }
        };

        perm(perm, vec);

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
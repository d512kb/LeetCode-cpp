// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> vec;

        unordered_map<int, int> numCounts;
        for (int n : nums) { ++numCounts[n]; }

        auto perm = [&](auto&& self, vector<int>& vec) -> void {
            if (vec.size() == nums.size()) {
                result.push_back(vec);
                return;
            }

            for (auto& [num, count] : numCounts) {
                if (count > 0) {
                    --count;
                    vec.push_back(num);
                    self(self, vec);
                    vec.pop_back();
                    ++count;
                }
            }
        };

        perm(perm, vec);

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
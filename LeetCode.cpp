// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        const int sz = nums.size();

        unordered_map<int, vector<int>> positions;

        for (int i = 0; i < sz; ++i) {
            positions[nums[i]].push_back(i);
        }

        vector<int> result;
        for (int q : queries) {
            const auto& pos = positions[nums[q]];

            if (pos.size() < 2) {
                result.push_back(-1);
            } else {
                int idx = distance(pos.begin(), lower_bound(pos.begin(), pos.end(), q));
                int val = 0;

                if (idx == 0) {
                    val = min(pos[idx + 1] - q, sz - pos.back() + q);
                } else if (idx == pos.size() - 1) {
                    val = min(q - pos[idx - 1], sz - pos.back() + pos.front());
                } else {
                    val = min(q - pos[idx - 1], pos[idx + 1] - q);
                }

                result.push_back(val);
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
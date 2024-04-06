// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> used(nums.size(), 0);
        vector<int> pm;

        perm(nums, used, pm, result);

        return result;

    }
private:
    void perm(vector<int>& nums, vector<int>& used, vector<int>& pm, vector<vector<int>>& result) {
        if (pm.size() == nums.size()) {
            result.push_back(pm);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = 1;
                pm.push_back(nums[i]);
                perm(nums, used, pm, result);
                pm.pop_back();
                used[i] = 0;
            }
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

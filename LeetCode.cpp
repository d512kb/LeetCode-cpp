// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> v;

        calc(candidates, 0, target, v, result);

        return result;
    }
private:
    void calc(vector<int>& candidates, int index, int target, vector<int>& v, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(v);
            return;
        }

        if (target < 0)
            return;

        for (; index < candidates.size(); ++index) {
            target -= candidates[index];
            v.push_back(candidates[index]);
            calc(candidates, index, target, v, result);
            v.pop_back();
            target += candidates[index];
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

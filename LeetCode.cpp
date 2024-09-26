// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));

        vector<vector<int>> result;
        vector<int> comb;
        calcSum(candidates, candidates.begin(), target, comb, result);
        return result;
    }
private:
    void calcSum(vector<int>& candidates, vector<int>::iterator from, int target, vector<int>& comb, vector<vector<int>>& result) {
        if (target <= 0) { if (target == 0) { result.push_back(comb); } return; }
        if (from == candidates.end()) { return; }

        comb.push_back(*from);
        calcSum(candidates, from + 1, target - *from, comb, result);
        comb.pop_back();

        auto nextCandidate = upper_bound(from, candidates.end(), *from);

        if (nextCandidate != candidates.end()) {
            calcSum(candidates, nextCandidate, target, comb, result);
        }
    }
};

int main() {
    INIT_TIME(timer);
    
    PRINT_ELAPSED(timer);
    return 0;
}
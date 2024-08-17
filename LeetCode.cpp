// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> build;

        generateCombinations(1, k, n, build, result);

        return result;
    }
private:
    void generateCombinations(int from, int k, int n, vector<int>& build, vector<vector<int>>& result) {
        if (n < 0) {
            return;
        }

        if (k == 0) {
            if (n == 0) {
                result.push_back(build);
            }

            return;
        }

        for (int i = from; i <= 9; ++i) {
            build.push_back(i);
            generateCombinations(i + 1, k - 1, n - i, build, result);
            build.pop_back();
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
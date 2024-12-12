// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> cache(cuts.size(), vector<int>(cuts.size(), -1));

        auto cutStick = [&](auto&& self, int i, int j) -> int {
            if (i + 1 == j) { return 0; }

            int& cachedValue = cache[i][j];
            if (cachedValue != -1) { return cachedValue; }

            int minCut = numeric_limits<int>::max();
            int cutCost = cuts[j] - cuts[i];

            for (int k = i + 1; k < j; ++k) {
                minCut = min(minCut, self(self, i, k) + self(self, k, j) + cutCost);
            }

            return cachedValue = minCut;
        };

        return cutStick(cutStick, 0, cuts.size() - 1);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
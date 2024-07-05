// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto& v1, const auto& v2) { return v1[1] < v2[1]; });

        int chainLen = 0;
        int lastNexus = numeric_limits<int>::min();

        for (auto iter = pairs.begin(), iterEnd = pairs.end(); iter != iterEnd; ++iter) {
            if ((*iter)[0] > lastNexus) {
                ++chainLen;
                lastNexus = (*iter)[1];
            }
        }

        return chainLen;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
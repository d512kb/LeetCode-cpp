// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n + 1);
        vector<int> trustedBy(n + 1);

        for (auto& t : trust) {
            ++trusts[t[0]];
            ++trustedBy[t[1]];
        }

        for (int i = 1; i <= n; ++i) {
            if (trusts[i] == 0 && trustedBy[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gi = 0;
        int result = 0;

        for (int cookie : s) {
            if (gi >= g.size()) {
                return result;
            }

            if (g[gi] <= cookie) {
                ++result;
                ++gi;
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
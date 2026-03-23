// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<char> friends(n);

        size_t idx = 0;
        size_t step = 0;

        while (friends[idx] == 0) {
            friends[idx] = 1;

            step += k;
            idx = (idx + step) % n;
        }

        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (friends[i] == 0) { ans.push_back(i + 1); }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        const int sz = dist.size();
        vector<float> appearance(sz);

        for (int i = 0; i < sz; ++i) {
            appearance[i] = static_cast<float>(dist[i]) / speed[i];
        }

        sort(appearance.begin(), appearance.end());

        int ans = 1;
        for (int i = 1; i < sz; ++i) {
            if (appearance[i] <= i) { return ans; }
            ++ans;
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
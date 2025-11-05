// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int start = -1;

        for (int i = 0; i < forts.size(); ++i) {
            if (forts[i] != 0) {
                start = i;
                break;
            }
        }

        if (start == -1) { return 0; }
        int stop = 0;
        int ans = 0;

        while (start < forts.size()) {
            stop = start + 1;

            while (stop < forts.size() && forts[stop] == 0) {
                ++stop;
            }

            if (stop == forts.size()) { return ans; }

            if (forts[start] + forts[stop] == 0) {
                ans = max(ans, stop - start - 1);
            }

            start = stop;
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
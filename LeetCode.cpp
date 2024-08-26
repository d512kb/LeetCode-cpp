// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int lastStart = numeric_limits<int>::max();
        for (auto iter = intervals.rbegin(); iter != intervals.rend(); ++iter) {
            if ((*iter)[1] > lastStart) {
                ++ans;
            } else {
                lastStart = (*iter)[0];
            }
        }

        return ans;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
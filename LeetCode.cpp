// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int longestTime = 0;
        int prevTime = 0;
        int ans = 0;

        for (int i = 0; i < logs.size(); ++i) {
            int diff = logs[i][1] - prevTime;

            if (diff > longestTime) {
                ans = logs[i][0];
                longestTime = diff;
            }
            else if (diff == longestTime) {
                if (logs[i][0] < ans) {
                    ans = logs[i][0];
                }
            }

            prevTime = logs[i][1];
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
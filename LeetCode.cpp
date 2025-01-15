// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<>> pq;

        int ans = 1;
        for (ans; ans < heights.size(); ++ans) {
            int diff = heights[ans] - heights[ans - 1];

            if (diff > 0) {
                pq.push(diff);

                if (pq.size() > ladders) {
                    bricks -= pq.top();
                    pq.pop();

                    if (bricks < 0) { return ans - 1; }
                }
            }
        }

        return ans - 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (const auto& b : buildings) {
            events.emplace_back(b[0], -b[2]); // start, negative height
            events.emplace_back(b[1], b[2]);  // end, positive height
        }
        sort(events.begin(), events.end());

        multiset<int, greater<>> heights = { 0 };
        vector<vector<int>> result;
        int prev = 0;

        for (auto [x, h] : events) {
            if (h < 0) heights.insert(-h); // start
            else heights.erase(heights.find(h)); // end

            int curr = *heights.begin();
            if (curr != prev) {
                result.push_back({ x, curr });
                prev = curr;
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);
 
    PRINT_ELAPSED(timer);
    return 0;
}
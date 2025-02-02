// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<pair<int, int>> eventsTimes;
        eventsTimes.reserve(events.size());

        for (const auto& e : events) { eventsTimes.emplace_back(e[0], e[1]); }
        sort(eventsTimes.begin(), eventsTimes.end());

        auto cmp = [](const auto& e1, const auto& e2) { return e1.second > e2.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
        auto eventsTimesIter = eventsTimes.begin();
        int ans = 0;

        for (int day = eventsTimes[0].first; !pq.empty() || eventsTimesIter != eventsTimes.end(); ++day) {
            while (!pq.empty() && pq.top().second < day) { pq.pop(); }

            while (eventsTimesIter != eventsTimes.end() && eventsTimesIter->first == day) {
                pq.push(std::move(*eventsTimesIter++));
            }

            if (!pq.empty()) {
                ++ans;
                pq.pop();
            }
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
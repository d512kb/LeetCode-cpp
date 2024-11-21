// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(begin(intervals), end(intervals), [](const auto& int1, const auto& int2) { return int1[0] < int2[0]; });
        auto intervalsIter = intervals.begin();

        auto sortedQueries = queries;
        sort(begin(sortedQueries), end(sortedQueries));
        sortedQueries.erase(unique(begin(sortedQueries), end(sortedQueries)), end(sortedQueries));

        unordered_map<int, int> lengths;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int query : sortedQueries) {
            while (intervalsIter != intervals.end() && (*intervalsIter)[0] <= query) {
                if ((*intervalsIter)[1] >= query) {
                    pq.emplace((*intervalsIter)[1] - (*intervalsIter)[0] + 1, (*intervalsIter)[1]);
                }
                ++intervalsIter;
            }

            while (!pq.empty() && pq.top().second < query) { pq.pop(); }

            if (pq.empty()) { lengths[query] = -1; } else { lengths[query] = pq.top().first; }
        }

        vector<int> result;
        result.reserve(queries.size());

        for (int q : queries) { result.push_back(lengths[q]); }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
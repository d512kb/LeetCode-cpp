// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        if (queries.size() < k) {
            return vector<int>(queries.size(), -1);
        }

        priority_queue<int> pq;
        auto iter = next(queries.begin(), k);

        for_each(queries.begin(), iter, [this, &pq](const auto& vec) { pq.push(calcDistance(vec)); });

        int distance = pq.top();
        vector<int> result(k - 1, -1);
        result.push_back(distance);

        for (; iter < queries.end(); ++iter) {
            int newDistance = calcDistance(*iter);

            if (newDistance < distance) {
                pq.pop();
                pq.push(newDistance);
                distance = pq.top();
            }

            result.push_back(distance);
        }

        return result;
    }
private:
    inline int calcDistance(const vector<int>& point) {
        return abs(point[0]) + abs(point[1]);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
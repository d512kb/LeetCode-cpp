// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int sz = costs.size();
        uint64_t cost = 0;

        if (candidates < sz / 2.) {
            priority_queue<int, vector<int>, greater<int>> pqLeft(costs.begin(), next(costs.begin(), candidates));
            priority_queue<int, vector<int>, greater<int>> pqRight(costs.rbegin(), next(costs.rbegin(), candidates));

            int left = candidates;
            int right = sz - left - 1;

            while (k--) {
                if (!pqLeft.empty() && !pqRight.empty()) {
                    if (pqLeft.top() <= pqRight.top()) {
                        cost += pqLeft.top();
                        pqLeft.pop();

                        if (left <= right) { pqLeft.push(costs[left++]); }
                    } else {
                        cost += pqRight.top();
                        pqRight.pop();

                        if (left <= right) { pqRight.push(costs[right--]); }
                    }
                } else {
                    if (!pqLeft.empty()) {
                        cost += pqLeft.top();
                        pqLeft.pop();
                    } else {
                        cost += pqRight.top();
                        pqRight.pop();
                    }
                }
            }

            return cost;
        } else {
            make_heap(costs.begin(), costs.end(), greater<>());

            while (k--) {
                cost += costs.front();
                pop_heap(costs.begin(), costs.end(), greater<>());
                costs.pop_back();
            }

            return cost;
        }

        return cost;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
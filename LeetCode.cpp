// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        const int last = arr.size() - 1;

        using FractionState = pair<double, pair<int, int>>;
        priority_queue<FractionState, vector<FractionState>, greater<>> pq;

        for (int i = 0; i < last; ++i) {
            pq.emplace(1. * arr[i] / arr[last], make_pair(i, last));
        }

        while (--k) {
            auto state = pq.top();
            pq.pop();

            state.first = 1. * arr[state.second.first] / arr[--state.second.second];

            if (state.first < 1) { pq.push(state); }
        }

        return { arr[pq.top().second.first], arr[pq.top().second.second] };
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
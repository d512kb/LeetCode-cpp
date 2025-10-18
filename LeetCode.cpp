// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < nums.size(); ++i) {
            pq.emplace(nums[i], i);
        }

        for (int i = 0; i < k; ++i) {
            auto [val, index] = pq.top();
            pq.pop();
            pq.emplace(val * multiplier, index);
        }

        vector<int> result(nums.size());

        while (!pq.empty()) {
            auto [val, index] = pq.top();
            result[index] = val;
            pq.pop();
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
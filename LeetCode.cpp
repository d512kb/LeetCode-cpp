// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        auto cmp = [](const auto& p1, const auto& p2) { return p1.first > p2.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;

        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i + 1); // put next index
        }

        constexpr int modulo = 1e9 + 7;
        int ans = 0;
        --left; // make it 0-based

        for (int i = 0; i < right; ++i) {
            auto val = pq.top();
            pq.pop();

            if (i >= left) {
                ans = (ans + val.first) % modulo;
            }

            if (val.second < n) {
                val.first += nums[val.second++];
                pq.push(val);
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
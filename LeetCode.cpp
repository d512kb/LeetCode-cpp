// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz = nums1.size();
        vector<pair<int, int>> v;
        v.reserve(sz);

        for (int i = 0; i < sz; ++i) {
            v.emplace_back(nums1[i], nums2[i]);
        }

        sort(v.begin(), v.end(), [](auto& p1, auto& p2) { return p1.second > p2.second; });

        priority_queue<int, vector<int>, greater<int>> pq;
        int64_t sum = 0;
        int64_t result = 0;

        for (int i = 0; i < k; ++i) {
            pq.push(v[i].first);
            sum += v[i].first;
        }

        result = sum * v[k - 1].second;

        for (int i = k; i < sz; ++i) {
            auto& p = v[i];

            if (p.first > pq.top()) {
                sum += p.first - pq.top();
                pq.pop();
                pq.push(p.first);
            }

            result = max(result, sum * p.second);
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < sz1; ++i) {
            pq.push({ nums1[i] + nums2[0], {i, 0} });
        }

        vector<vector<int>> result;

        while (!pq.empty()) {
            const auto& vals = pq.top();
            int i = vals.second.first;
            int j = vals.second.second;
            pq.pop();

            result.push_back({ nums1[i], nums2[j] });
            if (--k == 0)
                return result;

            if (++j < sz2) {
                pq.push({ nums1[i] + nums2[j], {i, j} });
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

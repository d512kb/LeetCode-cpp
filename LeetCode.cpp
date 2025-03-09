// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        const int sz = nums1.size();

        vector<pair<int, int>> values;
        for (int i = 0; i < sz; ++i) { values.emplace_back(nums1[i], i); }

        sort(values.begin(), values.end());

        priority_queue<int, vector<int>, greater<>> pq;
        long long sum = 0;

        vector<long long> result(sz);

        for (int i = 0; i < sz; ) {
            auto currSum = sum;
            int val = values[i].first;

            for (; i < sz && values[i].first == val; ++i) {
                int idx = values[i].second;
                result[idx] = currSum;

                sum += nums2[idx];
                pq.push(nums2[idx]);
            }

            while (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
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
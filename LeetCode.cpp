// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < k; ++i) {
            pq.emplace(nums[i], i);
        }

        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > pq.top().first) {
                pq.pop();
                pq.emplace(nums[i], i);
            }
        }

        vector<int> result;

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        sort(result.begin(), result.end());
        transform(result.begin(), result.end(), result.begin(), [&nums](int i) { return nums[i]; });

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
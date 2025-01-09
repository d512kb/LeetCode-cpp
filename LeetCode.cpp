// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<int, greater<>> pqMax;
        multiset<int> pqMin;
        int64_t runningSum = 0;

        for (int i = 1; i <= dist + 1; ++i) { pqMin.insert(nums[i]); }

        while (pqMax.size() < k - 1) {
            pqMax.insert(*pqMin.begin());
            runningSum += *pqMin.begin();
            pqMin.erase(pqMin.begin());
        }

        int64_t result = runningSum;
        for (int a = 1, b = dist + 2; b < nums.size(); ++a, ++b) {
            if (pqMin.extract(nums[a]).empty()) {
                pqMax.extract(nums[a]);
                runningSum -= nums[a];
            }

            if (nums[b] < *pqMax.begin()) {
                pqMax.insert(nums[b]);
                runningSum += nums[b];
            } else {
                pqMin.insert(nums[b]);
            }

            if (pqMax.size() < k - 1) {
                pqMax.insert(*pqMin.begin());
                runningSum += *pqMin.begin();
                pqMin.extract(*pqMin.begin());
            }

            if (pqMax.size() > k - 1) {
                pqMin.insert(*pqMax.begin());
                runningSum -= *pqMax.begin();
                pqMax.extract(*pqMax.begin());
            }

            result = min(result, runningSum);
        }

        return result + nums[0];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        int64_t result = 0;

        while (k--) {
            if (pq.top() == 0) { return result; }
            result += pq.top();
            pq.push(ceil(pq.top() / 3.));
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
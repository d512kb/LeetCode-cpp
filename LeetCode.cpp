// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int modNumber = 1000000007;
        auto start = nums.begin();
        auto stop = lower_bound(start, nums.end(), 1 + target - *start);

        vector<int> seqs(2 + distance(start, stop));
        seqs[0] = 0;
        seqs[1] = 1;
        int prevTwo = 1;

        for (int i = 2; i < seqs.size(); ++i) {
            seqs[i] = (seqs[i - 1] + prevTwo) % modNumber;
            prevTwo = (prevTwo * 2) % modNumber;
        }

        int ans = 0;
        for (; start < stop && *start < 1 + target - *start; ++start) {
            stop = lower_bound(start, stop, 1 + target - *start);

            ans += seqs[distance(start, stop)];
            ans %= modNumber;
        }

        return ans;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
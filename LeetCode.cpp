// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int negPrev = 1;
        int posPrev = 1;
        int neg = 1;
        int pos = 1;
        int ans = nums.front();

        for (int n : nums) {
            neg = min(n, min(n * negPrev, n * posPrev));
            pos = max(n, max(n * negPrev, n * posPrev));

            ans = max(ans, max(neg, pos));

            negPrev = neg;
            posPrev = pos;
        }

        return ans;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
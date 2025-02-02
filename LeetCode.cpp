// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        constexpr int modulo = 1e9 + 7;
        unordered_map<int64_t, int64_t> revCount;

        for (int n : nums) {
            int64_t num = n;
            int64_t rev = 0;

            while (n) {
                rev = rev * 10 + n % 10;
                n /= 10;
            }

            ++revCount[num - rev];
        }

        int ans = 0;
        for (auto [num, count] : revCount) {
            ans += ((count - 1) * count / 2) % modulo;
            ans %= modulo;
        };

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
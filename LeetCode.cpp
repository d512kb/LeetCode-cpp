// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        const int sz = nums.size();
        int ans = 0;

        for (int i = 0; i < sz; ++i) {
            if (isPrime(nums[i][i])) {
                ans = max(ans, nums[i][i]);
            }

            if (isPrime(nums[i][sz - i - 1])) {
                ans = max(ans, nums[i][sz - i - 1]);
            }
        }

        return ans;
    }

private:
    bool isPrime(int n) {
        if (n == 1) { return false; }
        if (n == 2) { return true; }
        if (n % 2 == 0) { return false; }

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) { return false; }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
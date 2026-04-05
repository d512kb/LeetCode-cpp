// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        array<vector<int>, 10> numbers;

        for (int n : nums) {
            int dig = 0;
            int a = n;

            while (a) {
                dig = max(dig, a % 10);
                a /= 10;
            }

            numbers[dig].push_back(n);
        }

        int ans = -1;

        for (auto& n : numbers) {
            if (n.size() > 1) {
                sort(n.begin(), n.end());
                ans = max(ans, *n.rbegin() + *(n.rbegin() + 1));
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
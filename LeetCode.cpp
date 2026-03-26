// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        array<int, 10> countDigits{};
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            char d = a % 10;

            for (int j = 1; j < 10; ++j) {
                if (gcd(j, d) == 1) {
                    ans += countDigits[j];
                }
            }

            while (a >= 10) { a /= 10; }
            ++countDigits[a];
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
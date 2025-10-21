// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = numeric_limits<int>::max();

        for (int n : nums) {
            int val = 0;

            while (n) {
                val += n % 10;
                n /= 10;
            }

            ans = min(ans, val);
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
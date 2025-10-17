// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            ans += min(n % 3, 3 - n % 3);
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
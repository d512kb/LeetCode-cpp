// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            if (n % 2 == 0) {
                ans |= n;
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
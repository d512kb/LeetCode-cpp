// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> numCount;
        for (int n : nums) { ++numCount[n]; }

        int ans = 0;
        for (auto [n, count] : numCount) {
            if (count == 1) { return -1; }
            ans += ceil(count / 3.);
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
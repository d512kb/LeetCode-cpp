// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double sum = 0;
        unordered_set<int> setNums;

        for (int n : nums) {
            sum += n;
            setNums.insert(n);
        }

        int ans = (sum / nums.size()) + 1;
        if (ans <= 0) { ans = 1; }

        while (setNums.contains(ans)) {
            ++ans;
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
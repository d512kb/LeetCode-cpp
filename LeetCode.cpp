// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0;
        int doubleSum = 0;

        for (int n : nums) {
            if (n < 10) {
                singleSum += n;
            }
            else {
                doubleSum += n;
            }
        }

        return singleSum != doubleSum;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
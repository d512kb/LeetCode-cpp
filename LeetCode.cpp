// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len = k;
        for (int n : nums) {
            if (n == 1) {
                if (len < k) { return false; }
                len = 0;
            } else {
                ++len;
            }
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
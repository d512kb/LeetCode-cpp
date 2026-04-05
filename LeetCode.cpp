// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        array<char, 101> count{};

        for (int n : nums) {
            if (++count[n] > 2) { return false; }
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
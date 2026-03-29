// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool scoreBalance(string s) {
        auto rightSum = accumulate(s.begin(), s.end(), 0, [](int a, char b) { return a + b - 'a' + 1; });
        int leftSum = 0;

        for (char c : s) {
            int val = c - 'a' + 1;

            leftSum += val;
            rightSum -= val;

            if (leftSum == rightSum) { return true; }
        }

        return false;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
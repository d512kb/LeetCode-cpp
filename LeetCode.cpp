// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int totalSum = 0;
        int digitSum = 0;

        for (int n : nums) {
            totalSum += n;

            while (n) {
                digitSum += n % 10;
                n /= 10;
            }
        }

        return abs(totalSum - digitSum);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
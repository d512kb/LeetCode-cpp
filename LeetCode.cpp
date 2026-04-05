// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        auto cmp = [](int a, int b) {
            int aRefl = 0;
            int bRefl = 0;

            int aCopy = a;
            while (aCopy) {
                aRefl = (aRefl << 1) + aCopy % 2;
                aCopy >>= 1;
            }

            int bCopy = b;
            while (bCopy) {
                bRefl = (bRefl << 1) + bCopy % 2;
                bCopy >>= 1;
            }

            if (aRefl == bRefl) { return a < b; }
            return aRefl < bRefl;
            };

        sort(nums.begin(), nums.end(), cmp);

        return nums;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
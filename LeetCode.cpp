// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        constexpr int bitsCount = 32;
        vector<int> oneBitsCount(bitsCount);

        for (int n : nums) {
            for (int i = 0; i < bitsCount; ++i) {
                oneBitsCount[i] += ((1 << i) & n) >> i;
            }
        }

        int result = 0;
        for (int i = 0; i < bitsCount; ++i) {
            result += oneBitsCount[i] * (nums.size() - oneBitsCount[i]);
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
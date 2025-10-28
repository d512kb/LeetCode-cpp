// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        constexpr size_t bitwidth = 32;
        array<int, bitwidth> bitsCounter{};

        for (int n : nums) {
            bitset<bitwidth> bset(n);

            for (int i = 0; i < bitwidth; ++i) {
                bitsCounter[i] += bset[i];
            }
        }

        bitset<bitwidth> bset;

        for (int i = 0; i < bitwidth; ++i) {
            if (bitsCounter[i] >= k) {
                bset[i] = 1;
            }
        }

        return bset.to_ulong();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
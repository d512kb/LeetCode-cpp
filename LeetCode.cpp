// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int16_t> bits(32, 0);

        for (int n : nums) {
            for (int i = 31; i >= 0; --i) {
                bits[i] += n % 2;
                n >>= 1;
            }
        }

        uint32_t powerOfTwo = 1;
        int result = bits[31] % 3 > 0;

        for (int i = 30; i >= 0; --i) {
            powerOfTwo *= 2;

            if (bits[i] % 3) {
                result += powerOfTwo;
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

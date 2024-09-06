// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1;
        int right = n;

        while (left <= right) {
            uint64_t mid = left + (right - left) / 2;
            uint64_t sum = mid * (mid + 1) / 2;

            if (sum < n) {
                left = mid + 1;
            } else if (sum > n) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return right;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
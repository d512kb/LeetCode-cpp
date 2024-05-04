// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        uint64_t low = 0;
        uint64_t high = x;

        while (low <= high) {
            uint64_t mid = low + (high - low) / 2;
            auto sqrMid = mid * mid;

            if (sqrMid < x) {
                low = mid + 1;
            } else if (sqrMid > x) {
                high = mid - 1;
            } else {
                return mid;
            }
        }

        return high;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

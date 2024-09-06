// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int min = 1;
        int max = 46340;

        while (min <= max) {
            int mid = min + (max - min) / 2;
            int val = mid * mid;

            if (val == num) {
                return true;
            } else if (val < num) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
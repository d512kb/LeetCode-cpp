// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

int guess(int) { return 0; };

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int ans = guess(mid);

            if (ans < 0) {
                right = mid - 1;
            } else if (ans > 0) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        return left;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
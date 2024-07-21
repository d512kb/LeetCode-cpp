// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        int result = 0;

        while (k) {
            if (k % 2) {
                if (!(n % 2)) {
                    return -1;
                }

            } else {
                if (n % 2) {
                    ++result;
                }
            }

            k /= 2;
            n /= 2;
        }

        while (n) {
            if (n % 2)
                ++result;

            n /= 2;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
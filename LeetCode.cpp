// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        while (n != 1) {
            int t = 0;

            while (n) {
                t += (n % 10) * (n % 10);
                n /= 10;
            }

            n = t;

            if (t == 4)
                return false;
        }

        return true;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

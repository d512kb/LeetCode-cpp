// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int upLimit = numeric_limits<int>::max() / 10;
        int downLimit = numeric_limits<int>::min() / 10;
        int result = 0;

        while (x) {
            if (result > upLimit || result < downLimit) return 0;
            result = result * 10 + (x % 10);
            x /= 10;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);
    
    PRINT_ELAPSED(timer);
    return 0;
}
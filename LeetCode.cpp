// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int evenSum = 0;
        int oddSum = 0;

        for (int i = 0; i < num.size(); ++i) {
            if (i % 2) {
                oddSum += num[i] - '0';
            } else {
                evenSum += num[i] - '0';
            }
        }

        return evenSum == oddSum;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
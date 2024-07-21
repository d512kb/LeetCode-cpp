// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int dp = 0;
        int result = 0;

        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] == '1') {
                result += dp;

                if (s[i + 1] == '0') {
                    dp += 1;
                    ++result;
                }
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
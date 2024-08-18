// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int result = 0;
        int sz = s.size();

        for (int i = 0; i < sz; ++i) {
            int ones = 0;
            int zeroes = 0;

            for (int j = i; j < sz; ++j) {
                if (s[j] == '1') {
                    ++ones;
                } else {
                    ++zeroes;
                }

                if (ones <= k || zeroes <= k) {
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
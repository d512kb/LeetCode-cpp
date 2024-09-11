// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int sz = s.size();

        for (int div = 2; div <= sz; ++div) {
            if (sz % div) { continue; }

            int a = 0;
            int b = sz / div;

            for (; b < sz; ++a, ++b) {
                if (s[a] != s[b]) {
                    break;
                }
            }

            if (b == sz) {
                return true;
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
// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int sz = s.size();
        int ans = 0;

        for (int i = 0; i < sz; ++i) {
            int charCount[26]{};

            for (int j = i; j < sz; ++j) {
                if (++charCount[s[j] - 'a'] >= k) {
                    ans += sz - j;
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;
        vector<int> counts(26);
        vector<int> countsPrev(26);

        for (char c : s) { ++counts[c - 'a']; }
        for (int i = 0; i < t; ++i) {
            swap(counts, countsPrev);

            for (int c = 0; c < 25; ++c) {
                counts[c + 1] = (counts[c + 1] + countsPrev[c]) % mod;
                countsPrev[c] = 0;
            }

            counts[0] = (counts[0] + countsPrev[25]) % mod;
            counts[1] = (counts[1] + countsPrev[25]) % mod;
            countsPrev[25] = 0;
        }

        int ans = 0;

        for (int i = 0; i < 26; ++i) {
            ans = (ans + counts[i]) % mod;
        }

        return ans;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
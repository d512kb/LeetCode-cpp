// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);

        for (char c : s) { ++freq[c - 'a']; }
        sort(begin(freq), end(freq), greater<>());

        int ans = 0;
        for (int i = 1; i < 26; ++i) {
            if (freq[i] >= freq[i - 1]) {
                int newFreq = max(0, freq[i - 1] - 1);

                ans += freq[i] - newFreq;
                freq[i] = newFreq;
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
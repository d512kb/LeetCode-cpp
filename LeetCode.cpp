// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> charCount(26);
        for (char c : text) { ++charCount[c - 'a']; }
        int ans = 0;

        for (char c = 'a'; c <= 'z'; ++c) {
            if (charCount[c - 'a'] == 0) { continue; }

            int start = 0;
            int stop = 0;
            char filler = 0;

            for (stop; stop < text.size(); ++stop) {
                if (text[stop] == c && filler < 2) { continue; }
                if (text[stop] != c && ++filler < 2) { continue; }
                if (text[start++] != c) { --filler; }
            }

            ans = max(ans, min(charCount[c - 'a'], stop - start));
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
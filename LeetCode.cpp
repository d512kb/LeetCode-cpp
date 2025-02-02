// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        array<int, 26> charCount{};

        for (char c : s) {
            ++charCount[c - 'a'];
        }

        int maxF = 0;
        int minF = s.size();
        for (int f : charCount) {
            if (f == 0) { continue; }

            if (f % 2) { maxF = max(maxF, f); } else { minF = min(minF, f); }
        }

        return maxF - minF;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
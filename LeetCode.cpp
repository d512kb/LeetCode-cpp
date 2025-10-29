// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        array<int, 26> freq{};

        for (char c : s) {
            ++freq[c - 'a'];
        }

        int commonFreq = 0;

        for (int f : freq) {
            if (f != 0) {
                if (commonFreq == 0) { commonFreq = f; }
                else if (commonFreq != f) { return false; }
            }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
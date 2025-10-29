// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;

        for (const auto& word : words) {
            if (s.starts_with(word)) {
                ++ans;
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
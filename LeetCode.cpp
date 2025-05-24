// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxSubstrings(string word) {
        const auto sz = word.size();
        array<int, 26> prevPos;
        fill(prevPos.begin(), prevPos.end(), -1);
        int ans = 0;

        for (int i = 0; i < sz; ++i) {
            auto& pos = prevPos[word[i] - 'a'];
            if (pos == -1) {
                pos = i;
            } else if (i - pos >= 3) {
                fill(prevPos.begin(), prevPos.end(), -1);
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
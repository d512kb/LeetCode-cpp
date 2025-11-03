// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) { return false; }

        vector<int> wrongPos;
        array<int, 26> rightPos;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                wrongPos.push_back(i);
            }
            else {
                ++rightPos[s[i] - 'a'];
            }

            if (wrongPos.size() > 2) { return false; }
        }

        if (wrongPos.size() == 1) { return false; }
        if (wrongPos.empty()) { return find_if(rightPos.begin(), rightPos.end(), [](int c) { return c > 1; }) != rightPos.end(); }

        return s[wrongPos[0]] == goal[wrongPos[1]] && s[wrongPos[1]] == goal[wrongPos[0]];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
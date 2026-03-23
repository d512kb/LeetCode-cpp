// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<pair<char, char>> swapped;

        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                swapped.emplace_back(s1[i], s2[i]);
                if (swapped.size() > 2) { return false; }
            }
        }

        if (swapped.empty()) { return true; }
        if (swapped.size() == 1) { return false; }

        return swapped[0].first == swapped[1].second && swapped[0].second == swapped[1].first;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
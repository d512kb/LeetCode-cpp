// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        array<char, 26> positions;
        for (int i = 0; i < order.size(); ++i) {
            positions[order[i] - 'a'] = i;
        }

        sort(s.begin(), s.end(), [&positions](char a, char b) { return positions[a - 'a'] < positions[b - 'a']; });
        return s;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
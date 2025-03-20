// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        array<char, 26> chars{};

        for (char c : allowed) { chars[c - 'a'] = 1; }

        int result = 0;
        for (const string& str : words) {
            bool consistent = true;

            for (char c : str) {
                if (chars[c - 'a'] == 0) {
                    consistent = false;
                    break;
                }
            }

            if (consistent) {
                ++result;
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
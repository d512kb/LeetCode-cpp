// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        short sChars[128]{ 0 }, tChars[128]{ 0 };

        for (int i = 0; i < s.size(); ++i) {
            ++sChars[s[i]];
            ++tChars[t[i]];
        }

        for (int i = 0; i < 128; ++i) {
            if (sChars[i] != tChars[i])
                return false;
        }

        return true;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

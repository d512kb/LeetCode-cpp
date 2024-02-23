// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        char sMap[256]{ 0 };
        char tMap[256]{ 0 };

        for (int i = 0; i < s.size(); ++i) {
            char& sChar = sMap[s[i]];
            char& tChar = tMap[t[i]];

            if (sChar != 0 && sChar != t[i])
                return false;
            else if (tChar != 0 && tChar != s[i])
                return false;

            sChar = t[i];
            tChar = s[i];
        }

        return true;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;

        int a = 0, b = 0;
        int lenMax = 0;

        for (b; b < s.size(); ++b) {
            if (chars.contains(s[b])) {
                lenMax = max(lenMax, b - a);
                a = chars[s[b]] + 1;
            }

            chars[s[b]] = b;
        }

        return max(lenMax, b - a);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto lastChar = find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !isspace(c); });
        int len = 0;

        while (lastChar != s.rend()) {
            if (*lastChar++ == ' ')
                return len;

            ++len;
        }

        return len;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

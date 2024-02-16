// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int a = 0;
        int b = s.size() - 1;

        while (a < b) {
            if (!isalnum(s[a])) { ++a; continue; }
            if (!isalnum(s[b])) { --b; continue; }

            if (tolower(s[a++]) != tolower(s[b--])) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}

// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int64_t result{ 0 };
        int charIndex{ 0 };
        bool sign{ false };

        if (s.empty())
            return result;

        while (isSpace(s[charIndex])) {
            ++charIndex;

            if (charIndex == s.size())
                return result;
        }

        if (isSign(s[charIndex])) {
            sign = s[charIndex] == '-';
            ++charIndex;

            if (charIndex == s.size())
                return result;
        }

        while (s[charIndex] == '0') {
            ++charIndex;

            if (charIndex == s.size())
                return result;
        }

        while (isDigit(s[charIndex]) && charIndex < s.size()) {
            result = result * 10 + chtoi(s[charIndex]);
            ++charIndex;

            if ((sign && -result < numeric_limits<int>::min()) || result > numeric_limits<int>::max()) {
                return sign ? numeric_limits<int>::min() : numeric_limits<int>::max();
            }
        }

        if ((sign && result < numeric_limits<int>::min()) || result > numeric_limits<int>::max()) {
            return sign ? numeric_limits<int>::min() : numeric_limits<int>::max();
        }

        return sign ? -result : result;
    }

private:
    inline bool isDigit(char ch) {
        return 48 <= ch && ch <= 57;
    }
    inline bool isSpace(char ch) {
        return ch == ' ';
    }
    inline bool isSign(char ch) {
        return ch == '-' || ch == '+';
    }
    inline int chtoi(char ch) {
        return ch - 48;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << sol.myAtoi("3.14159") << endl;

    PRINT_ELAPSED(timer);

    return 0;
}

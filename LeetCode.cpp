// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        vector<char> stack;
        stack.reserve(s.size());

        for (char c : s) {
            if (c == '*') {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }

        return string(stack.begin(), stack.end());
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
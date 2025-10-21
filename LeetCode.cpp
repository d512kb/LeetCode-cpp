// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        array<char, 26> chars{};

        for (char c : sentence) {
            chars[c - 'a'] = 1;
        }

        return all_of(chars.begin(), chars.end(), [](char c) { return c == 1; });
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
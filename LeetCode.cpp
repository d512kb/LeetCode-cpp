// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string result;

        for (int i = s.size() - 1; i >= 0;) {
            if (s[i] == '#') {
                result.push_back('j' + stoi(s.substr(i - 2, 2)) - 10);
                i -= 3;
            }
            else {
                result.push_back('a' + s[i] - '0' - 1);
                i -= 1;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
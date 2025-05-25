// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string resultingString(string s) {
        string result;

        for (char c : s) {
            if (!result.empty() && adjacent(result.back(), c)) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }

        return result;
    }
private:
    inline bool adjacent(char a, char b) const {
        return abs(a - b) == 1 || abs(a - b) == 25;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
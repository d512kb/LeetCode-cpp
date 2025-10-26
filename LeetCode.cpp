// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string result;

        for (char c : s) {
            if (isdigit(c)) {
                if (!result.empty() && !isdigit(result.back())) {
                    result.pop_back();
                }
            }
            else {
                result.push_back(c);
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
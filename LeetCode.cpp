// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string largestEven(string s) {
        while (!s.empty()) {
            if (s.back() == '2') { return s; }

            s.pop_back();
        }

        return s;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
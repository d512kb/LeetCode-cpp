// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        size_t absent = 0;
        size_t late = 0;

        for (char c : s) {
            if (c == 'A') {
                if (++absent >= 2) { return false; }
                late = 0;
            }
            else if (c == 'L') {
                if (++late >= 3) { return false; }
            }
            else { late = 0; }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.size() > typed.size() || name[0] != typed[0]) { return false; }

        int i = 0;
        int j = 0;

        while (j < typed.size()) {
            if (name[i] == typed[j]) {
                ++i;
                ++j;
            }
            else if (name[i - 1] == typed[j]) {
                ++j;
            }
            else {
                return false;
            }
        }

        return i == name.size();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
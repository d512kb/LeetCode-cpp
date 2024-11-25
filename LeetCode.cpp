// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int maxOpen = 0;
        int minOpen = 0;

        for (char c : s) {
            if (c == '(') {
                ++maxOpen;
                ++minOpen;
            } else if (c == ')') {
                --maxOpen;
                --minOpen;
            } else {
                ++maxOpen;
                --minOpen;
            }

            if (minOpen < 0) { minOpen = 0; }
            if (maxOpen < 0) { return false; }
        }

        return minOpen == 0;
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
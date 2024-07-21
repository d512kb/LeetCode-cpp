// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        string wovels{ "aeiou" };

        for (char c : s) {
            if (wovels.find(c) != string::npos) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
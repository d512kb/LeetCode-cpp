// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string sChanged;
            for (int i = 0; i < s.size() - 1; ++i) {
                sChanged.push_back((s[i] - 'a' + s[i + 1] - 'a') % 10 + 'a');
            }
            s = sChanged;
        }

        return s[0] == s[1];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
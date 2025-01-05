// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int lastIndex = s.size() - 1;
        int steps = 0;

        while (lastIndex != 0) {
            if (s[lastIndex] == '0') {
                --lastIndex;
                ++steps;
            } else {
                char carry = 1;
                for (int i = lastIndex; i >= 0; --i) {
                    if (s[i] == '1') {
                        s[i] = '0';
                    } else {
                        s[i] += 1;
                        carry = 0;
                        break;
                    }
                }

                ++steps;

                if (carry) {
                    steps += lastIndex + 1;
                    break;
                }
            }
        }

        return steps;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
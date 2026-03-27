// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int large = -1;
        int largest = -1;

        for (char c : s) {
            if (isdigit(c)) {
                int n = c - '0';

                if (n > largest) {
                    large = largest;
                    largest = n;
                }
                else if (n > large && n < largest) {
                    large = n;
                }
            }
        }

        return large;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
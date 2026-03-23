// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        size_t i = 0;

        while (i < bits.size() - 1) {
            if (bits[i] == 1) {
                i += 2;
            }
            else {
                i += 1;
            }
        }

        return i != bits.size();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
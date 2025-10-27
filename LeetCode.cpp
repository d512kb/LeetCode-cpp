// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int threshold = arr.size() / 4;
        int currInt = -1;
        int currCount = 0;

        for (int c : arr) {
            if (c == currInt) {
                ++currCount;
            }
            else {
                currInt = c;
                currCount = 1;
            }

            if (currCount > threshold) { return c; }
        }

        return -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}